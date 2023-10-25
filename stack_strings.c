#include "monty.h"

/**
 * print_char - Prints Ascii value.
 * @stack: Pointer pointing to a pointer top node of the stack.
 * @line_number: opcode line number.
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	num = (*stack)->n;
	if (num < 0 || num > 127)
		string_err(10, line_number);
	printf("%c\n", num);
}

/**
 * print_str - Prints string.
 * @stack: Pointer pointing to a pointer top node of the stack.
 * @ln: opcode line number.
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int num;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		num = tmp->n;
		if (num <= 0 || num > 127)
			break;
		printf("%c", num);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates first node to the stack bottom.
 * @stack: Pointer pointing to a pointer top node of the stack.
 * @ln: opcode of line number.
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates last node to top of the stack.
 * @stack: Pointer pointing to a pointer top node of the stack.
 * @ln: opcode of line number.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
