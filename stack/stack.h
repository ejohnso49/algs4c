//
// Created by eric on 8/13/18.
//

#ifndef ALGS4C_STACK_ARR_H
#define ALGS4C_STACK_ARR_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct stack_arr_s stack_arr_t;

struct stack_arr_s {
    size_t N;
    unsigned int size;
    size_t elem_size;
    void *data;
};

extern int stack_arr_init(stack_arr_t **stack, size_t N, size_t elem_size);
extern int stack_arr_push(stack_arr_t *stack, void *item);
extern void stack_arr_free(stack_arr_t **stack);
extern int stack_arr_pop(stack_arr_t *stack, void *item);
extern bool stack_arr_is_empty(stack_arr_t *stack);
extern unsigned int stack_arr_get_size(stack_arr_t *stack);

#endif //ALGS4C_STACK_ARR_H
