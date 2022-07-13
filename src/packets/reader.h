#ifndef WEIMAR_READER_H
#define WEIMAR_READER_H

#include <stdint.h>

// Reads an unsigned LEB128 integer from the buffer, incrementing the buffer pointer.
void read_uleb128(uint32_t *value, uint8_t** buffer);

// Reads an ULEB128 prefixed string from the buffer, incrementing the buffer pointer.
// Returns the pointer to the string. Has to be manually freed.
char* read_string(uint8_t** buffer);

// Macro based reader
#define PREAD_NEW(identifier, type, buffer) \
    type identifier; \
    memcpy(&identifier, buffer, sizeof(type)); \
    buffer += sizeof(type);

#define PREAD_INTO_PTR(ptr, type, buffer) \
    memcpy(ptr, buffer, sizeof(type)); \
    buffer += sizeof(type);

#endif // WEIMAR_READER_H
