#include "hash_tables.h"

/**
 * hash_table_create - creates a table
 * @size: the size
 * Return: hash_table_t obj
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = malloc(sizeof(hash_table_t));
	unsigned long int i;

	/* Check if malloc fails */
	if (table == NULL)
		return (NULL);

	table->array = malloc(sizeof(hash_node_t *) * size);

	/* Check if malloc fails */
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}

	table->size = size;

	for (i = 0; i < size; i++)
	{
		table->array[i] = NULL;
	}

	return (table);
}
