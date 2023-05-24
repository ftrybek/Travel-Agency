#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <string>
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

    bool add_customer(Customer *customer);
    bool remove_customer(string name);
    bool add_hotel(Hotel *hotel);
    bool remove_hotel(string name);
    bool add_transaction(int id, string type, Customer *customer, Hotel *hotel, TravelAgency *travel_agency);
    // bool remove_transaction(Transactions *transaction);
    bool check_transaction(int id, string type, Customer *customer, Hotel *hotel);

    void show_customers();
    void show_hotels();
    void show_transactions();
    void show_unique_transactions(const string &name);
    void print_customer(string name);
    void print_hotel(string name);
    void print_transaction(const int &id);

    void set_name(string name);
    string get_name();
    Customer *get_customer(string name);
    Hotel *get_hotel(string name);
    Transactions *get_transaction(int id);
    TravelAgency *get_travel_agency();

private:
    Customer *find_customer(string name);
    Transactions *find_transaction(int id);
    Hotel *find_hotel(string name);

private:
    string name;
    list<Customer *> customers;
    list<Transactions> transactions;
    list<Hotel *> hotels;
};

#endif