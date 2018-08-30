//
// Created by eric on 8/13/18.
//

#include "stack_arr.h"
#include <string.h>

static int stack_arr_resize(stack_arr_t *stack, size_t N) {
    void *temp;

    temp = calloc(N, stack->elem_size);
    if (temp == NULL) {
        return -1;
    }

    memcpy(temp, stack->data, stack->size * stack->elem_size);
    free(stack->data);
    stack->data = temp;
    stack->N = N;
    return 1;
}

int stack_arr_init(stack_arr_t **stack, size_t N, size_t elem_size) {
    void *temp;

    *stack = (stack_arr_t *) calloc(1, sizeof(stack_arr_t));

    (*stack)->N = N;
    (*stack)->elem_size = elem_size;

    temp = calloc((*stack)->N, (*stack)->elem_size);
    if (temp == NULL) {
        return -1;
    } else {
        (*stack)->data = temp;
        return 1;
    }
}

int stack_arr_push(stack_arr_t *stack, void *item) {
    void *dest;
    if (item == NULL) {
        return -1;
    }

    if (stack->size == stack->N) {
        stack_arr_resize(stack, stack->N << 1);
    }

    dest = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(dest, item, stack->elem_size);
    stack->size++;
    return 1;
}

int stack_arr_pop(stack_arr_t *stack, void *item) {
    void *src;
    if (stack_arr_is_empty(stack)) {
        return -1;
    }

    if ((stack->N > 0) && (stack->size < (stack->N >> 2))) {
        stack_arr_resize(stack, stack->N >> 1);
    }

    stack->size--;
    src = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(item, src, stack->elem_size);
    return 1;
}

void stack_arr_free(stack_arr_t **stack) {
    if ((*stack) != NULL) {
        if ((*stack)->data != NULL) {
            free((*stack)->data);
            (*stack)->data = NULL;
        }

        free(*stack);
        *stack = NULL;
    }
}

bool stack_arr_is_empty(stack_arr_t *stack) {
    return stack->size == 0;
}

unsigned int stack_arr_get_size(stack_arr_t *stack) {
    return stack->size;
}