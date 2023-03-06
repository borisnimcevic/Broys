/*
 * Description: Pin configuration
 * Author: Boris Nimcevic
 * Date: 2023/02/03
 *
 * Copyright (C) 2023 Lilordag
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "driver/gpio.h"

#define PIN_MAX_DIGIT 3
#define PIN_MAX_NUMBER 9

// digits (total of 4)
#define DIGI0 GPIO_NUM_21
#define DIGI1 GPIO_NUM_3
#define DIGI2 GPIO_NUM_10
#define DIGI3 GPIO_NUM_9

// parts of seven segment display
#define A_LED GPIO_NUM_0
#define B_LED GPIO_NUM_1
#define C_LED GPIO_NUM_4
#define D_LED GPIO_NUM_5
#define E_LED GPIO_NUM_6
#define F_LED GPIO_NUM_7
#define G_LED GPIO_NUM_20

static const gpio_num_t digit_pins[] = {
    // digits
    DIGI0,
    DIGI1,
    DIGI2,
    DIGI3,
};

static const gpio_num_t led_pins[] = {
    // segments
    A_LED, B_LED, C_LED, D_LED, E_LED, F_LED, G_LED,
};

static const uint8_t values[11][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
    {0, 0, 0, 0, 0, 0, 0}, // off
};

void initGPIOs(void);
void setPlace(const uint8_t place);
void setDigit(const uint8_t digit);
void clearLED(void);

#endif /* PIN_CONFIG_H */
