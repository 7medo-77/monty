#include "monty.h"

/**
 * rotl_funct - Rotates the stack so that the first node
 *				becomes the last and the seconde last
 *				becomes the first
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void rotl_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe, *temp;

	(void)top;
	(void)line_number;

	probe = param.top;
	temp = param.top;

	if (!probe || !temp)
		return;

	while (probe->next)
		probe = probe->next;

	probe->next = temp;
	param.top = param.top->next;

	if (param.top)
		param.top->prev = NULL;

	temp->next = NULL;
	temp->prev = probe;
}


/**
 * rotr_funct - Rotates the stack so that it inverts
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void rotr_funct(stack_t **top, unsigned int line_number)
{
	stack_t *last, *secondLast;

	(void)top;
	(void)line_number;

	last = param.top;
	secondLast = param.top;

	if (!last || !last->next)
		return;

	while (last->next)
		last = last->next;

	secondLast = last->prev;
	secondLast->next = NULL;

	last->prev = NULL;
	last->next = param.top;
	param.top->prev = last;
	param.top = last;
}


/**
 * free_list - Frees linked list
 */
void free_list(void)
{
	stack_t *temp;

	temp = param.top;
	if (!temp)
		return;

	while (param.top)
	{
		temp = param.top;
		param.top = param.top->next;
		free(temp);
	}
	param.line_string = NULL;
	free(param.line_string);
}

/**
 * comment_funct - Does nothing upon interpreting the command
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void comment_funct(stack_t **top, unsigned int line_number)
{
	(void) top;
	(void) line_number;
	if (param.line_string && param.line_string[0] == '#')
		return;
}
