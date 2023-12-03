#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_print(ht);

	hash_table_set(ht, "Betty", "Updated Cool");
	hash_table_set(ht, "new_key", "New Value");
	hash_table_set(ht, "", "Empty Key");
	hash_table_set(ht, "Empty Value", "");
	hash_table_set(ht, "Null Value", NULL);
	hash_table_set(NULL, "Invalid Table", "Value");

	hash_table_print(ht);


	return (EXIT_SUCCESS);
}
