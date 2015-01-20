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

	array = realloc(array,sizeof(int)*2);

	for (i = 0; i < 2; ++i)
	{
		printf("%d\n", array[i]);
	}
	free(array);
	return 0;
}