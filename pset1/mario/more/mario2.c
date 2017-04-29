#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    printf("Please enter the height of the pyramid, note that Mario can't climb more than 23 steps\n");

    do {
        
        h = get_int();
    }
    while (h < 0 || h > 23);
    
    for(int i = 0; i< h; i++){
        for(int spaces = 0; spaces < h-i;spaces++){
            printf(" ");
        }
        for(int number=0;number<2+i;number++){
            printf("#");
            
        }
        printf("  ");
        for(int ln=2+i;ln > 0;ln--){
            printf("#");
        }
        printf("\n");
    }
}