#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"




int isEven(void *hint,void *item){
	return ((*((int*)item)%2)==0);
}

int isDivisible(void* hint, void* item){
	return ((*((int *)item)%*((int *)hint))==0);
}

int isMatch(void* hint, void* item){
	return ((*((char *)item)==*((char *)hint)));
}

void test__areEqual_01__for_equality_of_two_int_arrays_for_right_condition(){
	int arr1[] = {1,2,3};
	int arr2[] = {1,2,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test__areEqual_02__for_equality_of_two_float_arrays_for_right_condition(){
	float arr1[] = {1.2,2.9,3.8};
	float arr2[] = {1.2,2.9,3.8}; 
	ArrayUtil array1 = {arr1, sizeof(float), 3};
	ArrayUtil array2 = {arr2, sizeof(float), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test__areEqual_03__for_equality_of_two_char_arrays_for_right_condition(){
	char arr1[] = "Sup";
	char arr2[] = "Sup"; 
	ArrayUtil array1 = {arr1, sizeof(char), 3};
	ArrayUtil array2 = {arr2, sizeof(char), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test__areEqual_04__for_equality_of_two_char_arrays_for_wrong_condition_by_element(){
	char arr1[] = "Sup";
	char arr2[] = "Sid"; 
	ArrayUtil array1 = {arr1, sizeof(char), 3};
	ArrayUtil array2 = {arr2, sizeof(char), 3};
	assertEqual(areEqual(array1, array2) , 0);
}

void test__areEqual_05__for_equality_of_two_double_arrays_for_right_condition(){
	double arr1[] = {1,2,3};
	double arr2[] = {1,2,3}; 
	ArrayUtil array1 = {arr1, sizeof(double), 3};
	ArrayUtil array2 = {arr2, sizeof(double), 3};
	assertEqual(areEqual(array1, array2) , 1);
}

void test__areEqual_06__for_equality_of_two_arrays_for_wrong_condition_by_element(){
	int arr1[] = {1,2,3};
	int arr2[] = {1,5,3}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 3};
	assertEqual(areEqual(array1, array2) , 0);
}

void test__areEqual_07__for_equality_of_two_arrays_for_wrong_condition_by_size(){
	int arr1[] = {1,2,3};
	int arr2[] = {1,2,3,4}; 
	ArrayUtil array1 = {arr1, sizeof(int), 3};
	ArrayUtil array2 = {arr2, sizeof(int), 4};
	assertEqual(areEqual(array1, array2), 0);
}

void test__areEqual_08__areEqual_returns_1_when_elements_of_both_char_array_are_same(){
	char arr1[] = "Suparna";
	char arr2[] = "Suparna";
	ArrayUtil array1 = {arr1, sizeof(char), 7};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
	assertEqual(areEqual(array1,array2), 1);
} 

void test__areEqual_09__areEqual_returns_1_when_elements_and_length_of_both_char_array_are_not_same(){
	char arr1[] = "Suparn";
	char arr2[] = "Suparna";
	ArrayUtil array1 = {arr1, sizeof(char), 6};
	ArrayUtil array2 = {arr2, sizeof(char), 7};
	assertEqual(areEqual(array1,array2), 0);
}

void test__areEqual_10__areEqual_returns_0_when_the_elements_of_two_array_of_double_type_are_not_same(){
	double arr1[] = {1.3,2.5,5.6};
	double arr2[] = {1.3,2.5,5.5};
	ArrayUtil array1 = {arr1, sizeof(double),3};
	ArrayUtil array2 = {arr2, sizeof(double),3};
	assertEqual(areEqual(array1,array2), 0);
}

void test__areEqual_11__areEqual_returns_0_when_lengths_of_two_array_of_double_type_are_unequal(){
	double arr1[] = {1.3,2.5,5.6};
	double arr2[] = {1.3,2.5};
	ArrayUtil array1 = {arr1, sizeof(double),3};
	ArrayUtil array2 = {arr2, sizeof(double),2};
	assertEqual(areEqual(array1,array2), 0);
} 

void test__create_01__creat_returns_new_ArraUtil_of_specified_size_and_length_with_int_type_base_and_set_all_element_to_zero(){
	int counter;
	ArrayUtil array = create(sizeof(int),5);
	assertEqual(array.length,5);
	assertEqual(array.typeSize,sizeof(int));
	for(counter=0;counter<array.length;counter++)
		assertEqual(((int *)array.base)[counter],0);
	dispose(array);
}

void test__create_02__creat_returns_new_ArraUtil_of_specified_size_and_length_with_char_type_base_and_set_all_element_to_zero(){
	int counter;
	ArrayUtil array = create(sizeof(char),5);
	assertEqual(array.length,5);
	assertEqual(array.typeSize,sizeof(char));
	for(counter=0;counter<array.length;counter++)
		assertEqual(((char *)array.base)[counter],0);
}

void test__create_03__creat_returns_new_ArraUtil_of_specified_size_and_length_with_float_type_base_and_set_all_element_to_zero(){
	int counter;
	ArrayUtil array = create(sizeof(float),5);
	assertEqual(array.length,5);
	assertEqual(array.typeSize,sizeof(float));
	for(counter=0;counter<array.length;counter++)
		assertEqual(((float *)array.base)[counter],0);
	dispose(array);
}

void test__create_04__creat_returns_new_ArraUtil_of_specified_size_and_length_with_double_type_base_and_set_all_element_to_zero(){
	int counter;
	ArrayUtil array = create(sizeof(double),5);
	assertEqual(array.length,5);
	assertEqual(array.typeSize,sizeof(double));
	for(counter=0;counter<array.length;counter++)
		assertEqual(((double *)array.base)[counter],0);
	dispose(array);
}

void test__resize_01__for_resize_an_existing_int_array_after_resizing_with_a_less_size(){
	int arr[] = {2,4,6,8,10};
	ArrayUtil result_array;
	ArrayUtil array = {arr, sizeof(int), 5};
	result_array = resize(array,3);
	assertEqual(result_array.length, 3);
	assertEqual(((int *)result_array.base)[0],2);
	assertEqual(((int *)result_array.base)[1],4);
	assertEqual(((int *)result_array.base)[2],6);
}

void test__resize_02__for_resize_an_existing_int_array_after_resizing_with_a_greater_size(){
	int arr[] = {2,4,6};
	ArrayUtil result_array;
	ArrayUtil array = {arr, sizeof(int), 3};
	result_array = resize(array,5);
	assertEqual(result_array.length, 5);
	assertEqual(((int *)result_array.base)[0],2);
	assertEqual(((int *)result_array.base)[1],4);
	assertEqual(((int *)result_array.base)[2],6);
	assertEqual(((int *)result_array.base)[3],0);
	assertEqual(((int *)result_array.base)[4],0);
}

void test__resize_03__for_resize_an_existing_char_array_after_resizing_with_a_less_size(){
	char arr[] = "ThoughtWorks";
	ArrayUtil result_array;
	ArrayUtil array = {arr, sizeof(char), 12};
	result_array = resize(array,7);
	assertEqual(result_array.length, 7);
	assertEqual(((char *)result_array.base)[0],'T');
	assertEqual(((char *)result_array.base)[1],'h');
	assertEqual(((char *)result_array.base)[2],'o');
	assertEqual(((char *)result_array.base)[3],'u');
	assertEqual(((char *)result_array.base)[4],'g');
	assertEqual(((char *)result_array.base)[5],'h');
	assertEqual(((char *)result_array.base)[6],'t');
}

void test__resize_04__for_resize_an_existing_char_array_after_resizing_with_a_greater_size(){
	char arr[] = "Tho";
	ArrayUtil result_array;
	ArrayUtil array = {arr, sizeof(char), 3};
	result_array = resize(array,5);
	assertEqual(result_array.length, 5);
	assertEqual(((char *)result_array.base)[0],'T');
	assertEqual(((char *)result_array.base)[1],'h');
	assertEqual(((char *)result_array.base)[2],'o');
	assertEqual(((char *)result_array.base)[3],0);
	assertEqual(((char *)result_array.base)[4],0);
}

void test__findIndex_01__findIndex_retruns_the_index_of_an_element_in_an_int_array(){
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
	dispose(array);
}

void test__findIndex_02__findIndex_retruns_negative1_for_an_element_which_is_not_in_an_int_array(){
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
	dispose(array);
}

void test__findIndex_03__findIndex_retruns_the_index_of_an_element_in_an_char_array(){
	char array[]= "Surajit";
	char element ='r';
	int index;
	ArrayUtil src;
	src.base = array;
	src.length = 4;
	src.typeSize = sizeof(char);
	index = findIndex(src,&element);
	assertEqual(index,2);
};

void test__findIndex_04__findIndex_retruns_negative1_for_an_element_which_is_not_in_an_char_array(){
	char array[]= "Surajit";
	char element ='o';
	int index;
	ArrayUtil src;
	src.base = array;
	src.length = 4;
	src.typeSize = sizeof(char);
	index = findIndex(src,&element);
	assertEqual(index,-1);
};

void test__findIndex_05__findIndex_retruns_the_index_of_an_element_in_an_float_array(){
	int index;
	float element=5.5;
	ArrayUtil array = create(sizeof(float),4);
	((float *)array.base)[0]=1.1;
	((float *)array.base)[1]=3.3;
	((float *)array.base)[2]=5.5;
	((float *)array.base)[3]=7.7;
	index = findIndex(array, &element);
	assertEqual(index,2);
	dispose(array);
}

void test__findIndex_06__findIndex_retruns_negative1_for_an_element_which_is_not_in_an_float_array(){
	int index;
	float element=4.4;
	ArrayUtil array = create(sizeof(float),4);
	((float *)array.base)[0]=1.1;
	((float *)array.base)[1]=3.3;
	((float *)array.base)[2]=5.5;
	((float *)array.base)[3]=7.7;
	index = findIndex(array, &element);
	assertEqual(index,-1);
	dispose(array);
}

void test__dispose_01__dispose_free_the_array(){
	ArrayUtil array = create(sizeof(int),2);
	assertEqual(((int*)array.base)[0],0);
	assertEqual(((int*)array.base)[1],0);
	dispose(array);
}

void test__findFirst_01__findFirst_retruns_first_even_number_from_the_int_array(){
	ArrayUtil array = create(sizeof(int),5);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=22;
	((int *)array.base)[2]=33;
	((int *)array.base)[3]=44;
	((int *)array.base)[4]=55;
	result=(int*)findFirst(array,isEven,0);
 	assertEqual(*result,22);
 	dispose(array);
}

void test__findFirst_02__findFirst_retruns_NULL_if_no_element_is_a_even_number_in_an_int_array(){
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
 	dispose(array);
}

void test__findFirst_03__findFirst_retruns_first_element_which_is_divisible_by_5_in_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=10;
	result=(int*)findFirst(array,isDivisible,&hint);
 	assertEqual(*result,5);
 	dispose(array);
}

void test__findFirst_04__findFirst_retruns_NULL_if_no_element_is_divisible_by_5_in_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=6;
	((int *)array.base)[2]=8;
	((int *)array.base)[3]=12;
	result=(int*)findFirst(array,isDivisible,&hint);
 	assertEqual((int)result,0);
 	dispose(array);
}

void test__findLast_01__findLast_retruns_last_even_number_from_the_int_array(){
	ArrayUtil array = create(sizeof(int),5);
	int *result;
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=22;
	((int *)array.base)[2]=33;
	((int *)array.base)[3]=44;
	((int *)array.base)[4]=55;
	result=(int*)findLast(array,isEven,0);
 	assertEqual(*result,44);
 	dispose(array);
}

void test__findLast_02__findLast_retruns_NULL_if_no_element_is_a_even_number_in_an_int_array(){
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
 	dispose(array);
}

void test__findLast_03__findLast_retruns_first_element_which_is_divisible_by_5_in_an_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=2;
	((int *)array.base)[1]=4;
	((int *)array.base)[2]=5;
	((int *)array.base)[3]=10;
	result=(int*)findLast(array,isDivisible,&hint);
 	assertEqual(*result,10);
 	dispose(array);
}

void test__findLast_04__findLast_retruns_NULL_if_no_element_is_divisible_by_5_in_an_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int *result;
	int hint = 5;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=6;
	((int *)array.base)[2]=8;
	((int *)array.base)[3]=12;
	result=(int*)findLast(array,isDivisible,&hint);
 	assertEqual((int)result,0);
 	dispose(array);
}

void test__count_01__count_retruns_2_if_two_even_numbers_are_present_in_the_int_array(){
	ArrayUtil array = create(sizeof(int),5);
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=22;
	((int *)array.base)[2]=33;
	((int *)array.base)[3]=44;
	((int *)array.base)[4]=55;
 	assertEqual(count(array,isEven,0),2);
 	dispose(array);
}

void test__count_02__count_retruns_0_if_no_even_number_is_present_in_the_int_array(){
	ArrayUtil array = create(sizeof(int),5);
	((int *)array.base)[0]=11;
	((int *)array.base)[1]=33;
	((int *)array.base)[2]=55;
	((int *)array.base)[3]=77;
	((int *)array.base)[4]=99;
 	assertEqual(count(array,isEven,0),0);
 	dispose(array);
}

void test__count_03__count_retruns_3_if_three_elements_are_divisible_by_2_in_an_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int hint = 2;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=6;
	((int *)array.base)[2]=8;
	((int *)array.base)[3]=12;
 	assertEqual(count(array,isDivisible,&hint),3);
 	dispose(array);
}

void test__count_04__count_retruns_0_if_no_elements_is_divisible_by_2_in_an_int_array(){
	ArrayUtil array = create(sizeof(int),4);
	int hint = 2;
	((int *)array.base)[0]=3;
	((int *)array.base)[1]=63;
	((int *)array.base)[2]=81;
	((int *)array.base)[3]=121;
 	assertEqual(count(array,isDivisible,&hint),0);
 	dispose(array);
}

void test__count_05__count_retruns_2_if_3_elements_is_matched_with_hint_in_an_char_array(){
	char arr[] = "ThoughtWorks";
	char hint = 'o';
	ArrayUtil array = {arr,sizeof(char),12};
	assertEqual(count(array,isMatch,&hint),2);
}

void test__count_06__count_retruns_0_if_no_element_is_matched_with_hint_in_an_char_array(){
	char arr[] = "ThoughtWorks";
	char hint = 'x';
	ArrayUtil array = {arr,sizeof(char),12};
	assertEqual(count(array,isMatch,&hint),0);
}
