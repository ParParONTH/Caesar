#include <stdio.h>
#include "Caesar.h"


int main(int argc, char* argv[])
{	
	enum state op = DECIPHER;
	int key = 1; int line_len;
	char line[20] = "aBCDEFG";
	char* p_line = &line[0];
	line_len = (signed int)strlen(p_line);
	int mod;
	mod = -30 % 26;
	printf("%d\n", mod);
	printf("%s\n", p_line);
	printf("%d\n", line_len);
	decipher_or_encrypt_line(p_line, op, key);
	printf("%s\n", p_line);
	return 0;
}

