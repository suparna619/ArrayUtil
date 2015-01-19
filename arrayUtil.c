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
