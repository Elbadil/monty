#include "monty.h"

/**
 * op_pop - Removes the top element of a stack
 * @stack: Double pointer to the top of a stack
 * @line_number: keeps track of lines in the file
*/

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
