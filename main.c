#include "monty.h"

parameters_all param;

/**
 * main - Monty code interpreter
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 Always success
 */
int main(int argc, char **argv)
{
	char example[1024];
	FILE *ofile;
	void (*Func_pointer)(stack_t **top, unsigned int line_number);

	(void) argc;
	(void) argv;
	init_struct();
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(param.line_string);
		exit(EXIT_FAILURE);
	}

	ofile = fopen(argv[1], "r");

	if (!ofile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(param.line_string);
		exit(EXIT_FAILURE);
	}

	while (fgets(example, 1024, ofile) != 0)
	{
		param.line_no++;
		param.line_string = strtok(example, param.delims);
		if (param.line_string == NULL)
			continue;
		Func_pointer = opcode_handling(param);
		Func_pointer(&param.top, param.line_no);
	}
	free_list();
	fclose(ofile);
	return (0);
}

