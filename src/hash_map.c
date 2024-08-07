#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "hash_map.h"

#define ADD_ON_RESIZE 7

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
  vec->size += sizeof(KeyVal) + strlen(to_append.key ) + strlen(to_append.val) + 2;

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

	to_ret.capacity = 11;
	to_ret.size = sizeof(KeyValVec) * to_ret.capacity;
    to_ret.ptr = malloc(to_ret.size);
	to_ret.element_num = 0;

	for (size_t i = 0; i < to_ret.capacity; i++) {
		to_ret.ptr[i] = KeyValVec_init();
	}

	return to_ret;
}

void HashMap_print(HashMap map) {
    for (size_t i = 0; i < map.capacity; i++) {
        KeyValVec_print(map.ptr[i]);
    }
    printf("\n"); 
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

void HashMap_add(HashMap* map, KeyVal element) {

	if ( map->capacity <= map->element_num ) {
		// HashMap_resize(map, map->capacity + ADD_ON_RESIZE);
		HashMap_clean_and_resize(map, map->capacity + ADD_ON_RESIZE);
	}

    int place = HashMap_hash_and_mod(*map, element.key);

	if (!KeyValVec_contains_key(map->ptr[place], element.key)) {
    	KeyValVec_append(&map->ptr[place], element);
		map->element_num += 1;
	} else {
		for (size_t i = 0; i < map->ptr[place].len; i++) {
			if (map->ptr[place].ptr[i].key == element.key) {
				map->ptr[place].ptr[i].val = element.val;
			}
		}	
	}
}

void HashMap_clean_and_resize(HashMap* map, size_t new_size) {
	KeyValVec old_hashed_key_vals = KeyValVec_init();

	for (size_t i = 0; i < map->capacity; i++) {
		for (size_t j = 0; j < map->ptr[i].len; j++) {
			KeyValVec_append(&old_hashed_key_vals, map->ptr[i].ptr[j]);
		}	
	}

	HashMap_free(map);

	map->capacity = new_size;
	map->size = sizeof(KeyValVec) * map->capacity;
    map->ptr = malloc(map->size);

	map->element_num = 0;

	for (size_t i = 0; i < map->capacity; i++) {
		map->ptr[i] = KeyValVec_init();
	}

	for (size_t i = 0; i < old_hashed_key_vals.len; i++) {
		HashMap_add(map, old_hashed_key_vals.ptr[i]);
	}
	
	free(old_hashed_key_vals.ptr);
}

void HashMap_free(HashMap* map) {
	for (size_t i = 0; i < map->capacity; i++) {
		free(map->ptr[i].ptr);
	}
	free(map->ptr);
}

int HashMap_hash_and_mod(HashMap map, unsigned char *str) {
	return (int)(hash(str) % map.capacity);
}
