#include <iostream>
#include <string>
#include <list>
#include "TravelAgency.h"
#include "Customer.h"
#include "Hotel.h"
#include "Transactions.h"
using namespace std;

int main()
{
    static const std::string TRAVEL_AGENCY_NAME = "ITAKA";

    TravelAgency agency1(TRAVEL_AGENCY_NAME);
    Hotel hotel1("Grand", "London", "single-bed", 3, 400);
    Hotel hotel2("Shibuya", "Tokyo", "double-bed", 2, 249.5);
    Customer cust1("John Wayne", "jw@gmail.com", 1000);
    Customer cust2("Mary Jane", "mj@gmail.com", 2000);
    cout << "Hello" << endl;
    cout << agency1.get_name() << endl;
    cout << hotel1.get_name() << endl;
    cout << hotel1.get_adress() << endl;
    cout << hotel1.get_room_type() << endl;
    cout << hotel1.get_stay_nights() << endl;
    cout << hotel1.get_price() << endl;
    cout << cust1.get_name() << endl;
    cout << cust1.get_email() << endl;
    cout << cust1.get_account_balance() << endl;
    agency1.set_name("RAINBOW");
    cout << agency1.get_name() << endl;
    agency1.add_customer(&cust1);
    agency1.add_customer(&cust2);
    agency1.add_hotel(&hotel1);
    agency1.add_hotel(&hotel2);
    agency1.show_customers();
    agency1.remove_customer("John Wayne");
    cout << "--" << endl;
    agency1.show_customers();
    cout << "--" << endl;
    agency1.show_hotels();
    agency1.remove_hotel("Grand");

    cout << "--" << endl;
    agency1.show_hotels();
    cout << "--" << endl;
    agency1.print_customer("Mary Jane");
    agency1.print_hotel("Shibuya");
    cout<< "CHUUUUJ"<< endl;
    cust1.add_hotel(&hotel2);
    agency1.add_transaction(1234, "booking", &cust2, &hotel2, &agency1);
    agency1.print_transaction(1234);
    agency1.print_customer("Mary Jane");
    cust2.cancel_booking(1111, &hotel2, &agency1);
    agency1.print_transaction(1111);
    agency1.print_customer("Mary Jane");
        cout << "Hello" << endl;
    agency1.show_unique_transactions("Shibuya");

    return 0;
}