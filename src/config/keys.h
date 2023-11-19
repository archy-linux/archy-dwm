#ifndef KEYS_H
#define KEYS_H

#include "../archy_dwm.h"
#include <X11/X.h>

typedef struct {
  unsigned int mod;
  KeySym keysym;

  void (*func)(const Arg *);

  const Arg arg;
} Key;

/* key definitions */
#define MODKEY Mod4Mask // The super key

#define TAGKEYS(KEY, TAG)                                               \
      {MODKEY, KEY, view, {.ui = 1 << TAG}},                                \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},        \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                 \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

#ifndef ACTIONS_H
#include "../actions.h"
#endif //ACTIONS_H
#ifndef LAYOUTS_H
#include "../layouts/layouts.h"
#endif //LAYOUTS_H
// X11 keysym definitions
#include <X11/XF86keysym.h> // req (libxinerama1 and libxinerama-dev)

#include <X11/keysym.h>

static Key keys[] = {
        /* modifier                  key        function        argument */
        {MODKEY, XK_f, fullscreen, {0}},
        {MODKEY|ShiftMask, XK_b, togglebar, {0}},
        // Change the focus
        {MODKEY, XK_e, focusstack, {.i = +1}},
        {MODKEY, XK_a, focusstack, {.i = -1}},
        // incress and decrees the masters
        {MODKEY, XK_i, incnmaster, {.i = +1}},
        {MODKEY, XK_d, incnmaster, {.i = -1}},
        // Change the focus window size (in the tile mode)
        {MODKEY, XK_equal, setmfact, {.f = -0.05f}},
        {MODKEY, XK_minus, setmfact, {.f = +0.05f}},
        {MODKEY, XK_Tab, view, {0}},
        {MODKEY | ShiftMask, XK_e, movestack, {.i = +1}},
        {MODKEY | ShiftMask, XK_a, movestack, {.i = -1}},
        // Toogle styky mode
        {MODKEY | ShiftMask, XK_s, togglesticky, {0}},
        // Quit from the foucsed window (kill)
        {MODKEY|ShiftMask, XK_q, killclient, {0}},
        /************************* Switch between layouts *************************/
        // Tiled layout
        {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
        // Floating layout
        {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
        // Monocle layout
        {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
        // Grid layout
        {MODKEY, XK_g, setlayout, {.v = &layouts[3]}},
        // Spiral layout
        {MODKEY, XK_r, setlayout, {.v = &layouts[4]}},
        // Dwindle layout
        {MODKEY, XK_d, setlayout, {.v = &layouts[5]}},
        // Centerd master layout
        {MODKEY, XK_c, setlayout, {.v = &layouts[6]}},
        // Centerd floating master layout
        {MODKEY, XK_x, setlayout, {.v = &layouts[7]}},
        // Toggle between current layout and tile layout
        {MODKEY, XK_s, setlayout, {0}},
        // Toggle floating window
        {MODKEY | ShiftMask, XK_f, togglefloating, {0}},
        // Mirror the current tagg in all tags
        {MODKEY, XK_0, tag, {.ui = ~0}},
        // Multi monitor stuff
        {MODKEY, XK_comma, focusmon, {.i = -1}},
        {MODKEY, XK_period, focusmon, {.i = +1}},
        {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
        {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
        /************************* Tag keys *************************/
        TAGKEYS(XK_1, 0)
        TAGKEYS(XK_2, 1)
        TAGKEYS(XK_3, 2)
        TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4)
        TAGKEYS(XK_6, 5)
        TAGKEYS(XK_7, 6)
        TAGKEYS(XK_8, 7)
        TAGKEYS(XK_9, 8)
        TAGKEYS(XK_semicolon, 9)
};

#endif // keys_H
