#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();
	KeyValVec vec = KeyValVec_init();

	KeyValVec_append(&vec, (KeyVal){"white", "cat"});
	KeyValVec_append(&vec, (KeyVal){"porsche", "car"});
	KeyValVec_append(&vec, (KeyVal){"2017", "year"});
	KeyValVec_append(&vec, (KeyVal){"black", "dog"});
	KeyValVec_append(&vec, (KeyVal){"yellow", "color"});
	KeyValVec_append(&vec, (KeyVal){"c", "language"});
	KeyValVec_append(&vec, (KeyVal){"rust", "language"});
	KeyValVec_append(&vec, (KeyVal){"minecraft", "game"});
	KeyValVec_append(&vec, (KeyVal){"list", "data type"});

	for (size_t i = 0; i < vec.len; i++) {
		HashMap_add(&map, vec.ptr[i]);
	}
	
	HashMap_print(map);

	printf("key: %s, val: %s\n", "minecraft", HashMap_get(map, "minecraft"));

	HashMap_free(&map);
}
