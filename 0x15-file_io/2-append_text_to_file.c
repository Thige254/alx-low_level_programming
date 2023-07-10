#include "main.h"

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
