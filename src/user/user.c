#include "user.h"

void free_user(User* user) {
    free_buffer(user->buffer);
    // TODO: Check if this is the right thing to do.
    free(user->uuid);
    free(user->name);
    free(user->safe_name);
    free(user->action_str);
    free(user->action_bmap_md5);

    free(user);
}

User* allocate_user() {
    User* user = malloc(sizeof(User));
    user->buffer = create_buffer();
    //user->uuid = malloc();
    //user->name = malloc();
    //user->safe_name = malloc();
    //user->action_str = malloc();
    user->action_bmap_md5 = malloc(33);
    return user;
}
