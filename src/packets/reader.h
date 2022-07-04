#ifndef WEIMAR_READER_H
#define WEIMAR_READER_H

#include <stdint.h>

// TODO: Look into using ints for error codes.

// Reads an uint8_t from the buffer, incrementing the buffer pointer.
void read_uint8(uint8_t *value, uint8_t** buffer);
// Reads an uint16_t from the buffer, incrementing the buffer pointer.
void read_uint16(uint16_t *value, uint8_t** buffer);
// Reads an uint32_t from the buffer, incrementing the buffer pointer.
void read_uint32(uint32_t *value, uint8_t** buffer);
// Reads an uint64_t from the buffer, incrementing the buffer pointer.
void read_uint64(uint64_t *value, uint8_t** buffer);
// Reads a int16_t from the buffer, incrementing the buffer pointer.
void read_int16(int16_t *value, uint8_t** buffer);
// Reads a int32_t from the buffer, incrementing the buffer pointer.
void read_int32(int32_t *value, uint8_t** buffer);
// Reads a int64_t from the buffer, incrementing the buffer pointer.
void read_int64(int64_t *value, uint8_t** buffer);
// Reads a float from the buffer, incrementing the buffer pointer.
void read_float(float *value, uint8_t** buffer);

#endif // WEIMAR_READER_H
