#ifndef colors_H
#define colors_H

static const char norm_fg[] = "#e4ded4";
static const char norm_bg[] = "#191b1f";
static const char norm_border[] = "#282c34";

static const char sel_fg[] = "#e4ded4";
static const char sel_bg[] = "#3f2124";
static const char sel_border[] = "#e4ded4";

static const char urg_fg[] = "#e4ded4";
static const char urg_bg[] = "#313036";
static const char urg_border[] = "#312e36";

static const char *colors[][3] = {
        /*               fg           bg         border                         */
        [SchemeNorm] = {norm_fg, norm_bg, norm_border}, // unfocused wins
        [SchemeSel]  = {sel_fg, sel_bg, sel_border},  // the focused win
        [SchemeUrg] =  {urg_fg, urg_bg, urg_border},
};

#endif // colors_H
