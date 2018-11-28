/************************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Oct 10, 2018
//
//  FILE:        llist.cpp
//
//  DESCRIPTION: A c++ implementation of the banking program
//               deveolped for project 1.
//
*************************************************************/

#include <cstdlib>
#include <cstring>
#include "llist.h"

using namespace std;

/*****************************************************************
//
//  Function name: readfile
//
//  Description:   A method to read the bank records from a file.
//
//  Paramters:     none
//
//  return values: : 0 : success
//                  -1 : error
//
******************************************************************/

int llist::readfile()
{
    int status;
    int account;
    int fileStatus;
    int checker;
    ifstream fileInput;
    string tempString, addressString, nameString, accountString;

    char temp[80] = "";
    char address[80] = "";
    char name[25] = "";
    char CR[2] = "\n";

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "readfile call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    status = -1;
    fileStatus = 1;

    fileInput.open(filename);

    if (!fileInput.is_open())
    {
        fileStatus = -1;
        fileInput.close();
    }

    if (fileStatus == 1)
    {
        checker = fileInput.get();
        status = 0;
        while (checker != EOF)
        {

            std::getline(fileInput, accountString);
            account = atoi(accountString.c_str());

            std::getline(fileInput, nameString);
            strcpy(name, nameString.c_str());
            name[strlen(name) - 1] = '\0';

            while (temp[0] != '#')
            {
                std::getline(fileInput, tempString);
                strcpy(temp, tempString.c_str());
                strcat(address, temp);
                strcat(address, CR);
            }

            address[strlen(address) - 3] = '\0';
            status = addRecord(account, name, address);

            strcpy(temp, "");
            strcpy(address, "");
            strcpy(name, "");

            addressString.clear();
            checker = fileInput.get();
        }

        fileInput.close();
    }
    return status;
}

/*****************************************************************
//
//  Function name:  writefile
//
//  Description:    A method to write bank records to a text file.
//
//  Parameters:     none
//
//  Return values:  0 : success
//                 -1 : error
//
******************************************************************/

void llist::writefile()
{
    record *temp;
    int status, count;
    ofstream fileOutput;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "writeFile call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    count = 0;
    status = -1;
    temp = start;
    fileOutput.open(filename);

    if (fileOutput.is_open())
    {
        status = 0;
    }

    if (status == 0)
    {
        while (temp != NULL)
        {

            /******************************************************************
             * Some hackery to deal with the file checker in the readfile fxn *
             ******************************************************************/

            if (count >= 0)
            {
                fileOutput << 0;
            }

            fileOutput << temp->accountno << "\n";
            fileOutput << temp->name << "\n";
            fileOutput << temp->address << "\n#\n";

            temp = temp->next;
            count++;
        }
    }
    fileOutput.close();
}

/*********************************************************************
//
//  Function name: reverse
//
//  Description:   The private utility implemnetation of the
//                 no argument reverse method for the client.
//
//  Parameters:    record * (start) : The start of the linked list to
//                                    be reversed.
//
//  Return value:  record * : The pointer to the new starting address.
//
***********************************************************************/

record * llist::reverse(record *from)
{
    int status = 0;
    record *reversify;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "private reverse call" << from;
        cout << "\n--------------------------------------------------------\n";
    #endif

    if (from == NULL)
    {
        cout << "\nNo records exist to reverse\n";
        status = -1;
    }

    if (status != -1)
    {
        if (from->next == NULL)
        {
            start = from;
        }
        else
        {
            reversify = reverse(from->next);
            reversify->next = from;
        }
        from->next = NULL;
    }
    return from;
}

/******************************************************************
//
//  Function name: cleanup
//
//  Description:   The private auxillary method currently
//                 used for the destructor and assignment overload.
//
//  Parameters:    none
//
//  Return values: void
//
*******************************************************************/

void llist::cleanup()
{
    record *current;
    record *temp;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "cleanup call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    current = start;

    while (current != NULL)
    {
        temp = current->next;
        delete(current);
        current = temp;
    }
}

/********************************************************************
//
//  Function name: llist
//
//  Description:   The default constructor for a linked list object.
//
//  Parameters:    none
//
//  Return values: An implicit object instantiation.
//
*********************************************************************/

llist::llist()
{
    char file[16] = "records.txt";
    strcpy(filename, file);
    start = NULL;
    readfile();

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "llist constructor call";
        cout << "\n--------------------------------------------------------\n";
    #endif
}

/**************************************************************
//
//  Function name: llist
//
//  Description:   Overloaded constructor with formal parameter
//                 for specifying filename to be written.
//
//  Parameters:    char [] (file) : filename
//
//  Return value:  An implicit object instantiation
//
***************************************************************/

llist::llist(char file[])
{
    strcpy(filename, file);
    start = NULL;
    readfile();

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "llist constructor call with parameter" << file;
        cout << "\n--------------------------------------------------------\n";
    #endif
}

/****************************************************************************
//
//  Function name: llist
//
//  Description:   Copy constructor for the linked list class.
//
//  Parameters:     const llist & (original) : reference to the original list
//                 char [] (file) : file name to write copied list to.
//
//  Return value:  none
//
*****************************************************************************/

llist::llist(const llist &original, string file)
{
    start = NULL;
    strcpy(filename, file.c_str());

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "----------------------------------------------------------------------\n";
        cout << "llist copy constructor call. original: " << &original << "file: " << file;
        cout << "\n----------------------------------------------------------------------\n";
    #endif

    copy(original);
}

/****************************************************************************
//
//  Function name: copy
//
//  Description:   A method for copying from one linked list to
//                 another.
//
//  Parameters:    const llist& (original) : The original data to be copied.
//
//  Return value:  void
//
*****************************************************************************/

void llist::copy(const llist& original)
{
    record *temp = original.start;

    #ifdef DEBUG
        cout << "";
    #endif

    while (temp != NULL)
    {
        addRecord(temp->accountno, temp->name, temp->address);
        temp = temp->next;
    }
}

/********************************************************
//
//  Function name: ~llist
//
//  Description:   Desctructor for the linked list class.
//
//  Parameters:    none
//
//  Return value:  none
//
*********************************************************/

llist::~llist()
{
    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "destructor call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    writefile();
    cleanup();
}

/********************************************************************
//
//  Function name: addRecord
//
//  Description:   A method to add a record to a linked list.
//
//  Parameters:    int (account) : the account number for the record.
//                 char[] (name) : the name for the account.
//                 char[] (address) : the address for the account.
//
//  Return values: 0 : success
//                -1 : error
//
*********************************************************************/

int llist::addRecord (int account, char name[25], char address[80])
{
    record *temp;
    record *current;
    record *successor;
    int status;

    status = -1;
    temp = new record;

    temp->accountno = account;
    strcpy(temp->name, name);
    strcpy(temp->address, address);

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "addRecord call. account: " << account << " name: " << name <<  "\naddress: ";
        cout <<  address;
        cout << "\n--------------------------------------------------------\n";
    #endif

    if (start == NULL || start->accountno > account)
    {
        temp->next = start;
        start = temp;
        status = 0;
    }
    else
    {
        current = start;
        successor = current->next;

        while (successor != NULL && successor->accountno < account)
        {
            current = successor;
            successor = successor->next;
        }

        current->next = temp;
        temp->next = successor;
        status = 0;
    }

    return status;
}

/*******************************************************************
//
//  Function name: printRecord
//
//  Description:   A method to print a single record from the list.
//
//  Parameters:    int (account) : The key to be searched.
//
//  Return value:  0 : success
//                -1 : error
//
*******************************************************************/

int llist::printRecord (int account)
{

    record *temp;
    int status;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "printRecord call" << account;
        cout << "\n--------------------------------------------------------\n";
    #endif

    temp = start;
    status = -1;

    while (temp != NULL && temp->accountno == account)
    {
        if (status == -1)
        {
            status = 0;
        }

        cout << "\n";
        cout << "Account: " << temp->accountno;
        cout << "\nName: " << temp->name;
        cout << "\nAddress: " << temp->address;
        temp = temp->next;
    }

    if (status == -1)
    {
        while (temp != NULL)
        {
            while (temp != NULL && temp->accountno != account)
            {
                temp = temp->next;
            }

            if (temp != NULL)
            {
                if (status == -1)
                {
                    status = 0;
                }

                cout << "\n";
                cout << "Account: " << temp->accountno;
                cout << "\nName: " << temp->name;
                cout << "\nAddress: " << temp->address;
                temp = temp->next;
            }
        }
    }

    return status;
}

/************************************************************************
//
//  Function name: operator<<
//
//  Description:   A custom overload to ostream for printing all records
//                 in the dynamic linked list.
//
//  Parameters:    ostream& (os) : The reference to out stream.
//                 llist& (list): The reference to the linked list.
//
//  Return values: os (ostream) : the out stream to printed to console.
//
*************************************************************************/

ostream& operator<<(ostream& os, llist& list)
{
    record *temp = list.start;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "printAllRecords call." << list;
        cout << "\n--------------------------------------------------------\n";
    #endif

    if (temp != NULL)
    {
        while (temp != NULL)
        {
            os << "\n" << "Account: " << temp->accountno
            << "\nName: " << temp->name
            << "\nAddress: " << temp->address
            << "\n";
            temp = temp->next;
        }
    }
    else
    {
        os << "\nThere don't appear to be any records in the system.\n";
    }
    return os;
}

/**********************************************************************
//
//  Function name: operator=
//
//  Description:   An overload for the assignment operator, used
//                 to avoid memory leaks.
//
//  Parameters:    const llist& (original): reference to the original
//                                          linked list object.
//
//  Return value:  llist : a copy of the original linked list object.
//
***********************************************************************/

llist& llist::operator=(const llist& original)
{
    cleanup();
    copy(original);
    return *this;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "assignment operator overload call referencing: \n" << &original;
        cout << "\n--------------------------------------------------------\n";
    #endif
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  Description:   A method to delete a record from a linked list.
//
//  Parameters:    int (account) : The key to be searched.
//
//  Return values: 0 : success
//                -1 : error
//
******************************************************************/

int llist::deleteRecord(int account)
{
    record *temp;
    record *previous;
    int status;

    temp = start;
    status = -1;

    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "deleteRecord call. account: " << account;
        cout << "\n--------------------------------------------------------\n";
    #endif

    while (temp != NULL && temp->accountno == account)
    {
        if (status == -1)
        {
            status = 0;
        }

        start = temp->next;
        delete(temp);
        temp = start;
    }

    if (status == -1)
    {
        while (temp != NULL)
        {
            while (temp != NULL && temp->accountno != account)
            {
                previous = temp;
                temp = temp->next;
            }

            if (temp != NULL)
            {
                if (status == -1)
                {
                    status = 0;
                }

                previous->next = temp->next;
                delete(temp);
                temp = previous->next;
            }
        }
    }

    return status;
}

/*******************************************************************
//
//  Function name: reverse
//
//  Description:   The public method to be used on the client side.
//
//  Parameters:    none
//
//  Return value:  void
//
********************************************************************/

void llist::reverse()
{
    #ifdef DEBUG
        cout << "\n***Debugmode***\n";
        cout << "--------------------------------------------------------\n";
        cout << "public reverse call";
        cout << "\n--------------------------------------------------------\n";
    #endif

    reverse(start);
}
