#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename:  pointer to filename
 * @text_content: string to add to the end of the file.
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, width, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	width = write(text, text_content, length);

	if (o == -1 || width == -1)
		return (-1);

	close(o);

	return (1);
}
