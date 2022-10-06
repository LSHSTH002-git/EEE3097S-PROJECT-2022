#ifndef XOR_ALGO_H
#define XOR_ALGO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aXor(char buffer[], char compressed[]){
    
    char xorKey = 'A';

    int len = strlen(compressed);

    for(int i = 0; i< len; i++){
        buffer[i] = compressed[i] ^ xorKey;
    }


}

void dXor(char buffer[], char Encrypted[]){
    char xorKey = 'A';//this is the password, if wrong then algorithm is doomed.

    int len = strlen(Encrypted);

    for(int i = 0; i< len; i++){
        buffer[i] = Encrypted[i] ^ xorKey;
    }
}

#endif
