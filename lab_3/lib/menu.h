#pragma once
#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdio_ext.h>

enum input_states {
    INIT        = 'n',
    PRINT       = 'p',
    ADD         = 'a',
    DELETE      = 'd',
    INDIVIDUAL  = 'i',
    MENU        = 'm',
    QUIT        = 'q'
};


void printMenu(void);

#endif
