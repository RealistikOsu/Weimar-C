#ifndef WEIMAR_HTTP_H
#define WEIMAR_HTTP_H

#include <stdint.h>

typedef struct {
    // The user token used to identify the user.
    char token[17];
    // References of the body inside the http buffer.
    char* packet_buffer;
    // Referenced the end of the body inside the http buffer.
    char* packet_buffer_end;

} Request;

#endif // WEIMAR_HTTP_H
