#include "server.h"
#include "../utils/macros.h"

Server* server;

Server* server_init() {
    server = HEAP_ALLOC(Server);
}

Server* server_get() {
    return server;
}

void add_server_user(Server* server, User* user) {
    server->users[server->user_count++] = user;
}

void remove_server_user(Server* server, User* user) {
    for (uint8_t i = 0; i < server->user_count; i++) {
        if (server->users[i] == user) {
            // We have to move all users 1 index forward.
            for (uint8_t j = i; j < server->user_count - 1; j++) {
                server->users[j] = server->users[j + 1];
            }
            server->user_count--;
            break;
        }
    }
}
