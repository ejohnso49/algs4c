//
// Created by eric on 8/22/18.
//
#include <stdio.h>
#include "../queue.h"
#include "../../unity/src/unity.h"

void test_queue_init() {
    queue_t *queue = NULL;
    unsigned int test_N = 50;
    unsigned int test_init_val = 0;
    queue_init(&queue, test_N, sizeof(unsigned int));

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->data);
    TEST_ASSERT_EQUAL_UINT(test_N, queue->N);
    TEST_ASSERT_EACH_EQUAL_MEMORY(&test_init_val, queue->data, sizeof(unsigned int), test_N);
    TEST_ASSERT_TRUE(queue_is_empty(queue));
    TEST_ASSERT_EQUAL_UINT(sizeof(unsigned int), queue->elem_size);

    queue_free(&queue);

    TEST_ASSERT_NULL(queue);
}

void test_queue_en_de_queue() {
    queue_t *queue = NULL;
    unsigned int test_N = 50;
    unsigned int result = 0;
    unsigned int empty_deq;

    queue_init(&queue, test_N, sizeof(unsigned int));
    for (unsigned int i = 0; i < test_N; i++) {
        queue_enqueue(queue, (void *) &i);
    }

    TEST_ASSERT_EQUAL_UINT(test_N, queue->N);
    TEST_ASSERT_EQUAL_UINT(test_N, queue_get_size(queue));

    for (unsigned int i = 0; i < test_N; i++) {
        queue_dequeue(queue, &result);
        TEST_ASSERT_EQUAL_UINT(i, result);
        TEST_ASSERT_EQUAL_UINT(test_N - i - 1, queue_get_size(queue));
    }
    TEST_ASSERT_EQUAL_UINT(0, queue_get_size(queue));

    empty_deq = result;
    queue_dequeue(queue, &empty_deq);
    TEST_ASSERT_EQUAL_UINT(result, empty_deq);

    queue_free(&queue);
    TEST_ASSERT_NULL(queue);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_queue_init);
    RUN_TEST(test_queue_en_de_queue);

    return UNITY_END();
}