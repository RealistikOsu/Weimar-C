#ifndef WEIMAR_SERVER_H
#define WEIMAR_SERVER_H

#include <stdint.h>
#include "../user/user.h"
#define MAX_USERS 200

typedef struct {
    User* users[MAX_USERS];
    uint8_t user_count;
} Server;

Server* server_init();
Server* server_get();
void add_server_user(Server* server, User* user);
void remove_server_user(Server* server, User* user);

#endif // WEIMAR_SERVER_H
