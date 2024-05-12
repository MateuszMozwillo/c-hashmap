#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();

	HashMap_add(&map, (KeyVal){"asd", "1"});
	HashMap_add(&map, (KeyVal){"sd", "2"});
	HashMap_add(&map, (KeyVal){"ds", "2"});

	HashMap_print(map);

	HashMap_add(&map, (KeyVal){"sd", "3"});
	HashMap_add(&map, (KeyVal){"axxxxis", "3"});
	HashMap_add(&map, (KeyVal){"wawwawawawaw", "4"});

	HashMap_print(map);

	HashMap_add(&map, (KeyVal){"wawxxawawaw", "4"});
	HashMap_add(&map, (KeyVal){"wawwawsadfxxawawaw", "4"});
	HashMap_add(&map, (KeyVal){"was", "4"});
	HashMap_add(&map, (KeyVal){"dog", "4"});

	HashMap_add(&map, (KeyVal){"wawwaw", "4"});
	HashMap_add(&map, (KeyVal){"wadfxxawawaw", "4"});
	HashMap_add(&map, (KeyVal){"w", "4"});
	HashMap_add(&map, (KeyVal){"dg", "4"});

	HashMap_print(map);

	printf("%s\n", HashMap_get(map, "was"));
}
