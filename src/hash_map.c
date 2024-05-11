#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "hash_map.h"

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

//prints KeyVal struct with new line
void KeyVal_println(KeyVal to_print) {
	printf("('%s', '%s')\n", to_print.key, to_print.val);
}

//prints KeyVal struct without new line
void KeyVal_print(KeyVal to_print) {
	printf("('%s', '%s')", to_print.key, to_print.val);
}

KeyValVec KeyValVec_init() {
	KeyValVec to_ret;

	to_ret.len = 0;
	to_ret.ptr = malloc(1);
	to_ret.size = 1;

	return to_ret;
}

KeyVal KeyValVec_get(KeyValVec vec, int index) {
	return vec.ptr[index];
}

void KeyValVec_append(KeyValVec* vec, KeyVal to_append) {
	vec->size += (sizeof(to_append.key ) + sizeof(to_append.val)) * sizeof(char);

	vec->ptr = realloc(vec->ptr, vec->size);
	vec->ptr[vec->len] = to_append;
	vec->len += 1;
}

bool KeyValVec_contains(KeyValVec vec, KeyVal check) {
    for (size_t i = 0; i < vec.len; i++) {
        if (vec.ptr[i].key == check.key && vec.ptr[i].val == check.val) {
            return true;
        }
    }
    return false;
}

void KeyValVec_print(KeyValVec vec) {
	
	printf("[ ");
	
	for (size_t i = 0; i < vec.len; i++) {
		
		KeyVal_print(vec.ptr[i]);

		if (i != vec.len - 1) {
			printf(", ");
		}
	}

	printf(" ]\n");

}

HashMap HashMap_init() {
	HashMap to_ret;

	to_ret.len = 0;
	to_ret.size = 1;
	to_ret.ptr = malloc(1);

	return to_ret;
}

void HashMap_print(HashMap map) {
    for (size_t i = 0; i < map.len; i++) {
        KeyValVec_print(map.ptr[i]);
    }
    printf("\n"); 
}

void HashMap_add(HashMap* map, KeyVal element) {
    map->len += 1;
    map->size += 8;
    int place = HashMap_HashAndMod(*map, element.key);
    map->ptr = realloc(map->ptr, map->size);
    KeyValVec_append(&map->ptr[place], element);
}

int HashMap_HashAndMod(HashMap map, unsigned char *str) {
	return (int)(hash(str) % map.len);
}
