#include "monty.h"
/**
 * div_funct - Divides the second top element of
 *			   the stack with the top element of the stack
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void div_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe, *temp;

	(void)top;
	(void)line_number;

	probe = param.top;

	if (!probe || !probe->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (param.top->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			temp = param.top;
			param.top->next->n /= param.top->n;
			param.top = param.top->next;
			if (param.top)
				param.top->prev = NULL;
			free(temp);
		}
	}

}


/**
 * mod_funct - Computes the rest of the division of the second top
 *			   element of the stack by the top element of the stack.
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void mod_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe, *temp;

	(void)top;
	(void)line_number;

	probe = param.top;

	if (!probe || !probe->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (param.top->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			temp = param.top;
			param.top->next->n %= param.top->n;
			param.top = param.top->next;
			if (param.top)
				param.top->prev = NULL;
			free(temp);
		}
	}
}


/**
 * nop_funct - Does nothing upon interpreting the command
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void nop_funct(stack_t **top, unsigned int line_number)
{
	(void) top;
	(void) line_number;
}

/**
 * pchar_funct - Prints a character in place of integer if
 *				 the integer value was within the ascii range
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void pchar_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe;

	(void) top;
	(void) line_number;
	probe = param.top;

	if (!probe)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", param.line_no);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (probe->n < 33 || probe->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", param.line_no);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", probe->n);
	}
}

/**
 * pstr_funct - Prints a string if node integer is in the ascii range
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void pstr_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe;

	(void) top;
	(void) line_number;
	probe = param.top;

	if (!probe)
		printf("\n");
	else
	{
		while (probe && probe->n != 0 && (probe->n >= '!' && probe->n <= '~'))
		{
			printf("%c", probe->n);
			probe = probe->next;
		}
		printf("\n");
	}
}

