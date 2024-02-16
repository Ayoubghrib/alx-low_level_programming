#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table with a given size
 * @size: size of the hash table
 * Return: the created hash table, or NULL if function fails
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;
	hash_node_t **array = NULL;
	unsigned long int i;

	/* Validate size to prevent negative or excessively large values */
	if (size == 0 || size > MAX_TABLE_SIZE)
		return (NULL);

	/* Allocate memory for the table structure */
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL); /* Memory allocation failed */

	/* Allocate memory for the array of hash nodes */
	array = calloc(size, sizeof(hash_node_t *));
	if (array == NULL)
	{
		free(table); /* Clean up previously allocated memory */
		return (NULL); /* Memory allocation failed */
	}

	/* Initialize each element of the array to NULL */
	for (i = 0; i < size; i++)
		array[i] = NULL;

	/* Populate the hash table structure */
	table->array = array;
	table->size = size;

	return (table);
}

