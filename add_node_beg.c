#include "monty.h"

/**
 * add_node_beg - Adds new node at the beginning of stack
 * @head: Double pointer to the top of a stack
 * @n: data of the node to be added
 * Return: New node at the top of a stack
*/

stack_t *add_node_beg(stack_t **head, const int n)
{
	stack_t *newn;

	newn = malloc(sizeof(stack_t));
	if (newn == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(op.op_file);
		free(op.op_cmd);
		free_stack_list(*head);
		exit(EXIT_FAILURE);
	}

	newn->n = n;
	newn->prev = NULL;
	newn->next = (*head);

	if (*head != NULL)
		(*head)->prev = newn;
	*head = newn;

	return (newn);
}
