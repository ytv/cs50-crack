#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

#define SALT_LEN         2
#define MAX_PW_LEN       8
#define DICTIONARY_PATH  "/usr/share/dict/words"

typedef uint8_t  BYTE;

bool compare_PW(char * POTENTIAL_PW, const char * CIPHERED_PW);
void brute(const char * CIPHERED_PW, bool * cracked, char * SALT);

int main(int argc, string argv[])
{
    const char * CIPHERED_PW = argv[1];
    char * SALT = malloc( ((SALT_LEN)+1) * sizeof(char));
    SALT[0] = CIPHERED_PW[0];
    SALT[1] = CIPHERED_PW[1];
    SALT[2] = '\0';
    bool cracked = false;
    
    // printf("%s\n", SALT);
    // printf("%s\n", CIPHERED_PW);
    
    //check for correct arguments
    if(argc != 2)
    {
        printf("ERROR 1: please enter ONE command-line argument\n");
        return 1;
    }
/*    
    //dictionary attack    
    FILE * DICTIONARY = fopen(DICTIONARY_PATH, "r");
    char buffer[MAX_PW_LEN+1];
    
    if(DICTIONARY == NULL)
    {
        printf("ERROR 2: dictionary file does not exist\n");
        return 2;
    }
    
    while(fgets(buffer, sizeof(buffer), DICTIONARY) != NULL)
    {
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
            
        if(compare_PW(crypt(buffer, SALT), CIPHERED_PW))
        {
            printf("%s\n", buffer);
            cracked = true;
            break;
        }
    }
    
    fclose(DICTIONARY); 
*/    
    // brute force attack
    brute(CIPHERED_PW, &cracked, SALT);

    if(cracked == false)
        printf("Crack was unsuccessful\n");
    else
        printf("Crack successful\n");
        
    return 0;
}

bool compare_PW(char * POTENTIAL_PW, const char * CIPHERED_PW)
{
    if(strcmp(POTENTIAL_PW, CIPHERED_PW) == 0)
        return true;
    else
        return false; 
}

void brute(const char * CIPHERED_PW, bool * cracked, char * SALT)
{
    char s[MAX_PW_LEN] = {0};
    
    int upBound = 122; //"a" to "b": 97 to 122
    int lowBound = 97; // all printable ASCII characters: 32 to 126
    
    for(int int8 = lowBound; int8 <= upBound; int8++)
    {  
        for(int int7 = lowBound; int7 <= upBound; int7++)
        { 
            for(int int6 = lowBound; int6 <= upBound; int6++)
            {
                for(int int5 = lowBound; int5 <= upBound; int5++)
                {
                    for(int int4 = lowBound; int4 <= upBound; int4++)
                    {
                        for(int int3 = lowBound; int3 <= upBound; int3++)
                        {
                            for(int int2 = lowBound; int2 <= upBound; int2++)
                            {
                                for(int int1 = lowBound; int1 <= upBound; int1++)
                                {
                                    s[0] = (char)int1; 
                                    //char * s = "crimson";
                                    
                                    if(compare_PW(crypt(s, SALT), CIPHERED_PW))
                                    {
                                        printf("%s\n",s);
                                        *cracked = true;
                                        break;
                                    }
                                }
                                if (*cracked == true)
                                    break;
                                s[1] = (char)int2;
                             }
                             s[2] = (char)int3;
                             if (*cracked == true)
                                    break; 
                         }
                         s[3] = (char)int4; 
                         if (*cracked == true)
                                    break;
                     }
                     s[4] = (char)int5;
                     if (*cracked == true)
                         break; 
                 } 
                 s[5] = (char)int6; 
                 if (*cracked == true)
                     break;
             } 
             s[6] = (char)int7; 
             if (*cracked == true)
                 break;
         }
         s[7] = (char)int8; 
         if (*cracked == true)
             break;
     } 
}
