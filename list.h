struct node {
  struct node *next;
  char *data;
};

typedef struct {
  struct node *root;
} list;

/* Allocates and initializes a new list */
list* create_list( );

/* Adds item to end of the list. This function allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item);

/* Removes the string from the end of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll);

/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list *ll);

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the liist should be freed. */
void flush_list(list* ll);

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll);
