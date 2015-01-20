typedef struct arrayUtil
{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqual(ArrayUtil array1, ArrayUtil array2);

ArrayUtil create(int typesize, int length);

ArrayUtil resize(ArrayUtil array, int length);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);
