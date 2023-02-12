#include <iostream>

using namespace std;
class Directory
{
protected:
    string personName;
    string dateOfBirth;
public:
    void setPersonInfo(string pn, string db)
    {
        personName = pn;
        dateOfBirth = db;
    }
    void displayInfo1()
    {
         cout << "Name:" << personName << endl;
         cout << "Date Of Birth:" << dateOfBirth << endl;
    }
};
class NationalDirectory : public Directory
{
protected:
    int personAge;
    string personCity;
public:
    void setPersonAge(int age)
    {
        personAge = age;
    }
    void setPersonCity(string city)
    {
        personCity = city;
    }
    void displayInfo2()
    {
        cout << "Age:" << personAge << endl;
        cout << "City:" << personCity << endl;
    }
};
class LocalDirectory : public NationalDirectory
{
protected:
    string personAddress;
    string personTelNo;
    string personLocalArea;
    double zipCode;
public:
    void setPersonAddress(string address)
    {
        personAddress = address;
    }
    void setPersonTelNo(string telNo)
    {
        personTelNo = telNo;
    }
    void setPersonLocalArea(string Larea)
    {
        personLocalArea = Larea;
    }
    void setPersonZipcode(double zc)
    {
        zipCode = zc;
    }
    void displayInfo3()
    {
        cout << "Address:"<< personAddress << endl;
        cout << "Phone number:" << personTelNo << endl;
        cout << "Local area:" << personLocalArea << endl;
        cout << "Post code:" << zipCode << endl;
    }

};
class Profession : public LocalDirectory
{
protected:
    string personProfession;
    string personInstitution;
    string personGrade;
    double personSalary;
public:
    void setPersonProfession(string prof)
    {
        personProfession = prof;
    }
    void setPersonInstitution(string inst)
    {
        personInstitution = inst;
    }
    void setPersonGrade(string Pgrade)
    {
        personGrade = Pgrade;
    }
    void setPersonSalary(double S)
    {
        personSalary = S;
    }
    void displayInfo4()
    {
        cout << "Profession:"<< personProfession << endl;
        cout << "Organization:" << personInstitution << endl;
        cout << "Pay grade:" << personGrade << endl;
        cout << "Salary:" << personSalary << endl;
    }

};
int main()
{
    Profession person;
    person.setPersonInfo("Risat","18 November 2003");
    person.setPersonAge(19);
    person.setPersonCity("Narsingdi");
    person.setPersonAddress("18,Rangamati Road");
    person.setPersonTelNo("016******56");
    person.setPersonLocalArea("Rnagamati");
    person.setPersonZipcode(1600);
    person.setPersonProfession("General Manager");
    person.setPersonInstitution("NGGHS");
    person.setPersonGrade("First");
    person.setPersonSalary(130000);
    person.displayInfo1();
    person.displayInfo2();
    person.displayInfo3();
    person.displayInfo4();
    return 0;
}
