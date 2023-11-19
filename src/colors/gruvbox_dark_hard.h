//
// Created by anas on 08/28/23.
//
#ifndef GRUVBOX_DARK_HARD_H
#define GRUVBOX_DARK_HARD_H

static const char norm_fg[] = "#D5C4A1"; // light2
static const char norm_bg[] = "#1D2021"; // dark0_hard
static const char norm_border[] = "#504945"; // dark2

static const char sel_fg[] = "#D79921"; // neutral_yellow
static const char sel_bg[] = "#1D2021"; // dark0_hard
static const char sel_border[] = "#7C6F64"; // dark4

static const char urg_fg[] = "#D5C4A1"; // light4
static const char urg_bg[] = "#FB4934"; // bright_red
static const char urg_border[] = "#458588"; // neutral_blue

static const char *colors[][3] = {
        /*               fg           bg         border                         */
        [SchemeNorm] = {norm_fg, norm_bg, norm_border}, // unfocused wins
        [SchemeSel]  = {sel_fg, sel_bg, sel_border},  // the focused win
        [SchemeUrg] =  {urg_fg, urg_bg, urg_border},
};

#endif //GRUVBOX_DARK_HARD_H
