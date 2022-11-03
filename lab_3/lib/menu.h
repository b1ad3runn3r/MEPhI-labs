#pragma once
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdio_ext.h>

enum input_states {
    PRINT       = '1',
    ADD         = '2',
    POP         = '3',
    INDIVIDUAL  = '4',
    INIT        = '5',
    QUIT        = '6'
};


void printMenu(void);

//void processInput(void);

#endif
