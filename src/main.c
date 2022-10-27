#include <stdlib.h>
#include "nanolib.h"
#include "player1Movements.h"
#include "player2Movements.h"
#include "ballMovement.h"


int main()
{   
    init_input_GPIO(D6, PULLUP);
    init_USART0();
    init_pin_ADC(A4);
    init_master_SPI(SPI_MODE_0, SPI_MSB_FIRST, SPI_PRESCALER_128);
    init_MAX7219();
    clear_MAX7219();    
    init_ADC(ADC_AVCC, ADC_RIGHT_ADJUST, ADC_PRESCALER_128);
    init_pin_ADC(A5);
    init_pin_ADC(A7);
    srand(analog_read(A4));
    t_ball ball ;
    uint32_t last_refresh= get_time();
    uint32_t refresh_time=250;
    init_time();
    int launch=0;
    
    for (;;)
    {   
        while (!launch){
            uint8_t player1Pos= player1Movements();
            uint8_t player2Pos= player2Movements();
            if (!read_input_GPIO(D6)){
                launch=1;
                ball.x=(rand()%2)+4;
                ball.y=(rand()%2)+4;
                ball.xDirection=rand()%2;
                ball.yDirection=rand()%3;
                
            }
        }
        
        sei();
        uint8_t player1Pos= player1Movements();
        uint8_t player2Pos= player2Movements();
        uint32_t now= get_time();
        if (now-last_refresh>refresh_time)
        {   
           write_column_MAX7219(ball.x, 0b00000000);
           ball = ballMovement(ball, player1Pos, player2Pos); 
           last_refresh=now;
        }
        if(ball.x==1 || ball.x==8){
            launch=0;
        }
    }

    return 0;
}