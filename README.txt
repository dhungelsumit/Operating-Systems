Sumit Dhungel
CSCI 401 Operating Systems
Instructor: Gedare Bloom
Project 1, Part 1 : Version #3

The project contains four different files: list.h , list.c, list_test.c and Makefile

list.h is a header file which contains the struct definitions , typedefs and function prototypes.
It can be shared between several source files using #include.

list.c is a source file which contains the implementation of the function bodies of linked list data structure for storing character string. 
create_list() method allocates a space in a memory for a new list and initializes it. 
add_to_list() method adds a new element to the end of a given list. If the addition is successful, it returns 0. Otherwise, it returns 1.
remove_from_list() method removes the string from the end of the list and returns pointer to it.
print_list() method prints every element in a list.
flush_list() method removes every element from the entire list and reinitializes it.
free_list() method performs similar to flush_list() method. However, it also ensures that the memory allocated for the list is freed.

list_test.c contains the test of the implementation of the linked list.
test_create_list() tests if a new list could be created properly. If not, there will be segmentation fault.
test_add_to_list_empty() tests if it is possible to add a element to a new list. The test fails if add_to_list returns 1.
test_add_to_list_multiple() tests if it is possible to add multiple elements to a new list. The test fails if add_to_list returns 1.	
test_print_list_empty() tests if print_list is called on empty list, nothing will be printed.
test_print_list_single() tests that the element is displayed properly if print_list is called on a list containing single element.
test_print_list_multiple() tests that the element are displayed properly if print_list is called on a list containing multiple elements.
test_remove_from_list_empty() tests that if the remove_from _list is called on empty list, NULL is returned.
test_remove_from_list_single() tests that the removal works properly on a list containing single element.
test_remove_from_list_multiple() tests that the removal works properly on a list containing multiple elements.
test_addition_after_remove() ensures that remove doesnot remove the linked list entirely from the memory.
test_flush_list() tests that if the flush method is called on a list, all the elements are removed from it.
test_flush_addition() tests that after flushing, it is possible to add new elements to the list.
test_free_list() tests that if free is called, the elements are removed from the list and memory is freed.

Makefile compiles list.c and list_test.c to create a binary executable named list_test3. 

To build the file, 

- Unzip the file to a directory
- Go to the directory containing all the above mentioned files in the terminal and run the command : make 

Some of the challenges for me were:
- The first challenge was to learn c and learn concepts of memory allocation in it properly.
- I was also having hard time testing that my free_list function properly.
- I was new to concepts about the Makefile and I was having hard time creating it.

Some of the resources I used are:
- http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
- http://cslibrary.stanford.edu/

