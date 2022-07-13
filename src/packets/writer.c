#include "writer.h"
#include <string.h>

void write_uint8(uint8_t* value, uint8_t** buffer) {
    **buffer = *value;
    (*buffer)++;
}

void write_uint16(uint16_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(uint16_t));
    (*buffer) += sizeof(uint16_t);
}

void write_uint32(uint32_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(uint32_t));
    (*buffer) += sizeof(uint32_t);
}

void write_uint64(uint64_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(uint64_t));
    (*buffer) += sizeof(uint64_t);
}

void write_int16(int16_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(int16_t));
    (*buffer) += sizeof(int16_t);
}

void write_int32(int32_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(int32_t));
    (*buffer) += sizeof(int32_t);
}

void write_int64(int64_t* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(int64_t));
    (*buffer) += sizeof(int64_t);
}

void write_float(float* value, uint8_t** buffer) {
    memcpy(*buffer, value, sizeof(float));
    (*buffer) += sizeof(float);
}

void write_uleb128(uint32_t* value, uint8_t** buffer) {
    // Make a copy of value
    uint32_t v = *value;

    do {
        uint8_t byte = v & 0x7f;
        v >>= 7;
        if (v != 0) {
            byte |= 0x80;
        }
        write_uint8(&byte, buffer);
    } while (v != 0);    
}

void write_string(char* value, uint8_t** buffer) {
    uint32_t length = strlen(value);

    // Exists byte
    if (length > 0) {
        write_u8(0xb, buffer);
        write_uleb128(&length, buffer);
        memcpy(*buffer, value, length);
        (*buffer) += length;
    }
    else {
        write_u8(0, buffer);
    }
}
