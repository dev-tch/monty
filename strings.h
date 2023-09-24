#ifndef STRINGS_H
#define STRINGS_H
int is_space(char c);
int is_empty(char  *str);
char *_strdup(char *str);
int _isdigit(char *str);
char *_strtok_r(char *str, const char *delim, char **saveptr);
#endif
