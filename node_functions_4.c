#include "monty.h"

/**
 * queue_funct - Sets the format of the data to a queue (FIFO)
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 */
void queue_funct(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}
/**
 * stack_funct - Sets the format of the data to a stack (LIFO)
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 */
void stack_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe;

	(void)top;
	(void)line_number;

	probe = param.top;

	if (!probe || !probe->next)
		return;

	while (probe->next)
		probe = probe->next;

	param.top = probe;

	while (probe)
	{
		probe->next = probe->prev;
		probe->prev = NULL;
		probe = probe->next;
	}

	param.top->prev = NULL;
}
