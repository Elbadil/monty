#include "monty.h"

/**
 * op_add - Adds the value of the two top elements in the stack
 * @stack: Double pointer to the top of a stack
 * @line_number: keeps track of lines in the file
*/

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int first, second;
	int result = 0;
	stack_t *current = *stack;
	int counter = 0;

	while (current)
	{
		counter++;
		current = current->next;
	}

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}

	first = (*stack)->n;
	second = (*stack)->next->n;
	result = first + second;

	(*stack)->next->n = result;

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
