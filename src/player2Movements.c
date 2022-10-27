
   
#include "nanolib.h"
#include "player1Movements.h"

uint8_t player2Movements(){
    
    if (analog_read(A7) < 170)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b11100000);
        return 0b11100000;
    }
    else if (analog_read(A7) < 340)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b01110000);
        return 0b01110000;
    }
    else if (analog_read(A7) < 510)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00111000);
        return 0b00111000;
    }
     else if (analog_read(A7) < 680)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00011100);
        return 0b00011100;
    }
    else if (analog_read(A7) < 850)
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00001110);
        return 0b00001110;
    }
    else
    {
        write_column_MAX7219(MAX7219_COLUMN7, 0b00000111);
        return 0b00000111;
    }
    
}
