#ifndef WEIMAR_USER_H
#define WEIMAR_USER_H

#include <stdint.h>
#include "buffer.h"
#include "../constants/mode.h" // Not sure if I should be including this here

// A 2D position vector.
struct Position {
    float x;
    float y;
};

// A structure representing user stats. All types (unless specified)
// correspond to types used in packets.
typedef struct {
    int64_t total_score;
    int64_t ranked_score;
    uint16_t pp; // i16 in packets.
    int32_t play_count;
    float accuracy;
    uint16_t max_combo;
    int32_t rank;
} Stats;

typedef struct {
    // Identity
    uint16_t id;
    char* name; // Possibly specify a max length.
    char* safe_name;
    char* password_bcrypt;
    Stats stats[MODE_AP_STD + 1];

    // Live state
    uint8_t country;
    char* uuid; // Possibly also specify max len as we have control over this
    UserBuffer* buffer;
    Position position;

    // Action
    uint8_t action_id; // Either use enum of #define
    char* action_str;
    char* action_bmap_md5;
    int32_t action_bmap_id;
    uint32_t action_mods;
} User;

// Creates an example user for testing purposes.
User* user_create_test(char* name);

// Sets the user action, freeing the previous values.
void set_action(
    User* user,
    uint8_t action_id,
    char* action_str,
    char* action_bmap_md5,
    int32_t action_bmap_id,
    uint32_t action_mods
);


#endif // WEIMAR_USER_H