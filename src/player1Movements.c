#include "nanolib.h"
#include "player2Movements.h"

uint8_t player1Movements()
{
    if (analog_read(A5) < 170)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b11100000);
        return 0b11100000;
    }
    else if (analog_read(A5) < 340)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b01110000);
        return 0b01110000;
    }
    else if (analog_read(A5) < 510)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00111000);
        return 0b00111000;
    }
     else if (analog_read(A5) < 680)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00011100);
        return 0b00011100;
    }
    else if (analog_read(A5) < 850)
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00001110);
        return 0b00001110;
    }
    else
    {
        write_column_MAX7219(MAX7219_COLUMN0, 0b00000111);
        return 0b00000111;
    }


}