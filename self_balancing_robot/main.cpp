/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "q_encoder.hpp"

int main() {
    stdio_init_all();
    printf("test");

    QEncoder enc_left = QEncoder(pio0, 6, 0);
    QEncoder enc_right = QEncoder(pio1, 8, 0, true);
    while (1) {
        QEncoderValue left_read = enc_left.fetch();
        QEncoderValue right_read = enc_right.fetch();
        printf("left [position %8d, delta %6d] --- right [position %8d, delta %6d]\n", left_read.value, left_read.delta, right_read.value, right_read.delta);
        sleep_ms(100);
    }
}