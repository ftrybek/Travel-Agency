#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include "Customer.h"
#include "Hotel.h"
#include "Transactions.h"
using namespace std;

class Customer;
class Hotel;
class Transactions;

class TravelAgency
{

public:
    TravelAgency();

    TravelAgency(string name);

    ~TravelAgency();

    void set_name(string name);

    string get_name();

    Customer *get_customer(string name);

    Hotel *get_hotel(string name, string adress);

    Transactions *get_transaction(int id, string name_customer, string name_hotel);

    TravelAgency *get_travel_agency();

    bool add_customer(Customer *customer);

    bool remove_customer(string name);

    bool add_hotel(Hotel *hotel);

    bool remove_hotel(string name);

    bool add_transaction(int id, string type, Customer *customer, Hotel *hotel, TravelAgency *travel_agency);

    // bool remove_transaction(Transactions *transaction);

    void show_customers();

    void show_hotels();

    // void show_transactions();

    void print_customer(string name);

    void print_hotel(string name, string adress);

    void print_transaction(const int &id);

    // void show_unique_transactions(const string &name);

    // bool check_transaction(int id, string type, Customer *customer, Hotel *hotel);

    // void allocate_pointers(TravelAgency *travel_agency, Customer *customer, Hotel *hotel, Transactions *transaction, string type);

private:
    Customer *find_customer(string name);
    Transactions *find_transaction(int id);
    Hotel *find_hotel(string name);

private:
    string name;
    list<Customer *> customers;
    list<Transactions *> transactions;
    list<Hotel *> hotels;
};

#endif