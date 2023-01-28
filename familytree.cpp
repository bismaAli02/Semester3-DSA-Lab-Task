#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <conio.h>
using namespace std;
struct person
{
    string name;
    int age;
    char gender;
    person *left;
    person *right;
};

class BinaryTree
{

public:
    person *root;
    BinaryTree()
    {
        root = NULL;
    }
    person *addNode(string name, int age, char gender)
    {
        person *record = new person();
        record->name = name;
        record->age = age;
        record->gender = gender;
        record->left = NULL;
        record->right = NULL;
        return record;
    }
    bool FindFather(person *p, string Fname)
    {
        queue<person *> q;
        q.push(root);
        while (!q.empty())
        {
            person *temp = q.front();
            q.pop();
            if (temp->name == Fname)
            {
                if (temp->left == NULL)
                {
                    temp->left = p;
                    return true;
                }
                else if (temp->right == NULL)
                {
                    temp->right = p;
                    return true;
                }
                cout << "Hi";
                return false;
            }

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        return false;
    }
    person *ViewPerson(string name)
    {
        queue<person *> q;
        q.push(root);
        while (!q.empty())
        {
            person *temp = q.front();
            q.pop();
            if (temp->name == name)
            {
                return temp;
            }

            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        return NULL;
    }
    person *FindParent(string name)
    {
        queue<person *> q;
        q.push(root);
        while (!q.empty())
        {
            person *temp = q.front();
            q.pop();
            if (temp->left->name == name || temp->right->name == name)
            {
                return temp;
            }
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        return NULL;
    }
    void bfs()
    {
        queue<person *> q;
        q.push(root);
        while (!q.empty())
        {
            person *temp = q.front();
            q.pop();
            cout << temp->name << "\t";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    void preOrder()
    {
        stack<person *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            person *curr = stack.top();
            stack.pop();
            cout << curr->name << "\t";
            if (curr->right != NULL)
                stack.push(curr->right);
            if (curr->left != NULL)
                stack.push(curr->left);
        }
    }
    void postOrder()
    {
        stack<person *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            person *curr = s1.top();
            s2.push(curr);
            s1.pop();
            if (curr->left != NULL)
                s1.push(curr->left);
            if (curr->right != NULL)
                s1.push(curr->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->name << "\t";
            s2.pop();
        }
    }
    void inOrder()
    {
        stack<person *> stack;
        person *curr = root;
        while (!stack.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                cout << curr->name << " ";
                curr = curr->right;
            }
        }
    }
};
char Menu()
{
    cout << "Press 1 to Add a Person" << endl;
    cout << "Press 2 to View a Person" << endl;
    cout << "Press 3 to Find Parent of a Person" << endl;
    cout << "Press 4 to Find Child of a Person" << endl;
    cout << "Press 5 to View the Family in Breadth First Traversal" << endl;
    cout << "Press 6 to View the Family in Depth First Traversal" << endl;
    char op;
    cout << "Enter your Option: ";
    cin >> op;
    return op;
}
char DepthMenu()
{
    cout << "Press 1 to View in Pre-Order" << endl;
    cout << "Press 2 to View in In-Order" << endl;
    cout << "Press 3 to View in Post-Order" << endl;
    char op;
    cout << "Enter your Option: ";
    cin >> op;
    return op;
}
bool AddPerson(bool first, BinaryTree *family)
{
    string name;
    int age;
    char gender;
    string Fname;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    person *p = family->addNode(name, age, gender);
    if (!first)
    {
        do
        {
            cout << "Enter Father Name: ";
            cin >> Fname;
        } while (!family->FindFather(p, Fname));
    }
    else
    {
        family->root = p;
        first = false;
    }
    return first;
}
void ViewPerson(BinaryTree *family)
{
    string name;
    cout << "Enter Name of Person you want to Find: ";
    cin >> name;
    person *p = family->ViewPerson(name);
    if (p != NULL)
    {
        cout << "Name: " << p->name << endl;
        cout << "Age: " << p->age << endl;
        cout << "Gender: " << p->gender << endl;
    }
    else
    {
        cout << "Person Not Found: " << endl;
    }
}
void FindParent(BinaryTree *family)
{
    string name;
    cout << "Enter Name of Person of which Parent you want to Find: ";
    cin >> name;
    person *p = family->FindParent(name);
    if (p != NULL)
    {
        cout << "Parent Name is: " << p->name << endl;
    }
    else
    {
        cout << "Parent not found";
    }
}
void FindChildren(BinaryTree *family)
{
    string name;
    cout << "Enter Name of Person of which Children you want to Find: ";
    cin >> name;
    person *p = family->ViewPerson(name);
    if (p != NULL)
    {
        if (p->left != NULL)
        {
            cout << "Left Child: " << p->left->name << endl;
        }
        if (p->right != NULL)
        {
            cout << "Right Child: " << p->right->name << endl;
        }
        if (p->left == NULL && p->right == NULL)
        {
            cout << "Person has no Child" << endl;
        }
    }
    else
    {
        cout << "Person not found";
    }
}

main()
{
    BinaryTree family = BinaryTree();
    bool first = true;
    system("cls");
    while (true)
    {
        char op = Menu();
        if (op == '1')
        {
            first = AddPerson(first, &family);
        }
        else if (op == '2')
        {
            ViewPerson(&family);
        }
        else if (op == '3')
        {
            FindParent(&family);
        }
        else if (op == '4')
        {
            FindChildren(&family);
        }
        else if (op == '5')
        {
            family.bfs();
        }
        else if (op == '6')
        {
            char op1 = DepthMenu();
            if (op1 == '1')
            {
                family.preOrder();
            }
            else if (op1 == '2')
            {
                family.inOrder();
            }
            else if (op1 == '3')
            {
                family.postOrder();
            }
        }
        getch();
        system("cls");
    }
}