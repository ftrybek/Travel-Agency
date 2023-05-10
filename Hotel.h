#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include "Customer.h"
#include "Transactions.h"
#include "TravelAgency.h"
using namespace std;

class Customer;
class TravelAgency;
class Transactions;

class Hotel
{
    private:

        string name;

        string adress;

        string room_type;

        int stay_nights;

        float price;

        list<Customer*> customers;

        list<Transactions*> transactions;

        list<TravelAgency*> travel_agencies;

        Customer* find_customer(string name);
        Transactions* find_transaction(int id);
        TravelAgency* find_travel_agency(string name);

    public:

        Hotel();

        Hotel(string name, string adress, string room_type, int stay_nights, float price);

        ~Hotel();

        bool add_customer();

        bool remove_customer();

        void remove_all_transactions();

        void remove_all_customers();

        void remove_travel_agencies(TravelAgency* travel_agency);

        bool add_transaction(Transactions* transaction);

        bool remove_transaction(Transactions* transaction);

        bool add_travel_agency(TravelAgency* travel_agency);

        bool remove_travel_agency(TravelAgency* travel_agency);

        string get_name();

        string get_adress();

        string get_room_type();

        int get_stay_nights();

        float get_price();

        void set_name(string name);

        void set_adress(string adress);

        void set_room_type(string room_type);

        void set_stay_nights(int stay_nights);

        void set_price(float price);
};

#endif