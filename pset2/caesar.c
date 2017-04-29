#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    
    bool keyFlag = false;
    int key = 0;
    string text = "";
    int l = 0;
    
    
    
    do
    {
        
        if(argc != 2)
        {
          
            printf("It's require an integer as your encryption key.\n");
            return 1;
        }
        else
        {
            
            key = atoi(argv[1]);
            keyFlag = true;
        }
    } while(!keyFlag);
    
    
    text = GetString();
    l = strlen(text);
    for(int i = 0; i < l; i++)
    {
        
        if(isalpha(text[i]))
        {
            
            if(islower(text[i]))
            {
               printf("%c", ((((text[i] - 97)+key)%26)+97));
             
            }
            // Work with upper case characters
            else
            {
                printf("%c", ((((text[i] - 65)+key)%26)+65));
             
            }
        }
        
        else
        {
            printf("%c", text[i]);
        }
    }
    
    printf("\n");
    return 0;  
}