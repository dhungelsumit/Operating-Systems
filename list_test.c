#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Test if the new list can be successfully 
 * created. If the new list is not successfully 
 * created, the test will return segmentation fault. */
void test_create_list(){
	printf("*** Testing create list ***\n");
	list *test_list = create_list();
	 printf("New list successfuly created!!\n\n");
	 free(test_list);
}

/* Test to add a single item to an empty list. The 
 * add_to_list will  return 0 only if the item is successfully added. */
void test_add_to_list_empty(){
	printf("*** Testing if an item can be added to empty list ***\n");
	printf("!!! Result must be equal to 0 !!!\n");	
	list *test_list = create_list();
	int result = add_to_list(test_list, "TEST");
	if (result == 0){
		printf("Result = %d . Addition Successful!!!\n\n",result);
	}
	else{
		printf("Result = %d . Addition Failed!!!\n\n",result);
	}
	free(test_list);	
}

/* Test to add multiple items to an empty list. The add_to_list will 
 * return 0 only if the item is successfully added. */
 void test_add_to_list_multiple(){
	printf("*** Testing if multiple can be added to empty list ***\n");
	list *test_list = create_list();
	int result1 = add_to_list(test_list, "TEST1");
	int result2 = add_to_list(test_list, "TEST2");
	if (result1 == 0 && result2 == 0){
		printf("Addition Successful!!!\n\n");
	}
	else{
		printf("Addition Failed!!!\n\n");
	}
	free(test_list);		
}

/* Test to print the items in an empty list. There should not be any output. */
 void test_print_list_empty(){
	printf("*** Testing printing items of empty list ***\n");
	printf("!!! Output must be empty !!! \n\n");	
	list *test_list = create_list();
	printf("***** OUTPUT *****\n");	
	print_list(test_list);
	printf("\n*********************\n\n");
	free(test_list);	
}

/* Test to print if single item is in a list. The print_list must print the 
 * single item. */
void test_print_list_single(){
	printf("*** Testing printing items of single list ***\n");
	printf("!!! Output must be equal to item added !!! \n\n");	
	list *test_list = create_list();
	char *test_item = "TEST";
	printf("Item added: %s\n",test_item);
	printf("***** OUTPUT *****\n");	
	int result = add_to_list(test_list, test_item);
	print_list(test_list);
	printf("*********************\n");
	if (result == 0){
		printf("Printing successful!!\n\n");	
	} else {
		printf("Printing failed!\n\n");			
	}
	free(test_list);	
}

/* Test to print if multiple items are in a list. The print_list must print the
 * added items in the chronological since new item is added to end. */
void test_print_list_multiple(){
	printf("*** Testing printing multiple items of a list ***\n");
	printf("!!! Output must be equal to items added in order !!! \n\n");	
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	int result1 = add_to_list(test_list, test_item1);
	int result2 = add_to_list(test_list, test_item2);
	int result3 = add_to_list(test_list, test_item3);	
	printf("***** OUTPUT *****\n");		
	print_list(test_list);
	printf("*********************\n");
	if (result1 == 0 && result2 == 0 && result3 == 0){
		printf("Printing successful!!\n\n");	
	} else {
		printf("Printing failed!\n\n");			
	}	
	free(test_list);	
}

/* Test to remove element from  an empty list. The remove_from_list will return NULL. */
 void test_remove_from_list_empty(){
	printf("*** Testing if remove working properly in an empty list ***\n");
	printf("!!! Result must be equal to NULL !!!\n");	
	list *test_list = create_list();
	char *result = remove_from_list(test_list);
	if (result == NULL){
		printf("Removal Successful!!!\n\n");
	}
	else{
		printf("Removal Failed!!!\n\n");
	}
	free(test_list);	
}

/* Test to remove the element from  a list containing a single item. The remove_from_list will return the item. */
void test_remove_from_list_single(){
	printf("*** Testing if single item can be removed ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";	
	add_to_list(test_list, test_item1);
	printf("\nItem added: %s\n",test_item1);
	printf("***** BEFORE REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");
	char *result = remove_from_list(test_list);
	printf("Item removed: %s\n",result);	
	printf("***** AFTER REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");		
	if (*result == *test_item1){
		printf("Removal Successful!!!\n\n");
	}
	else{
		printf("Removal Failed!!!\n\n");
	}
	free(test_list);		
}

/* Test to remove the element from  a list containing a multiple items. The remove_from_list will return the item. */
 void test_remove_from_list_multiple(){
	printf("*** Testing if item can be removed from list containing multiple elements ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("*********************\n");	printf("***** BEFORE REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");
	char *result = remove_from_list(test_list);
	printf("Item removed: %s\n",result);	
	printf("***** AFTER REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");	
	if (*result == *test_item3){
		printf("Removal Successful!!!\n\n");
	}
	else{
		printf("Removal Failed!!!\n\n");
	}
	free(test_list);		
}

/* Test to check if addition works properly after removal. */
void test_addition_after_remove(){
	printf("*** Testing if addition works properly after removal ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("*********************\n");	printf("***** BEFORE REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");
	char *result = remove_from_list(test_list);
	printf("Item removed: %s\n",result);	
	printf("***** AFTER REMOVAL: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");	
	if (*result == *test_item3){
		printf("Removal Successful!!!\n\n");
	}
	else{
		printf("Removal Failed!!!\n\n");
	}

	char *test_item4 = "NEW_ITEM";
	printf("New Item added : %s\n",test_item4);
	add_to_list(test_list, test_item4);	
	printf("***** AFTER ADDITION: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");	
	free(test_list);		
}

/* Test if flush list works properly. */
void test_flush_list(){
	printf("*** Testing flush list ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("*********************\n");
	printf("***** BEFORE FLUSHING: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");
	flush_list(test_list);
	printf("*********************\n");	
	printf("***** AFTER FLUSHING: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");	
	free(test_list);	
}

/* Test if we can add elements after flushing */
void test_flush_addition(){
	printf("*** Testing if addition is possible after flushing ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("*********************\n");	
	printf("***** BEFORE FLUSHING: OUTPUT *****\n");	
	print_list(test_list);
	printf("*********************\n");
	flush_list(test_list);
	printf("*********************\n");	
	printf("***** AFTER FLUSHING: OUTPUT *****\n\n");	
	print_list(test_list);
	printf("**********************************\n\n");	
	printf("***** AFTER FLUSHING: ADDITION *****\n");		
	test_item1 = "ITEM1";
	test_item2 = "ITEM2";
	test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("***** OUTPUT *****\n");		
	print_list(test_list);
	printf("*********************\n\n");
	free(test_list);	
}

/* Test if free list works properly. */
void test_free_list(){
	printf("*** Testing free list ***\n");
	list *test_list = create_list();
	char *test_item1 = "ITEM1";
	char *test_item2 = "ITEM2";
	char *test_item3 = "ITEM3";
	printf("Item added 1: %s\n",test_item1);
	printf("Item added 2: %s\n",test_item2);
	printf("Item added 3: %s\n",test_item3);
	add_to_list(test_list, test_item1);
	add_to_list(test_list, test_item2);
	add_to_list(test_list, test_item3);	
	printf("*********************\n");
	printf("***** BEFORE FREEING: OUTPUT *****\n");	
	print_list(test_list);
	printf("**********************************\n");
	free_list(test_list);
	printf("*********************\n");	
	printf("***** AFTER FREEING: OUTPUT *****\n\n");	
	print_list(test_list);
	printf("*********************************\n");	
	free(test_list);	
}

int main(){
	test_create_list();
	test_add_to_list_empty();
	test_add_to_list_multiple();	
	test_print_list_empty();
	test_print_list_single();
	test_print_list_multiple();
	test_remove_from_list_empty();
	test_remove_from_list_single();
	test_remove_from_list_multiple();
	test_addition_after_remove();
	test_flush_list();
	test_flush_addition();
	test_free_list();
	return 0;
}
