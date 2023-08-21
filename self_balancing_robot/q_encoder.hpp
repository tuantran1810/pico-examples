#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "quadrature_encoder.pio.h"

#ifndef _Q_ENCODER_HPP
#define _Q_ENCODER_HPP

struct QEncoderValue {
    int value;
    int delta;
};

struct QEncoder {
    QEncoder(const PIO pio, const uint pin_a, const uint state_machine, bool reverse = false) {
        this->pio = pio;
        this->old_value = 0;
        this->state_machine = state_machine;
        this->reverse = 1;
        if (reverse) {
            this->reverse = -1;
        }
        pio_add_program(this->pio, &quadrature_encoder_program);
        quadrature_encoder_program_init(this->pio, this->state_machine, pin_a, 0);
    }

    QEncoderValue fetch() {
        int v = this->reverse * quadrature_encoder_get_count(this->pio, this->state_machine);
        int delta = v - this->old_value;
        this->old_value = v;
        return QEncoderValue {
            value: v,
            delta: delta,
        };
    }

private:
    PIO pio;
    int old_value;
    uint state_machine;
    int reverse;
};

#endif
