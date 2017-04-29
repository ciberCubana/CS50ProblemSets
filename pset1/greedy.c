#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float money;
    int coin_used=0;

    do {
        printf("How much change is owed?\n");
        money = GetFloat();
    }
    while (money < 0);
    
    money*=100;
    money=round(money);
    
   while(money >= 25){
   coin_used++;
   money-=25;
   }
   while(money >= 10){
   coin_used++;
   money-=10;
   }
   while(money >= 5){
   coin_used++;
   money-=5;
   }
   while(money >= 1){
   coin_used++;
   money-=1;
   }
   
    printf("%i\n",coin_used);  
    
}
