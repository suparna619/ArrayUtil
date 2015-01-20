#include <stdio.h>
#include <stdlib.h>
typedef struct arrayUtil
{
	int *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqualForArrayElements(ArrayUtil array1 , ArrayUtil array2){
	int counter;
	for(counter = 0;counter<array1.length; counter++){
		if(array1.base[counter] != array2.base[counter]) 
			break;
	}
	return (counter == array1.length)?1:0;
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

ArrayUtil resize(ArrayUtil array, int length){
	int counter;
	int length_of_array = array.length;
	array.length = length;
	array.base = realloc(array.base,array.typeSize*length);
		for (counter = length_of_array; counter < length; ++counter)
		{
			array.base[counter] = 0;
		}
	return array;
}
