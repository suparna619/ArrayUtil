#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

int areEqualForArrayElements(ArrayUtil array1 , ArrayUtil array2){
	int counter;
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
	int counter;
	int length_of_array = util.length;
	util.length = length;
	util.base = realloc(util.base,util.typeSize*length);
	for (counter = length_of_array; counter < length; ++counter)
	{
		((char *)util.base)[counter] = 0;
	}
	return util;
}

int findIndex(ArrayUtil util, void* element){
	int counter; char *e = (char *)element;
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
	int counter;
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
	int counter;
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