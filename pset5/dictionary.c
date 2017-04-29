/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>

#include <string.h>

#include <cs50.h>


#include "dictionary.h"



/**
 * Returns true if word is in dictionary else false.
 */
 
typedef struct node{
    bool is_word;
    struct node * children[27];
}node;

node * root;

int wc = 0;

void myunload(node* cn)
{
    for(int i = 0; i < 27; i ++)
    {
        if(cn -> children[i] != NULL)
        {
            myunload(cn -> children[i]);
        }
    }
    
    free(cn);
}


bool check(const char* word)
{
    // TODO
   
    node* cn = root;
    
    int i;
    int c;
    
    
    i = 0;
    
    while(cn != NULL)
    {
        c = word[i];
        if(c == '\0')
        {
            return cn -> is_word;
        }
         if(c >= 65 && c < 91)
    {
        c = c + 32;
        c = c - 97;
        
    }   
    else if(c >= 97 && c < 123)
    {
        c = c - 97;
        
    }
    else if(c == 39)
    {
        c = c - 13;
       
    }
    else
    {
        return -1;
    }
        
        
        cn = cn -> children[c];

        i ++;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* d)
{
    FILE* fp = fopen(d,"r");

    if(fp == NULL)
    {
        return false;
    }

    root = calloc(sizeof(node), 1); 
    node* cn;
    cn = root;
    
    
   for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        //int number = convert(c);
        if(c >= 65 && c < 91)
    {
        c = c + 32;
        c = c - 97;
        
    }   
    else if(c >= 97 && c < 123)
    {
        c = c - 97;
        
    }
    else if(c == 39)
    {
        c = c - 13;
       
    }
    else
    {
        return -1;
    }
        
        
        
        if(c != '\n')
        {
            if(cn -> children[c] == NULL)
            {
                cn -> children[c] = calloc(sizeof(node), 1);
                cn = cn -> children[c];
            }
            else 
            {
                cn = cn -> children[c];
            }   
        }        
        else
        {
            cn -> is_word = true;
            wc = wc + 1; 
            cn = root;           
        }
     
    }   
    fclose(fp);    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    
    return wc;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    myunload(root);
    return true;
}


