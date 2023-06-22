#include "monty.h"

/**
 * op_execute - links a command to it's function and execute it
 * @stack: Double pointer to the stack
 * @cmds: Commands present in the monty byte codes file
 * @op_file: File to be treated
 * @line: keeps track of lines in the file
 * Return: 0 always succes
*/

int op_execute(stack_t **stack, char *cmds, unsigned int line, FILE *op_file)
{
	instruction_t instruc[] = {
		{"pall", op_pall}, {"push", op_push}, {"mod", op_mod},
		{"pint", op_pint}, {"pop", op_pop}, {"pchar", op_pchar},
		{"swap", op_swap}, {"sub", op_sub},
		{"add", op_add}, {"div", op_div},
		{"nop", op_nop}, {"mul", op_mul},
		{NULL, NULL}
	};

	unsigned int i = 0;
	char *cmd = NULL;

	cmd = strtok(cmds, " \t\r\n");
	while (instruc[i].opcode != NULL && cmd != NULL)
	{
		if (strcmp(cmd, instruc[i].opcode) == 0)
		{
			if (strcmp(instruc[i].opcode, "push") == 0)
			{
				op.op_arg = strtok(NULL, " \t\r\n");
				instruc[i].f(stack, line);
			}
			else
			{
				instruc[i].f(stack, line);
			}
			return (0);
		}
		i++;
	}

	if (instruc[i].opcode == NULL && cmd != NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
		fclose(op_file);
		free(cmds);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
