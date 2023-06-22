#include "monty.h"

/**
 * free_stack_list - Frees a stack
 * @stack: Pointer to the top of a stack
 * Return: Nothing
*/

void free_stack_list(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}
