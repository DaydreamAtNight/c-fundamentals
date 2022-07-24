/*
create an address book with functions:
1 Create: add a new contact to the address book
2 Read:   read a contact from the address book
3 Update: update a contact in the address book
4 Delete: delete a contact from the address book
5 Display: display all contacts in the address book
6 Clear:  clear the address book
0 Exit:   exit the program
*/

#include <iostream>
#include <string.h>
using namespace std;

#define MAX_CONTACT_COUNT 100

struct Contact
{
    char name[20];
    char phone[20];
    char email[20];
};

struct ContactBook
{
    Contact contact[MAX_CONTACT_COUNT];
    int contact_count;
};

void showMenu()
{
    system("clear");
    cout << "***********************" << endl;
    cout << "*****  1. Create  *****" << endl;
    cout << "*****  2. Read    *****" << endl;
    cout << "*****  3. Update  *****" << endl;
    cout << "*****  4. Delete  *****" << endl;
    cout << "*****  5. Display *****" << endl;
    cout << "*****  6. Clear   *****" << endl;
    cout << "*****  0. Exit    *****" << endl;
    cout << "***********************" << endl;
}

bool checkEmpty(const ContactBook *contact_book)
{
    if (contact_book->contact_count == 0)
    {
        cout << "The address book is empty." << endl;
        return true;
    }
    else
    {
        return false;
    }
}

int checkExist(const ContactBook *contact_book, const char *name)
{
    for (int i = 0; i < contact_book->contact_count; i++)
    {
        if (strcmp(contact_book->contact[i].name, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

void selectMenu(int *choice)
{
    int temp_choice;
    for (;;)
    {
        cout << "Enter your choice: ";
        cin >> temp_choice;
        if (temp_choice >= 0 && temp_choice <= 6)
        {
            *choice = temp_choice;
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }
    cout << endl;
}

void createContact(ContactBook *contact_book)
{
    if (contact_book->contact_count == MAX_CONTACT_COUNT)
    {
        cout << "Contact book is full!" << endl;
        return;
    }

    cout << "Enter name: ";
    cin >> contact_book->contact[contact_book->contact_count].name;
    // cin.getline(contact_book->contact[contact_book->contact_count].name, 20);
    cout << "Enter phone: ";
    cin >> contact_book->contact[contact_book->contact_count].phone;
    cout << "Enter email: ";
    cin >> contact_book->contact[contact_book->contact_count].email;

    contact_book->contact_count++;
}

void readContact(const ContactBook *contact_book)
{

    if (checkEmpty(contact_book))
        return;

    cout << "Enter contact name: ";
    char name[20];
    cin >> name;

    int index = checkExist(contact_book, name);

    if (index != -1)
    {
        cout << "Name: " << contact_book->contact[index].name << endl;
        cout << "Phone: " << contact_book->contact[index].phone << endl;
        cout << "Email: " << contact_book->contact[index].email << endl;
    }
    else
    {
        cout << "Contact not found!" << endl;
    }
}

void updateContact(ContactBook *contact_book)
{
    if (checkEmpty(contact_book))
        return;
    cout << "Enter contact name: ";
    char name[20];
    cin >> name;

    int index = checkExist(contact_book, name);

    if (index != -1)
    {
        cout << "Enter new name: ";
        cin >> contact_book->contact[index].name;
        cout << "Enter new phone: ";
        cin >> contact_book->contact[index].phone;
        cout << "Enter new email: ";
        cin >> contact_book->contact[index].email;
    }
    else
    {
        cout << "Contact name no match !" << endl;
    }
}

void deleteContact(ContactBook *contact_book)
{
    if (checkEmpty(contact_book))
        return;
    cout << "Enter contact name: ";
    char name[20];
    cin >> name;

    int index = checkExist(contact_book, name);

    if (index != -1)
    {
        for (int j = index; j < contact_book->contact_count - 1; j++)
        {
            contact_book->contact[j] = contact_book->contact[j + 1];
        }
        contact_book->contact_count--;
    }
    else
    {
        cout << "Contact name no match !" << endl;
    }
}

void displayContact(const ContactBook *contact_book)
{
    if (checkEmpty(contact_book))
        return;

    for (int i = 0; i < contact_book->contact_count; i++)
    {
        cout << "------------------------" << endl;
        cout << "Name: " << contact_book->contact[i].name << endl;
        cout << "Phone: " << contact_book->contact[i].phone << endl;
        cout << "Email: " << contact_book->contact[i].email << endl;
    }
}

void clearContact(ContactBook *contact_book)
{
    if (checkEmpty(contact_book))
        return;
    cout << "Are you sure to clear the address book? (y/n) ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        for (int i = 0; i < contact_book->contact_count; i++)
        {
            contact_book->contact[i].name[0] = '\0';
            contact_book->contact[i].phone[0] = '\0';
            contact_book->contact[i].email[0] = '\0';
        }
        contact_book->contact_count = 0;
    }
}

int main()
{
    int choice;
    ContactBook contact_book;
    contact_book.contact_count = 0;
    showMenu();
    selectMenu(&choice);

    for (;;)
    {
        switch (choice)
        {
        case 0:
            cout << "Bye!" << endl;
            return 0;
        case 1:
            cout << "Create" << endl;
            createContact(&contact_book);
            break;
        case 2:
            cout << "Read" << endl;
            readContact(&contact_book);
            break;
        case 3:
            cout << "Update" << endl;
            updateContact(&contact_book);
            break;
        case 4:
            cout << "Delete" << endl;
            deleteContact(&contact_book);
            break;
        case 5:
            cout << "Display" << endl;
            displayContact(&contact_book);
            break;
        case 6:
            cout << "Clear" << endl;
            clearContact(&contact_book);
            break;
        }
        system("read -n 1 -s -p \"\nPress any key to continue...\"");
        showMenu();
        selectMenu(&choice);
    }

    return 0;
}