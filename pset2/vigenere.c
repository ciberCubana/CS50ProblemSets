#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    
    int final_cod;
    int keyVal;

   
    if (argc != 2)
    {
        printf("It's require a string as your encryption key.\n");
        return 1;
    }
    
    string key = argv[1]; 
    int keylength = strlen(argv[1]);

    for (int i = 0; i < keylength; i++)
    {
        if ((key[i] >= '0') && (key[i] <= '9'))
        {
            printf("Upsss...the keyword must to be a word without numbers.\n");
            return 1;
        }
    }

    string textToCode = GetString();  
    int length = strlen(textToCode);

    for(int i = 0, j = 0; i < length; i++, j++)
    {
        if (j >= keylength)
        {
            j = 0;
        }
        keyVal = key[j]; 
        if (!isalpha(textToCode[i]))
        {
            j = (j - 1);
        }  

        
        if ((keyVal >= 'A') && (keyVal <=  'Z'))
        {
            keyVal = (keyVal -  'A');
        }

        
        if ((keyVal >= 'a') && (keyVal <= 'z'))
        {
            keyVal = (keyVal - 'a');
        }

        
        final_cod = (textToCode[i] + keyVal);

        if (isupper(textToCode[i]) && (final_cod > 'Z'))
        {
            final_cod = (final_cod - 26);
        }

        if (islower(textToCode[i]) && (final_cod > 'z'))
        {
            final_cod = (final_cod - 26);
        }

        
        if (isalpha(textToCode[i]))
        {
            printf("%c", final_cod);
        }

         
        else
        {
            printf("%c", textToCode[i]);
        }

    }  
    printf("\n");
    return 0;
}
