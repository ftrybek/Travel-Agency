#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <algorithm>
#include "Customer.h"
#include "Hotel.h"
#include "TravelAgency.h"
using namespace std;

class Customer;
class Hotel;
class TravelAgency;

class Transactions
{
private:
    int id;

    string type;

    Customer *customer;

    Hotel *hotel;

    TravelAgency *travel_agency;

public:
    Transactions(int id, string type, Customer *customer, Hotel *hotel, TravelAgency *travel_agency);

    ~Transactions();

    int get_id();

    string get_type();

    Customer *get_customer();

    Hotel *get_hotel();

    TravelAgency *get_travel_agency();

    // void print_transaction();

    // bool is_enough_balance();
};

#endif