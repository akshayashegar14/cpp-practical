
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    string department;
    string college;

public:
    
    Student(int r, string n, string d, string c)
    {
        rollNo = r;
        name = n;
        department = d;
        college = c;

        cout << "Student object created successfully!" << endl;
    }

    
    void display()
    {
        cout << "\n----- Student Information -----" << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Department  : " << department << endl;
        cout << "College     : " << college << endl;
    }

    
    ~Student()
    {
        cout << "\nStudent object destroyed successfully!" << endl;
    }
};

int main()
{
    Student s1(205, "Priya", "CSE", "Chennai Institute of Technology");

    s1.display();

    return 0;
}
