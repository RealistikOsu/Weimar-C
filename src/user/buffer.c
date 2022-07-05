#include "buffer.h"

#define BUFFER_SIZE 5120

UserBuffer* create_buffer() {
    UserBuffer* buffer = malloc(sizeof(UserBuffer));
    buffer->data = malloc(BUFFER_SIZE);
    buffer->start = buffer->data;
    return buffer;
}

void empty_buffer(UserBuffer* buffer) {
    buffer->data = buffer->start;
    // Zero out the old data
    memset(buffer->data, 0, BUFFER_SIZE);
}

void free_buffer(UserBuffer* buffer) {
    free(buffer->start);
    free(buffer);
}
