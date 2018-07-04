#include <stdio.h>
#include <stdlib.h>

#define MAX 32

char *read_input(char *);
int my_atoi(char *);
void quick_sort(int *, int, int);
void quick_sort_rec(int *,int, int);
int partition(int *, int, int);
void print_array(int *, int);
void swap(int *, int*);
