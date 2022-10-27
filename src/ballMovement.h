#include <stdint.h>

typedef struct s_ball{
    uint8_t x;
    uint8_t y;
    uint8_t xDirection;
    uint8_t yDirection;
} t_ball;
t_ball ballMovement(t_ball ball, uint8_t player1, uint8_t player2);