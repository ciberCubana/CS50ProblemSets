#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m;
    int b;
    printf("Minutes: ");
    do {
        
        m = get_int();
    }
    while (m < 0);
    
    b = m*12;
    
    printf("Bottles:%i\n",b);
   
}