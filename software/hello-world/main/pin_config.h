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
// digits (total of 4)
// static const gpio_num_t DIGI0 = GPIO_NUM_21;
// static const gpio_num_t DIGI1 = GPIO_NUM_3;
// static const gpio_num_t DIGI2 = GPIO_NUM_10;
// static const gpio_num_t DIGI3 = GPIO_NUM_9;

#define DIGI0 GPIO_NUM_21
#define DIGI1 GPIO_NUM_3
#define DIGI2 GPIO_NUM_10
#define DIGI3 GPIO_NUM_9
// parts of seven segment display
// static const gpio_num_t A_LED = GPIO_NUM_0;
// static const gpio_num_t B_LED = GPIO_NUM_1;
// static const gpio_num_t C_LED = GPIO_NUM_4;
// static const gpio_num_t D_LED = GPIO_NUM_5;
// static const gpio_num_t E_LED = GPIO_NUM_6;
// static const gpio_num_t F_LED = GPIO_NUM_7;
// static const gpio_num_t G_LED = GPIO_NUM_20;

#define A_LED GPIO_NUM_0
#define B_LED GPIO_NUM_1
#define C_LED GPIO_NUM_4
#define D_LED GPIO_NUM_5
#define E_LED GPIO_NUM_6
#define F_LED GPIO_NUM_7
#define G_LED GPIO_NUM_20

static const gpio_num_t display_pins[] = {
    DIGI0,DIGI1,DIGI2,DIGI3,
    A_LED,B_LED,C_LED,D_LED,
    E_LED,F_LED,G_LED,
};

void initGPIOs(void);

#endif /* PIN_CONFIG_H */