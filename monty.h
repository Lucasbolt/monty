#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
extern char **tokens;
extern char *topcode;
extern char *num;
extern char *buff;
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
extern stack_t *head;
/**
 * struct instruction_s - opcode and its functions
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instructions_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Error handlers */
int inc_error(void);
int file_error(char *str);
int instruction_error(unsigned int line_n, char *opcode);
void malloc_error(void);
void push_error(unsigned int line_n);
void add_error(unsigned int line_n);
void pop_error(unsigned int line_n);
void swap_error(unsigned int line_n);
void pint_error(unsigned int line_n);

char *modifier(char *str);
int handle_monty(FILE *fp);
int handle_opcode(char *string, unsigned int line_n);
int token_count(char **ttk);
int delim_count(char *string);
char **string_splitter(char *string);
int freemem(char **tokens, char **front);
void frees_stack(void);
unsigned int count_stack(stack_t *stack);
int check_push_param(char *param);
int check_digits(char *param);

void handle_add(stack_t **stack, unsigned int line_n);
void handle_push(stack_t **stack, unsigned int line_n);
void handle_nop(stack_t **stack, unsigned int line_n);
void handle_pop(stack_t **stack, unsigned int line_n);
void handle_pint(stack_t **stack, unsigned int line_n);
void handle_swap(stack_t **stack, unsigned int line_n);
void handle_pall(stack_t **stack, unsigned int line_n);
#endif
