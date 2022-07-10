#ifndef layouts_H
#define layouts_H

// Include all layouts
#include "tile.c"
#include "monocle.c"
#include "grid.c"
#include "fibonacci.c"

// Layouts array
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile     },    /* first entry is default */
	{ "><>",      NULL     },    /* no layout function means floating behavior */
	{ "[M]",      monocle  },
	{ "HHH",      grid     },
        { "[@]",      spiral   },
        { "[\\]",     dwindle  },
};

#endif // !layouts.h
