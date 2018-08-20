//
// Created by eric on 8/19/18.
//
#include <stdio.h>
#include "../stack.h"
#include "../../unity/src/unity.h"

void test_stack_init(void) {
    stack_t *stack;
    unsigned int test_N = 50;
    unsigned int test_init_val = 0;
    stack_init(&stack, test_N, sizeof(unsigned int));

    TEST_ASSERT_EQUAL_UINT(test_N, stack->N);
    TEST_ASSERT_EACH_EQUAL_MEMORY(&test_init_val, stack->data, sizeof(unsigned int), test_N);
    TEST_ASSERT_EQUAL_UINT(0, stack->size);
    TEST_ASSERT_EQUAL_UINT(sizeof(unsigned int), stack->elem_size);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_stack_init);

    return UNITY_END();
}
