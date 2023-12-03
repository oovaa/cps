#include "hash_tables.h"


/**
 * hash_table_get - retrieves the value associated with a key in a hash table
 * @ht: pointer to the hash table
 * @key: key to search for in the hash table
 *
 * Return: value associated with the element, or NULL if key not found
 *
 * Description:
 *   This function retrieves the value associated with the given key in the
 *   specified hash table. It calculates the index in the hash table based on
 *   the provided key using the djb2 hash algorithm. If the key is found in the
 *   linked list at the calculated index, it returns the corresponding value.
 *   If the key is not found, it returns NULL.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{

	hash_node_t *tmp = NULL;

	if (!ht || !key)
		return (NULL);

	tmp = ht->array[key_index((const unsigned char *)key, ht->size)];
	if (!tmp)
		return (NULL);

	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;

	return ((tmp) ? tmp->value : NULL);

}
