#include <iostream>
#include <vector>

using namespace std;

class Student
{
private:
    int id;
    string name;

public:
    Student(int id, string name)
    {
        this->name = name;
        this->id = id;
    }

    void viewStudentInfo()
    {
        cout << "\n-----------------------------------\n";
        cout << "ID  : " << this->id << endl;
        cout << "Name: " << this->name;
        cout << "\n-----------------------------------\n";
    }

    int getId()
    {
        return this->id;
    }
};

class StudentManager
{
private:
    vector<Student> students;

public:
    void addStudent()
    {
        int id;
        string name;

        cout << "Please enter student id :";
        cin >> id;

        cin.ignore();

        cout << "Please enter student name: ";
        getline(cin, name);

        Student newStudent(id, name);
        students.push_back(newStudent);

        cout << "\n-----------------------------------\n";
        cout << "Student added successfully.";
        cout << "\n-----------------------------------\n";
    }

    void viewAllStudents()
    {
        if (students.size() == 0)
        {
            cout << "\n-----------------------------------\n";
            cout << "Sorry, No students to show.";
            cout << "\n-----------------------------------\n";
            return;
        }
        for (int i = 0; i < students.size(); i++)
        {
            students[i].viewStudentInfo();
        }
    }

    void removeStudentById()
    {
        if (students.size() == 0)
        {
            cout << "\n-----------------------------------\n";
            cout << "Sorry, No students to remove.";
            cout << "\n-----------------------------------\n";
            return;
        }

        int id;
        bool found;

        cout << "Please enter student id: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                found = true;
                students.erase(students.begin() + i);

                cout << "\n-----------------------------------\n";
                cout << "Student removed successfully.";
                cout << "\n-----------------------------------\n";
            }
        }
        if (!found)
        {
            cout << "\n-----------------------------------\n";
            cout << "Sorry, student not found.";
            cout << "\n-----------------------------------\n";
        }
    }

    void searchStudentById()
    {
        if (students.size() == 0)
        {
            cout << "\n-----------------------------------\n";
            cout << "No students to search.";
            cout << "\n-----------------------------------\n";
            return;
        }

        int id;
        bool found;

        cout << "Please Enter student id: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                found = true;
                students[i].viewStudentInfo();
            }
        }
        if (!found)
        {
            cout << "\n-----------------------------------\n";
            cout << "Sorry, student not found.";
            cout << "\n-----------------------------------\n";
        }
    }
};

int main()
{
    StudentManager manager;
    int choice;

    do
    {
        cout << endl;
        cout << "1. To add Student." << endl;
        cout << "2. To remove Student by ID." << endl;
        cout << "3. To view all Students." << endl;
        cout << "4. To search student by ID." << endl;
        cout << "5. To exit." << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            manager.addStudent();

            break;
        }
        case 2:
        {
            manager.removeStudentById();

            break;
        }
        case 3:
        {
            manager.viewAllStudents();

            break;
        }
        case 4:
        {
            manager.searchStudentById();

            break;
        }
        case 5:
        {
            cout << "\n-----------------------------------\n";
            cout << "Thank You.";
            cout << "\n-----------------------------------\n\n";

            break;
        }
        }
    } while (choice != 5);

    return 0;
}