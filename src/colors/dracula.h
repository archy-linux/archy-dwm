//
// Created by anas on 10/31/22.
//
// inspired from: https://github.com/0x73hahd/dwm-config/blob/dev/source/colors/dracula.h

#ifndef DRACULA_H
#define DRACULA_H

static const char norm_fg[] = "#ff79c6";
static const char norm_bg[] = "#282a36";
static const char norm_border[] = "#282a36";

static const char sel_fg[] = "#ffb86c";
static const char sel_bg[] = "#282a36";
static const char sel_border[] = "#ffb86c";

static const char urg_fg[] = "#e4ded4";
static const char urg_bg[] = "#313036";
static const char urg_border[] = "#312e36";

static const char *colors[][3] = {
        /*               fg           bg         border                         */
        [SchemeNorm] = {norm_fg, norm_bg, norm_border}, // unfocused wins
        [SchemeSel]  = {sel_fg, sel_bg, sel_border},  // the focused win
        [SchemeUrg] =  {urg_fg, urg_bg, urg_border},
};

#endif //DRACULA_H
