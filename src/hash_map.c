#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "hash_map.h"

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

void KeyVal_println(KeyVal to_print) {
	printf("('%s', '%s')\n", to_print.key, to_print.val);
}

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
	vec->size += sizeof(KeyVal) + strlen(to_append.key ) + strlen(to_append.val) + 1;

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

bool KeyValVec_contains_key(KeyValVec vec, char* key) {
    for (size_t i = 0; i < vec.len; i++) {
        if (vec.ptr[i].key == key) {
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

	to_ret.len = 10;
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
    int place = HashMap_hash_and_mod(*map, element.key);
    map->size = sizeof(KeyValVec) * map->len;
    map->ptr = realloc(map->ptr, map->size);
	if (!KeyValVec_contains_key(map->ptr[place], element.key)) {
    	KeyValVec_append(&map->ptr[place], element);
	} else {
		for (size_t i = 0; i < map->ptr[place].len; i++) {
			if (map->ptr[place].ptr[i].key == element.key) {
				map->ptr[place].ptr[i].val = element.val;
			}
		}	
	}
}

char* HashMap_get(HashMap map, char* key) {
	int pos = HashMap_hash_and_mod(map, key);
	if ( KeyValVec_contains_key(map.ptr[pos], key) ) {
		if (map.ptr[pos].len == 1 &&map.ptr[pos].ptr[0].key == key) {
			return map.ptr[pos].ptr[0].val;
		} else {
			for (size_t i = 0; i < map.ptr[pos].len; i++) {
				if (map.ptr[pos].ptr[i].key == key) {
					return map.ptr[pos].ptr[i].val;
				}
			}	
		}
	}
	return 0;
}

int HashMap_hash_and_mod(HashMap map, unsigned char *str) {
	return (int)(hash(str) % map.len);
}
