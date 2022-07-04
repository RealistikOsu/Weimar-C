#include "reader.h"
#include <string.h>

// TODO: Macro this possibly?

void read_uint8(uint8_t* value, uint8_t** buffer) {
    *value = **buffer;
    (*buffer)++;
}

void read_uint16(uint16_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(uint16_t));
    (*buffer) += sizeof(uint16_t);
}

void read_uint32(uint32_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(uint32_t));
    (*buffer) += sizeof(uint32_t);
}

void read_uint64(uint64_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(uint64_t));
    (*buffer) += sizeof(uint64_t);
}

void read_int16(int16_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(int16_t));
    (*buffer) += sizeof(int16_t);
}

void read_int32(int32_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(int32_t));
    (*buffer) += sizeof(int32_t);
}

void read_int64(int64_t* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(int64_t));
    (*buffer) += sizeof(int64_t);
}

void read_float(float* value, uint8_t** buffer) {
    memcpy(value, *buffer, sizeof(float));
    (*buffer) += sizeof(float);
}

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
