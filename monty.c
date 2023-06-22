#include "monty.h"
op_t op = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @argc: Number of arguments in command line
 * @argv: Pointer to an array of character pointers that list all arguments
 * Return: 0 success
*/
int main(int argc, char **argv)
{
	char *cmds = NULL;
	size_t line_size = 0;
	FILE *op_file;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	op_file = fopen(argv[1], "r");
	op.op_file = op_file;
	if (op_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&cmds, &line_size, op_file) != -1)
	{
		op.op_cmd = cmds;
		op_execute(&stack, cmds, line_number, op_file);
		line_number++;
	}
	free(cmds);
	free_stack_list(stack);
	fclose(op_file);
	return (0);
}
