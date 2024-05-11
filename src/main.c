#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	HashMap map = HashMap_init();
	KeyVal test;

	test.key = "i am key";
	test.val = "i am value";

	HashMap_add(&map, test);
	HashMap_print(map);

	test.key = "gaaaaa";
	test.val = "jkndsjsaaaaaaak";

	HashMap_add(&map, test);
	HashMap_print(map);
}
