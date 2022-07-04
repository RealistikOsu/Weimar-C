#include "buffer.h"

#define BUFFER_SIZE 5120

UserBuffer* create_buffer() {
    UserBuffer* buffer = malloc(sizeof(UserBuffer));
    buffer->data = malloc(BUFFER_SIZE);
    buffer->start = buffer->data;
    return buffer;
}

void empty_buffer(UserBuffer* buffer) {
    // we are writing over the old data.
    buffer-> data = buffer-> start;
}

void free_buffer(UserBuffer* buffer) {
    free(buffer->start);
    free(buffer);
}
