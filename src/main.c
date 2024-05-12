#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();

	HashMap_add(&map, (KeyVal){"asd", "1"});
	HashMap_add(&map, (KeyVal){"sd", "2"});
	HashMap_add(&map, (KeyVal){"sd", "3"});
	HashMap_add(&map, (KeyVal){"axxxxis", "3"});
	HashMap_add(&map, (KeyVal){"wawwawawawaw", "4"});

	HashMap_print(map);

	printf("%s\n", HashMap_get(map, "sd"));
}
