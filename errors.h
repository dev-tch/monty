#ifndef ERRORS_H
#define ERRORS_H
void malloc_err(void);
void push_err(int line_number);
void push_err404(int line_number);
void empty_err(int line_number, char *msg);
void short_err(int line_number, char *msg);
#endif
