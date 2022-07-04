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
