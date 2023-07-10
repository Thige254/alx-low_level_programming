#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename:  pointer to filename
 * @text_content: string to add to the end of the file.
 *
 * Return: 1 on success. 0 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int text, width, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	text = open(filename, O_WRONLY | O_APPEND);
	width = write(text, text_content, length);

	if (text == -1 || width == -1)
		return (-1);

	close(text);

	return (1);
}
