#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
} ht_hash_table;

ht_hash_table* ht_new();

void ht_delete_hash_table(ht_hash_table* hash_table);

#endif // HASH_TABLE
