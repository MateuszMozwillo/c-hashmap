#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();

	HashMap_add(&map, (KeyVal){"white", "cat"});
	HashMap_add(&map, (KeyVal){"porsche", "car"});
	HashMap_add(&map, (KeyVal){"2017", "year"});

	HashMap_add(&map, (KeyVal){"black", "dog"});
	HashMap_add(&map, (KeyVal){"yellow", "color"});
	HashMap_add(&map, (KeyVal){"c", "language"});

	HashMap_add(&map, (KeyVal){"rust", "language"});
	HashMap_add(&map, (KeyVal){"minecraft", "game"});
	HashMap_add(&map, (KeyVal){"list", "data type"});

	HashMap_print(map);

	printf("%s\n", HashMap_get(map, "rust"));

	HashMap_delete(&map);
}
