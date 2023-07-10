#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *make_buffer(char *file);
void close_file(int ar);

/**
 * make_buffer -  bytes for a buffer alocation(1024 in mumber)
 * @file: filename that buffer is storing chars for.
 *
 * Return:  pointer to newly-allocated buffer.
 */
char *make_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int ar)
{
	int a;

	a = close(ar);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close ar %d\n", ar);
		exit(100);
	}
}

/**
 * main - Copy content of a file to another file.
 * @argc: arguments number supplied to the program.
 * @argv:  array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: For incorrect arg - exit code 97.
 * If file_from unreadable/non-existent file - exit code 98.
 * If file_to non-readable/non-creatable file - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = make_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
