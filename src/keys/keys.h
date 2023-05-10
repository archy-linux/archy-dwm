#ifndef KEYS_H
#define KEYS_H

#include "../yo_dwm.h"
#include <X11/X.h>

typedef struct {
  unsigned int mod;
  KeySym chain;
  KeySym keysym;

  void (*func)(const Arg *);

  const Arg arg;
} Key;

/* key definitions */
#define MODKEY Mod4Mask // Super key

#define TAGKEYS(CHAIN, KEY, TAG)                                               \
  {MODKEY, CHAIN, KEY, view, {.ui = 1 << TAG}},                                \
      {MODKEY | ControlMask, CHAIN, KEY, toggleview, {.ui = 1 << TAG}},        \
      {MODKEY | ShiftMask, CHAIN, KEY, tag, {.ui = 1 << TAG}},                 \
      {MODKEY | ControlMask | ShiftMask,                                       \
       CHAIN,                                                                  \
       KEY,                                                                    \
       toggletag,                                                              \
       {.ui = 1 << TAG}},

// Include all the key bindings
#ifndef KEYS_C
#include "keys.c"
#endif

#endif // keys_H
