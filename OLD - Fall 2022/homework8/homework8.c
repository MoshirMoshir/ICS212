/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    Homework 8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 14, 2022
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
#include <string.h>

int readfile(const char [], unsigned char []);
int writefile(const char [], const unsigned char []);
void printheader(const unsigned char []);
void makeheader(const unsigned char[], unsigned char[]);

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads a file (database_data) to fill database  
//
//  Parameters:    struct record **start : address of address of first record
//                 char file[] : file to be read
//
//  Return values:  0 : success 
//                  -1 : failed          
//
****************************************************************/
int readfile(const char a[], unsigned char b[])
{
    FILE *fp;
    int bytes_read;

    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen failed");
        return 1;
    }

    bytes_read = fread(&my_header, sizeof(my_header), 1, fp);
    if (bytes_read == -1) {
        perror("fread failed");
        fclose(fp);
        return 1;
    } else if (bytes_read != sizeof(my_header)) {
        fprintf(stderr, "expected to read %d bytes, actually read %d\n", sizeof(my_header), bytes_read);
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}

int writefile(const char a[], const unsigned char b[])
{
    return -1;
}

void printheader(const unsigned char a[])
{
    //print source port (decimal number)
    //print destination port (decimal number)
    //pring sequence number ((unsigned) decimal number)
    //print ackowledgement number ((unsigned) decimal number)
    // print control bits
}

void makeheader(const unsigned char a[], unsigned char b[])
{

}