#include <iostream>
#include <vector>

using namespace std;

class Sort
{
public:
    void display(vector<int>);

    void selectionSort(vector<int> &);
    void merge(vector<int> &, int, int, int);
    void mergeSort(vector<int> &, int, int);

    int linearSearch(vector<int>, int);
    int binarySearch(vector<int>, int, int, int);
};

int main()
{
    Sort sorter;

    int size, sortChoice, searchChoice;

    cout << "Please enter size of array: ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Please enter data: ";
        cin >> arr[i];
    }

    sorter.display(arr);

    cout << endl;
    cout << "0. For exit." << endl;
    cout << "1. For selection Sort." << endl;
    cout << "2. For merge Sort." << endl;
    cout << "Please enter your choice: ";
    cin >> sortChoice;

    switch (sortChoice)
    {
    case 0:
    {
        cout << "\n-------------------------------\n";
        cout << "Exiting.... Thank You.";
        cout << "\n-------------------------------\n";
        break;
    }
    case 1:
    {
        sorter.selectionSort(arr);
        sorter.display(arr);
        break;
    }
    case 2:
    {
        sorter.mergeSort(arr, 0, arr.size() - 1);
        sorter.display(arr);
        break;
    }
    }

    do
    {
        cout << endl;
        cout << "0. For exit." << endl;
        cout << "1. To perform Linear Search." << endl;
        cout << "2. To perform Binary Search." << endl;
        cout << "Please enter your choice: ";
        cin >> searchChoice;

        switch (searchChoice)
        {
        case 0:
        {
            cout << "\n-------------------------------\n";
            cout << "Exiting.... Thank You.";
            cout << "\n-------------------------------\n";

            break;
        }
        case 1:
        {
            int key;
            cout << "Please Enter value to search: ";
            cin >> key;
            int index = sorter.linearSearch(arr, key);
            if (index != -1)
            {
                cout << "Value found at index " << index << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }
            break;
        }
        case 2:
        {
            int key;
            cout << "Please enter value to search: ";
            cin >> key;
            int index = sorter.binarySearch(arr, 0, arr.size() - 1, key);
            if (index != -1)
            {
                cout << "Value found at index " << index << endl;
            }
            else
            {
                cout << "Value not found." << endl;
            }

            break;
        }
        }

    } while (searchChoice != 0);
}

void Sort::display(vector<int> arr)
{
    cout << "\n-------------------------------\n";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n-------------------------------\n";
}

void Sort::selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int Sort::linearSearch(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }

    return -1;
}

int Sort::binarySearch(vector<int> arr, int start, int end, int key)
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

void Sort::merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void Sort::mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}