#include "Caesar.h"
#define ERROR -1 



char decipher_or_encryption(char letter, enum state op, int key)
{
	/* input:
	 char letter - letter to be deciphered or encrypted
	 enum state op - which operation is to be done deciphering or encrypting
	 int key - key
	 this function checks that ascii valuse of letter and according to it decids on a pivot
	 if its a small letter the pivot will be 'a' if its CAPS the pivot will be 'A'
	 and if it is neither then it must me a special character so it does not change
	 then the function deciphers or encrypts according to the op and key as seen in the
	 examples.*/
	char pivot;
	if ('a' <= letter && letter <= 'z')
	{
		pivot = 'a';
	}
	else if ('A' <= letter && letter <= 'Z')
	{
		pivot = 'A';
	}
	else
		return letter;
	
	switch (op)
	{
	case DECIPHER:
		return pivot + (letter - pivot - (key%26)+26) % 26;
			break;
	case ENCRYPT:
		return pivot + ((letter - pivot + key) % 26);
			break;
	default:
		printf("problem\n");
		exit(ERROR);
	}
}

void decipher_or_encrypt_line(char* p_line, enum state op, int key)
{
	/* this function gets a line pointer and for each letter calls the
	decipher_or_encrypt function.
	input:
	char* p_line - line pointer
	enum state op - deciphering or encrypting
	int key - key */
	signed int len = strlen(p_line);
	for (signed int i = 0; i < len ; i++)
	{
		*p_line = decipher_or_encryption(*p_line, op, key);
		p_line++;
	}
	p_line = p_line - len;
}


