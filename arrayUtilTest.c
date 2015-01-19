#include "../expr_assert.h"
#include "arrayUtil.h"



void test_for_equality_of_two_arrays_for_right_condition(){
	int arr1[3] ={1,2,3};
	int arr2[3] = {1,2,3}; 
	ArrayUtil array1 = { arr1  , sizeof(int) , 3 };
	ArrayUtil array2 = { arr2  , sizeof(int) , 3 };
	assertEqual(areEqual(array1, array2) , 1);

}

void test_for_equality_of_two_arrays_for_wrong_condition_by_element(){
	int arr1[3] ={1,2,3};
	int arr2[3] = {1,5,3}; 
	ArrayUtil array1 = { arr1  , sizeof(int) , 3 };
	ArrayUtil array2 = { arr2  , sizeof(int) , 3 };
	assertEqual(areEqual(array1, array2) , 0);
}

void test_for_equality_of_two_arrays_for_wrong_condition_by_size(){
	int arr1[3] ={1,2,3};
	int arr2[4] = {1,2,3,4}; 
	ArrayUtil array1 = { arr1  , sizeof(int) , 3 };
	ArrayUtil array2 = { arr2  , sizeof(int) , 4 };
	assertEqual(areEqual(array1, array2) , 0);
}