//
// Created by eric on 8/19/18.
//
#include <stdio.h>
#include "../stack.h"
#include "../../unity/src/unity.h"

void test_stack(void) {
    TEST_ASSERT_EQUAL_INT32(0, 1);
}

int main(void) {
    printf("We're running a test!\n");
    UNITY_BEGIN();

    printf("We're in Unity mode\n");
    RUN_TEST(test_stack);

    printf("Ending Unity mode!\n");

    return UNITY_END();
}
