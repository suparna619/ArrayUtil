#include "../expr_assert.h"
#include "arrayUtil.h"



void test_for_equality_of_two_arrays_for_right_condition(){
	int arr1[3] ={1,2,3};
	int arr2[3] = {1,2,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 1);

}

void test_for_equality_of_two_arrays_for_wrong_condition_by_element(){
	int arr1[3] ={1,2,3};
	int arr2[3] = {1,5,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 0);
}

void test_for_equality_of_two_arrays_for_wrong_condition_by_size(){
	int arr1[3] = {1,2,3};
	int arr2[4] = {1,2,3,4}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 4};
	assertEqual(areEqual(array1, array2), 0);
}

void test_areEqual_returns_1_when_elements_of_both_char_array_are_same(){
	char arr1[] ={'s','u','p','a','r','n','a'};
	char arr2[] ={'s','u','p','a','r','n','a'};
	ArrayUtil array1 = {arr1, sizeof(char), 7};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
	assertEqual(areEqual(array1,array2), 1);
} 

void test_areEqual_returns_1_when_elements_and_length_of_both_char_array_are_not_same(){
	char arr1[] ={'s','u','p','a','r','n'};
	char arr2[] ={'s','u','p','a','r','n','a'};
	ArrayUtil array1 = {arr1, sizeof(char), 6};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
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

void test_for_resize_an_existing_array_after_resizing_for_a_less_size(){
	ArrayUtil array = create(sizeof(int), 5);
	ArrayUtil result_array;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=6;
	((int *)array.base)[3]=8;
	((int *)array.base)[4]=10;
	result_array = resize(array,3);
	assertEqual(result_array.length, 3);
	assertEqual(((int *)result_array.base)[0],2);
	assertEqual(((int *)result_array.base)[1],4);
	assertEqual(((int *)result_array.base)[2],6);
}

void test_for_resize_an_existing_array_after_resizing_for_a_greater_size(){
	ArrayUtil array = create(sizeof(int), 3);
	ArrayUtil result_array;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=6;
	result_array = resize(array,5);
	assertEqual(result_array.length, 5);
	assertEqual(((int *)result_array.base)[0],2);
	assertEqual(((int *)result_array.base)[1],4);
	assertEqual(((int *)result_array.base)[2],6);
	assertEqual(((int *)result_array.base)[3],0);
	assertEqual(((int *)result_array.base)[4],0);
}

void test_findIndex_retruns_the_index_of_an_element_in_array(){
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

void test_it_return_indexof_2(){
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