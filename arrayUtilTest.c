#include <stdio.h>
#include <stdlib.h>
#include "../expr_assert.h"
#include "arrayUtil.h"



void test_for_equality_of_two_int_arrays_for_right_condition(){
	int arr1[] ={1,2,3};
	int arr2[] = {1,2,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test_for_equality_of_two_float_arrays_for_right_condition(){
	float arr1[] ={1.2,2.9,3.8};
	float arr2[] = {1.2,2.9,3.8}; 
	ArrayUtil array1 = {arr1, sizeof(float), 3};
	ArrayUtil array2 = {arr2, sizeof(float), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test_for_equality_of_two_char_arrays_for_right_condition(){
	char arr1[] ={'a','b','c'};
	char arr2[] = {'a','b','c'}; 
	ArrayUtil array1 = {arr1, sizeof(char), 3};
	ArrayUtil array2 = {arr2, sizeof(char), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test_for_equality_of_two_char_arrays_for_wrong_condition_by_element(){
	char arr1[] = "sup";
	char arr2[] = "sil"; 
	ArrayUtil array1 = {arr1, sizeof(char), 3};
	ArrayUtil array2 = {arr2, sizeof(char), 3};
	assertEqual(areEqual(array1, array2) , 0);
}

void test_for_equality_of_two_double_arrays_for_right_condition(){
	double arr1[] ={1,2,3};
	double arr2[] = {1,2,3}; 
	ArrayUtil array1 = {arr1, sizeof(double), 3};
	ArrayUtil array2 = {arr2, sizeof(double), 3};
	assertEqual(areEqual(array1, array2) , 1);
}
void test_for_equality_of_two_arrays_for_wrong_condition_by_element(){
	int arr1[] ={1,2,3};
	int arr2[] = {1,5,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 0);
}

void test_for_equality_of_two_arrays_for_wrong_condition_by_size(){
	int arr1[] = {1,2,3};
	int arr2[] = {1,2,3,4}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 4};
	assertEqual(areEqual(array1, array2), 0);
}

void test_areEqual_returns_1_when_elements_of_both_char_array_are_same(){
	char arr1[] = {'s','u','p','a','r','n','a'};
	char arr2[] = {'s','u','p','a','r','n','a'};
	ArrayUtil array1 = {arr1, sizeof(char), 7};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
	assertEqual(areEqual(array1,array2), 1);
} 

void test_areEqual_returns_1_when_elements_and_length_of_both_char_array_are_not_same(){
	char arr1[] = {'s','u','p','a','r','n'};
	char arr2[] = {'s','u','p','a','r','n','a'};
	ArrayUtil array1 = {arr1, sizeof(char), 6};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
	assertEqual(areEqual(array1,array2), 0);
}

void test_areEqual_returns_0_when_the_elements_of_two_array_of_double_type_are_not_same(){
	double arr1[] = {1.3,2.5,5.6};
	double arr2[] = {1.3,2.5,5.5};
	ArrayUtil array1 = {arr1, sizeof(double),3};
	ArrayUtil array2 = {arr2, sizeof(double),3};
	assertEqual(areEqual(array1,array2), 0);
}

void test_areEqual_returns_0_when_lengths_of_two_array_of_double_type_are_unequal(){
	double arr1[] = {1.3,2.5,5.6};
	double arr2[] = {1.3,2.5};
	ArrayUtil array1 = {arr1, sizeof(double),3};
	ArrayUtil array2 = {arr2, sizeof(double),2};
	assertEqual(areEqual(array1,array2), 0);
} 

void test_creat_returns_new_ArraUtil_of_specified_size_and_length_and_set_all_element_to_zero(){
	int counter;
	ArrayUtil array = create(sizeof(int),5);
	assertEqual(array.length,5);
	assertEqual(array.typeSize,sizeof(int));
	for(counter=0;counter<array.length;counter++){
		assertEqual(((int *)array.base)[counter],0);
	}
}

void test_for_create_new_array_in_utility_for_right_condition(){
	ArrayUtil array;
	array = create(sizeof(int), 4);
	assertEqual(array.length, 4);
	assertEqual(((int *)array.base)[0],0);
	assertEqual(((int *)array.base)[1],0);
	assertEqual(((int *)array.base)[2],0);
	assertEqual(((int *)array.base)[3],0);
}

void test_for_resize_an_existing_array_after_resizing_with_a_less_size(){
	ArrayUtil array = create(sizeof(int), 5);
	ArrayUtil result_array;
	((char *)array.base)[0]=2;
	((char *)array.base)[1]=4;
	((char *)array.base)[2]=6;
	((char *)array.base)[3]=8;
	((char *)array.base)[4]=10;
	result_array = resize(array,3);
	assertEqual(result_array.length, 3);
	assertEqual(((char *)result_array.base)[0],2);
	assertEqual(((char *)result_array.base)[1],4);
	assertEqual(((char *)result_array.base)[2],6);
}

void test_for_resize_an_existing_array_after_resizing_with_a_greater_size(){
	ArrayUtil array = create(sizeof(int), 3);
	ArrayUtil result_array;
	((char *)array.base)[0]=2;
	((char *)array.base)[1]=4;
	((char *)array.base)[2]=6;
	result_array = resize(array,5);
	assertEqual(result_array.length, 5);
	assertEqual(((char *)result_array.base)[0],2);
	assertEqual(((char *)result_array.base)[1],4);
	assertEqual(((char *)result_array.base)[2],6);
	assertEqual(((char *)result_array.base)[3],0);
	assertEqual(((char *)result_array.base)[4],0);
}

void test_findIndex_retruns_the_index_of_an_element_in_an_int_array(){
	int index;
	int element=5;
	ArrayUtil array = create(sizeof(int),4);
	ArrayUtil array1;
	((int *)array.base)[0]=1;
	((int *)array.base)[1]=3;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=7;
	index = findIndex(array, &element);
	assertEqual(index,2);
}

void test_findIndex_retruns_negative1_for_an_element_which_is_not_in_the_array(){
	int index;
	int element=2;
	ArrayUtil array = create(sizeof(int),4);
	ArrayUtil array1;
	((int *)array.base)[0]=1;
	((int *)array.base)[1]=3;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=7;
	index = findIndex(array, &element);
	assertEqual(index,-1);
}

void test_findIndex_retruns_the_index_of_an_element_in_an_char_array(){
	char array[]= {'a','b','c','d'};
	char element ='c';
	int index;
	ArrayUtil src;
	src.base = array;
	src.length = 4;
	src.typeSize = sizeof(char);
	index = findIndex(src,&element);
	assertEqual(index,2);
};

void test_dispose_free_the_array(){
	ArrayUtil array = create(sizeof(int),2);
	assertEqual(((int*)array.base)[0],0);
	assertEqual(((int*)array.base)[1],0);
	dispose(array);
}

int isEven(void *hint,void *item){
	return ((*((int*)item)%2)==0);
}
void test_findFirst_retruns_first_even_number_from_the_array(){
	ArrayUtil array = create(sizeof(int),5);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=22;
	((int *)array.base)[2]=33;
	((int *)array.base)[3]=44;
	((int *)array.base)[4]=55;
	result=(int*)findFirst(array,isEven,0);
 	assertEqual(*result,22);
}

void test_findFirst_retruns_NULL_if_no_element_is_a_even_number_in_array(){
	ArrayUtil array = create(sizeof(int),6);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=33;
	((int *)array.base)[2]=55;
	((int *)array.base)[3]=77;
	((int *)array.base)[4]=99;
	((int *)array.base)[5]=111;
	result=(int*)findFirst(array,isEven,0);
 	assertEqual((int)result,0);
}

int isDivisible(void* hint, void* item){
	return ((*((int *)item)%*((int *)hint))==0);
}

void test_findFirst_retruns_first_element_which_is_divisible_by_5_in_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=10;
	result=(int*)findFirst(array,isDivisible,&hint);
 	assertEqual(*result,5);
}

void test_findFirst_retruns_NULL_if_no_element_is_divisible_by_5_in_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=6;
	((int *)array.base)[2]=8;
	((int *)array.base)[3]=12;
	result=(int*)findFirst(array,isDivisible,&hint);
 	assertEqual((int)result,0);
}

void test_findLast_retruns_last_even_number_from_the_array(){
	ArrayUtil array = create(sizeof(int),5);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=22;
	((int *)array.base)[2]=33;
	((int *)array.base)[3]=44;
	((int *)array.base)[4]=55;
	result=(int*)findLast(array,isEven,0);
 	assertEqual(*result,44);
}

void test_findLast_retruns_NULL_if_no_element_is_a_even_number_in_array(){
	ArrayUtil array = create(sizeof(int),6);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=33;
	((int *)array.base)[2]=55;
	((int *)array.base)[3]=77;
	((int *)array.base)[4]=99;
	((int *)array.base)[5]=111;
	result=(int*)findLast(array,isEven,0);
 	assertEqual((int)result,0);
}

void test_findLast_retruns_first_element_which_is_divisible_by_5_in_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=10;
	result=(int*)findLast(array,isDivisible,&hint);
 	assertEqual(*result,10);
}

void test_findLast_retruns_NULL_if_no_element_is_divisible_by_5_in_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=6;
	((int *)array.base)[2]=8;
	((int *)array.base)[3]=12;
	result=(int*)findLast(array,isDivisible,&hint);
 	assertEqual((int)result,0);
}