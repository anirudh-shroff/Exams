#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int counter = 0;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addAtStart()
    {
        int data;
        cout << "Please enter data to insert: ";
        cin >> data;

        Node *newnode = new Node(data);

        newnode->next = head;
        head = newnode;

        counter++;

        cout << "\n-----------------------------------------------\n";
        cout << "Data added successfully at the beginning.";
        cout << "\n-----------------------------------------------\n";
    }

    void viewAllData()
    {
        if (counter == 0)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Sorry, List is empty.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        Node *temp;
        temp = head;

        cout << "\n-----------------------------------------------\n";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";
        cout << "\n-----------------------------------------------\n";
    }

    void addAtEnd()
    {
        int data;
        cout << "Please, enter data to insert: ";
        cin >> data;

        Node *newNode = new Node(data);

        if (counter == 0 || head == nullptr)
        {
            head = newNode;

            counter++;

            cout << "\n-----------------------------------------------\n";
            cout << "List is empty.\nInserted node will be the first.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        Node *temp;
        temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        counter++;

        cout << "\n-----------------------------------------------\n";
        cout << "Data added successfully at the end.";
        cout << "\n-----------------------------------------------\n";
    }

    void searchByKey()
    {
        if (counter == 0)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Sorry, list is empty.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        int key;
        cout << "Please, enter position to search: ";
        cin >> key;

        if (key >= counter)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid position.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        Node *temp;
        temp = head;

        for (int i = 0; i < key; i++)
        {
            temp = temp->next;
        }

        cout << "\n-----------------------------------------------\n";
        cout << "Data at position " << key << " : " << temp->data;
        cout << "\n-----------------------------------------------\n";
    }

    void deleteAtStart()
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;

            cout << "\n----------------------------------------\n";
            cout << "First Node Deleted Successfully.";
            cout << "\n----------------------------------------\n";

            counter--;
            return;
        }

        Node *temp;
        temp = head;

        head = head->next;

        delete temp;
        temp = nullptr;

        cout << "\n----------------------------------------\n";
        cout << "First Node Deleted Successfully.";
        cout << "\n----------------------------------------\n\n";

        counter--;
    }

    void deleteByKey()
    {
        if (counter == 0)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "List is empty.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        int key;
        cout << "Enter position to delete: ";
        cin >> key;

        if (key >= counter || key < 0)
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Invalid position.";
            cout << "\n-----------------------------------------------\n";
            return;
        }

        if (key == 0)
        {
            deleteAtStart();
            return;
        }

        Node *temp;
        temp = head;

        if (key == 0)
        {
        }

        for (int i = 0; i < (key - 1); i++)
        {
            temp = temp->next;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;
        deleteNode = nullptr;

        counter--;

        cout << "\n-----------------------------------------------\n";
        cout << "Node deleted successfully.";
        cout << "\n-----------------------------------------------\n";
    };
};

int main()
{
    int choice;

    LinkedList list;

    do
    {

        cout << endl;
        cout << "1. TO add data at beginning." << endl;
        cout << "2. To add data at end." << endl;
        cout << "3. To display all data." << endl;
        cout << "4. To search by key." << endl;
        cout << "5. To delete data." << endl;
        cout << "6. To exit." << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            list.addAtStart();

            break;
        }
        case 2:
        {
            list.addAtEnd();

            break;
        }
        case 3:
        {
            list.viewAllData();

            break;
        }
        case 4:
        {
            list.searchByKey();

            break;
        }
        case 5:
        {
            list.deleteByKey();

            break;
        }
        case 6:
        {
            cout << "\n-----------------------------------------------\n";
            cout << "Thank You.";
            cout << "\n-----------------------------------------------\n";

            break;
        }
        }

    } while (choice != 6);

    return 0;
}