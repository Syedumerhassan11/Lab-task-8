#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) 
        : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() = 0;
    void updateInfo(string a, string p, string e) { address = a; phoneNumber = p; email = e; }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, double g, int year)
        : Person(n, i, a, p, e), GPA(g), enrollmentYear(year) {}

    void enrollCourse(string course) { coursesEnrolled.push_back(course); }
    void displayInfo() override { cout << name << " " << id << " " << GPA << " " << enrollmentYear << endl; }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string dept, double sal)
        : Person(n, i, a, p, e), department(dept), salary(sal) {}

    void assignCourse(string course) { coursesTaught.push_back(course); }
    void displayInfo() override { cout << name << " " << id << " " << department << " " << salary << endl; }
};

class Staff : public Person {
    string position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string pos, double sal)
        : Person(n, i, a, p, e), position(pos), salary(sal) {}

    void displayInfo() override { cout << name << " " << id << " " << position << " " << salary << endl; }
};

class Course {
    string courseId, courseName, instructor, schedule;
public:
    Course(string id, string name, string instr, string sched) 
        : courseId(id), courseName(name), instructor(instr), schedule(sched) {}

    void registerStudent(Student &s) { s.enrollCourse(courseName); }
    double calculateGrade() { return 0; }
};

int main() {
    Student s("Alice", "S001", "123 St", "123456", "alice@mail.com", 3.8, 2022);
    Professor p("Dr. Bob", "P001", "456 St", "789123", "bob@mail.com", "CS", 80000);
    Staff st("Charlie", "ST001", "789 St", "456789", "charlie@mail.com", "Admin", 50000);

    Course c("CS101", "Intro to CS", "Dr. Bob", "MWF 10AM");
    c.registerStudent(s);

    s.displayInfo();
    p.displayInfo();
    st.displayInfo();

    return 0;
}

