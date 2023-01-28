#include <iostream>
#include <fstream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    bool push(int item)
    {
        node *record = new node();
        record->data = item;
        record->next = top;
        top = record;
        return true;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        else
        {
            node *temp;
            temp = top;
            top = top->next;
            int item = temp->data;
            delete temp;
            return item;
        }
        return 0;
    }

    int view()
    {
        return top->data;
    }
};

int Menu(string MenuName, string NextMenuName, int MenuNumber, string BackName, int BackNumber)
{
    cout << "------ " << MenuName << " Menu --------" << endl;
    cout << "press " << BackNumber << " to go " << BackName << endl;
    cout << "press " << MenuNumber << " to go to " << NextMenuName << " menu" << endl;
    cout << "Enter your option ";
    int option;
    cin >> option;
    return option;
}

// this array make for generic menues just increase the size of array and memues automatical generated
string Name[13] = {"Main", "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Nineth", "Tenth", "Eleventh"};
main()
{
    stack s = stack();
    int option = 0;
    s.push(0);
    system("cls");
    while (true)
    {
        string backName = "Exit";
        int BackNumber = -1;
        if (Name[option] == "Main")
        {
            backName = "Exit";
            BackNumber = -1;
        }
        else
        {
            backName = "Back";
            BackNumber = 0;
        }
        option = Menu(Name[option], Name[option + 1], option + 1, backName, BackNumber);
        if (option != 0)
        {
            s.push(option);
        }
        else
        {
            s.pop();
            option = s.view();
        }
        if (option == -1)
        {
            break;
        }
    }
}