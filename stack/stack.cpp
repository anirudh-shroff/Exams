#include <iostream>
using namespace std;

class Stack
{
private:
    int top, size, count, *arr;

public:
    Stack(int size)
    {
        this->count = 0;
        this->top = -1;
        this->size = size;
        this->arr = new int[size];
    }

    void push();
    void pop();
    void viewAll();
    void checkFull();
    void checkEmpty();
    void peek();
};

void Stack::peek()
{
    if (count == 0 || top == -1)
    {
        cout << "\n-------------------------------------\n";
        cout << "  The Stack is empty.  ";
        cout << "\n-------------------------------------\n";
        return;
    }

    cout << "\n-------------------------------------\n";
    cout << "  Top element: " << arr[top];
    cout << "\n-------------------------------------\n";
}

void Stack::push()
{
    if (this->count == this->size)
    {
        cout << "\n---------------------------------------\n";
        cout << "  The Stack is full.  ";
        cout << "\n---------------------------------------\n";
        return;
    }

    int data;
    cout << "\n-------------------------------------\n";
    cout << "Please Enter data to push: ";
    cout << "\n-------------------------------------\n";
    cin >> data;
    top++;
    arr[top] = data;
    count++;
    cout << "\n------------------------------------------\n";
    cout << "  The Data is pushed successfully.  ";
    cout << "\n------------------------------------------\n";
}

void Stack::pop()
{
    if (count == 0 || top == -1)
    {
        cout << "\n-------------------------------------\n";
        cout << "  The Stack is empty.  ";
        cout << "\n-------------------------------------\n";
        return;
    }

    arr[this->top] = 0;
    this->top--;
    this->count--;

    cout << "\n-----------------------------------------\n";
    cout << "  The Data has popped successfully.  ";
    cout << "\n-----------------------------------------\n";
}

void Stack::viewAll()
{
    if (count == 0 || top == -1)
    {
        cout << "\n-------------------------------------\n";
        cout << "  The Stack is empty.  ";
        cout << "\n-------------------------------------\n";
        return;
    }

    cout << "\n---\n";
    for (int i = this->top; i >= 0; i--)
    {
        cout << " " << arr[i] << endl;
    }
    cout << "---\n";
}

void Stack::checkFull()
{
    if (this->count == this->size)
    {
        cout << "\n-------------------------------------\n";
        cout << "  The Stack is Full.  ";
        cout << "\n-------------------------------------\n";
    }
    else
    {
        cout << "\n-------------------------------------\n";
        cout << "  The Stack is not Full.  ";
        cout << "\n-------------------------------------\n";
    }
}
void Stack::checkEmpty()
{
    if (this->count == 0)
    {
        cout << "\n--------------------------------------\n";
        cout << "  The Stack is Empty.  ";
        cout << "\n--------------------------------------\n";
    }
    else
    {
        cout << "\n--------------------------------------\n";
        cout << "  The Stack is not Empty.  ";
        cout << "\n--------------------------------------\n";
    }
}

int main()
{

    Stack stack(5);

    int choice;
    do
    {
        cout << endl;
        cout << "1. TO Push Data" << endl;
        cout << "2. To Pop Data" << endl;
        cout << "3. To Display top element" << endl;
        cout << "4. To View All Elements" << endl;
        cout << "5. To Check if stack is empty" << endl;
        cout << "6. TO Check if stack is full" << endl;
        cout << "0. For Exit" << endl;
        cout << endl;
        cout << "Please Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
        {
            cout << "\n---------------------------------------\n";
            cout << "               Thank you";
            cout << "\n---------------------------------------\n";
            break;
        }
        case 1:
        {
            stack.push();
            break;
        }
        case 2:
        {
            stack.pop();
            break;
        }
        case 3:
        {
            stack.peek();
            break;
        }
        case 4:
        {
            stack.viewAll();
            break;
        }
        case 5:
        {
            stack.checkEmpty();
            break;
        }
        case 6:
            stack.checkFull();
            break;
        }

    } while (choice != 0);

    return 0;
}