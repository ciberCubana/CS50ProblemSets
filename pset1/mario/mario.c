#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    

    do {
        printf("Height: \n");
        h = GetInt();
    }
    while (h < 0 || h > 23);
    
    for(int i = 1; i <= h; i++){
        for(int spaces = 0; spaces < h-i; spaces++){
            printf(" ");
        }
        for(int number=0;number<1+i;number++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}