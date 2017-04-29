#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    
    
    string name = GetString();
    bool b = true;
    
    
    if(name != NULL){
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            if (name[i] == ' ')
            {
                b = true;
            }
            else 
            {
                if (b)
                {
                    if (name[i] >= 'A' && name[i] <= 'Z')
                    {
                        printf("%c", name[i]);
                    }
                    else if (name[i] >= 'a' && name[i] <= 'z')
                    {
                        printf("%c", name[i] - 'a' + 'A'); 
                    }
                    b = false;
                }
            }
            
        }
    }
    
    printf("\n");
}