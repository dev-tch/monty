#ifndef MONTY_H
#define MONTY_H
/*libraries*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
#define MAX_LINE_LENGTH 4048

/**
 * struct list_s - a list to handle line data
 * @arg: data of each node
 * @len: length of data
 * @next: next node adress
 *
 * Description: LinkedList node structure
 */
typedef struct list_s
{
char *arg;
int len;
struct list_s *next;
} list_t;
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

/*extern char *data_stack;*/
/**
 * struct infos_wrk - working data
 * @list_tok: list of line data
 * @stack: list contains operation opcode
 * @line_buffer: buffer to save reading line
 * @fp: file pointer
 *
 * Description: working data
 * for stack, queues, LIFO, FIFO
 */
typedef struct infos_wrk
{
	list_t *list_tok;
	stack_t *stack;
	char line_buffer[MAX_LINE_LENGTH];
	FILE *fp;
} wrk_t;
extern wrk_t data;

list_t *add_token_to_list(list_t **head, char *str);
void cleanupList(list_t **head);
void handle_opcode(stack_t **stack, unsigned int line_number);
void swap_top_node(stack_t **stack, unsigned int li);
void add_sum_top(stack_t **stack, unsigned int li);
void do_nothing(stack_t **stack, unsigned int li);
void malloc_err(void);
void push_err(int line_number);
void push_err404(int line_number);
void empty_err(int line_number, char *msg, int code);
void short_err(int line_number, char *msg);
void free_dlistint(stack_t *head);
void free_data(void);
void init(FILE *stm);
void split_data(char *line, int numline);
/*extern List  *list_tok;*/
#endif
