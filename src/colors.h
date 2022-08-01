#ifndef colors_H
#define colors_H

#define wal "/home/anas/.cache/wal/colors-wal-dwm.h"

#if __has_include(wal)
#include wal
#else
static const char norm_fg[] = "#e4ded4";
static const char norm_bg[] = "#071F33";
static const char norm_border[] = "#9f9b94";

static const char sel_fg[] = "#e4ded4";
static const char sel_bg[] = "#3484C8";
static const char sel_border[] = "#e4ded4";

static const char urg_fg[] = "#e4ded4";
static const char urg_bg[] = "#4F86B6";
static const char urg_border[] = "#4F86B6";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    [schemeurg] =  { urg_fg,      urg_bg,    urg_border },
};
#endif

#endif // !colors.h
