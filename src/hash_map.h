#include <stdlib.h>

unsigned long hash(unsigned char *str);

typedef struct KeyVal {
	char* key;
	char* val;
} KeyVal;

//prints KeyVal struct with new line
void KeyVal_println(KeyVal to_print);

//prints KeyVal struct without new line
void KeyVal_print(KeyVal to_print);

typedef struct KeyValVec {
	KeyVal* ptr;
	int len;
	int size;
} KeyValVec;

KeyValVec KeyValVec_init();

KeyVal KeyValVec_get(KeyValVec vec, int index);

void KeyValVec_append(KeyValVec* vec, KeyVal to_append);

void KeyValVec_print(KeyValVec vec);

typedef struct HashMap {

	KeyValVec* ptr;
	int len;
	int size;

} HashMap;

HashMap HashMap_init();

int HashMap_HashAndMod(HashMap map, unsigned char *str);
