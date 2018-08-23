//
// Created by eric on 8/21/18.
//

#ifndef ALGS4C_QUEUE_H
#define ALGS4C_QUEUE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_s queue_t;

struct queue_s {
    unsigned int N;
    size_t elem_size;
    unsigned int size;
    unsigned int dequeue_index;
    unsigned int enqueue_index;
    void *data;
};

extern int queue_enqueue(queue_t *queue, void *item);
extern int queue_dequeue(queue_t *queue, void *item);
extern int queue_init(queue_t **queue, unsigned int N, size_t elem_size);
extern void queue_free(queue_t **queue);
extern bool queue_is_empty(queue_t *queue);
extern unsigned int queue_get_size(queue_t *queue);

#endif //ALGS4C_QUEUE_H
