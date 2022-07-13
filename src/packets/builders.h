#ifndef WEIMAR_BUILDERS_H
#define WEIMAR_BUILDERS_H

#include <stdint.h>

#define HEADER_LEN 7

// Writes a 0 length packet to the buffer. Very efficient.
// Note packet IDs are usually uint16_t, however they do not exceed
// the size of a uint8_t.
void write_simple_packet(UserBuffer* buffer, uint8_t packet_id);

#endif // WEIMAR_BUILDERS_H
