#include "monty.h"
/**
 * init_struct - Initialize global struct with values
 *
 * Return: No return type
 */
void init_struct(void)
{
	param.delims = "\n ";

	param.top = NULL;
	param.line_no = 0;
}


/**
 * push_funct - Adds a node at the end of a doubly linked list
 *
 * @top: pointer to the top of the stack (head of the doubly linked list)
 * @line_number: Line number in the Monty file
 *
 */
void push_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe, *new;
	long int value;
	char *endptr;

	(void)top, (void)line_number, probe = param.top;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	param.line_string = strtok(NULL, param.delims);
	if (param.line_string)
	{
		value = strtol(param.line_string, &endptr, 10);
		if (*endptr == '\0' && errno != ERANGE)
			new->n = value;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!probe)
		new->next = NULL, new->prev = NULL, param.top = new;
	else
	{
		new->next = probe;
		new->prev = NULL;
		probe->prev = new;
		param.top = new;
	}
}


/**
 * pall_funct - Prints content of all nodes of the linked list
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void pall_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe = param.top;

	(void) top;
	(void) line_number;
	if (!probe)
		return;

	while (probe)
	{
		fprintf(stdout, "%d\n", probe->n);
		probe = probe->next;
	}
}

/**
 * pint_funct - Print integer content of the head node
 *
 * @top: pointer to first node in doubly linked list stack
 * @line_number: Line number in the monty file
 *
 */
void pint_funct(stack_t **top, unsigned int line_number)
{
	stack_t *probe = param.top;

	(void) top;
	(void) line_number;
	if (!probe)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", param.line_no);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", probe->n);
}


/**
 * opcode_handling - Adds a node at the end of a doubly linked list
 *
 * @param: struct of parameters needed by linked list functions
 *
 * Return: Function pointer to linked list operations
 */
void (*opcode_handling(parameters_all param))(stack_t **, unsigned int)
{
	instruction_t arr[] = {
		{"push", push_funct},
		{"pall", pall_funct},
		{"pint", pint_funct},
		{"pop", pop_funct},
		{"swap", swap_funct},
		{"add", add_funct},
		{"nop", nop_funct},
		{"#", comment_funct},
		{"sub", sub_funct},
		{"div", div_funct},
		{"mul", mul_funct},
		{"mod", mod_funct},
		{"pchar", pchar_funct},
		{"pstr", pstr_funct},
		{"rotl", rotl_funct},
		{"rotr", rotr_funct},
		{"stack", stack_funct},
		{"queue", queue_funct},
		{NULL, NULL},
	};
	int index = 0;

	if (param.line_string && param.line_string[0] == '#')
		return (arr[7].f);
	while (arr[index].opcode)
	{
		if (strcmp(arr[index].opcode, param.line_string) == 0)
			return (arr[index].f);
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n"
			, param.line_no, param.line_string);
	exit(EXIT_FAILURE);
}

