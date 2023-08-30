#include "../config.h"
#include "keys.h"
#include "functions.h"
#include "../layouts/layouts.h"
// X11 keysym definitions
#include <X11/XF86keysym.h> // req (libxinerama1 and libxinerama-dev)

#include <X11/keysym.h>

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg,
                                 "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL};
static const char *termcmd[] = {TERMINAL, NULL};
// Music
static const char *CMUS[] = {TERMINAL, "--class=cmus", "-e", "cmus"}; // Just start cmus :)
static const char *SPOTIFY[] = {"brave-browser-beta", "--app=https://open.spotify.com"};    // because I love music :D

static Key keys[] = {
        /* modifier                     chain key         key        function        argument */
        /* ---------------------------------- Apps Keys ---------------------------------- */
        // Dmenu (launcher)
        {MODKEY | ShiftMask, XK_d, spawn, {.v = dmenucmd}},
        // Rofi launcher (small)
        {MODKEY | ShiftMask | ControlMask, XK_d, spawn, SHCMD("rofi -show drun")},
        {MODKEY, XK_Return, spawn, {.v = termcmd}},
        /************************************* Start the web browers *************************************/
        // Firefox-developer-edition
        {MODKEY | ShiftMask, XK_f, spawn, SHCMD("firefox-developer-edition")},
        // brave-beta
        {MODKEY | ShiftMask, XK_b, spawn, SHCMD("brave-beta")},
        // Google chrome stable
        {MODKEY | ShiftMask, XK_g, spawn, SHCMD("google-chrome-stable")},
        // Tor brower
        {MODKEY | ShiftMask, XK_t, spawn, SHCMD("tor-browser")},
        /************************************* Start the caht/email/\* apps *************************************/
        // Discord
        {MODKEY | ShiftMask, XK_d, spawn, SHCMD("discord")},
        // Obsidian
        {MODKEY | ShiftMask, XK_o, spawn, SHCMD("obsidian")},
        /************************************* Start the dev apps *************************************/
        // Jetbrains toolbox
        {MODKEY | ShiftMask, XK_j, spawn, SHCMD("jetbrains-toolbox")},
        
        /************************************* Start multi media apps *************************************/
        {MODKEY, XK_l, spawn, SHCMD("luncher")},
        // cmus
        {MODKEY | ShiftMask, XK_c, spawn, {.v = CMUS}},
        // Spotify
        {MODKEY | ShiftMask, XK_s, spawn, {.v = SPOTIFY}},
        /************************************* Start the emoji piker apps *************************************/
        // Emoji selector (rofi)
        {Mod4Mask, XK_e, spawn, SHCMD("rofimoji")},
        /************************************* dwm keys *************************************/
        // Full screen mode
        {MODKEY, XK_f, fullscreen, {0}},
        // Toggle the slstatus bar (hide/show)
        {MODKEY, XK_b, togglebar, {0}},
        // Change the focus
        {MODKEY, XK_j, focusstack, {.i = +1}},
        {MODKEY, XK_k, focusstack, {.i = -1}},
        // Change the stack layout (horizontal/virtecal)
        {MODKEY, XK_i, incnmaster, {.i = +1}},
        {MODKEY, XK_d, incnmaster, {.i = -1}},
        // Change the focus window size (in the tile mode)
        {MODKEY, XK_h, setmfact, {.f = -0.05f}},
        {MODKEY, XK_l, setmfact, {.f = +0.05f}},
        {MODKEY, XK_Tab, view, {0}},
        {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
        {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},
        // Toogle styky mode
        {MODKEY | ShiftMask, XK_s, togglesticky, {0}},

        // Quit from the foucsed window (kill)
        {MODKEY, XK_q, killclient, {0}},
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
        {MODKEY | Mod1Mask, XK_f, togglefloating, {0}},
        // View all tags
        {MODKEY, XK_0, view, {.ui = ~0}},
        // Mirror the current tagg in all tags
        {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
        // I don't know
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
        /* ---------------------------------- Control Keys ---------------------------------- */
        // Brightness controllers (requires xbacklight)
        {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightness up")},
        {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightness down")},
        // Sound controllers (requires pamixer)
        {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("volume-control up")},
        {0, XF86XK_AudioLowerVolume, spawn, SHCMD("volume-control down")},
        {0, XF86XK_AudioMute, spawn, SHCMD("volume-control mute")},
        // Media controls (requires playerctl)
        {0, XF86XK_AudioPlay, spawn, SHCMD("playerctl play-pause")},
        {0, XF86XK_AudioStop, spawn, SHCMD("playerctl stop")},
        {0, XF86XK_AudioNext, spawn, SHCMD("playerctl next")},
        {0, XF86XK_AudioPrev, spawn, SHCMD("playerctl previous")},

        {Mod1Mask, XK_F1, spawn, SHCMD("playerctl volume 0.0")},
        {Mod1Mask, XK_F2, spawn, SHCMD("playerctl volume 0.1-")},
        {Mod1Mask, XK_F3, spawn, SHCMD("playerctl volume 0.1+")},
        // Mute and unmute mic
        {0, XF86XK_AudioMicMute, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle")},
        // Take a screenshot
        {0, XK_Print, spawn, SHCMD("~/take-screenshot")},
        {Mod1Mask, XK_Print, spawn, SHCMD("take-screenshot --region")},
        {Mod2Mask, XK_Print, spawn, SHCMD("take-screenshot --activewindow")},
        {Mod1Mask | Mod2Mask, XK_Print, spawn, SHCMD("take-screenshot --fullscreen --background --copy-image")},
        /* ---------------------------------- lock Keys ---------------------------------- */
        // Lock the screen
        {MODKEY | ShiftMask, XK_x, spawn, SHCMD("betterlockscreen -l dim")},
        // // Kill dwm (super + shift + alt + q)
        // { MODKEY|ShiftMask|Mod1Mask,         XK_q,                   quit,           {0} },
};


