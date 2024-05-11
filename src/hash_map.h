#include <stdlib.h>
#include <stdbool.h>

typedef struct KeyVal {
	char* key;
	char* val;
} KeyVal;

typedef struct KeyValVec {
	KeyVal* ptr;
	int len;
	int size;
} KeyValVec;

typedef struct HashMap {

	KeyValVec* ptr;
	int len;
	int size;

} HashMap;

unsigned long hash(unsigned char *str);

//prints KeyVal struct with new line
void KeyVal_println(KeyVal to_print);

//prints KeyVal struct without new line
void KeyVal_print(KeyVal to_print);

KeyValVec KeyValVec_init();

KeyVal KeyValVec_get(KeyValVec vec, int index);

void KeyValVec_append(KeyValVec* vec, KeyVal to_append);

bool KeyValVec_contains(KeyValVec vec, KeyVal check);

void KeyValVec_print(KeyValVec vec);

HashMap HashMap_init();

int HashMap_HashAndMod(HashMap map, unsigned char *str);

void HashMap_print(HashMap map);

void HashMap_add(HashMap* map, KeyVal element);