#include "Customer.h"

Customer::Customer(string name, string email, float account_balance)
{
    this->name = name;
    this->email = email;
    this->account_balance = account_balance;
}

Customer::~Customer()
{
    travel_agencies.clear();
    hotels.clear();
    transactions.clear();
}

void Customer::set_name(string name)
{
    this->name = name;
}

void Customer::set_email(string email)
{
    this->email = email;
}

void Customer::set_account_balance(float account_balance)
{
    this->account_balance = account_balance;
}

string Customer::get_name()
{
    return this->name;
}

string Customer::get_email()
{
    return this->email;
}

float Customer::get_account_balance()
{
    return this->account_balance;
}

Hotel *Customer::find_hotel(string name)
{
    for (auto it = hotels.begin(); it != hotels.end(); ++it)
    {
        if ((*it)->get_name() == name)
        {
            return *it;
        }
    }
    return nullptr;
}

Transactions *Customer::find_transaction(int id)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it)
    {
        if ((*it)->get_id() == id)
        {
            return *it;
        }
    }
    return nullptr;
}

TravelAgency *Customer::find_travel_agency(string name)
{
    for (auto it = travel_agencies.begin(); it != travel_agencies.end(); ++it)
    {
        if ((*it)->get_name() == name)
        {
            return *it;
        }
    }
    return nullptr;
}

bool Customer::book_hotel(int id, Hotel *hotel, TravelAgency *travel_agency)
{
    if (travel_agency == nullptr)
    {
        return false;
    }
    string type = "booking";
    // travel_agency->add_transaction(id, type, this, hotel);
    return true;
}

bool Customer::cancel_booking(int id, Hotel *hotel, TravelAgency *travel_agency)
{
    string type = "cancelling";
    // travel_agency->add_transaction(id, type, this, hotel);
    return true;
}

void Customer::remove_all_transactions()
{
    transactions.clear();
}

void Customer::remove_all_hotels()
{
    hotels.clear();
}
// void remove_all_travel_agencies(TravelAgency* travel_agency);
// void Customer::Remove_StockMarket(StockMarket* stockmarket)
// {
//     auto it = stockmarkets.begin();
//     stockmarkets.erase(
//         remove_if(
//             stockmarkets.begin(),
//             stockmarkets.end(),
//             [stockmarket](auto t) { return t == stockmarket; }
//         ),
//         stockmarkets.end()
//     );
// }



bool Customer::add_hotel(Hotel *hotel)
{
    if (hotel == nullptr)
    {
        return false;
    }
    if (find_hotel(hotel->get_name()))
    {
        return false;
    }
    hotels.__emplace_back(hotel);
    return true;
}

bool Customer::remove_hotel(string name)
{
    if (find_hotel(name) == nullptr)
    {
        return false;
    }
    for (auto it = hotels.begin(); it != hotels.end(); ++it)
    {
        if ((*it)->get_name() == name)
        {
            hotels.erase(it);
            return true;
        }
    }
    return false;
}

bool Customer::add_travel_agency(TravelAgency *travel_agency)
{
    if (travel_agency == nullptr)
    {
        return false;
    }
    if (find_travel_agency(travel_agency->get_name()))
    {
        return false;
    }
    travel_agencies.__emplace_back(travel_agency);
    return true;
}

bool Customer::remove_travel_agency(string name)
{
    if (find_travel_agency(name) == nullptr)
    {
        return false;
    }
    for (auto it = travel_agencies.begin(); it != travel_agencies.end(); ++it)
    {
        if ((*it)->get_name() == name)
        {
            travel_agencies.erase(it);
            return true;
        }
    }
    return false;
}
// bool add_transaction(Transactions* transaction);

// bool remove_transaction(Transactions* transaction);