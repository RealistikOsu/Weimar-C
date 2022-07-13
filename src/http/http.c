// A really cursed HTTP server made specifically for a bancho. It will not support anything else.
// It is recommended to use Nginx on top of this as your proxy.

#include <sys/socket.h>
#include "http.h"

// 1kb buffer for reading http
#define HTTP_BUFFER_SIZE 1024

char* DEFAULT_RESPONSE = "HTTP/1.1 200 OK\r\nContent-Length: 19\r\n\r\nPowered by Weimar-C\r\n";

void handle_request() {
    char* buffer = malloc(HTTP_BUFFER_SIZE);
    // TODO: Buffer reading


    // Parsing the buffer.
}

// MySQL is 
