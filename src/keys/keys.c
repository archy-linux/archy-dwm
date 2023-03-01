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
        {MODKEY | ShiftMask, -1, XK_d, spawn, {.v = dmenucmd}},
        // Rofi launcher (small)
        {MODKEY | ShiftMask | ControlMask, -1, XK_d, spawn, SHCMD("rofi -show drun")},
        // Start the main terminal
        {MODKEY, -1, XK_Return, spawn, {.v = termcmd}},
        // Start the alacritty terminal
        {MODKEY, XK_t, XK_a, spawn, SHCMD("alacritty")},
        // kitty
        {MODKEY, XK_t, XK_k, spawn, SHCMD("kitty")},
        /************************************* File browsers *************************************/
        // GUI filebrowser
        {MODKEY | ShiftMask, XK_f, XK_g, spawn, SHCMD("~/.scripts/filebrowser")},
        // Rofi file browser (small)
        {MODKEY | ShiftMask, XK_f, XK_f, spawn, SHCMD("rofi -show filebrowser")},
        // Terminal file manager (ranger)
        {MODKEY | ShiftMask, XK_f, XK_t, spawn, SHCMD(TERMINAL " -e ranger")},
        /************************************* Start the web browers *************************************/
        // Firefox-developer-edition
        {MODKEY, XK_w, XK_f, spawn, SHCMD("firefox-developer-edition")},
        // brave-beta
        {MODKEY, XK_w, XK_b, spawn, SHCMD("brave-beta")},
        // Google chrome stable
        {MODKEY, XK_w, XK_g, spawn, SHCMD("google-chrome-stable")},
        // Tor brower
        {MODKEY, XK_w, XK_t, spawn, SHCMD("tor-browser")},
        /************************************* Start the caht/email/\* apps *************************************/
        // Discord
        {MODKEY, XK_c, XK_d, spawn, SHCMD("discord")},
        // Obsidian
        {MODKEY, XK_c, XK_o, spawn, SHCMD("obsidian")},
        /************************************* Start the dev apps *************************************/
        // Jetbrains toolbox
        {MODKEY, XK_a, XK_j, spawn, SHCMD("jetbrains-toolbox")},
        // IntelliJ IDEA
        {MODKEY, XK_a, XK_i, spawn, SHCMD("~/.scripts/idea")},
        // Clion
        {MODKEY, XK_a, XK_c, spawn, SHCMD("~/.scripts/clion")},
        // NeoVim
        {MODKEY, XK_a, XK_n, spawn, SHCMD(TERMINAL " -e nvim")},
        // Vim
        {MODKEY, XK_a, XK_v, spawn, SHCMD(TERMINAL " -e vim")},
        // emacs
        {MODKEY, XK_a, XK_e, spawn, SHCMD("emacs")},
        /************************************* Start personalize apps *************************************/
        // nitrogen
        {MODKEY, XK_p, XK_b, spawn, SHCMD("nitrogen")},
        // nm-connection-editor
        {MODKEY, XK_p, XK_n, spawn, SHCMD("nm-connection-editor")},
        /************************************* Start multi media apps *************************************/
        {MODKEY, -1, XK_l, spawn, SHCMD("~/.scripts/luncher")},
        // cmus
        {MODKEY, XK_m, XK_c, spawn, {.v = CMUS}},
        // Spotify
        {MODKEY, XK_m, XK_s, spawn, {.v = SPOTIFY}},
        /************************************* Start the emoji piker apps *************************************/
        // Emoji selector (rofi)
        {Mod4Mask, -1, XK_e, spawn, SHCMD("rofimoji")},
        /************************************* dwm keys *************************************/
        // Full screen mode
        {MODKEY, -1, XK_f, fullscreen, {0}},
        // Toggle the slstatus bar (hide/show)
        {MODKEY, -1, XK_b, togglebar, {0}},
        // Change the focus
        {MODKEY, -1, XK_j, focusstack, {.i = +1}},
        {MODKEY, -1, XK_k, focusstack, {.i = -1}},
        // Change the stack layout (horizontal/virtecal)
        {MODKEY, -1, XK_i, incnmaster, {.i = +1}},
        {MODKEY, -1, XK_d, incnmaster, {.i = -1}},
        // Change the focus window size (in the tile mode)
        {MODKEY, -1, XK_h, setmfact, {.f = -0.05f}},
        {MODKEY, -1, XK_l, setmfact, {.f = +0.05f}},
        {MODKEY, -1, XK_Tab, view, {0}},
        {MODKEY | ShiftMask, -1, XK_j, movestack, {.i = +1}},
        {MODKEY | ShiftMask, -1, XK_k, movestack, {.i = -1}},
        // Toogle styky mode
        {MODKEY | ShiftMask, -1, XK_s, togglesticky, {0}},

        // Quit from the foucsed window (kill)
        {MODKEY, XK_q, XK_q, killclient, {0}},
        /************************* Switch between layouts *************************/
        // Tiled layout
        {MODKEY, XK_s, XK_t, setlayout, {.v = &layouts[0]}},
        // Floating layout
        {MODKEY, XK_s, XK_f, setlayout, {.v = &layouts[1]}},
        // Monocle layout
        {MODKEY, XK_s, XK_m, setlayout, {.v = &layouts[2]}},
        // Grid layout
        {MODKEY, XK_s, XK_g, setlayout, {.v = &layouts[3]}},
        // Spiral layout
        {MODKEY, XK_s, XK_r, setlayout, {.v = &layouts[4]}},
        // Dwindle layout
        {MODKEY, XK_s, XK_d, setlayout, {.v = &layouts[5]}},
        // Centerd master layout
        {MODKEY, XK_s, XK_c, setlayout, {.v = &layouts[6]}},
        // Centerd floating master layout
        {MODKEY, XK_s, XK_x, setlayout, {.v = &layouts[7]}},
        // Toggle between current layout and tile layout
        {MODKEY, XK_s, XK_s, setlayout, {0}},

        // Toggle floating window
        {MODKEY | Mod1Mask, -1, XK_f, togglefloating, {0}},
        // View all tags
        {MODKEY, -1, XK_0, view, {.ui = ~0}},
        // Mirror the current tagg in all tags
        {MODKEY | ShiftMask, -1, XK_0, tag, {.ui = ~0}},
        // I don't know
        {MODKEY, -1, XK_comma, focusmon, {.i = -1}},
        {MODKEY, -1, XK_period, focusmon, {.i = +1}},
        {MODKEY | ShiftMask, -1, XK_comma, tagmon, {.i = -1}},
        {MODKEY | ShiftMask, -1, XK_period, tagmon, {.i = +1}},
        /************************* Tag keys *************************/
        TAGKEYS(-1, XK_1, 0)
        TAGKEYS(-1, XK_2, 1)
        TAGKEYS(-1, XK_3, 2)
        TAGKEYS(-1, XK_4, 3)
        TAGKEYS(-1, XK_5, 4)
        TAGKEYS(-1, XK_6, 5)
        TAGKEYS(-1, XK_7, 6)
        TAGKEYS(-1, XK_8, 7)
        TAGKEYS(-1, XK_9, 8)
        TAGKEYS(-1, XK_semicolon, 9)
        /* ---------------------------------- Control Keys ---------------------------------- */
        // Brightness controllers (requires xbacklight)
        {0, -1, XF86XK_MonBrightnessUp, spawn, SHCMD("~/.scripts/brightness up")},
        {0, -1, XF86XK_MonBrightnessDown, spawn, SHCMD("~/.scripts/brightness down")},
        // Sound controllers (requires pamixer)
        {0, -1, XF86XK_AudioRaiseVolume, spawn, SHCMD("~/.scripts/volume up")},
        {0, -1, XF86XK_AudioLowerVolume, spawn, SHCMD("~/.scripts/volume down")},
        {0, -1, XF86XK_AudioMute, spawn, SHCMD("~/.scripts/volume mute")},
        // Media controls (requires playerctl)
        {0, -1, XF86XK_AudioPlay, spawn, SHCMD("playerctl play-pause")},
        {0, -1, XF86XK_AudioStop, spawn, SHCMD("playerctl stop")},
        {0, -1, XF86XK_AudioNext, spawn, SHCMD("playerctl next")},
        {0, -1, XF86XK_AudioPrev, spawn, SHCMD("playerctl previous")},

        {Mod1Mask, -1, XK_F1, spawn, SHCMD("playerctl volume 0.0")},
        {Mod1Mask, -1, XK_F2, spawn, SHCMD("playerctl volume 0.1-")},
        {Mod1Mask, -1, XK_F3, spawn, SHCMD("playerctl volume 0.1+")},
        // Mute and unmute mic
        {0, -1, XF86XK_AudioMicMute, spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle")},
        // Take a screenshot
        {0, -1, XK_Print, spawn, SHCMD("~/.scripts/screenshot")},
        {Mod1Mask, -1, XK_Print, spawn, SHCMD("~/.scripts/screenshot --region")},
        {Mod2Mask, -1, XK_Print, spawn, SHCMD("~/.scripts/screenshot --activewindow")},
        {Mod1Mask | Mod2Mask, -1, XK_Print, spawn,
         SHCMD("~/.scripts/screenshot --fullscreen --background --copy-image")},
        /* ---------------------------------- lock Keys ---------------------------------- */
        // Lock the screen
        {MODKEY | ShiftMask, -1, XK_x, spawn, SHCMD("betterlockscreen -l dim")},
        {0, -1, XF86XK_Suspend, spawn, SHCMD("betterlockscreen -l dim")},
        // // Kill dwm (super + shift + alt + q)
        // { MODKEY|ShiftMask|Mod1Mask,    -1,      XK_q,                   quit,           {0} },
};


