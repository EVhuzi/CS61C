#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    unsigned Flag;
    Flag = (*reg & 0x1) ^ ((*reg >> 2) & 0x1) ^ ((*reg >> 3) & 0x1) & ((*reg >> 5) & 0x1);
    *reg = (*reg >> 1) | ((Flag & 0x1) << 15);
}

