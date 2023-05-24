#include "Transactions.h"

Transactions::Transactions(int id, string type, Customer *customer, Hotel *hotel, TravelAgency *travel_agency)
{
    this->id = id;
    this->type = type;
    this->customer = customer;
    this->hotel = hotel;
    this->travel_agency = travel_agency;
}

Transactions::~Transactions()
{
}

int Transactions::get_id()
{
    return this->id;
}

string Transactions::get_type()
{
    return this->type;
}

Customer *Transactions::get_customer()
{
    return customer;
}

Hotel *Transactions::get_hotel()
{
    return hotel;
}

TravelAgency *Transactions::get_travel_agency()
{
    return travel_agency;
}
