#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include "Hotel.h"
#include "Transactions.h"
#include "TravelAgency.h"
using namespace std;

class TravelAgency;
class Hotel;
class Transactions;

class Customer
{
private:
    string name;

    string email;

    float account_balance;

    list<TravelAgency *> travel_agencies;

    list<Transactions *> transactions;

    list<Hotel *> hotels;

    Hotel *find_hotel(string name);
    Transactions *find_transaction(int id);
    TravelAgency *find_travel_agency(string name);

public:
    Customer(string name, string email, float account_balance);

    ~Customer();

    void set_name(string name);

    void set_email(string email);

    void set_account_balance(float account_balance);

    string get_name();

    string get_email();

    float get_account_balance();

    bool book_hotel(int id, Hotel *hotel, TravelAgency *travel_agency);

    bool cancel_booking(int id, Hotel *hotel, TravelAgency *travel_agency);

    // void remove_all_transactions();

    // void remove_all_hotels() {

    // }

    // void remove_all_travel_agencies(TravelAgency* travel_agency);

    // bool add_transaction(Transactions* transaction);

    // bool remove_transaction(Transactions* transaction);

    bool add_hotel(Hotel *hotel);

    bool remove_hotel(string name);

    // void remove_travel_agency(TravelAgency* travel_agency);

    // bool add_travel_agency(TravelAgency* travel_agency);
};

#endif