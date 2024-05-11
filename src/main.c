#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();

	HashMap_add(&map, (KeyVal){"asd", "dsa"});
	HashMap_print(map);

	HashMap_add(&map, (KeyVal){"sd", "dsa"});
	HashMap_print(map);

	HashMap_add(&map, (KeyVal){"axxxxis", "dsa"});
	HashMap_print(map);

	HashMap_add(&map, (KeyVal){"wawwawawawaw", "dsa"});
	HashMap_print(map);
}
