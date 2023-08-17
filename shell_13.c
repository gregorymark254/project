#include "shell.h"

/**
 **_realloc -  allocating a memory block
 *@ptr: Pointer to the node
 *@old: Previous pointer of the Pointer
 *@new: new size of pointer
 *Return: null or address
*/

void *_alloc(void *ptr, unsigned int old, unsigned int new)

{
	void *end;

	if (new == old)
		return (ptr);
	if (new == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	end = malloc(new);
	if (end == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		_array(end, '\0', new);
		free(ptr);
	}
	else
	{
		memcpy(end, ptr, old);
		free(ptr);
	}
	return (end);

}

/**
 * all_free - free array
 * @cmd:Pointer to an array
 * @line: Pointer to the array
 * Return: null or address
*/

void all_free(char **cmd, char *line)

{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _memory_copy - coping memory
 * @dest: pointer to the node
 * @src: Pointer to the source
 * @n: size of the node
 *Return: null or address
*/

char *_memory_copy(char *dest, char *src, unsigned int n)

{
	unsigned int c;

	for (c = 0; c < n; c++)
	{
		dest[c] = src[c];
	}
	return (dest);
}

/**
 * _array - filling an array
 * @a: pointer to the node
 * @el: input to the array
 * @len:length of array
 *Return: null or address
*/

void *_array(void *a, int el, unsigned int len)

{
	char *p = a;
	unsigned int c = 0;

	while (c < len)
	{
		*p = el;
		p++;
		c++;
	}
	return (a);
}

/**
 * _calc -  asign memory to an array
 * @size: Size of array
 * Return: null or address
*/

void *_calc(unsigned int size)

{
	char *a;
	unsigned int c;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (c = 0; c < size; c++)
	{
		a[c] = '\0';
	}
	return (a);
}

