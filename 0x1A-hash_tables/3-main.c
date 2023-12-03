#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;
	unsigned int i;

	ht = hash_table_create(1024);
	if (ht == NULL)
	{
		fprintf(stderr, "Failed to create hash table\n");
		return (EXIT_FAILURE);
	}

	hash_table_set(ht, "betty", "cool");
	hash_table_set(ht, "omar", "NULL");
	hash_table_set(ht, "tata", "zxcz");
	hash_table_set(ht, "nanan", "hgnhg");
	hash_table_set(ht, "ovvaa", "asa");
	hash_table_set(ht, "koka", "lkmk");
	hash_table_set(ht, "cool", "gpt");
	hash_table_set(ht, "NULL", "test");

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *current = ht->array[i];

		while (current != NULL)
		{
			printf("%u %s = %s\n", i, current->key, current->value);
			current = current->next;
		}
	}

	return (EXIT_SUCCESS);
}
