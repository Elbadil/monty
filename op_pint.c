#include "monty.h"

/**
 * op_pint - Prints the value of the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: keeps track on lines in the file
*/

void op_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
