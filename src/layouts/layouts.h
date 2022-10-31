#ifndef layouts_H
#define layouts_H

// Include all layouts
#include "tile.c"
#include "monocle.c"
#include "grid.c"
#include "fibonacci.c"
#include "centeredmaster.h"

// Layouts array
static const Layout layouts[] = {
        /* symbol     arrange function */
        {"[]=",  tile},    /* first entry is default */
        {"><>", NULL},    /* no layout function means floating behavior */
        {"[M]",  monocle}, // 2
        {"HHH",  grid}, // 3
        {"[@]",  spiral}, // 4
        {"[\\]", dwindle}, // 5
        {"|M|",  centeredmaster}, // 6
        {">M>",  centeredfloatingmaster}, // 7
};

#endif // layouts_H
