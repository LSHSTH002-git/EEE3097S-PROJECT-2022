/*===========================================================================================================================================================
  Author      :S'thabiso Lushaba
  Date        :Sept 2022
  Description : Encrypts/Decrypts stdio using AES(rijndael-128) encryption algorithm.

 =============================================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcrypt.h>
#include <math.h>
#include <stdint.h>
#include<time.h>

int encrypt(
    void* buffer,
    int buffer_len, /* Because the plaintext could include null bytes*/
    char* IV, 
    char* key,
    int key_len 
){
  MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  int blocksize = mcrypt_enc_get_block_size(td);
  if( buffer_len % blocksize != 0 ){return 1;}

  mcrypt_generic_init(td, key, key_len, IV);
  mcrypt_generic(td, buffer, buffer_len);
  mcrypt_generic_deinit (td);
  mcrypt_module_close(td);
  
  return 0;
}

int decrypt(
    void* buffer,
    int buffer_len,
    char* IV, 
    char* key,
    int key_len 
){
  MCRYPT td = mcrypt_module_open("rijndael-128", NULL, "cbc", NULL);
  int blocksize = mcrypt_enc_get_block_size(td);
  if( buffer_len % blocksize != 0 ){return 1;}
  
  mcrypt_generic_init(td, key, key_len, IV);
  mdecrypt_generic(td, buffer, buffer_len);
  mcrypt_generic_deinit (td);
  mcrypt_module_close(td);
  
  return 0;
}

void display(char* ciphertext, int len){
  int v;
  for (v=0; v<len; v++){
    printf("%d ", ciphertext[v]);
  }
  printf("\n");
}

int main()
{
  clock_t start_t, end_t;
  double total_t;
  int i;

  

  char line[256];
  char* IV = "AAAAAAAAAAAAAAAA";
  char* key = "0123456789abcdef";
  int keysize = 16; // 128 bits 

  FILE *fpointer;
  fpointer = fopen("TestFileData.txt","r");
/*===========================================================================================================================================================
  Encrpt and Decrypt the Data, output in the command line to show it is working.
  =============================================================================================================================================================*/
  printf("plain Data:\n");
  while(!feof(fpointer))
  {
    fgets(line,256,fpointer);
    

  }
  printf("%s\n", line);
  fclose(fpointer); 

  //ENCRYPT THE DATA
  start_t = clock();
  encrypt(line,256,IV,key,keysize);
  printf("Cipher Text:\n");display(line , 256);


  //DECRYPT THE DATA 
  printf("Decrypted Text:\n");
  decrypt(line,256,IV,key,keysize);
  printf("%s\n",line);
  end_t = clock();

  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Total time taken by CPU: %f\n", total_t  );
  printf("Exiting of the program...\n");


  MCRYPT td, td2;
  
  
  //char* plaintext = "test text 123";
  /*char* buffer;
  int buffer_len = 16;*

  buffer = calloc(1, buffer_len);
  strncpy(buffer, line, buffer_len);

  printf("==C==\n");
  printf("plain:   %s\n", line);
  encrypt(buffer, buffer_len, IV, key, keysize); 
  printf("cipher:  "); display(buffer , buffer_len);
  decrypt(buffer, buffer_len, IV, key, keysize);
  printf("decrypt: %s\n", buffer);
  */
  return 0;
}
