# EEE3097S PROJECT 2022

COMPRESSION AND ENCRYPTION OF DATA

The System was designed for a device called SHARC BUOY which is used to collect environmental data in the southern ocean. the system compresses and encrypts that data before it sent to a remote location to be decompressed and decrypted. 

## What you need to get started with this project

##### stm32f051r8t6
##### ICM-20948
##### STM32CubeIDE
##### need to know basic python programming language
##### need to know basic C programming language


## Project folders
### Compression folder
-This folder containes files that were used to comperss data, one of the files is Huffman.c file which is c file that comoresses and decompresses data.

to run the file you need to follow these steps

1. open your IDE, preferrably Visual studio
2. open the compression folder on your IDE 
3. type "make" on the command line
4. then depending on whether you want to compress or decompress(create an input file on this folder)
    4.1 to compress run " ./huffamn -e nameOfTheInputFile nameOfTheOutputFile"
    4.2 to decompress run "./huffman -d nameOfThecompressedFile nameOfTheOutput"
    once the data is decompressed the program will prompt to enter two files to be compared which you might you to compare the original data to the decompressed data

- Also the folder contains uartData.py which is used to read data from the serial port(you might want to open the file and change the communication port to the the one you are using) of the pc, to run this just type "python uartData.py" the enter now it should create a file called data.txt on the folder which will be used to store data when there is date in the serial port.

### Datasheets
 This folder contains all the documents that were used in the project.

### Encryption 
This folder has three subfolders which contains all the file that were used to encrypt and decrypt data but the subfolder of interest is XOR Algorithm, this subfolder contains main.c which encryt and decrypt data to run this file you need to create a file with a content that you wish to encrypt. 

- run "gcc -o main main.c" on the command line
- run "./main

this will create a new file called Encrypted.txt to store encrypted data
and  it will create another new file called Decryped.txt which stores decrypted data

should you wish to compare the input data and decrypted data, you can go one folder back and then enter and then Enter Compare Files folder.

- run "gcc -o main main.c" on the command line
- run "./main

this will prompt you to enter the paths to the files you wish to compare.

### IMU folder

Contains the code used to read data from the ICM-20948 sensor using the STM32F0
Go to IMUDATA.ioc to see how the bins are configured and build a circuit accordingly.

### Paper design folder

Contains a pdf Document showin the analysis of the requirements of the project

## Contributing
Should you find yourself browsing through this git repo, feel free to use the codes however you want but do not use it for monetary benefits and do not push any changes to the git repo.

## Authors and acknowledgment
S'THABISO AND VEE

## Project status
The project is completed but might come back to improve it.
