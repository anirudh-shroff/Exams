#include <iostream>
#include <vector>


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
    Node *HEAD;
    int counter = 0;


public:
    LinkedList()
    {
        HEAD = nullptr;
    }


    void addAtStart()
    {
        int data;
        cout << "Please enter data to insert: ";
        cin >> data;


        Node *newNode = new Node(data);


        newNode->next = HEAD;
        HEAD = newNode;
        cout << "\n----------------------------------------\n";
        cout << "Successfully inserted at the beginning.";
        cout << "\n----------------------------------------\n";


        counter++;
    }


    void viewData()
    {
        if (counter == 0 || HEAD == nullptr)
        {
            cout << "\n----------------------------------------\n";
            cout << "List is empty.";
            cout << "\n----------------------------------------\n";
            return;
        }


        Node *temp;
        temp = HEAD;
        cout << "\n----------------------------------------\n";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
        cout << "\n----------------------------------------\n\n";
    }


    void updateData()
    {
        if (counter == 0 || HEAD == nullptr)
        {
            cout << "\n----------------------------------------\n";
            cout << "List is empty.";
            cout << "\n----------------------------------------\n";
            return;
        }


        int data, pos;


        cout << "Please enter position to update data at: ";
        cin >> pos;
        cout << "Please enter new data to insert: ";
        cin >> data;


        if (pos >= counter)
        {
            cout << "\n----------------------------------------\n";
            cout << "Invalid Position.";
            cout << "\n----------------------------------------\n\n";
            return;
        }


        Node *temp;
        temp = HEAD;


        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }


        temp->data = data;


        cout << "\n----------------------------------------\n";
        cout << "Data Updated Successfully.";
        cout << "\n----------------------------------------\n\n";
    }
};


int binarySearch(vector<int> &arr, int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }


    int mid = (start + end) / 2;


    if (key == arr[mid])
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, end, key);
    }
}


void display(vector<int> &arr)
{
    cout << "\n-----------------------------------------\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n-----------------------------------------\n";
}


int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;


    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }


    int pIdx = start + count;


    int temp = arr[pIdx];
    arr[pIdx] = arr[start];
    arr[start] = temp;


    int i = start;
    int j = end;


    while (i < pIdx && j > pIdx)
    {
        while (arr[i] < pivot)
        {
            i++;
        }


        while (arr[j] > pivot)
        {
            j--;
        }


        if (i < pIdx && j > pIdx)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;


            i++;
            j--;
        }
    }


    return pIdx;
}


void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }


    int pIdx = partition(arr, start, end);


    quickSort(arr, start, pIdx - 1);
    quickSort(arr, pIdx + 1, end);
}


int main()
{
    int menuChoice;
    int listChoice;


    do
    {
        cout << endl;
        cout << "0. To exit." << endl;
        cout << "1. To Perform Operations on Linked List." << endl;
        cout << "2. To Perform Quick Sort on array." << endl;
        cout << "3. To Perform Binary Search on array." << endl;
        cout << "Please enter your choice: ";
        cin >> menuChoice;


        switch (menuChoice)
        {
        case 0:
        {
            cout << "\n-----------------------------------------\n";
            cout << "Thank you.";
            cout << "\n-----------------------------------------\n";
            break;
        }
        case 1:
        {


            LinkedList list;


            do
            {
                cout << endl;
                cout << "0. To exit Linked List." << endl;
                cout << "1. To add at start." << endl;
                cout << "2. To view all Data." << endl;
                cout << "3. To update Data." << endl;
                cout << "To enter your choice: ";
                cin >> listChoice;


                switch (listChoice)
                {
                case 0:
                {
                    cout << "\n-----------------------------------------\n";
                    cout << "To return to main menu.";
                    cout << "\n-----------------------------------------\n";
                    break;
                }
                case 1:
                {
                    list.addAtStart();
                    break;
                }
                case 2:
                {
                    list.viewData();
                    break;
                }
                case 3:
                {
                    list.updateData();
                    break;
                }
                }


            } while (listChoice != 0);


            break;
        }
        case 2:
        {
            int size;
            cout << "Please enter size of the array: ";
            cin >> size;
            vector<int> arr(size);


            for (int i = 0; i < arr.size(); i++)
            {
                cout << "Enter data: ";
                cin >> arr[i];
            }


            quickSort(arr, 0, arr.size() - 1);


            display(arr);


            break;
        }
        case 3:
        {
            int size;
            cout << "Please enter size of the array: ";
            cin >> size;
            vector<int> arr(size);


            for (int i = 0; i < arr.size(); i++)
            {
                cout << "Enter data: ";
                cin >> arr[i];
            }
           
            quickSort(arr, 0, arr.size() - 1);
            display(arr);


            int key;
            cout << "Please enter value to search: ";
            cin >> key;
            int idx = binarySearch(arr, 0, arr.size() - 1, key);


            if (idx != -1)
            {
                cout << "\n-----------------------------------------\n";
                cout << "Data found at index " << idx;
                cout << "\n-----------------------------------------\n";
            }
            else
            {
                cout << "\n-----------------------------------------\n";
                cout << "Data not found.";
                cout << "\n-----------------------------------------\n";
            }


            break;
        }
        }
    } while (menuChoice != 0);


    return 0;
}

