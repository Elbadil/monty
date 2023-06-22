#include "monty.h"

/**
 * op_swap - Swaps the the two top elements of a stack
 * @stack: Double pointer to the top of a stack
 * @line_number: keeps track of lines in the file
*/

void op_swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *current = *stack;
	int counter = 0;

	while (current)
	{
		counter++;
		current = current->next;
	}

	if (counter < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n; /* storing first node in temp */
	(*stack)->n = (*stack)->next->n; /* first_node->n = 2 */
	(*stack)->next->n = temp; /* second_node->n = 3 */
}
