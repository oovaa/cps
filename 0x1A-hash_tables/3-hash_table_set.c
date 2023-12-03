#include "hash_tables.h"

hash_node_t *makeNode(const char *key, const char *value);

/**
 * hash_table_set - sets a key to a value in the hash table
 * @ht: hash table to add elemt to
 * @key: key for the data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned int index;
	hash_node_t  *tmp, *node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	if (!ht->array[index])
	{
		ht->array[index] = makeNode(key, value);
		return ((ht->array[index]) ? 1 : 0);
	}
	else if (ht->array[index])
	{
		tmp = ht->array[index];
		while (tmp)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->value);
				tmp->value = strdup(value);
				if (!tmp->value)
					return (0);
				return (1);
			}
			tmp = tmp->next;
		}

		node = makeNode(key, value);
		if (!node)
			return (0);
		node->next = ht->array[index];
		ht->array[index] = node;
	return ((node->next) ? 1 : 0);
	}
	return (0);
}

/**
 * makeNode - creates a node
 * @key: key for the data
 * @value: data to store
 *
 * Return: 1 if successful, 0 otherwise
 */

hash_node_t *makeNode(const char *key, const char *value)
{
	hash_node_t *node = malloc(sizeof(hash_node_t));

	if (!node)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	return (node);
}
