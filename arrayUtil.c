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
	int i;
	ArrayUtil a;
	a.typeSize = sizeof(int);
	printf("Enter the array length: \n");
	scanf("%d",&a.length);
	a.base = malloc(a.typeSize*a.length);
	for (i = 0; i < a.length; ++i)
	{
		printf("Enter element at position %d : \n", i+1);
		scanf("%d",&a.base[i]);
		printf("%d\n", a.base[i]);
	}

	for (i = 0; i < a.length; ++i)
	{
		printf("Element at position %d : %d\n",i+1,a.base[i]);
	}

	return 0;
}