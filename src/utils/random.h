#ifndef WEIMAR_RANDOM_H
#define WEIMAR_RANDOM_H

#include <stdint.h>

const char* CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
void random_init();
char* random_string(uint8_t length);

#endif // WEIMAR_RANDOM_H