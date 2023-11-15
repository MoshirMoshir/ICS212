/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework 8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 11, 2023
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//   Program that reads data of a TCP header and
//   generates a reponse header
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int readfile(const char [], unsigned char []);
int writefile(const char [], const unsigned char []);
void printheader(const unsigned char []);
void makeheader(const unsigned char[], unsigned char[]);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Takes the 3 input files and generates 3 output files          
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//                 
****************************************************************/
int main(int argc, char* argv[])
{
    const char request1[] = "request1.bin";
    const char response1[] = "response1.bin";
    const char request2[] = "request2.bin";
    const char response2[] = "response2.bin";
    const char request3[] = "request3.bin";
    const char response3[] = "response3.bin";
    unsigned char data[20];
    unsigned char response[20];

    readfile(request1, data);
    printf("Request1.bin:\n");
    printheader(data);
    printf("\n");
    makeheader(data, response);
    printf("Response1.bin:\n");
    printheader(response);
    writefile(response1, response);

    readfile(request2, data);
    printf("Request2.bin:\n");
    printheader(data);
    printf("\n");
    makeheader(data, response);
    printf("Response2.bin:\n");
    printheader(response);
    writefile(response2, response);

    readfile(request3, data);
    printf("Request3.bin:\n");
    printheader(data);
    printf("\n");
    makeheader(data, response);
    printf("Response3.bin:\n");
    printheader(response);
    writefile(response3, response);

    return 0;
}
/*****************************************************************
//
//  Function name: readfile();
//
//  DESCRIPTION:   reads input file and stores data in data[]
//
//  Parameters:    const char filename[] : file to be read
//                 unsigned char data[] : array to store data
//
//  Return values:  0 : success 
//                 -1 : failed          
//
****************************************************************/
int readfile(const char filename[], unsigned char data[])
{
    int out = 0;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        out = -1; 
    }

    fread(data, sizeof(unsigned char), 20, file);
    fclose(file);

    return out; 
}
/*****************************************************************
//
//  Function name: writefile();
//
//  DESCRIPTION:   writes a response file based on data[]
//
//  Parameters:    const char filename[] : file to be written
//                 const unsigned char data[] : data
//
//  Return values:  0 : success 
//                 -1 : failed          
//
****************************************************************/
int writefile(const char filename[], const unsigned char data[])
{
    int out = 0;
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        out = -1; 
    }

    fwrite(data, sizeof(unsigned char), 20, file);

    fclose(file);
    return out; 
}
/*****************************************************************
//
//  Function name: printheader();
//
//  DESCRIPTION:   prints out header
//
//  Parameters:    const unsigned char data[] : data to be printed          
//
****************************************************************/
void printheader(const unsigned char data[])
{
    unsigned int sourcePort = (data[0] << 8) | data[1];
    unsigned int destPort = (data[2] << 8) | data[3];
    unsigned int sequenceNum = (data[4] << 24) | (data[5] << 16) | (data[6] << 8) | data[7];
    unsigned int ackNum = (data[8] << 24) | (data[9] << 16) | (data[10] << 8) | data[11];
    int i;

    printf("Source Port: %u\n", sourcePort);
    printf("Destination Port: %u\n", destPort);
    printf("Sequence Number: %u\n", sequenceNum);
    printf("Acknowledgment Number: %u\n", ackNum);

    printf("Control Bits set to 1: ");
    for (i = 12; i < 18; ++i) {
        if ((data[i] >> 7) & 1) {
            printf("%d ", i - 12);
        }
    }
    printf("\n");
}
/*****************************************************************
//
//  Function name: makeheader();
//
//  DESCRIPTION:   creates a response header based on header[]
//
//  Parameters:    const unsigned char header[] : header to be read
//                 unsigned char response[] : response header
//
****************************************************************/
void makeheader(const unsigned char header[], unsigned char response[])
{
    unsigned int sourcePort = (header[0] << 8) | header[1];
    int i;

    if (sourcePort > 32767) {
        response[1] ^= (1 << 3);  
        response[0] ^= (1 << 10); 
    }

    for (i = 2; i < 20; ++i) {
        response[i] = header[i];
    }
}