#ifndef WEIMAR_BUFFER_H
#define WEIMAR_BUFFER_H

#include <stdint.h>

struct UserBuffer {
    uint8_t* data;
    uint8_t* start;
};

// Creates a new heap allocated buffer of the default size.
UserBuffer* create_buffer();

// Resets the data end pointer to the start of the buffer.
void empty_buffer(UserBuffer* buffer);

// Frees the memory allocated for the buffer. Makes the buffer invalid.
void free_buffer(UserBuffer* buffer);

#endif // WEIMAR_BUFFER_H