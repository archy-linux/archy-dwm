//
// Created by anas on 10/31/22.
//

#ifndef MOUSE_H
#define MOUSE_H

#include <X11/X.h>

typedef struct {
    unsigned int click;
    unsigned int mask;
    unsigned int button;

    void (*func)(const Arg *arg);

    const Arg arg;
} Button;

enum {
    ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
    ClkClientWin, ClkRootWin, ClkLast
}; /* clicks */

#ifndef MOUSE_C
#include "mouse.c"
#endif

#endif //MOUSE_H
