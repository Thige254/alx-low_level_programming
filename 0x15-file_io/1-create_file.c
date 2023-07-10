#include "main.h"

/**
 * create_file - To create a file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write to the file.
 *
 * Return: Returns: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int av, width, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	av = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	width = write(av, text_content, length);

	if (av == -1 || width == -1)
		return (-1);

	close(av);

	return (1);
}
