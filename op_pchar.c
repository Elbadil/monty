#include "monty.h"
/**
 * op_pchar - Prints the top element of the stack as character
 * @stack: Double pointer to the top of a stack
 * @line_number: keeps track of lines in the file
*/
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}
	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current->n);
}
