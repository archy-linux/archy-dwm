/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, 
  "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

/* key definitions */
#define MODKEY Mod4Mask // win/super key

#define TAGKEYS(KEY,TAG) \
	{1, {{MODKEY,                        KEY}},      view,           {.ui = 1 << TAG} }, \
	{1, {{MODKEY|ControlMask,            KEY}},      toggleview,     {.ui = 1 << TAG} }, \
	{1, {{MODKEY|ShiftMask,              KEY}},      tag,            {.ui = 1 << TAG} }, \
	{1, {{MODKEY|ControlMask|ShiftMask,  KEY}},      toggletag,      {.ui = 1 << TAG} },

// X11 keysym definitions
#include <X11/XF86keysym.h> // req (libxinerama1 and libxinerama-dev)
static Keychord keychords[] = {
	/* modifier                     key        function        argument */
	/* ---------------------------------- Apps Keys ---------------------------------- */
	// Dmenu (launcher)
	{1, {{MODKEY|ShiftMask,             XK_d}},      spawn,                  {.v = dmenucmd } },
	// Rofi launcher (small)
	{1, {{MODKEY|ShiftMask|ControlMask, XK_d}},      spawn,                  SHCMD("rofi -show drun") }, 
	// Start the main terminal
	{1, {{MODKEY,                       XK_Return}}, spawn,                  {.v = termcmd } },
        // Start the alacritty terminal
	{2, {{MODKEY, XK_t},                {0, XK_a}},      spawn,              SHCMD("alacritty")  },
	// Start the alacritty terminal with tmux
	{2, {{MODKEY, XK_t},                {ShiftMask, XK_a}},      spawn,           SHCMD("alacritty -e tmux")  },
        // kitty
	{2, {{MODKEY, XK_t},                {0, XK_k}},              spawn,           SHCMD("kitty")  },
        // kitty with tmux
	{2, {{MODKEY, XK_t},                {ShiftMask, XK_k}},      spawn,           SHCMD("kitty -e tmux")  },
	/************************************* File browsers *************************************/
        // GUI filebrowser (pcmanfm)
	{2, {{MODKEY|ShiftMask, XK_f},      {0, XK_g}},     spawn,           SHCMD(GUI_FILEMANAGER) },
	// Rofi file browser (small)
        {2, {{MODKEY|ShiftMask, XK_f},      {0, XK_f}},     spawn,           SHCMD("rofi -show filebrowser") },
        // Terminal file manager (ranger)
        {2, {{MODKEY|ShiftMask, XK_f},      {0, XK_t}},     spawn,           SHCMD(TERMINAL " -e ranger") },
	/************************************* Start the web browers *************************************/
        // Google chrome stable
	{2, {{MODKEY, XK_w},                {0, XK_g}},     spawn,           SHCMD(WEBBROWSER) },
        // Tor brower
	{2, {{MODKEY, XK_w},                {0, XK_t}},     spawn,           SHCMD("tor-browser") },
	/************************************* Start the caht/email/\* apps *************************************/
	// Discord
	{2, {{MODKEY, XK_c},                {0, XK_d}},      spawn,           SHCMD("discord") },
        // Obsidian
	{2, {{MODKEY, XK_c},                {0, XK_o}},      spawn,           SHCMD("obsidian") },
	/************************************* Start the dev apps *************************************/
	// Jetbrains toolbox
	{2, {{MODKEY, XK_a},                {0, XK_j}},     spawn,         SHCMD("jetbrains-toolbox") },
        // NeoVim
	{2, {{MODKEY, XK_a},                {0, XK_n}},     spawn,         SHCMD(TERMINAL " -e nvim") },
        // Vim
	{2, {{MODKEY, XK_a},                {0, XK_v}},     spawn,         SHCMD(TERMINAL " -e vim") },
        // emacs
	{2, {{MODKEY, XK_a},                {0, XK_e}},     spawn,         SHCMD("emacs") },
	/************************************* Start personalize apps *************************************/
        // nitrogen
        {2, {{MODKEY, XK_p},                {0, XK_b}},    spawn,         SHCMD("nitrogen") },
        // nm-connection-editor
        {2, {{MODKEY, XK_p},                {0, XK_n}},    spawn,         SHCMD("nm-connection-editor") },
	/************************************* Start multi media apps *************************************/
        // cmus
        {2, {{MODKEY, XK_m},                 {0, XK_c}},    spawn,          SHCMD("sh -c \"" TERMINAL " -e cmus\" & sh -c \"cmus-rpc --link\"") },
        // vlc
        {2, {{MODKEY, XK_m},                 {0, XK_v}},    spawn,          SHCMD("vlc") },
        // vlc in the main terminal
        {2, {{MODKEY, XK_m},                 {ShiftMask, XK_v}},    spawn,          SHCMD(TERMINAL "nvlc") },
	/************************************* Start the emoji piker apps *************************************/
	// Emoji selector (rofi)
	{1, {{Mod4Mask,                    XK_e}},    spawn,          SHCMD("rofimoji") },
	/************************************* dwm keys *************************************/
	// Full screen mode
	{1, {{MODKEY,			XK_f}},      fullscreen,     {0} },
	// Toggle the slstatus bar (hide/show)
	{1, {{MODKEY,                   XK_b}},      togglebar,      {0} },
        // Change the focus
	{1, {{MODKEY,                   XK_j}},      focusstack,     {.i = +1 } },
	{1, {{MODKEY,                   XK_k}},      focusstack,     {.i = -1 } },
        // Change the stack layout (horizontal/virtecal)
	{1, {{MODKEY,                   XK_i}},      incnmaster,     {.i = +1 } },
	{1, {{MODKEY,                   XK_d}},      incnmaster,     {.i = -1 } },
        // Change the focus window size (in the tile mode)
	{1, {{MODKEY,                   XK_h}},      setmfact,       {.f = -0.05} },
	{1, {{MODKEY,                   XK_l}},      setmfact,       {.f = +0.05} },
//	{ MODKEY,                       XK_Return, zoom,           {0} },
	{1, {{MODKEY,                   XK_Tab}},    view,           {0} },

	{1, {{MODKEY|ShiftMask,          XK_j}},     movestack,      {.i = +1 } }, 
	{1, {{MODKEY|ShiftMask,          XK_k}},     movestack,      {.i = -1 } }, 
        // Toogle styky mode
        {1, {{MODKEY|ShiftMask,          XK_s}},     togglesticky,    {0} },
    
	// Quit from the foucsed window (kill)
	{2, {{MODKEY, XK_q},            {0, XK_q}},      killclient,     {0} },
        /************************* Switch between layouts *************************/
	// Tiled layout
	{2, {{MODKEY, XK_s},           {0, XK_t}},      setlayout,      {.v = &layouts[0]} },
	// Floating layout
	{2, {{MODKEY, XK_s},           {0, XK_f}},      setlayout,      {.v = &layouts[1]} },
	// Monocle layout
	{2, {{MODKEY, XK_s},           {0, XK_m}},      setlayout,      {.v = &layouts[2]} },
        // Grid layout
	{2, {{MODKEY, XK_s},           {0, XK_g}},      setlayout,      {.v = &layouts[3]} },
        // Spiral layout
	{2, {{MODKEY, XK_s},           {0, XK_r}},      setlayout,      {.v = &layouts[4]} },
        // Dwindle layout
	{2, {{MODKEY, XK_s},           {ShiftMask, XK_r}},      setlayout,      {.v = &layouts[5]} },
        // Centerd master layout
	{2, {{MODKEY, XK_s},           {0, XK_c}},      setlayout,      {.v = &layouts[6]} },
        // Centerd floating master layout
	{2, {{MODKEY, XK_s},           {ShiftMask, XK_c}},      setlayout,      {.v = &layouts[7]} },

        // Toggle between current layout and tile layout  
	{2, {{MODKEY, XK_s},             {0, XK_space}},  setlayout,      {0} },
        // Toggle floating window
	{1, {{MODKEY|Mod1Mask,           XK_f}},        togglefloating,     {0} },
        // View all tags
	{1, {{MODKEY,                    XK_0}},        view,           {.ui = ~0 } },
        // Mirror the current tagg in all tags
	{1, {{MODKEY|ShiftMask,          XK_0}},        tag,            {.ui = ~0 } },
        // I don't know
	{1, {{MODKEY,                    XK_comma}},    focusmon,       {.i = -1 } },
	{1, {{MODKEY,                    XK_period}},   focusmon,       {.i = +1 } },
	{1, {{MODKEY|ShiftMask,          XK_comma}},    tagmon,         {.i = -1 } },
	{1, {{MODKEY|ShiftMask,          XK_period}},   tagmon,         {.i = +1 } },
        /************************* Tag keys *************************/
	TAGKEYS(                         XK_1,                      0)
	TAGKEYS(                         XK_2,                      1)
	TAGKEYS(                         XK_3,                      2)
	TAGKEYS(                         XK_4,                      3)
	TAGKEYS(                         XK_5,                      4)
	TAGKEYS(                         XK_6,                      5)
	TAGKEYS(                         XK_7,                      6)
	TAGKEYS(                         XK_8,                      7)
	TAGKEYS(                         XK_9,                      8)
        TAGKEYS(                         XK_semicolon,              9)
	/* ---------------------------------- Control Keys ---------------------------------- */
	// Brightness controllers (requires xbacklight)
	{1, {{0,                               XF86XK_MonBrightnessUp}},   spawn, SHCMD("xbacklight -inc 5") },
	{1, {{0,                               XF86XK_MonBrightnessDown}}, spawn, SHCMD("xbacklight -dec 5") },
	// Sound controllers (requires pamixer)
	{1, {{0,                               XF86XK_AudioRaiseVolume}}, spawn, SHCMD("pamixer --allow-boost -i 4") },
	{1, {{0,                               XF86XK_AudioLowerVolume}}, spawn, SHCMD("pamixer --allow-boost -d 4") },
	{1, {{0,                               XF86XK_AudioMute}},        spawn, SHCMD("pamixer -t") },
	// Media controls (requires playerctl)
	{1, {{0,                               XF86XK_AudioPlay}},	 spawn,	SHCMD("playerctl play-pause") },
	{1, {{0,                               XF86XK_AudioStop}},       spawn, SHCMD("playerctl stop") },
	{1, {{0,                               XF86XK_AudioNext}},	 spawn,	SHCMD("playerctl next") },
	{1, {{0,                               XF86XK_AudioPrev}},	 spawn,	SHCMD("playerctl previous")  },
        // Mute and unmute mic
	{1, {{0,			       XF86XK_AudioMicMute}},	spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	// Take a screenshot
	{1, {{0,			       XK_Print}},		spawn, SHCMD(SCREENSHOT) },
	/* ---------------------------------- lock Keys ---------------------------------- */
	// Lock the screen
	{1, {{MODKEY|ShiftMask,    	       XK_x}},     spawn,          SHCMD("betterlockscreen -l dim") },
	{1, {{0,                     XF86XK_Suspend}},     spawn,          SHCMD("betterlockscreen -l dim") },
	// Kill dwm (super + shift + alt + q)
	{1, {{MODKEY|ShiftMask|Mod1Mask,       XK_q}},      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

