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
//  DESCRIPTION:   Tests possible data to writefile and readfile          
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

    return 0;
}
/*****************************************************************
//
//  Function name: readfile();
//
//  DESCRIPTION:   reads a file (database_data) to fill database  
//
//  Parameters:    struct record **start : address of address of first record
//                 char file[] : file to be read
//
//  Return values:  0 : success 
//                 -1 : failed          
//
****************************************************************/
int readfile(const char a[], unsigned char b[])
{
    FILE *fp = fopen("INPUT", "r");
    int bytes_read;

    bytes_read = fread(b, sizeof(a) + 1, 1, fp);
    if (bytes_read == -1) {
        perror("fread failed");
        fclose(fp);
        return 1;
    } else if (bytes_read != sizeof(a)) {
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
    int i;
    unsigned int sequence;
    unsigned int acknowledgement;
    //print source port (decimal number)
    for (i = 0; i < 16; i++)
    {
        printf("%d", a[i]);
    }
    //print destination port (decimal number)
    for (i = 16; i < 32; i++)
    {
        printf("%d", a[i]);
    }
    //print sequence number ((unsigned) decimal number)
    for (i = 32; i < 64; i++)
    {
        sequence += a[i];
    }
    printf("%u", sequence);
    //print acknowledgement number ((unsigned) decimal number)
    for (i = 64; i < 96; i++)
    {
        acknowledgement += a[i];
    }
    printf("%u", acknowledgement);
    // print control bits
}

void makeheader(const unsigned char a[], unsigned char b[])
{

}