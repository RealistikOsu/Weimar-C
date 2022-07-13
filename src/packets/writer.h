#ifndef WEIMAR_WRITER_H
#define WEIMAR_WRITER_H

#include <stdint.h>

void write_uint8(uint8_t* value, uint8_t** buffer);
void write_uint16(uint16_t* value, uint8_t** buffer);
void write_uint32(uint32_t* value, uint8_t** buffer);
void write_uint64(uint64_t* value, uint8_t** buffer);
void write_int16(int16_t* value, uint8_t** buffer);
void write_int32(int32_t* value, uint8_t** buffer);
void write_int64(int64_t* value, uint8_t** buffer);
void write_float(float* value, uint8_t** buffer);

void write_uleb128(uint32_t* value, uint8_t** buffer);
void write_string(char* value, uint8_t** buffer);

#endif // WEIMAR_WRITER_H