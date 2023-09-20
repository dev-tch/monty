#ifndef LIST_H
#define LIST_H
/*libs*/
#include <stdlib.h>
#include <string.h>
typedef struct list_data_line  List;
/**
 * struct list_data_line - a list to handle line data
 * @arg: data of each node
 * @len: length of data
 * @next: next node adress
 *
 * Description: helper list to hold data for processing shell commands
 */
struct list_data_line
{
char *arg;
int len;
List *next;
};
#endif
