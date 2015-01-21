typedef struct arrayUtil
{
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (MatchFunc)(void* hint, void* item);



int areEqual(ArrayUtil array1, ArrayUtil array2);

ArrayUtil create(int typesize, int length);

ArrayUtil resize(ArrayUtil array, int length);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);

void* findLast(ArrayUtil util, MatchFunc* match, void* hint);