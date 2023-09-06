#ifndef MAIN_H
#define MAIN_H
/**
 * File: main.h
 * Contains function prototyes of functions used 
 * in 0x0B-mallox_free project 
 */
int _putchar(char c);
char *create_array(unsigned int size, char c);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int **alloc_grid(int width, int height);
void free_grid(int **grid, int height);
char *argstostr(int ac, char **av);
char **strtow(char *str);
#endif
