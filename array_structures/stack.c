//
// Created by eric on 8/13/18.
//

#include "stack.h"
#include <string.h>
#include <stdio.h>

static int stack_resize(stack_t *stack, size_t N) {
    printf("Resizing to %lu\n", N);
    void *temp;

    temp = calloc(stack->elem_size, N * stack->elem_size);
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

    temp = calloc((*stack)->elem_size, (*stack)->N * (*stack)->elem_size);
    if (temp == NULL) {
        return -1;
    } else {
        (*stack)->data = temp;
        return 1;
    }
}

int stack_push(stack_t *stack, void *data) {
    void *dest;
    if (stack->size == stack->N) {
        stack_resize(stack, stack->N << 0x1);
    }

    printf("offset = %lu\n", stack->size * stack->elem_size);
    dest = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(dest, data, stack->elem_size);
    stack->size++;
    return 1;
}

int stack_pop(stack_t *stack, void *data) {
    void *src;
    if (stack->size < (stack->N >> 2)) {
        stack_resize(stack, stack->N >> 0x2);
    }

    stack->size--;
    src = (unsigned char *) stack->data + (stack->size * stack->elem_size);
    memcpy(data, src, stack->elem_size);
    return 1;
}

void stack_free(stack_t **stack) {
    if ((*stack)->data != NULL) {
        free((*stack)->data);
        (*stack)->data = NULL;
    }

    if ((*stack) != NULL) {
        free(*stack);
        *stack = NULL;
    }
}

bool is_empty(stack_t *stack) {
    return stack->size != 0;
}
