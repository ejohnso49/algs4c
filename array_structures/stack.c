//
// Created by eric on 8/13/18.
//

#include "stack.h"
#include <string.h>
#include <stdio.h>

static int stack_resize(stack_t *stack, size_t N) {
    void *temp;

    temp = calloc(N, stack->elem_size);
    if (temp == NULL) {
        return -1;
    }

    memcpy(temp, stack->data, stack->N * stack->elem_size);
    free(stack->data);
    stack->data = temp;
    stack->N = N;
    return 1;
}

int stack_init(stack_t **stack, size_t N, size_t elem_size) {
    void *temp;

    *stack = (stack_t *) calloc(1, sizeof(stack_t));

    (*stack)->N = N;
    (*stack)->elem_size = elem_size;

    temp = calloc((*stack)->elem_size, (*stack)->N);
    if (temp == NULL) {
        return -1;
    } else {
        (*stack)->data = temp;
        return 1;
    }
}

int stack_push(stack_t *stack, void *data) {
    void *dest;
    if (data == NULL) {
        return -1;
    }

    if (stack->size == stack->N) {
        stack_resize(stack, stack->N << 1);
    }

    dest = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(dest, data, stack->elem_size);
    stack->size++;
    return 1;
}

int stack_pop(stack_t *stack, void *data) {
    void *src;
    if (stack_is_empty(stack)) {
        return -1;
    }

    if ((stack->N > 1) && (stack->size <= (stack->N >> 1))) {
        stack_resize(stack, stack->N >> 1);
    }

    stack->size--;
    src = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(data, src, stack->elem_size);
    return 1;
}

void stack_free(stack_t **stack) {
    if ((*stack) != NULL) {
        if ((*stack)->data != NULL) {
            free((*stack)->data);
            (*stack)->data = NULL;
        }

        free(*stack);
        *stack = NULL;
    }
}

bool stack_is_empty(stack_t *stack) {
    return stack->size == 0;
}

unsigned int stack_get_size(stack_t *stack) {
    return stack->size;
}