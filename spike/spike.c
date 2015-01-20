#include <stdio.h>
#include <stdlib.h>

typedef struct arrayUtil
{
	int *base;
	int typeSize;
	int length;
} ArrayUtil;


int main()
{
	int *array,i;
	array = malloc(sizeof(int)*3);
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;

	array = calloc(1,sizeof(int));

	for (i = 0; i < 3; ++i)
	{
		// array[i] = 0;
		printf("%d\n", array[i]);
	}
	free(array);
	return 0;
}