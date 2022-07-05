#ifndef WEIMAR_USER_H
#define WEIMAR_USER_H

#include <stdint.h>
#include "buffer.h"
#include "../constants/mode.h" // Not sure if I should be including this here

// A 2D position vector.
typedef struct {
    float x;
    float y;
} Position;

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
    char password_bcrypt[61]; // All bcrypt hashes are 60 characters long. +1 for null terminator.
    Stats stats[MODE_AP_STD + 1];

    // Live state
    uint8_t country;
    char uuid[17]; // RealistikThinking moment: Do we need the null terminator since we know the len?
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

// Frees all memory associated with the user.
void free_user(User* user);

// Sets the user action, freeing the previous values.
void set_action(
    User* user,
    uint8_t action_id,
    char* action_str,
    char* action_bmap_md5,
    int32_t action_bmap_id,
    uint32_t action_mods
);

// Writes a 16 char (+ null terminator) to a character buffer.
void generate_uuid(char* uuid);

#endif // WEIMAR_USER_H