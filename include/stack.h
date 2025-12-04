#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
    void *value;
    int len;
    struct Element *next;
} Element;

bool push(Element **stack, void *value, size_t size);
Element pop(Element *stack);
void freeStack(Element *stack);

#endif