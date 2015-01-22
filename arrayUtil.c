#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

int counter;

int areEqualForArrayElements(ArrayUtil array1 , ArrayUtil array2){
	for(counter = 0; counter < array1.length*array1.typeSize; counter++){
		if(((char*) array1.base)[counter]!=((char*)array2.base)[counter]){
			return 0;
		}
	}
	return 1;
}

int areEqualForTypesize(ArrayUtil array1 , ArrayUtil array2){
	return (array1.typeSize == array2.typeSize) && areEqualForArrayElements(array1 , array2);
	
}

int areEqual( ArrayUtil array1 , ArrayUtil array2){
	return (array1.length == array2.length) && areEqualForTypesize(array1 , array2);
}

ArrayUtil create(int typesize , int length){
	ArrayUtil array;
	array.base = calloc(length,typesize);
	array.length = length;
	array.typeSize = typesize;
	return array;
}

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil new_util = create(util.typeSize, length);
	memcpy(new_util.base, util.base, util.length*util.typeSize);
	return new_util;
}

int findIndex(ArrayUtil util, void* element){
	char *e = (char *)element;
	char *array = (char *)util.base;
	for(counter = 0; counter < util.length*util.typeSize; counter = counter+util.typeSize){
		if(array[counter] == *e)
			return counter/util.typeSize;
	}
	return -1;
}

void dispose(ArrayUtil util){
	free(util.base);
	util.length = 0;
	util.typeSize = 0;
}

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	void *item = malloc(util.typeSize);
	char *base = (char *)util.base;
	for (counter=0; counter < util.length; counter++){
		memcpy(item,&(base[counter*util.typeSize]),util.typeSize);
		if(match(hint,item)){
			return item;
		}
	}
	return NULL;
}

void* findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *item = malloc(util.typeSize);
	char *base = (char *)util.base;
	for (counter = util.length-1; counter >=0 ; counter--){
		memcpy(item,&(base[counter*util.typeSize]),util.typeSize);
		if(match(hint,item)){
			return item;
		}
	}
	return NULL;	
}

int count(ArrayUtil util, MatchFunc* match, void* hint){
	int matchedItem = 0;
	void *item = malloc(util.typeSize);
	char *base = (char *)util.base;
	for (counter=0; counter < util.length; counter++){
		memcpy(item,&(base[counter*util.typeSize]),util.typeSize);
		if(match(hint,item))
			matchedItem++;
	}
	return matchedItem;
}