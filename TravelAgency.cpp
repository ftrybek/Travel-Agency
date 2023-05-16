#include "TravelAgency.h"

TravelAgency::TravelAgency()
{
    this->name = "";
}

TravelAgency::TravelAgency(string name)
{
    this->name = name;
}

TravelAgency::~TravelAgency()
{
    customers.clear();
    hotels.clear();
    transactions.clear();
}

void TravelAgency::set_name(string name)
{
    this->name = name;
}

string TravelAgency::get_name()
{
    return name;
}

Customer *TravelAgency::get_customer(string name)
{
    return find_customer(name);
}

Hotel *TravelAgency::get_hotel(string name)
{
    return find_hotel(name);
}

Transactions *TravelAgency::get_transaction(int id, string name_customer, string name_hotel)
{
    return find_transaction(id);
}

TravelAgency *TravelAgency::get_travel_agency()
{
    return this;
}

Hotel *TravelAgency::find_hotel(string name)
{
    for (auto &c : hotels)
    {
        if (c->get_name() == name)
        {
            return c;
        }
    }
    return nullptr;
}

Customer *TravelAgency::find_customer(string name)
{
    for (auto &c : customers)
    {
        if (c->get_name() == name)
        {
            return c;
        }
    }
    return nullptr;
}

Transactions *TravelAgency::find_transaction(int id)
{
    // for (auto &c : transactions)
    // {
    //     if (c->get_id() == id)
    //     {
    //         return c;
    //     }
    // }
    // return nullptr;

    for (auto &c : transactions)
    {
        if (c.get_id() == id)
        {
            Transactions *ptr = &c;
            return ptr;
        }
    }
    return nullptr;
}

bool TravelAgency::add_customer(Customer *customer)
{
    if (customer == nullptr)
    {
        return false;
    }
    customers.__emplace_back(customer);
    return true;
}

bool TravelAgency::remove_customer(string name)
{
    Customer *todelete = nullptr;
    todelete = find_customer(name);

    if (todelete == nullptr)
    {
        return false;
    }

    // todelete->remove_all_transactions();
    // todelete->remove_all_hotels();
    // todelete->remove_all_travel_agencies(this);
    // Remove_TransactionCustomer(todelete);

    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (*it == todelete)
        {
            customers.erase(it);
            return true;
        }
    }

    return false;
}

bool TravelAgency::add_hotel(Hotel *hotel)
{
    if (hotel == nullptr)
    {
        return false;
    }
    hotels.__emplace_back(hotel);
    return true;
}

bool TravelAgency::remove_hotel(string name)
{
    Hotel *todelete = nullptr;
    todelete = find_hotel(name);

    if (todelete == nullptr)
    {
        return false;
    }

    // todelete->Remove_AllTransactions();
    // todelete->Remove_AllCustomers();
    // todelete->Remove_StockMarkets(this);
    // Remove_TransactionCompany(todelete);

    for (auto it = hotels.begin(); it != hotels.end(); ++it)
    {
        if ((*it) == todelete)
        {
            hotels.erase(it);
            return true;
        }
    }
    return false;
}

bool TravelAgency::add_transaction(int id, string type, Customer *customer, Hotel *hotel, TravelAgency *travel_agency)
{
    if (!check_transaction(id, type, customer, hotel))
    {
        return false;
    }

    transactions.emplace_back(id, type, customer, hotel, this);

    if (type == "booking")
    {
        customer->set_account_balance(customer->get_account_balance() - hotel->get_price());
    }
    if (type == "cancelling")
    {
        customer->set_account_balance(customer->get_account_balance() + hotel->get_price() / 2);
    }
    // add poinetrs
    // Add_Pointers(customer, company, this, this->Get_Transaction(ID),amountShares,type);
    return true;
}
// bool remove_transaction(Transactions* transaction);

bool TravelAgency::check_transaction(int id, string type, Customer *customer, Hotel *hotel)
{
    if (find_transaction(id) != nullptr && find_transaction(id)->get_travel_agency() == this)
    {
        return false;
    }
    if (customer == nullptr || find_customer(customer->get_name()) == nullptr)
    {
        return false;
    }
    if (hotel == nullptr || find_hotel(hotel->get_name()) == nullptr)
    {
        return false;
    }
    if (hotel->get_stay_nights() < 1)
    {
        return false;
    }
    if (hotel->get_price() < 1)
    {
        return false;
    }
    if (customer->get_account_balance() < hotel->get_price())
    {
        return false;
    }
    if (type != "booking" && type != "cancelling")
    {
        return false;
    }
    return true;
}

void TravelAgency::print_customer(string name)
{
    cout << "Name : " << get_customer(name)->get_name() << endl;
    cout << "Email : " << get_customer(name)->get_email() << endl;
    cout << "Account balance : " << get_customer(name)->get_account_balance() << endl;
}

void TravelAgency::print_hotel(string name)
{
    cout << "Name : " << get_hotel(name)->get_name() << endl;
    cout << "Adress : " << get_hotel(name)->get_adress() << endl;
    cout << "Room type : " << get_hotel(name)->get_room_type() << endl;
    cout << "Nights of stay : " << get_hotel(name)->get_stay_nights() << endl;
    cout << "Price : " << get_hotel(name)->get_price() << endl;
}

void TravelAgency::print_transaction(const int &id)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it)
    {
        if (it->get_id() == id)
        {
            cout << "------------------------" << endl;
            cout << "ID : " << it->get_id() << endl;
            cout << "Customer : " << it->get_customer()->get_name() << endl;
            cout << "Hotel : " << it->get_hotel()->get_name() << endl;
            cout << "Travel Agency : " << this->get_name() << endl;
            cout << "Type : " << it->get_type() << endl;
            cout << "Price : " << it->get_hotel()->get_price() << endl;
            cout << "------------------------" << endl;
        }
    }
}

void TravelAgency::show_customers()
{
    for (auto &c : customers)
    {
        cout << "------------------------" << endl;
        cout << "Name : " << c->get_name() << endl;
        cout << "Email :" << c->get_email() << endl;
        cout << "Account balance : " << c->get_account_balance() << endl;
    }
    cout << "------------------------" << endl;
}

void TravelAgency::show_hotels()
{
    for (auto &c : hotels)
    {
        cout << "------------------------" << endl;
        cout << "Name : " << c->get_name() << endl;
        cout << "Adress : " << c->get_adress() << endl;
        cout << "Room type : " << c->get_room_type() << endl;
        cout << "Nights of stay : " << c->get_stay_nights() << endl;
        cout << "Price : " << c->get_price() << endl;
    }
    cout << "------------------------" << endl;
}

void TravelAgency::show_transactions()
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it)
    {
        cout << "------------------------" << endl;
        cout << "ID : " << it->get_id() << endl;
        cout << "Customer : " << it->get_customer()->get_name() << endl;
        cout << "Hotel : " << it->get_hotel()->get_name() << endl;
        cout << "Travel Agency : " << this->get_name() << endl;
        cout << "Price : " << it->get_hotel()->get_price() << endl;
    }
    cout << "------------------------" << endl;
}
// void show_unique_transactions(const string& name);

// void allocate_pointers(TravelAgency* travel_agency, Customer* customer, Hotel* hotel, Transactions* transaction, string type);
