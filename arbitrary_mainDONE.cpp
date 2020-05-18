#include <iostream>
//BY: FRANKIE HERBERT
//HELP FROM: TUTOR, CPP, BOOK, CLASSWORK, MULTIPLE SITES ON LINKED LIST FROM GEEKSFORGEEKS
#include "struct_nodeDONE.h"
using namespace std;


bool isempty(node *head); // what is expected to process
char menu();
void insertAsFirstEmlement(node *&head, node *&last, int number); // head and last element in list and value to insert passed by references to make changes
void insert(node *&head, node *&last, int number);
void remove(node *&head, node *&last);
void showList(node *current); //head with only current

bool isempty(node *head) // to see if list is empty
{
    if(head == NULL)
        return true;
    else
        return false;
}
char menu()  //menu items of what to expect
{
    char choice;

    cout << "MENU\n";
    cout << "1. ADD ITEM.\n";
    cout << "2. REMOVE ITEM.\n";
    cout << "3. SHOW ITEM.\n";
    cout << "4. EXIT\n";

    cin >> choice;

    return choice; // return to the main function
}

void insertAsFirstEmlement(node *&head, node *&last, int number) // last element in list and value to insert
{
    node *temp = new node; // create a temp node
    temp->number = number; //assigning the node
    temp->next = NULL;  //temp goes to NULL
    head = temp;  //set head
    last = temp;  // set last
}

void insert(node *&head, node *&last, int number)
{
    if(isempty(head))//if list is empty
        insertAsFirstEmlement(head, last, number); // if empty insert first element the last empty number
    else
    {
        node *temp = new node;
    temp->number = number;
    temp->next = NULL;
    last->next = temp; //links elements in list
    last = temp;
    }

}

void remove(node *&head, node *&last)
{
    if(isempty(head))
        cout << "The list is Empty.\n"; // message for if list is empty
    else if (head == last) //if one item in list
    {
        delete head;
        head == NULL;  //assign head and last to NULL
        last == NULL;
    }
    else  //if there is more than one item in list
    {
        node *temp = head;  // create another temp node
        head = head->next;
        delete temp;
    }
}

void showList(node *current) //head with only current
{
    if(isempty(current))
        cout << "The list is empty \n";
    else
    {
        cout << "The list contain: \n";  // show list
        while(current != NULL)  // loop through the list to check memory locations
        {
            cout << current->number << endl;
            current = current->next; //move to next value
        }
    }
}



int main()
{
    node *head = NULL; //the head and tail pointers set to NULL for nothing in list
    node *last = NULL;
    char choice;
    int number;

    do{ // create quick menu
        choice = menu();

        switch(choice)
        {
            case '1': cout << "please enter a number: ";  //adding item
            cin >> number;
            insert(head, last, number);
                    break;

            case '2': remove(head, last);  // removing item from list
                    break;

            case '3': showList(head); //show (get) list
                    break;

            default: cout << "Exit\n";  //to exit the program

        }
    }while(choice != '4');
    return 0;
}
