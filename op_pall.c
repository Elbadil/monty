#include "monty.h"

/**
 * op_pall - Prints all element of a stack
 * @stack: pointer to the head of the stack
 * @line_number: tracks the lines of a file
 * Return: Nothing
*/

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		return;
	}

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
