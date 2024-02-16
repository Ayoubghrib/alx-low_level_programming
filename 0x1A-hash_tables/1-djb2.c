#include "hash_tables.h"

/**
 * hash_djb2 - Hash function using the djb2 algorithm
 * @str: String to hash
 *
 * Return: Hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash = 5381;
	int c;

	if (str == NULL)
		return 0; 

	while ((c = *str++))
	{
		
		hash = ((hash << 5) + hash) ^ c;
	}
	return hash;
}

