#include <iostream>

using namespace std;
class student;
class person
{
private:
    string name;
    int age;
    string gender;
public:
    person();
    ~person();
    void setinfo(string name,int age,string gender)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void showinfo()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Gender:" << gender << endl;
    }
    friend class student;
};
person::person()
{
}
person::~person()
{
}
class student:public virtual person
{
protected:
    double cgpa;
    string studentid;
public:
    student();
    student(double cgpa, string studentid, string department);
bool eligible;
    ~student();
    string department;
    void showstdinfo()
    {
     person::showinfo();
     cout << "CGPA:" << cgpa << endl;
     cout << "Student Id:" << studentid << endl;
     cout << "Department:" << department << endl;
    }
};
student::student(double cgpa, string studentid, string department)
{
    this->cgpa = cgpa;
    this->studentid = studentid;
    this->department = department;
}
student::student()
{
}
student::~student()
{
}
class scholarshipStudent: public student
{
private:
    double percentage;
public:
 scholarshipStudent(double cgpa, string studentid, string department, double percentage);
~scholarshipStudent();
bool eligible()
{
    if (cgpa >= 3.75)
    {
        return true;
    }
    return false;
}
};
scholarshipStudent::scholarshipStudent(double cgpa, string studentid, string department, double percentage): student(cgpa, studentid, department)
{
    this->percentage = percentage;
}
scholarshipStudent::~scholarshipStudent()
{
}
class Teacher : public virtual person
{
private:
    int salary;
    string employeeid;
    string faculty;

public:
    Teacher();
    ~Teacher();
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }
    void setemployeeid(string employeeid)
    {
        this->employeeid = employeeid;
    }
    string getemployeeid()
    {
        return employeeid;
    }
    void setfaculty(string faculty)
    {
     this->faculty = faculty;
    }
    string getfaculty()
    {
        return faculty;
    }
    void showinfo()
    {
        person::showinfo();
        cout << "Faculty:" << faculty << endl;
        cout << "Employee Id:" << employeeid << endl;
    }

};
Teacher::Teacher()
{
}
Teacher::~Teacher()
{
}
class TeachingAssistant : public student, public Teacher
{
public:
    TeachingAssistant();
    ~TeachingAssistant();
    int classhour;
    void showinfo()
    {
        Teacher::showinfo();
        cout << "Class Hour:" << classhour << endl;
    }
};
TeachingAssistant::TeachingAssistant()
{
    classhour = 0;
}
TeachingAssistant::~TeachingAssistant()
{
}
class officer: public person
{
private:
    int workinghour;
    int overtime;
public:
    officer(int workinghour);
    ~officer();
    double payment(int standard = 1500)
    {
        return (standard*8) + (overtime*2000);
    }
};
officer::officer(int workinghour)
{
    this->workinghour = workinghour;
    if (workinghour >= 8)
    {
        overtime = workinghour - 8;
    }
    else
    {
        overtime = 0;
    }
}

officer::~officer()
{
}

int main()
{
    person p1;
    p1.setinfo("Amran Hossain", 20, "Male");
    p1.showinfo();
    cout << endl;
    student S1(3.50, "21-49418-1", "EEE");
    S1.setinfo("Rafsan Rounak", 19, "Male");
    S1.showstdinfo();
    if (S1.eligible)
    {
        cout << "Eligible for scholarship" << endl;
    }
    else
    {
        cout << "Not eligible for scholarship" << endl;
    }
    cout << endl;
    Teacher t1;
    t1.setinfo("Mahjabin Mahima", 25, "Female");
    t1.setfaculty("EEE");
    cout << "Faculty:" << t1.getfaculty()<< endl;
    t1.setemployeeid("33-45454-46");
    cout << "Employee ID:" <<t1.getemployeeid()<< endl;
    t1.setSalary(34558);
    t1.showinfo();
    cout << "Salary:" << t1.getSalary() << endl;
    cout << endl;
    TeachingAssistant T1;
    T1.classhour = 10;
    T1.setinfo("Rafi Alam", 23 , "Male");
    T1.setemployeeid("33-5576-47");
    T1.setfaculty("EEE");
    T1.setSalary(33450);
    T1.showinfo();
    cout << "Salary:" << T1.getSalary() << endl;
    cout << endl;
    officer O1(12);
    O1.setinfo("Mugdho Khan", 22, "Male");
    O1.showinfo();
    cout << "Payment:" << O1.payment(1600) << endl;
    return 0;
}
