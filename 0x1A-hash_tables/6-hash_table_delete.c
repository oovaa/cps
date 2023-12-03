#include "hash_tables.h"


/**
 * free_list - frees the memory occupied by a linked list
 * @node: pointer to the head of the linked list
 *
 * Description:
 *   This helper function recursively traverses the linked list and frees the
 *   memory occupied by each node, including keys and values.
 */
void free_list(hash_node_t *node)
{
	if (!node)
		return;

	free_list(node->next);

	free(node->key);
	free(node->value);
	free(node);
}

/**
 * hash_table_delete - deletes a hash table and frees all its memory
 * @ht: pointer to the hash table
 *
 * Description:
 *   This function frees the memory occupied by the given hash table. It
 *   iterates through each index in the hash table array and calls the
 *   free_list function to free the memory occupied by the linked list at that
 *   index.
 */

void hash_table_delete(hash_table_t *ht)
	{

		unsigned int i = 0;

		for (i = 0; i < ht->size; i++)
		{
			if (ht->array[i])
				free_list(ht->array[i]);

		}
	free(ht->array);
	free(ht);
	}
