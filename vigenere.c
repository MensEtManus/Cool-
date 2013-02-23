/*************************************
*vigenere.c
*
*Harvard CS50
*Hongbo Yang
*
*encrypts the text using Vigerene cypher
*print out the result
*
****************************************/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    string key = argv[1];
    if (argc != 2) //test if the user has given us only one command-line argument
    {
        printf("\n");
        return 1;
    }
    else           //test if the command-line argument is composed of entirely alphabetical characters
    {
        for(int i = 0; i < strlen(key); i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Please enter a string of plain text! \n");
                return 1;
            }
        }
    }
    
    string text = GetString(); //ask the user for a plain text
    int j = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        int index; 
        index = (j % strlen(key));
                    
        if (isupper(text[i]))  //if the letter in the text is upper case, the translation code is 65
        {                       // because the ASCII # of "A" is 65
            if (isupper(key[index]))  // if the letter of key at the index is upper case, then minus 65 to get 
            {                           //the final key[index]
                int c_u = (text[i] + key[index] - 65 -65) % 26;
                text[i] = c_u + 65;
            }
            else if (islower(key[index]))
            {
                int c_u = (text[i] + key[index] - 65 -97) % 26;
                text[i] = c_u + 65;
            }
            j++;
        }
        else if (islower(text[i]))  // the same reason for lower case letters
        {   
            if (isupper(key[index]))
            {
                int c_l = (text[i] - 97 + key[index] - 65) % 26;
                text[i] = c_l + 97;
            }
            else if (islower(key[index]))
            {
                int c_l = (text[i] - 97 + key[index] - 97) % 26;
                text[i] = c_l + 97;
            }
            j++;
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


