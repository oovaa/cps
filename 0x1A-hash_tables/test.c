#include "hash_tables.h"


shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *stable = malloc(sizeof(shash_table_t) + sizeof(shash_node_t *) * size);
	unsigned int i;

	if (!stable)
		return NULL;

	stable->shead = stable->stail = NULL;
	stable->size = size;

	stable->array = (shash_node_t **)(stable + 1);

	for (i = 0; i < size; i++)
		stable->array[i] = NULL;

	return stable;
}

shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	if (!node)
		return NULL;

	node->key = strdup(key);
	node->value = strdup(value);

	if (!node->key || !node->value) {
		free(node->key);
		free(node->value);
		free(node);
		return NULL;
	}

	node->snext = node->sprev = node->next = NULL;

	return node;

}

int add_to_sorted_list(shash_table_t *sht, shash_node_t *node)
{
    shash_node_t *tmp;

    if (!sht || !node)
        return 0;

    if (!sht->shead)
    {
        sht->shead = sht->stail = node;
        return 1;
    }

    tmp = sht->shead;
    while (tmp)
    {
        if (strcmp(tmp->key, node->key) > 0)
        {
            node->snext = tmp;
            node->sprev = tmp->sprev;

            if (node->sprev)
                node->sprev->snext = node;
            else
                sht->shead = node;

            tmp->sprev = node;
            return 1;
        }
        tmp = tmp->snext;
    }

    node->sprev = sht->stail;
    if (sht->stail)
        sht->stail->snext = node;
    sht->stail = node;

    return 1;
}


int shash_table_set(shash_table_t *ht, const char *key, const char *value)
	{
		unsigned int index;
		shash_node_t *newnode, *tmp; 
		shash_node_t **arr;

    	if (!ht || !key || !value)
     	   return 0;

		newnode = create_node(key, value);
		arr = ht->array;
		if (!newnode || ! arr)
			return 0;
		
		index = key_index((const unsigned char *)key, ht->size);
		tmp = arr[index];
		while (tmp)
		{
			if (strcmp(tmp->key, key) == 0)
			{
				free(tmp->key);
				tmp->key = strdup(key);
				free(newnode->key);
				free(newnode->value);
				free(newnode);
				return 1;
			}
			tmp = tmp->next;
		}
		newnode->next = arr[index];
		arr[index] = newnode;

		add_to_sorted_list(ht, newnode);
		return 1;
	}


char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *tmp;

    if (!ht || !key) {
        return NULL;
    }

	tmp = ht->array[key_index((const unsigned char *)key, ht->size)];

	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0)
			return tmp->value;
		tmp = tmp->next;
	}

	return NULL;
}

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp = ht->shead;

	printf("{");
	if (!tmp)
	{
		printf("it is empty");
		return;
	}
	
	while (tmp->snext)
	{
		printf("%s: %s, ",tmp->key, tmp->value);
		tmp = tmp->snext;
	}
	printf("%s: %s}\n",tmp->key, tmp->value);
}

void shash_table_print_rev(const shash_table_t *ht)
{

	shash_node_t *tmp = ht->stail;

	printf("{");
	if (!tmp)
	{
		printf("it is empty");
		return;
	}
	
	while (tmp->sprev)
	{
		printf("%s: %s, ",tmp->key, tmp->value);
		tmp = tmp->sprev;
	}
	printf("%s: %s}\n",tmp->key, tmp->value);
	
}

void shash_table_delete(shash_table_t *ht);

int main() {
    shash_table_t *ht;

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print_rev(ht);
    shash_table_set(ht, "j", "1");
    shash_table_print_rev(ht);
    shash_table_set(ht, "c", "2");
    shash_table_print_rev(ht);
    shash_table_set(ht, "b", "3");
    shash_table_print_rev(ht);
    shash_table_set(ht, "z", "4");
    shash_table_print_rev(ht);
    shash_table_set(ht, "n", "5");
    shash_table_print_rev(ht);
    shash_table_set(ht, "a", "6");
    shash_table_print_rev(ht);
    shash_table_set(ht, "m", "7");
    shash_table_print_rev(ht);
    shash_table_print(ht);
    return (EXIT_SUCCESS);
}



