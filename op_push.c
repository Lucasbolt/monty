#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @param: The value to adds on the stack
  *
  * Return: Nothing
  */
void handle_push(stack_t **stack, unsigned int param)
{
	unsigned int line = param;
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_error();

	new_node->n = atoi(num);
	if (*stack)
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	line++;
}
