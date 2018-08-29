//
// Created by eric on 8/21/18.
//

#ifndef ALGS4C_QUEUE_ARR_H
#define ALGS4C_QUEUE_ARR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_arr_s queue_arr_t;

struct queue_arr_s {
    unsigned int N;
    size_t elem_size;
    unsigned int size;
    unsigned int dequeue_index;
    unsigned int enqueue_index;
    void *data;
};

extern int queue_arr_enqueue(queue_arr_t *queue, void *item);
extern int queue_arr_dequeue(queue_arr_t *queue, void *item);
extern int queue_arr_init(queue_arr_t **queue, unsigned int N, size_t elem_size);
extern void queue_arr_free(queue_arr_t **queue);
extern bool queue_arr_is_empty(queue_arr_t *queue);
extern unsigned int queue_arr_get_size(queue_arr_t *queue);

#endif //ALGS4C_QUEUE_ARR_H
