/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main()
{
   
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        fclose(card);
        printf("Error...can't open the file\n");
        return 2;
    }
    
    uint8_t iniciojpg[4] = {0xff, 0xd8, 0xff, 0xe0};
	uint8_t iniciojpg2[4] = {0xff, 0xd8, 0xff, 0xe1};
    
    int count = 0;
    int open = 0;
	FILE* out;

		uint8_t buffer[512];
		uint8_t isjpg[4];
		fread(buffer, 512, 1, card);	

		while(fread(buffer, 512, 1, card) > 0)
		{
		    for(int i = 0; i < 4; i++)
				{
						isjpg[i] = buffer[i];
				}
				if((memcmp(iniciojpg, isjpg, 4) == 0 ) || (memcmp(iniciojpg2, isjpg, 4) == 0))
				{
						
						char newfoto[8];
						sprintf(newfoto, "%03d.jpg", count);

						if(open == 0)
						{
								out = fopen(newfoto, "w");
								fwrite(buffer, sizeof(buffer), 1, out);
								open = 1;
						}
						if(open == 1)
						{
								fclose(out);
								out = fopen(newfoto, "w");
								fwrite(buffer, sizeof(buffer), 1, out);
								count++;
						}
				}
				else
				{
						if(open == 1)
						{
								fwrite(buffer, sizeof(buffer), 1, out);
						}
				}
		}
    
	
    if(out)
    {
      fclose(out);
    }

		fclose(card);
		return 0;
}

