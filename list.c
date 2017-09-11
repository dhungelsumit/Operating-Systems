#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allocates and initializes a new list */
list* create_list(){
	list* new_list = (list*) malloc(sizeof(list));
	new_list->root = NULL;
	return new_list;
}

/* Adds item to end of the list. This function allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item){
	struct node* current  = (struct node*) malloc(sizeof(struct node));
	current = ll->root;
	char* new_item = strdup(item);	
	// Add item to a list if there is no item previously in the list.
	if (current == NULL){
		current = malloc(sizeof(struct node));
		current->data = new_item;
		// If the new item cannot be assigned to current->data, this means 
		// there was error while allocating the memory. In this case, return 1.
		if (current->data == NULL){
			return 1;
		}
		current->next = NULL;
		ll->root = current;
		return 0;
	}
	// Add item to a if there are other items previously in the list.
	while (current->next != NULL){
		current = current->next;
	}
	current->next = malloc(sizeof(struct node));
	current->next->data = new_item;
	if (current->next == NULL){
		return 1;
	}
	current->next->next = NULL;
	return 0;
}

/* Removes the string from the end of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll){
	struct node* current = ll->root;
	if (current == NULL){
		return NULL;
	}
	/* If only on item in the list. */
	if (current->next == NULL){
		char* deleted = strdup(current->data);
		ll->root = NULL;
		// Return the only element present in previous list.
		return deleted;
	}
	while (current->next->next != NULL){
		current = current->next;
	}
	// Allocates enough memory to hold old string and assign in to new char pointer.
	char* deleted = strdup(current->next->data);
	current->next = NULL;
	return deleted;
}

/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list *ll){
	struct node* current = (struct node*) malloc(sizeof(struct node));
	current = ll->root;
	// Nothing is printed if there is no item in the list.
	while (current != NULL){
		printf("%s\n",current->data);
		current = current->next;
	}
}
/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll){
	// Remove the elements from the list.
	while (ll->root != NULL){
		char* removed = remove_from_list(ll);
		free(removed);
	}
}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll){
	flush_list(ll);
	free(ll);
}
