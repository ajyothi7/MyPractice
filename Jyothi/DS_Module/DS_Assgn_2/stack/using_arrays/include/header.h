#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 256 //defines the max size to allocate space

int arr[MAX];

char * allocate_space(char *);
int my_atoi(char *);
char *read_input(char *);
void validate_int(int );
int push(int, int);
int pop(int);
int display(int);
