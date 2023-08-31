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
#define MODKEY Mod1Mask // The alt key

#define TAGKEYS(KEY, TAG)                                               \
      {MODKEY, KEY, view, {.ui = 1 << TAG}},                                \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},        \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                 \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

// Include all the key bindings
#ifndef KEYS_C
#include "keys.c"
#endif

#endif // keys_H
