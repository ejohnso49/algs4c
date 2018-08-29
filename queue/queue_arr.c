//
// Created by eric on 8/21/18.
//

#include "queue_arr.h"
#include "../include/common.h"
#include <string.h>

static int queue_arr_resize(queue_arr_t *queue, unsigned int N) {
    void *temp;

    temp = calloc(N, queue->elem_size);
    if (temp == NULL) {
        return -1;
    }

    for (unsigned int i = 0; i < queue->size; i++) {
        void *dest = (unsigned char *) temp + (i * queue->elem_size);
        void *src = (unsigned char *) queue->data +
                (((queue->dequeue_index + i) % queue->N) * queue->elem_size);
        memcpy(dest, src, queue->elem_size);
    }
    free(queue->data);
    queue->data = temp;
    queue->N = N;
    queue->enqueue_index = queue->size;
    queue->dequeue_index = 0;
    return 1;
}

int queue_arr_enqueue(queue_arr_t *queue, void *item) {
    void *dest;

    if (item == NULL) {
        return -1;
    }

    if (queue->size == queue->N) {
        queue_arr_resize(queue, queue->N << 1);
    }

    dest = (unsigned char *) queue->data + (queue->enqueue_index * queue->elem_size);
    memcpy(dest, item, queue->elem_size);
    queue->size++;
    queue->enqueue_index++;
    if (queue->enqueue_index == queue->N) {
        queue->enqueue_index = 0;
    }
    return 1;
}

int queue_arr_dequeue(queue_arr_t *queue, void *item) {
    void *src;

    if (queue_arr_is_empty(queue)) {
        return -1;
    }

    if ((queue->N > 0) && (queue->size < (queue->N >> 2))) {
        queue_arr_resize(queue, queue->N >> 1);
    }

    src = (unsigned char *) queue->data + (queue->dequeue_index * queue->elem_size);
    memcpy(item, src, queue->elem_size);
    queue->size--;
    queue->dequeue_index++;
    if (queue->dequeue_index == queue->N) {
        queue->dequeue_index = 0;
    }
    return 1;
}

int queue_arr_init(queue_arr_t **queue, unsigned int N, size_t elem_size) {
    void *temp;

    *queue = (queue_arr_t *) calloc(1, sizeof(queue_arr_t));

    (*queue)->N = N;
    (*queue)->elem_size = elem_size;

    temp = calloc((*queue)->N, (*queue)->elem_size);
    if (temp == NULL) {
        return -1;
    } else {
        (*queue)->data = temp;
        return 1;
    }
}

void queue_arr_free(queue_arr_t **queue) {
    if (*queue != NULL) {
        if ((*queue)->data != NULL) {
            free((*queue)->data);
            (*queue)->data = NULL;
        }

        free(*queue);
        *queue = NULL;
    }
}

bool queue_arr_is_empty(queue_arr_t *queue) {
    return queue->size == 0;
}

unsigned int queue_arr_get_size(queue_arr_t *queue) {
    return queue->size;
}