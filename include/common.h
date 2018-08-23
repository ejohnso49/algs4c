//
// Created by eric on 8/22/18.
//

#ifndef ALGS4C_COMMON_H
#define ALGS4C_COMMON_H

#define max(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })

#define min(a, b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })

#endif //ALGS4C_COMMON_H
