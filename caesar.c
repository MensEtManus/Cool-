/**************************************
*caesar.c
*
*Harvard CS50
*
*Hongbo Yang
*
*prompt the user for a text then encrypt it using Caesar cypher
*print out the result
*
****************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, string argv[])
{
    if (argc != 2)  //test if the user has give us a valid command line argument
    {   
        printf("\n");
        return 1;
    }
    
    string key = argv[1];
    int k = atoi(key);//convert string into an integer key
    
    //printf("Please give me a text: \n");
    string text = GetString();
    
    /*go through each letter in the text
      and encrypt them with caesar cypher*/
      
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))  //if the letter is upper case, the translation code is 65
        {                       // because the ASCII # of "A" is 65
            int c_u = (text[i] - 65 + k) % 26;
            text[i] = c_u + 65;
        }
        else if (islower(text[i]))  // the same reason for lower case letters
        {
            int c_l = (text[i] - 97 + k) % 26;
            text[i] = c_l + 97;
        }
        else                        //if it's not an alphabetical character, don't change it
        {
            text[i] = text[i];
        }
      
    }

    printf("%s", text);  //print out the cyphertext
    printf("\n");
    
    return 0;
}

