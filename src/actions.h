//
// Created by anas on 10/31/22.
//

#ifndef ACTIONS_H
#define ACTIONS_H

#include "archy_dwm.h"

static void focusmon(const Arg *arg);

static void fullscreen(const Arg *arg);

static void focusstack(const Arg *arg);

static void tagmon(const Arg *arg);

static void incnmaster(const Arg *arg);

static void killclient(const Arg *arg);

static void movemouse(const Arg *arg);

static void togglebar(const Arg *arg);

static void togglesticky(const Arg *arg);

static void togglefloating(const Arg *arg);

static void setmfact(const Arg *arg);

static void view(const Arg *arg);

static void movestack(const Arg *arg);

static void setlayout(const Arg *arg);

static void tag(const Arg *arg);

static void zoom(const Arg *arg);

static void quit(const Arg *arg);

#endif //ACTIONS_H
