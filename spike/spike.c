// #include <stdio.h>
// #include <stdlib.h>

// typedef struct arrayUtil
// {
// 	int *base;
// 	int typeSize;
// 	int length;
// } ArrayUtil;


// int main()
// {
// 	int *array,i;
// 	array = malloc(sizeof(int)*3);
// 	array[0] = 1;
// 	array[1] = 2;
// 	array[2] = 3;

// 	array = realloc(array,sizeof(int)*2);

// 	for (i = 0; i < 2; ++i)
// 	{
// 		printf("%d\n", array[i]);
// 	}
// 	free(array);
// 	return 0;
// }

#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "aBCDEF", 6);

   ret = memcmp(str1, str2, 5);

   printf("%d\n", ret);

   if(ret > 0)
   {
      printf("str2 is less than str1");
   }
   else if(ret < 0) 
   {
      printf("str1 is less than str2");
   }
   else 
   {
      printf("str1 is equal to str2");
   }
   
   return(0);
}