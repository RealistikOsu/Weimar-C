#ifndef WEIMAR_MODE_CONST_H
#define WEIMAR_MODE_CONST_H

#define MODE_VN_STD 0
#define MODE_VN_TAIKO 1
#define MODE_VN_CTB 2
#define MODE_VN_MANIA 3

#define MODE_RX_STD 4
#define MODE_RX_TAIKO 5
#define MODE_RX_CTB 6

#define MODE_AP_STD 7

// Converts a mode + cmode enum to a pure mode enum.
#define MODE_AS_VN(mode) mode == MODE_AP_STD ? mode % 4 : MODE_VN_STD

#define CMODE_VN 0
#define CMODE_RX 1
#define CMODE_AP 2

// Converts a mode + cmode enum to a pure cmode enum.
#define MODE_AS_CMODE(mode) mode == MODE_AP_STD ? mode / 4 : CMODE_VN // Integer division

#endif // WEIMAR_MODE_CONST_H