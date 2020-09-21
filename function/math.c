//
// Created by Akigaze on 9/20/2020.
//

#include "math.h"

int poww(int m, int n) {
    return innerPow(m, n);
}

static int innerPow(int m, int n) {
    return m * n;
}

