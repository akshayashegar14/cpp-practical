
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
public:
    string name;
    int mark;
    char grade;
};

int main()
{
    // Student Records
    vector<Student> students = {
        {"Priya", 88, ' '},
        {"Vikram", 76, ' '},
        {"Sneha", 94, ' '},
        {"Rahul", 69, ' '}
    };

    // Sort students in descending order of marks
    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.mark > b.mark;
         });

    // Assign grades using transform
    transform(students.begin(), students.end(),
              students.begin(),
              [](Student s)
              {
                  if (s.mark >= 90)
                      s.grade = 'A';
                  else if (s.mark >= 80)
                      s.grade = 'B';
                  else if (s.mark >= 60)
                      s.grade = 'C';
                  else
                      s.grade = 'F';

                  return s;
              });

    // Find first student scoring above 85
    auto it = find_if(students.begin(), students.end(),
                      [](const Student &s)
                      {
                          return s.mark > 85;
                      });

    // Calculate total marks
    int total = accumulate(students.begin(), students.end(), 0,
                           [](int sum, const Student &s)
                           {
                               return sum + s.mark;
                           });

    float average = (float)total / students.size();

    // Display student results
    cout << "\n========================================" << endl;
    cout << "       STUDENT PERFORMANCE REPORT       " << endl;
    cout << "========================================" << endl;

    cout << "\nName\t\tMarks\tGrade" << endl;
    cout << "----------------------------------------" << endl;

    for (const Student &s : students)
    {
        cout << left << setw(16) << s.name
             << setw(8) << s.mark
             << s.grade << endl;
    }

    cout << "----------------------------------------" << endl;

    if (it != students.end())
    {
        cout << "\nTop Scoring Student: " << it->name << endl;
        cout << "Marks Obtained     : " << it->mark << endl;
    }

    cout << "\nTotal Marks   : " << total << endl;
    cout << "Average Marks : " << fixed << setprecision(2)
         << average << endl;

    cout << "\n========================================" << endl;
    cout << "       REPORT GENERATED SUCCESSFULLY    " << endl;
    cout << "========================================" << endl;

    return 0;
}
