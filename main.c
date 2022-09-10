#include "monty.h"

/**
 * main - The entry to the interprator program
 *
 * @argc: Argument count
 * @argv: List of arguments
 * Return: 0 if success 1 otherwise
 */
int main(int argc, char **argv)
{
int fd;

fd = openFile(argc, argv);
return (fd);

}

/**
 * openFile - Tries to open file given as an argument
 *
 * @argc: Argument count
 * @argv: List of arguments
 * Return: The file descriptor
 */
int openFile(int argc, char **argv)
{
	int fd;
	char *errMessage;

	if (argc != 2)
	{
		printError("USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		errMessage = concatStrings("Error: Can't open file ", argv[1]);
		printError(errMessage);
		free(errMessage);
		exit(EXIT_FAILURE);
	}
	write(STDOUT_FILENO, argv[0], sizeof(argv[1]));
	return (1);
}


/**
 * printError - Prints errors to stderr and exits
 *
 * @msg: The message to be printed
 */
void printError(char msg[])
{
	write(STDERR_FILENO, msg, strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}


/**
 * concatStrings - Concatinates two strings
 *
 * @str1: First string
 * @str2: Second string
 * Return: Concatinated string
 */
char *concatStrings(char *str1, char *str2)
{
	char *newString = malloc(strlen(str1) + strlen(str2));

	strcpy(newString, str1);
	strcat(newString, str2);
	return (newString);
}
