#pragma once
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdio_ext.h>

enum input_states {
    PRINT       = 'p',
    ADD         = 'a',
    DELETE      = 'd',
    INDIVIDUAL  = 'i',
    QUIT        = 'q'
};


void printMenu(void);

//void processInput(void);

#endif
