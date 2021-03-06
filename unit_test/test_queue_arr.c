//
// Created by eric on 8/22/18.
//
#include <stdio.h>
#include "../queue/queue_arr.h"
#include "../unity/src/unity.h"

void test_queue_arr_init() {
    queue_arr_t *queue = NULL;
    unsigned int test_N = 50;
    unsigned int test_init_val = 0;
    queue_arr_init(&queue, test_N, sizeof(unsigned int));

    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->data);
    TEST_ASSERT_EQUAL_UINT(test_N, queue->N);
    TEST_ASSERT_EACH_EQUAL_MEMORY(&test_init_val, queue->data, sizeof(unsigned int), test_N);
    TEST_ASSERT_TRUE(queue_arr_is_empty(queue));
    TEST_ASSERT_EQUAL_UINT(sizeof(unsigned int), queue->elem_size);

    queue_arr_free(&queue);

    TEST_ASSERT_NULL(queue);
}

void test_queue_arr_en_de_queue() {
    queue_arr_t *queue = NULL;
    unsigned int test_N = 50;
    unsigned int result = 0;
    unsigned int empty_deq;

    queue_arr_init(&queue, test_N, sizeof(unsigned int));
    for (unsigned int i = 0; i < test_N; i++) {
        queue_arr_enqueue(queue, (void *) &i);
    }

    TEST_ASSERT_EQUAL_UINT(test_N, queue->N);
    TEST_ASSERT_EQUAL_UINT(test_N, queue_arr_get_size(queue));

    for (unsigned int i = 0; i < test_N; i++) {
        queue_arr_dequeue(queue, &result);
        TEST_ASSERT_EQUAL_UINT(i, result);
        TEST_ASSERT_EQUAL_UINT(test_N - i - 1, queue_arr_get_size(queue));
    }
    TEST_ASSERT_EQUAL_UINT(0, queue_arr_get_size(queue));

    empty_deq = result;
    queue_arr_dequeue(queue, &empty_deq);
    TEST_ASSERT_EQUAL_UINT(result, empty_deq);

    queue_arr_free(&queue);
    TEST_ASSERT_NULL(queue);
}

void test_queue_arr_growth_resize() {
    queue_arr_t *queue = NULL;

    queue_arr_init(&queue, 1, sizeof(int));
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->data);
    for (unsigned int i = 0; i < 100; i++) {
        unsigned int prev_N = queue->N;
        queue_arr_enqueue(queue, &i);
        TEST_ASSERT_EQUAL_UINT(i + 1, queue_arr_get_size(queue));
        if (i == prev_N && i > 0) {
            TEST_ASSERT_EQUAL_UINT(prev_N << 1, queue->N);
        }
    }

    queue_arr_free(&queue);
    TEST_ASSERT_NULL(queue);
}

void test_queue_arr_shrink_resize() {
    queue_arr_t *queue = NULL;
    unsigned int test_N = 500;

    queue_arr_init(&queue, test_N, sizeof(int));
    for (unsigned int i = 0; i < test_N; i++) {
        queue_arr_enqueue(queue, &i);
    }

    for (unsigned int i = test_N; i > 0; i--) {
        int temp;
        size_t prev_N = queue_arr_get_size(queue);
        queue_arr_dequeue(queue, &temp);
        if (i < (prev_N >> 2)) {
            TEST_ASSERT_EQUAL_UINT(prev_N >> 1, queue_arr_get_size(queue));
        }
    }
    TEST_ASSERT_TRUE(queue_arr_is_empty(queue));
    TEST_ASSERT_EQUAL_UINT(7, queue->N);
    queue_arr_free(&queue);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_queue_arr_init);
    RUN_TEST(test_queue_arr_en_de_queue);
    RUN_TEST(test_queue_arr_growth_resize);
    RUN_TEST(test_queue_arr_shrink_resize);

    return UNITY_END();
}
