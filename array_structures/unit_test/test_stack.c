//
// Created by eric on 8/19/18.
//
#include <stdio.h>
#include "../stack.h"
#include "../../unity/src/unity.h"

void test_stack_init_free(void) {
    stack_t *stack = NULL;
    unsigned int test_N = 50;
    unsigned int test_init_val = 0;
    stack_init(&stack, test_N, sizeof(unsigned int));

    TEST_ASSERT_NOT_NULL(stack);
    TEST_ASSERT_NOT_NULL(stack->data);
    TEST_ASSERT_EQUAL_UINT(test_N, stack->N);
    TEST_ASSERT_EACH_EQUAL_MEMORY(&test_init_val, stack->data, sizeof(unsigned int), test_N);
    TEST_ASSERT_TRUE(is_empty(stack));
    TEST_ASSERT_EQUAL_UINT(sizeof(unsigned int), stack->elem_size);

    stack_free(&stack);

    TEST_ASSERT_NULL(stack);
}

void test_stack_push_pop(void) {
    stack_t *stack = NULL;
    unsigned int test_N = 50;
    unsigned int result = 0;
    unsigned int empty_pop;

    stack_init(&stack, test_N, sizeof(unsigned int));
    for (unsigned int i = 0; i < test_N; i++) {
        stack_push(stack, (void *) &i);
    }

    TEST_ASSERT_EQUAL_UINT(test_N, stack->N);
    TEST_ASSERT_EQUAL_UINT(test_N, stack->size);


    for (int i = test_N - 1; i >= 0; i--) {
        stack_pop(stack, &result);
        TEST_ASSERT_EQUAL_UINT(i, result);
        TEST_ASSERT_EQUAL_UINT(i, stack->size);
    }
    TEST_ASSERT_EQUAL_UINT(0, stack->size);

    empty_pop = result;
    stack_pop(stack, &empty_pop);
    TEST_ASSERT_EQUAL_UINT(result, empty_pop);

    stack_free(&stack);
    TEST_ASSERT_NULL(stack);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_stack_init_free);
    RUN_TEST(test_stack_push_pop);

    return UNITY_END();
}
