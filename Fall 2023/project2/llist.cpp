/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 27, 2023
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   The second project for ICS 212 converting project 1 to C++
//
****************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "llist.h"
extern int debugmode;

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database list     
//
//  Parameters:    int uaccountno : account number to be added
//                 char uname[] : account name to be added
//                 char uaddress[] : account address to be added
//
****************************************************************/

int llist::addRecord(int uaccountno, char uname[], char uaddress[])
{
    record *temp;
    int i;

    if (debugmode == 1)
    {
        std::cout << "\naddRecord(" << this << ", " << uaccountno << ", " << uname << ", " << uaddress << ")\n";
    }

    temp = new record;

    strcpy(temp->name, uname);
    strcpy(temp->address, uaddress);
    temp->accountno = uaccountno;
    temp->next = NULL;

    if (start != NULL)
    {
        record *prev;
        prev = start;
        i = 0;

        if (temp->accountno >= prev->accountno)
        {
            temp->next = prev;
            start = temp;
        }
        else
        {
            if (prev->next == NULL)
            {
                temp->next = prev->next;
                prev->next = temp;
            }
            else
            {
                while (i < 1)
                {
                    if (temp->accountno >= prev->next->accountno)
                    {
                        temp->next = prev->next;
                        prev->next = temp;
                        i++;
                    }
                    else
                    {
                        prev = prev->next;
                    }
                }
            }
        }
    }
    else
    {
        temp->next = NULL;
        start = temp;
    }

    return 0;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all records in the database    
//
//  Parameters:    None
//
****************************************************************/

void llist::printAllRecords()
{
    if (debugmode == 1)
    {
        std::cout << "\nprintAllRecords(" << this << ")\n";
    }

    if (start == NULL || start->accountno == 0)
    {
        std::cout << "\ndatabase is empty\n\n";
    }
    else
    {
        record *current = start;
        while (current != NULL && current->accountno != 0)
        {
            std::cout << "Name      : " << current->name << "\n";
            std::cout << "AccountNo : " << current->accountno << "\n";
            std::cout << "Address   : " << current->address << "\n";

            current = current->next;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record in the database    
//
//  Parameters:    int uaccountno : account number to be found
//
//  Return values:  0 : success    
//                 -1 : failure       
//
****************************************************************/

int llist::findRecord(int uaccountno)
{
    int success = -1;

    if (debugmode == 1)
    {
        std::cout << "\nfindRecord(" << this << ", " << uaccountno << ")\n";
    }

    if (start == NULL)
    {
        std::cout << "\ndatabase is empty\n\n";
    }
    else
    {
        record *current = start;

        while (current != NULL)
        {
            if (current->accountno == uaccountno)
            {
                std::cout << "Name      : " << current->name << "\n";
                std::cout << "AccountNo : " << current->accountno << "\n";
                std::cout << "Address   : " << current->address << "\n";
                success = 0;
            }

            current = current->next;
        }
    }

    if (success == -1)
    {
        std::cout << "\naccount does not exist\n";
    }

    return success;
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   deletes a record from the database     
//
//  Parameters:    int uaccountno : account number to be deleted
//
//  Return values:  0 : success
//                 -1 : failure           
//
****************************************************************/

int llist::deleteRecord(int uaccountno)
{
    int success = -1;
    record *temp;
    record *tempnext;

    if (debugmode == 1)
    {
        std::cout << "\ndeleteRecord(" << this << ", " << uaccountno << ")\n";
    }

    temp = start;

    if (temp == NULL)
    {
        std::cout << "\ndatabase is empty\n";
    }
    else
    {
        if (temp->accountno == uaccountno)
        {
            start = temp->next;
            delete temp;
            success = 0;
        }
        else
        {
            while (temp->next != NULL && temp->next->accountno != uaccountno)
            {
                temp = temp->next;
            }

            if (temp->next->accountno == uaccountno)
            {
                tempnext = temp->next;
                temp->next = tempnext->next;
                delete tempnext;
                success = 0;
            }
            else
            {
                std::cout << "\naccount does not exist\n";
            }
        }
    }

    return success;
}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   writes the database to a file    
//
//  Parameters:    char filename[ ] : file to write to
//
//  Return values:  0 : success  
//                 -1 : failure         
//
****************************************************************/

int llist::writefile(char filename[ ])
{
    int success = -1;
    std::ofstream write(filename);

    if (debugmode == 1)
    {
        std::cout << "\nwritefile(" << this << ", " << filename << ")\n";
    }

    if (write.is_open())
    {
        if (start == NULL)
        {
            std::cout << "\ndatabase is empty\n";
        }
        else
        {
            record *current = start;

            while (current != NULL)
            {
                write << current->accountno;
                write << current->name;
                write << current->address << "\n";

                current = current->next;
            }
        }
        write.close();
        success = 0;
    }
    else
    {
        std::cout << "\nError: Unable to write a file\n";
    }

    return success;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   reads a file to fill database  
//
//  Parameters:   char filename[ ] : file to read
//
//  Return values:  0 : success 
//                 -1 : failure          
//
****************************************************************/

int llist::readfile(char filename[])
{
    int success = -1;
    record *temp;
    int uaccountno;
    char uname[30];
    char uaddress[50];
    char input;
    char prevInput;
    int running = 0;
    int i;

    std::ifstream read(filename);

    if (debugmode == 1)
    {
        std::cout << "\nreadfile(" << this << ", " << filename << ")\n";
    }

    if (read.is_open())
    {
        temp = new record;
        if (temp != NULL && !read.eof())
        {
            read >> uaccountno;
            temp->accountno = uaccountno;
            read.ignore(); // skip newline character
            read.getline(uname, 30);
            strcpy(temp->name, uname);
            i = 0;

            while (running == 0 && !read.eof())
            {
                if ((input = read.get()) == '\n' && prevInput == '\n')
                {
                    running++;
                }
                else
                {
                    if (input != EOF)
                    {
                        uaddress[i] = input;
                        prevInput = input;
                        i++;
                    }
                }
            }

            strcpy(temp->address, uaddress);
            start = temp;
        }

        while (temp != NULL && !read.eof())
        {
            temp = temp->next;
            temp = new record;
            read >> uaccountno;
            temp->accountno = uaccountno;
            read.ignore(); // skip newline character
            read.getline(uname, 30);
            strcpy(temp->name, uname);
            i = 0;

            while (running == 0 && !read.eof())
            {
                if ((input = read.get()) == '\n' && prevInput == '\n')
                {
                    running++;
                }
                else
                {
                    if (input != EOF)
                    {
                        uaddress[i] = input;
                        prevInput = input;
                        i++;
                    }
                }
            }

            strcpy(temp->address, uaddress);
        }

        read.close();
        success = 0;
    }
    else
    {
        std::cout << "\nFile not found, creating a new file...\n";
        writefile(filename);
    }

    return success;
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   cleans up memory     
//
//  Parameters:    None
//
****************************************************************/

void llist::cleanup()
{
    record *temp;
    record *tempnext;

    if (debugmode == 1)
    {
        std::cout << "\ncleanup(" << this << ")\n";
    }

    temp = start;

    while (temp != NULL)
    {
        tempnext = temp->next;
        delete temp;
        temp = tempnext;
    }

    start = NULL;
}
