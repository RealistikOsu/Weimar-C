#include "buffer.h"
#include "../utils/macros.h"

#define USER_BUFFER_SIZE 5120

UserBuffer* create_buffer() {
    UserBuffer* buffer = HEAP_ALLOC(UserBuffer);
    buffer->data = malloc(USER_BUFFER_SIZE);
    buffer->start = buffer->data;
    return buffer;
}

void empty_buffer(UserBuffer* buffer) {
    buffer->data = buffer->start;
    // Zero out the old data
    memset(buffer->data, 0, USER_BUFFER_SIZE);
}

void free_buffer(UserBuffer* buffer) {
    free(buffer->start);
    free(buffer);
}
