#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

void Compression(unsigned char *sizeOut, const char *Message_size) {  
    
	unsigned long long Buffer = 0;  
	char Bits = 0;
	
	while (*Message_size != 0) {
		Buffer |= (unsigned long long)(*Message_size++) << Bits;
		Bits += 7;
		if (Bits == 7 * 8) { 
			while (Bits > 0) {
				*sizeOut++ = Buffer;
				Buffer >>= 8;
				Bits -= 8;
			}
			Bits = 0;
			Buffer = 0;
		}
	}
	while (Bits > 0) {
		*sizeOut++ = Buffer;
		Buffer >>= 8;
		Bits -= 8;
	}
}


void Decompression (char *Out_size, const unsigned char *Compressed_size, unsigned CompressedLength) {
    
	unsigned long long Buffer = 0;
	char Bits = 0;
	while (CompressedLength) {
		while (CompressedLength && Bits < 7 * 8) {
			Buffer |= (unsigned long long)*Compressed_size++ << Bits;
			Bits += 8;
			--CompressedLength;
		}
		while (Bits > 0) {
			*Out_size++ = Buffer & 0x7F;
			Buffer >>= 7;
			Bits -= 7;
		}
		
		Bits = 0;
		Buffer = 0;
	}
}


int main(void) {
    
    
    clock_t begin = clock();
    
    int letters;
    
    //printf("Creator: Ceyhun Kivanc Demir, data compressor and decompressor\n\n");
    
    
    /*
    
    
    FILE *file;
    char filename[100]="Please Enter the name of file:";	
    printf("\n\nPlease Enter the name of file: ");
    scanf("%99s",filename);
    file=fopen(filename,"r");
    if(file==NULL){
		printf("\n%s File not found.\n\n",filename, strerror(errno));
		exit(1);
	}
	
	    
    
   
    fseek(file, 0, SEEK_END);
    long count = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    */
    
    char Message[] = "Accelerometer Reading : X:0.004395 Y:-0.004883 Z:1.009766 Gyrometer Reading X:0.304878 Y:0.121951 Z:1.58537\n";
    
    
    //fread(Message, strlen(Message)+1, count, file);  
   // Message[count]='\0';
    
	
	unsigned CompressedSize = sizeof(Message)*7/8; 
	unsigned char CompressedBytes[CompressedSize]; 
	char DecompressedSize[sizeof(Message)];
	double ratio = ((double)sizeof(Message)/(double)CompressedSize);
	
	
	printf("\nOirginal Data: %s\n", Message);
	Compression(CompressedBytes, Message);
	//printf("char number of message: %d\n", strlen(Message));

    


	printf("Compressed Data: ");
	for (int Byte = 0; Byte < CompressedSize; ++Byte) {
		printf("%02X ", CompressedBytes[Byte]);
	}
	printf("\n");
	
	
	Decompression(DecompressedSize, CompressedBytes, CompressedSize);
	DecompressedSize[sizeof(Message)] = 0; 
	
	printf("\nDecompressed Data: %s", DecompressedSize);
	//printf("char number of message: %d\n", strlen(DecompressedSize));
	
	if (strcmp(Message, DecompressedSize) == 0) {
		printf("\nCompression done.\n");
	} else {
		printf("\nCompression done!\n");
	}

	//clefclose(file);
    printf("OriginalBytes: %d\n", sizeof(Message)); // checking
    printf("CompressedBytes: %d\n", CompressedSize); // checking
    printf("decompressedBytes: %d\n", strlen(DecompressedSize)); // checking
    printf("Compression ratio: %.2f percent\n", ratio); // checking
	//printf("ComprBytes: %d\n", strcmp(Message, DecompressedSize));
	clock_t end = clock();
    printf("Execution time: %f [seconds]", ((double) (end - begin) / CLOCKS_PER_SEC));
    

	return 0;
}