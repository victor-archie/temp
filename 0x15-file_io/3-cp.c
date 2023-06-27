#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * check_io_status - checks if a file can be opened or closed
 * @status: file descriptor of the file to be opened
 * @file_descriptor: file descriptor
 * @filename: name of the file
 * @mode: closing or opening
 *
 * Return: void
 */
void check_io_status(int status, int file_descriptor, char *filename, char mode)
{
	if (mode == 'C' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", file_descriptor);
		exit(100);
	}
	else if (mode == 'O' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	else if (mode == 'W' && status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}

/**
 * main - copies the content of one file to another
 * @argc: argument count
 * @argv: arguments passed
 *
 * Return: 1 on success, exit otherwise
 */
int main(int argc, char *argv[])
{
	int source_file, destination_file, bytes_read = 1024, bytes_written, close_source, close_destination;
	unsigned int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
	}
	source_file = open(argv[1], O_RDONLY);
	check_io_status(source_file, -1, argv[1], 'O');
	destination_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	check_io_status(destination_file, -1, argv[2], 'W');
	while (bytes_read == 1024)
	{
		bytes_read = read(source_file, buffer, sizeof(buffer));
		if (bytes_read == -1)
			check_io_status(-1, -1, argv[1], 'O');
		bytes_written = write(destination_file, buffer, bytes_read);
		if (bytes_written == -1)
			check_io_status(-1, -1, argv[2], 'W');
	}
	close_source = close(source_file);
	check_io_status(close_source, source_file, NULL, 'C');
	close_destination = close(destination_file);
	check_io_status(close_destination, destination_file, NULL, 'C');

	return (0);
}
