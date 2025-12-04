#include "stack.h"

bool push(Element **stack, void *value, size_t size) {
    Element *elem = malloc(sizeof(Element));
    if (!elem) return false;

    elem->value = malloc(size);
    if (!elem->value) {
        free(elem);
        return false;
    }

    memcpy(elem->value, value, size);
    elem->len = (*stack ? (*stack)->len + 1 : 1);
    elem->next = *stack;
    *stack = elem;
    return true;
}

void freeStack(Element *stack){
    if(stack == NULL) return;
    freeStack(stack->next);
    free(stack->value);
    free(stack);
}
