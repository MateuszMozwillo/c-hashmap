#include <stdio.h>
#include <stdlib.h>

unsigned long hash(unsigned char *str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

typedef struct KeyVal {
	char* key;
	char* val;
} KeyVal;

void KeyVal_print(KeyVal to_print) {
	printf("('%s', '%s')\n", to_print.key, to_print.val);
}

//prints KeyVal struct without new line
void KeyVal_printnonl(KeyVal to_print) {
	printf("('%s', '%s')", to_print.key, to_print.val);
}

typedef struct KeyValVec {
	KeyVal* ptr;
	int len;
	int size;
} KeyValVec;

KeyValVec KeyValVec_init() {
	KeyValVec to_ret;

	to_ret.len = 0;
	to_ret.ptr = malloc(1);
	to_ret.size = 1;

	return to_ret;
}

void KeyValVec_append(KeyValVec* vec, KeyVal to_append) {
	vec->size = vec->size + sizeof(to_append.key) + sizeof(to_append.val);
	vec->ptr = realloc(vec->ptr, vec->size);
	vec->ptr[vec->len] = to_append;
	vec->len += 1;
}

void KeyValVec_print(KeyValVec vec) {
	
	printf("[ ");
	
	for (size_t i = 0; i < vec.len; i++) {
		
		KeyVal_printnonl(vec.ptr[i]);

		if (i != vec.len - 1) {
			printf(", ");
		}
	}

	printf(" ]\n");

}

typedef struct HashMap {

	KeyValVec* ptr;
	int size;

} HashMap;

int HashMap_HashAndMod(HashMap map, unsigned char *str) {
	return (int)(hash(str) % map.size);
}

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
