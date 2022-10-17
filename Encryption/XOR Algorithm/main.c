/*===========================================================================================================================================================
  Author      :S'thabiso Lushaba
  Date        :Sept 2022
  Description : Encrypts/Decrypts stdio using XOR encryption algorithm.

 =============================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

int main()
{

    char line [1000];
    char buffer[1000]; //encryption buffer


    FILE *_open;
    _open = fopen("new.txt","r");

    if(_open != NULL)
    {
    while(!feof(_open))
    {
        fgets(line,1000,_open);
    }
    fclose(_open);
    }


    //Assign the contents of the file to the buffer line

    //*************************************************
    //Encryption.

    char xorKey = 'A';
    int len = strlen(line);

    for(int i=0;i<len;i++)
    {
        buffer[i] = line[i]^xorKey;
    }
    //send the encrypted data to a txt file.
    FILE *_send;
    _send = fopen("Encrypted.txt","w");
    fprintf(_send,buffer);

    //*************************************************
    //Decryption.

    int len2 = strlen(buffer);
    //Random keys for demonstration purposes.
    for(int i=0;i<len;i++)
    {
        buffer[i] = buffer[i]^xorKey;
    }
    //send the encrypted data to a txt file.
    FILE *_send2;

    _send2 = fopen("Decrypted.txt","w");
    fprintf(_send2,buffer);
}
