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
	int arr1[3] = {1,2,3};
	int arr2[4] = {1,2,3,4}; 
	ArrayUtil array1 = { arr1  , sizeof(int) , 3 };
	ArrayUtil array2 = { arr2  , sizeof(int) , 4 };
	assertEqual(areEqual(array1, array2) , 0);
}

void test_for_create_new_array_in_utility_for_right_condition(){
	ArrayUtil array;
	array = create(sizeof(int) , 4);
	assertEqual(array.length, 4);
}

// void test_for_create_new_array_in_utility_for_wrong_condition(){
// 	ArrayUtil array;
// 	array = create(sizeof(int) , -1);
// 	assertEqual(array , 0);
// }

void test_for_resize_an_existing_array_for_right_condition(){
	int arr[5] = {1,2,3,4,5};
	ArrayUtil array = {arr, sizeof(int), 5};
	ArrayUtil result_array;
	result_array = resize(array,3);
	assertEqual(result_array.length, 3);
}