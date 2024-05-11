#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
	KeyValVec vec = KeyValVec_init();
	KeyVal test;
	test.key = "i am key";
	test.val = "i am value";
	KeyValVec_append(&vec, test);
	test.key = "new key";
	KeyValVec_append(&vec, test);
	KeyValVec_print(vec);
}

