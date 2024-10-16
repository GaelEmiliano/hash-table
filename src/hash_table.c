#include "hash_table.h"
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 53

static ht_item*
ht_new_item(const char* the_key, const char* the_value)
{
    ht_item* item = malloc(sizeof(ht_item));
    item->key = strdup(the_key);
    item->value = strdup(the_value);
    return item;
}

ht_hash_table*
ht_new()
{
    ht_hash_table* hash_table = malloc(sizeof(ht_hash_table));
    hash_table->size = MAX_ITEMS;
    hash_table->count = 0;
    hash_table->items = calloc((size_t)hash_table->size, sizeof(ht_item*));
    return hash_table;
}

static void
ht_delete_item(ht_item* item)
{
    free(item->key);
    free(item->value);
    free(item);
}

void
ht_delete_hash_table(ht_hash_table* hash_table)
{
    for (int i = 0; i < hash_table->size; i++) {
        ht_item* item = hash_table->items[i];
        if (item != NULL)
            ht_delete_item(item);
    }
    free(hash_table->items);
    free(hash_table);
}
