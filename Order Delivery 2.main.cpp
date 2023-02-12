#include <iostream>

using namespace std;
class order
{
private:
    int order_id;
    string delivery_location;
    double discount_percentage;
    double price;
public:
    order(int order_id,double price);
    ~order();
    void setdiscount_percentage (double discount_percentage)
    {
        this->discount_percentage = discount_percentage;
        double offer = price * (discount_percentage/100);
        price -= offer;
    }
    double getdiscount_percentage()
    {
        return discount_percentage;
    }
    void setdelivery_location (string deliver_location)
    {
        this->delivery_location = deliver_location;
        price += 50;
    }
    string getdelivery_location()
    {
        return delivery_location;
    }
    void showorder_details()
    {
        cout << "Order no:"<<order_id << endl;
        cout << "Delivery location:"<<delivery_location<< endl;
        cout << "Price:"<< price<< endl;
    }

};

order::order(int order_id,double price)
{
    this->order_id = order_id;
    this->price = price;
}

order::~order()
{
}

int main()
{
    order o1(572809, 340);

    o1.setdelivery_location("Khulna");
    cout << "Delivery location: "<< o1. getdelivery_location() << endl;
    o1. setdiscount_percentage(25);
    cout << "discount:"<< o1. getdiscount_percentage() << endl;
    cout<<endl;
    o1.showorder_details();
    return 0;
}
