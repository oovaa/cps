#include "hash_tables.h"

/**
 * print_list - prints the elements of a linked list
 * @node: pointer to the head of the linked list
 *
 * Description:
 *   This helper function prints the key-value pairs of a linked list.
 *   It recursively traverses the list and prints each node's key and value.
 */
void print_list(hash_node_t *node)
{
	if (!node)
		return;

	printf("'%s': '%s'", node->key, node->value);
	if (node->next)
		printf(", ");

	print_list(node->next);
}


/**
 * hash_table_print - prints the elements of a hash table
 * @ht: pointer to the hash table
 *
 * Description:
 *   This function prints the key-value pairs of the elements in the hash
 *   table. It traverses each index in the hash table array and prints the
 *   key-value pairs of the linked list at that index.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned int i = 0;
	int printed = 0;

	if (!ht || !ht->array)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			if (printed)
				printf(", ");
			print_list(ht->array[i]);
			printed = 1;
		}
	}
	printf("}\n");
}
