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
	 and if it is a number the pivot will be '0'.
	 additionaly the mod, for modulo, is 26 for charcter and 10 for digits. 
	 if it is neither then it must me a special character so it does not change
	 then the function deciphers or encrypts according to the op and key as seen in the
	 examples.*/
	char pivot; int mod;
	if ('a' <= letter && letter <= 'z')
	{
		mod = 26;
		pivot = 'a';
	}
	else if ('A' <= letter && letter <= 'Z')
	{
		mod = 26;
		pivot = 'A';
	}
	else if ('0' <= letter && letter <= '9')
	{
		mod = 10;
		pivot = '0';
	}
	else
		return letter;
	
	switch (op)
	{
	case DECIPHER:
		return pivot + (letter - pivot - (key%mod)+mod) % mod;
			break;
	case ENCRYPT:
		return pivot + ((letter - pivot + key) % mod);
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


