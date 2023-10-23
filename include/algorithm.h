
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "stdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

// ========================================================
// Here in this file you can declare C-functions (not C++), 
// that you can call from the main C++ code

int c_example_algorithm(int value);

void c_init();

void c_loop();

void c_exit();

// ========================================================

#ifdef __cplusplus
}
#endif

#endif // ALGORITHM_H
