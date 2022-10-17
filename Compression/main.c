#include <string.h>
#include "huffman.h"
#include "simple_file_buffer.h"
#include <time.h>
#include <stdlib.h>

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * col)
{
    char ch1, ch2;

    *line = 1;
    *col  = 0;

    do
    {
        // Input character from both files
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);
        
        // Increment line 
        if (ch1 == '\n')
        {
            *line += 1;
            *col = 0;
        }

        // If characters are not same then return -1
        if (ch1 != ch2)
            return -1;

        *col  += 1;

    } while (ch1 != EOF && ch2 != EOF);


    /* If both files have reached end */
    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}

int file_encode(const char *input_file, const char *output_file) {

    struct buffer_ops *in, *out;

    in = create_file_buffer_ops(input_file, "rb");
    if (!in) {
        LOGE("Create input file ops failed\n");
        return 1;
    }
    out = create_file_buffer_ops(output_file, "wb");
    if (!out) {
        LOGE("Create input file ops failed\n");
        goto OUT;
    }
    encode(in, out);
    desotry_file_buffer_ops(out);
OUT:
    desotry_file_buffer_ops(in);
    return 0;
}

int file_decode(const char *input_file, const char *output_file) {

    struct buffer_ops *in, *out;

    in = create_file_buffer_ops(input_file, "rb");
    if (!in) {
        LOGE("Create input file ops failed\n");
        return 1;
    }
    out = create_file_buffer_ops(output_file, "wb");
    if (!out) {
        LOGE("Create input file ops failed\n");
        goto OUT;
    }
    decode(in, out);
    desotry_file_buffer_ops(out);
OUT:
    desotry_file_buffer_ops(in);
    return 0;
}

int main(int argc, char *argv[]) {
    clock_t begin = clock();
    char *input, *output;
    if (argc < 3) {
        LOGE("Miss args.\n");
        LOGE("Usage: -d/-e input [output]\n");
        return 1;
    }
    input = argv[2];
    output = NULL;
    if (argc > 3) {
        output = argv[3];
    }
    if (!strcmp(argv[1], "-e")) {
        file_encode(input, output);
        long int res0;
        FILE* fp0 = fopen(argv[2], "r");
        fseek(fp0, 0L, SEEK_END);
        res0 = ftell(fp0);
        fclose(fp0);
        printf("Size of the original file is %ld bytes \n", res0);

        long int res01;
        FILE* fp01 = fopen(argv[3], "r");
        fseek(fp01, 0L, SEEK_END);
        res01 = ftell(fp01);
        fclose(fp01);
        printf("Size of the compressed file is %ld bytes \n", res01);
        clock_t end = clock();
        // Print execution time
        printf("\n\nExecution time: ");
        printf("%f", ((double) (end - begin) / CLOCKS_PER_SEC));
        printf(" [seconds]");

    } else if (!strcmp(argv[1], "-d")) {
        file_decode(input, output);
        long int res;
        FILE* fp = fopen(argv[2], "r");
        fseek(fp, 0L, SEEK_END);
        res = ftell(fp);
        fclose(fp);
        printf("Size of the compressed file is %ld bytes \n", res);
        long int res1;
        FILE* fp1 = fopen(argv[3], "r");
        fseek(fp1, 0L, SEEK_END);
        res1 = ftell(fp1);
        fclose(fp1);
        printf("Size of the decompressed file is %ld bytes \n", res1);
        clock_t end = clock();
        // Print execution time
        printf("\nExecution time: ");
        printf("%f", ((double) (end - begin) / CLOCKS_PER_SEC));
        printf(" [seconds]\n");
        // ------------------------------------------------------------------------------------------------------------
   /* File pointer to hold reference of input file */
    FILE * fPtr1; 
    FILE * fPtr2;
    char path1[100];
    char path2[100];

    int diff;
    int line, col;


    /* Input path of files to compare */
    printf("Enter path of first file: ");
    scanf("%s", path1);
    printf("Enter path of second file: ");
    scanf("%s", path2);


    /*  Open all files to compare */
    fPtr1 = fopen(path1, "r");
    fPtr2 = fopen(path2, "r");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr1 == NULL || fPtr2 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }


    /* Call function to compare file */
    diff = compareFile(fPtr1, fPtr2, &line, &col);

    if (diff == 0)
    {
        printf("\nBoth files are equal.");
    }
    else 
    {
        printf("\nFiles are not equal.\n");
        printf("Line: %d, col: %d\n", line, col);
    }


    /* Finally close files to release resources */
    fclose(fPtr1);
    fclose(fPtr2);
        //-------------------------------------------------------------------------------------------------------------
    } else {
        LOGE("Unknown action.\n");
    }

    return 0;
}
