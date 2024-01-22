#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct parameters - opcode and its function
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct parameters
{
        char *line_string;
        char *delims;
        unsigned int line_no;
        stack_t *top;
} parameters_all;

extern parameters_all param;
void free_list();

void init_struct(void);

void push_funct(stack_t **top, unsigned int line_number);
void pall_funct(stack_t **top, unsigned int line_number);
void pint_funct(stack_t **top, unsigned int line_number);
void pop_funct(stack_t **top, unsigned int line_number);
void swap_funct(stack_t **top, unsigned int line_number);
void add_funct(stack_t **top, unsigned int line_number);
void nop_funct(stack_t **top, unsigned int line_number);

void sub_funct(stack_t **top, unsigned int line_number);
void div_funct(stack_t **top, unsigned int line_number);
void mul_funct(stack_t **top, unsigned int line_number);
void mod_funct(stack_t **top, unsigned int line_number);
void comment_funct(stack_t **top, unsigned int line_number);
void pchar_funct(stack_t **top, unsigned int line_number);
void pstr_funct(stack_t **top, unsigned int line_number);
void rotl_funct(stack_t **top, unsigned int line_number);
void rotr_funct(stack_t **top, unsigned int line_number);
void stack_funct(stack_t **top, unsigned int line_number);
void queue_funct(stack_t **top, unsigned int line_number);

void (*opcode_handling(parameters_all param))(stack_t **, unsigned int);

#endif

