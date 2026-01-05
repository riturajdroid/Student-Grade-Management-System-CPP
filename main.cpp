#include <iostream>
#include <vector>
using namespace std;

class Student
{
    string name;
    int rollNumber;
    vector<int> grades;
    vector<string> subjects;

public:
    Student(string a, int r)
    {
        name = a;
        rollNumber = r;
    }

    void addGrade(string subject, int grade)
    {
        if (grade >= 0 && grade <= 100)
        {
            subjects.push_back(subject);
            grades.push_back(grade);
            cout << "the subject " << subject << " is added with grade " << grade << " is now added" << endl;
        }
        else
        {
            cout << "incorrect format";
        }
    }

    double calculateAverage()
    {
        vector<int>::iterator itr = grades.begin();
        float sum = 0.0;
        for (int i = 0;; i++)
        {

            if (itr != grades.end())
            {
                sum += *itr;
            }
            else
            {
                break;
            }
            itr++;
        }
        return sum / grades.size();
    }
    char getLetterGrade()
    {
        double percentage = calculateAverage();
        if (percentage >= 90)
        {

            return 'A';
        }
        else if (percentage >= 80 && percentage < 90)
        {
            return 'B';
        }
        else if (percentage >= 70 && percentage < 80)
        {
            return 'C';
        }
        else if (percentage >= 60 && percentage < 70)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    void displayReport()
    {
        cout << "Name: " << name << endl;
        cout << "Roll number " << rollNumber << endl;
        cout << "Grades:" << endl;

        vector<int>::iterator itr_grd = grades.begin();
        vector<string>::iterator itr_sub = subjects.begin();
        for (int i = 0;; i++)
        {
            if (itr_grd != grades.end())
            {
                cout << *itr_sub << "    " << *itr_grd << endl;
            }
            else
            {
                break;
            }
            itr_grd++;
            itr_sub++;
        }
        cout << "Average:" << calculateAverage() << endl;
        cout << "Letter grade" << getLetterGrade() << endl;
    }

    int getrollNumber()
    {
        return rollNumber;
    }
};

class GradeBook
{
    vector<Student> student;

public:
    void addStudent(Student s)
    {
        student.push_back(s);
    }

    void removeStudent(int rollNumber)
    {
        vector<Student>::iterator itr = student.begin();
        for (int i = 0;; i++)
        {

            if (itr != student.end())
            {
                if ((*itr).getrollNumber() == rollNumber)
                {
                    student.erase(itr);
                    break;
                }
            }
            else
            {
                break;
            }
            itr++;
        }
    }
    Student *findStudent(int rollNumber)
    {
        vector<Student>::iterator itr = student.begin();
        for (int i = 0;; i++)
        {
            if (itr != student.end())
            {
                if ((*itr).getrollNumber() == rollNumber)
                {
                    return &(*itr);
                    break;
                }
            }
            else
            {
                break;
            }
            itr++;
        }

        return nullptr;
    }

    void displayAllStudent()
    {
        vector<Student>::iterator itr = student.begin();
        for (int i = 0;; i++)
        {
            if (itr != student.end())
            {
                (*itr).displayReport();
            }

            else
            {
                break;
            }
            itr++;
        }
    }
    void displayTopPerformers(int n) // dont know about <algorithm> as of present
    {
        vector<Student>::iterator itr = student.begin();
        for (int i = 0; i < n; i++)
        {
            if (itr != student.end())
            {
                (*itr).displayReport();
            }

            else
            {
                break;
            }
            itr++;
        }
    }

    double getClassAverage()
    {
        vector<Student>::iterator itr = student.begin();
        float sum = 0;
        for (int i = 0;; i++)
        {
            if (itr != student.end())
            {
                sum += (*itr).calculateAverage();
            }
            else
            {
                break;
            }
            itr++;
        }
        return sum / student.size();
    }
};

int main()
{
    GradeBook book;
    while (1)
    {
        string name;
        int num, roll;
        cout << "(1)Add new student" << endl;
        cout << "(2)Add grade to existing student" << endl;
        cout << "(3)Display specific student report" << endl;
        cout << "(4)Display all students" << endl;
        cout << "(5)Display top 3 performers" << endl;
        cout << "(6)Display class average" << endl;
        cout << "(7)Remove student" << endl;
        cout << "(8)Exit" << endl;
        cout << "Enter the number you want to access" << endl;
        cin >> num;
        switch (num)
        {
        case 1:
        {
            cout << "Enter first name of the student and roll number : ";
            cin >> name >> roll;

            Student stu(name, roll);
            book.addStudent(stu);
            break;
        }
        case 2:
        {
            cout << "Enter the roll number of student";
            cin >> roll;

            Student *address = book.findStudent(roll);
            if (address != nullptr)
            {
                while (1)
                {
                    string subject;
                    int marks;
                    cout << "Enter the Name of Subject and Marks out of 100";
                    cin >> subject >> marks;
                    if (subject == "-1" && marks == -1)
                    {
                        break;
                    }
                    else
                    {
                        address->addGrade(subject, marks);
                    }
                }
            }
            else
            {
                cout << "Student not found!" << endl;
                break;
            }

            break;
        }
        case 3:
        {
            cout << "Enter the roll number of student";
            cin >> roll;
            Student *address = book.findStudent(roll);
            if (address != nullptr)
            {
                address->displayReport();
            }
            else
            {
                cout << "Student not found!" << endl;
            }
            break;
        }
        case 4:
        {
            book.displayAllStudent();
            break;
        }
        case 5:
        {
            book.displayTopPerformers(3);
            break;
        }
        case 6:
        {
            cout << "Class Average is " << book.getClassAverage();
            break;
        }
        case 7:
        {
            cout << "Enter the roll number of student: ";
            cin >> roll;
            Student *address = book.findStudent(roll);
            if (address != nullptr)
            {
                book.removeStudent(roll);
                cout << "Student removed successfully!" << endl;
            }
            else
            {
                cout << "Student not found!" << endl;
            }
            break;
        }
        case 8:
        {
            exit(0);
        }

        default:
        {
            cout << "Invalid" << endl;
            break;
        }
        }
        cout << endl;
    }

    return 0;
}