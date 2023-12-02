#include "huffman.h"

/**
 * symbol_create - Creates a new symbol with the given data and frequency.
 *
 * @data: The data of the symbol.
 * @freq: The frequency of the symbol.
 *
 * Return: A pointer to the newly created symbol, or NULL on failure.
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *new = malloc(sizeof(symbol_t));

	if (!new)
		return (NULL);

	new->data = data;
	new->freq = freq;

	return (new);
}
