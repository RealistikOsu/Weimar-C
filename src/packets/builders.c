#include "builders.h"
#include "../user/buffer.h"

void write_simple_packet(UserBuffer* buffer, uint8_t packet_id) {
    *buffer->data = packet_id;
    buffer->data += HEADER_LEN;
}
