#ifndef CONFIG_H
#define CONFIG_H
/* def */
#define WEBBROWSER        "firefox-developer-edition"
#define TERMINAL        "kitty"

/* appearance */
static const unsigned int borderpx = 1;        /* border pixel of windows */
static const unsigned int gappx = 3;        /* gaps size between windows */
static const unsigned int snap = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray = 1;     /* 0 means no systray */
static const int showbar = 1;        /* 0 means no bar */
static const int topbar = 1;        /* 0 means bottom bar */
static const char *fonts[] = {"monospace:size=7", "Noto Color Emoji:size=8",
                              "Nerd Font Mono:size=16:antialias=true:hinting=true"};
static const char dmenufont[] = "monospace:size=8";

#ifndef STDDEF_H
#include <stddef.h>
#endif

#include "colors.h"

// Autostart programs
static const char *const autostart[] = {
        // Start my build of slstatus
        "slstatus", NULL,
        // Keyboard layouts switch (requires setxkbmap)
        "setxkbmap", "-model", "pc101", "-layout", "us,ar", "-variant", ",,", "-option", "grp:win_space_toggle", NULL,
        // "xkbset", "exp", "=sticky", "-twokey", "-latchlock", NULL, // sticky keys
        "/bin/stickykeys", NULL, // sticky keys script
        // "picom", NULL, // Start compositor , for transparency
        "nitrogen", "--restore", NULL, // Restores the wallpaper
        "nm-applet", NULL, // Start the network manger
        "copyq", NULL, // clipboard manger
        NULL /* terminate */
};

/* tagging */
// static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
// static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const char *tags[] = {"www", "dev", "sys", "chat", "img", "vid", "mus", "vbox", "gfx", ";"};

static const Rule rules[] = {
        /* xprop(1):
         *	WM_CLASS(STRING) = instance, class
         *	WM_NAME(STRING) = title
         */
        /* class      instance    title       tags mask     isfloating   monitor */
        {"Gimp",                    NULL, NULL, 9,      1, -1},
        // { WEBBROWSER, NULL,       NULL,       1 << 8,       0,           -1 },
        {"Tor Browser",             NULL, NULL, 10,     0, -1},
        {"keepassxc",               NULL, NULL, 10,     0, -1},
        {"firefoxdeveloperedition", NULL, NULL, 1 << 6, 0, -1},
        {"discord",                 NULL, NULL, 4 << 5, 0, -1},

};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg,
                                 "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL};
static const char *termcmd[] = {TERMINAL, NULL};
/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#endif // CONFIG_H
