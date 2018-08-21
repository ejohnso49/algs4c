//
// Created by eric on 8/13/18.
//

#ifndef C_INTERVIEWS_STACK_H
#define C_INTERVIEWS_STACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_s stack_t;

struct stack_s {
    size_t N;
    unsigned int size;
    size_t elem_size;
    void *data;
};

extern int stack_init(stack_t **stack, size_t N, size_t elem_size);
extern int stack_push(stack_t *stack, void *item);
extern void stack_free(stack_t **stack);
extern int stack_pop(stack_t *stack, void *data);
extern bool stack_is_empty(stack_t *stack);
extern unsigned int stack_get_size(stack_t *stack);

#endif //C_INTERVIEWS_STACK_H
