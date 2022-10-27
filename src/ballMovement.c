#include "nanolib.h"
#include "ballMovement.h"

t_ball ballMovement (t_ball ball, uint8_t player1, uint8_t player2){;
    uint8_t y_bit;
    
    if (ball.xDirection == 0)
    {
        ball.x--;
    }
    else if (ball.xDirection == 1)
    {
        ball.x++;
    }

    if (ball.yDirection == 1)
    {
        ball.y--;
    }
    else if (ball.yDirection == 2)
    {
        ball.y++;
    }

    if (ball.y == 0){
        write_column_MAX7219(ball.x, 0b00000001);
        y_bit= 0b00000001;
    }
    else if (ball.y==1)
    {
        write_column_MAX7219(ball.x, 0b00000010);
        y_bit= 0b00000010;
    }
    else if (ball.y==2)
    {
        write_column_MAX7219(ball.x, 0b00000100);
        y_bit= 0b00000100;
    }
    else if (ball.y==3)
    {
        write_column_MAX7219(ball.x, 0b00001000);
        y_bit= 0b00001000;
    }
    else if (ball.y==4)
    {
        write_column_MAX7219(ball.x, 0b00010000);
        y_bit= 0b00010000;
    }
    else if (ball.y==5)
    {
        write_column_MAX7219(ball.x, 0b00100000);
        y_bit= 0b00100000;
    }
    else if (ball.y==6)
    {
        write_column_MAX7219(ball.x, 0b01000000);
        y_bit= 0b01000000;
    }
    else
    {
        write_column_MAX7219(ball.x, 0b10000000);
        y_bit= 0b10000000;
    }

    if(ball.x == 2){
        if (player1 & y_bit)  {
            ball.xDirection = 1;
            if(player1 >> 1 & y_bit ){
                if (player1 << 1 & y_bit){
                    ball.yDirection = 0;
                }
                else{
                    if(player1>>2 & y_bit){
                        ball.yDirection = 1;
                    }
                    
             }
             }
             else if (player1<<2 & y_bit){
                        ball.yDirection = 2;
                    }
            }
                
         }
    else if(ball.x == 7){
        if (player2 & y_bit)  { 
            ball.xDirection = 0;
             if(player2 >> 1 & y_bit ){
                if (player2 << 1 & y_bit){
                    ball.yDirection = 0;
                }
                else{
                    if(player2>>2 & y_bit){
                       
                        ball.yDirection = 1;
                    }
                   
             }
             }
              else if (player2<<2 & y_bit){
                        ball.yDirection = 2;
                    }
        }
    }
    if (ball.y == 0){
        ball.yDirection = 2;
    }
    else if (ball.y == 7){
        ball.yDirection = 1;
    }
    
    return ball;
}
