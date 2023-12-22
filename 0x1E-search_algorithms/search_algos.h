#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h> /* Include for size_t definition */

/* Define the listint_t structure */
/**
 * struct listint_s - singly linked list node
 * @n: Integer stored in the node
 * @next: Pointer to the next node
 *
 * Description: Node structure for a singly linked list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Define the skiplist_t structure */
/**
 * struct skiplist_s - singly linked list with an express lane
 * @n: Integer stored in the node
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: Node structure for a singly linked list
 */
typedef struct skiplist_s
{
	int n;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Function prototypes */
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t start, size_t end, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

/* Helper function */
void print_range(int *array, size_t start, size_t end);

#endif /* SEARCH_ALGOS_H */
