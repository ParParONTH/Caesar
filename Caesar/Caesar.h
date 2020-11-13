#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __Caesar_h__
#define __Caesar_h__
char decipher_or_encryption(char letter, enum state op, int key);
void decipher_or_encrypt_line(char* p_line, enum state op, int key);
enum state { DECIPHER = 1, ENCRYPT = 0 };
#endif // __Caesar_h__

