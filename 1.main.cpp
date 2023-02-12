#include <iostream>

using namespace std;
class employee
{
protected:
    int id;
    string name;
    double payment;

public:
    employee (int id, string name, double payment);
    ~employee();
    void show()
    {
        cout << "employee name:"<< name << endl;
        cout << "employee id:"<< id << endl;
    }
};
employee::employee(int id, string name, double payment)
{
    this->id = id, this->name = name, this->payment = payment;
}
employee::~employee()
{

}
class worker : public employee
{
public:
    worker(int id, string name, double payment);
    ~worker();
    double extra_hours(int hour)
    {
        int extra = hour*200;
        payment +=extra;
        return extra;
    }
    void total_income()
    {
     cout << "total income of" << name << "is" << payment << endl;
    }
};
worker ::worker(int id, string name, double payment) : employee(id,name,payment)
{
}
class vendor : public employee
{
public:
    vendor(int id, string name, double payment);
    ~vendor();
    double deductionpercentage(int deduction)
    {
        double reduceamount = payment * (deduction/100);
        payment-= reduceamount;
        return reduceamount;
    }
    void total_income()
    {
        cout << "total income of" << name << "is" << payment << endl;
    }
};
vendor::vendor(int id, string name, double payment) : employee(id,name,payment)
{
}

vendor::~vendor()
{
}
