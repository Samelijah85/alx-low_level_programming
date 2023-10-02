#ifndef MAIN_H
#define MAIN_H

char *create_array(unsigned int size, chat c);
Int _putchar(char c);
char *_strdup(char *str);
char *str_concat(Char *s1, char *s2);
Int **alloc_grid(int width, int height);
Void free_grid(int **grid, int height);
char *argstostr(int ac, char **av);

#endif
