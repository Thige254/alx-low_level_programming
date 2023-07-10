#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: pointer to the name of the file.
 * @text_content:  string to add.
 *
 * Return: - -1 if the function fails or filename is NULL 
 *         - -1 if the file does not exist the user lacks write neccesary permissions .
 *         otherwise  return- 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int copy, width, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	copy = open(filename, O_WRONLY | O_APPEND);
	width = write(copy, text_content, length);

	if (copy == -1 || width == -1)
		return (-1);

	close(copy);

	return (1);
}
