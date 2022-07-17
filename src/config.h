/* See LICENSE file for copyright and license details. */

/* def */
#define WEBBROWSER		"google-chrome-stable"
#define TERMINAL		"alacritty"
#define SCREENSHOT		"spectacle"
#define GUI_FILEMANAGER	        "pcmanfm"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps size between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/bar.sh"; /* Alternate bar launch command */

static const char *fonts[]          = { "monospace:size=11", "Noto Color Emoji:size=11", "Nerd Font Mono:weight=bold:size=15:antialias=true:hinting=true" };
static const char dmenufont[]       = "monospace:size=11";

#include "colors.h"

// Autostart programs
static const char *const autostart[] = {
    // Keyboard layouts switch (requires setxkbmap)
    "setxkbmap", "-model", "pc101", "-layout", "us,ar", "-variant", ",,", "-option", "grp:win_space_toggle", NULL,
    // "xkbset", "exp", "=sticky", "-twokey", "-latchlock", NULL, // sticky keys
    "/bin/stickykeys", NULL, // sticky keys script
    "picom", NULL, // Start compositor , for transparency
    "nitrogen", "--restore", NULL, // Restores the wallpaper
    "nm-applet", NULL, // Start the network manger
    "copyq", NULL, // clipboard manger
     NULL /* terminate */
 };

/* tagging */
// static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ WEBBROWSER, NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "layouts/layouts.h"
#include "movestack.c"
#include "keys/keys.h"
