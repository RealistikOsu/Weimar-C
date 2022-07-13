#include "reader.h"
#include <string.h>

void read_uleb128(uint32_t* value, uint8_t** buffer) {
    uint32_t result = 0;
    uint8_t shift = 0;
    do {
        uint8_t byte = **buffer;
        (*buffer)++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
    } while ((**buffer & 0x80) != 0);
    *value = result;
}

// TODO: Maybe take a pointer to a char*?
char* read_string(uint8_t** buffer) {
    uint32_t length;
    read_uleb128(&length, buffer);
    char* string = malloc(length + 1);
    memcpy(string, *buffer, length);
    string[length] = '\0';
    (*buffer) += length;
    return string;
}
