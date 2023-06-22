#include "monty.h"

/**
 * op_push - pushes a new data at the top of the stack
 * @stack: Double pointer to the stack
 * @line_number: keeps track of the lines of the file
*/
void op_push(stack_t **stack, unsigned int line_number)
{
	int value, i = 0;
	int non_int = 0;

	if (op.op_arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		while (op.op_arg[i])
		{
			if (isdigit(op.op_arg[i] == 0))
			{
				non_int = 1;
				break;
			}
			i++;
		}
		if (non_int == i || i == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(op.op_file);
			free(op.op_cmd);
			free_stack_list(*stack);
			exit(EXIT_FAILURE);
		}
	}

	value = atoi(op.op_arg);
	add_node_beg(stack, value);
}
