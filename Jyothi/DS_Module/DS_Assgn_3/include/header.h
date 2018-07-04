#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 32

char *read_input(char *);
int my_atoi(char *);
void selection_sort(int *, int);
void selection_sort_rec(int *,int, int);
void print_array(int *, int);
void swap(int *, int*);
void insertion_sort(int *, int);
void insertion_sort_rec(int *, int);
void bubble_sort(int *, int);
void bubble_sort_rec(int *, int);
void quick_sort(int *, int, int);
void quick_sort_rec(int *,int, int);
int partition(int *, int, int);
