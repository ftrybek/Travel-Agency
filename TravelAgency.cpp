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

Customer* TravelAgency::get_customer(string name)
{
    return find_customer(name);
}

Hotel* TravelAgency::get_hotel(string name, string adress)
{
    return find_hotel(name);
}

Transactions* TravelAgency::get_transaction(int id, string name_customer, string name_hotel)
{
    return find_transaction(id);
}

TravelAgency* TravelAgency::get_travel_agency()
{
    return this;
}

Hotel* TravelAgency::find_hotel(string name)
{
    for (auto& c : hotels)
    {
        if (c->get_name() == name)
        {
            return c;
        }
    }
    return nullptr;
}

Customer* TravelAgency::find_customer(string name)
{
    for (auto& c : customers)
    {
        if (c->get_name() == name)
        {
            return c;
        }
    }
    return nullptr;
}

Transactions* TravelAgency::find_transaction(int id)
{
    for (auto& c : transactions)
    {
        if (c->get_id() == id)
        {
            return c;
        }
    }
    return nullptr;

    //     for (auto& c : transactions) {
    //     if (c.get_id() == id) {
    //         Transactions* ptr = &c;
    //         return ptr;
    //     }
    // }
    // return nullptr;
}

bool TravelAgency::add_customer(Customer* customer)
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
    Customer* todelete = nullptr;
    todelete = find_customer(name);

    if (todelete == nullptr)
    {
        return false;
    }

    // todelete->remove_all_transactions();
    // todelete->remove_all_hotels();
    // todelete->remove_all_travel_agencies(this);
    //Remove_TransactionCustomer(todelete);

    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (*it == todelete) {
            customers.erase(it);
            return true;
        }
    }

    return false;
}

bool TravelAgency::add_hotel(Hotel* hotel)
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
    Hotel* todelete = nullptr;
    todelete = find_hotel(name);

    if (todelete == nullptr) {
        return false;
    }

    // todelete->Remove_AllTransactions();
    // todelete->Remove_AllCustomers();
    // todelete->Remove_StockMarkets(this);
    // Remove_TransactionCompany(todelete);

    for(auto it = hotels.begin(); it != hotels.end(); ++it)
    {
        if((*it) == todelete)
        {
            hotels.erase(it);
            return true; // exit the function after removing the company
        }
    }
    return false;
}

bool TravelAgency::add_transaction(int id, string type, Customer* customer, Hotel* hotel, TravelAgency* travel_agency)
{
    // if (!Check_Transaction(ID, customer, amountShares, company, type)) {
    //     return false;
    //}
    Transactions trans (id, type, customer, hotel, travel_agency);
    transactions.__emplace_back(trans);
    // if (type == "booking") {
    //     Update_InvestedMoney(company->Get_ShareCost()*amountShares);
    //     customer->Set_InvestedMoney(customer->Get_InvestedMoney() + amountShares * company->Get_ShareCost());
    //     customer->Set_PocketMoney(customer->Get_PocketMoney() - amountShares * company->Get_ShareCost());
    //     company->Update_SoldShares(amountShares);
    // }
    // else {
    //     Update_InvestedMoney(company->Get_ShareCost() * amountShares*(-1));
    //     customer->Set_InvestedMoney(customer->Get_InvestedMoney() - amountShares * company->Get_ShareCost());
    //     customer->Set_PocketMoney(customer->Get_PocketMoney() + amountShares * company->Get_ShareCost());
    //     company->Update_SoldShares(amountShares*(-1));
    // }
    //add poinetrs
    // Add_Pointers(customer, company, this, this->Get_Transaction(ID),amountShares,type);
    return true;
}
        // bool remove_transaction(Transactions* transaction);

void TravelAgency::print_customer(string name)
{
    cout << "Name : " << get_customer(name)->get_name()<< endl;
    cout << "Email : " << get_customer(name)->get_email()<< endl;
    cout << "Account balance : " << get_customer(name)->get_account_balance()<< endl;
}

void TravelAgency::print_hotel(string name, string adress)
{
    cout << "Name : " << get_hotel(name, adress)->get_name()<< endl;
    cout << "Adress : " << get_hotel(name, adress)->get_adress()<< endl;
    cout << "Room type : " << get_hotel(name, adress)->get_room_type() << endl;
    cout << "Nights of stay : " << get_hotel(name, adress)->get_stay_nights() << endl;
    cout << "Price : " << get_hotel(name, adress)->get_price() << endl;
}

void TravelAgency::print_transaction(const int& id)
{
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        // if (it->get_id() == id) {
        //     cout << "ID : " << id << endl;
        //     cout << "Customer : " << it->get_customer()->get_name() << endl;
        if ((*it)->get_id() == id) {
            cout << "ID : " << id << endl;
            cout << "Customer : " << (*it)->get_customer()->get_name() << endl;
        //     cout << "Customer : " << (*it)->get_customer()->get_name() << endl;
        //     // cout << "Company : " << it->Get_Company()->Get_Name() << endl;
        //     // cout << "Money : " << it->Get_Amount() << endl;
        //     // cout << "Shares : " << it->Get_Shares() << endl;
        //     // cout << "Price per share : " <<(double) it->Get_Amount() / it->Get_Shares() << endl;
        //     return;
        }
    }
}

void TravelAgency::show_customers()
{
    for (auto& c : customers)
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
    for (auto& c : hotels)
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

        // void show_transactions();

        // void show_unique_transactions(const string& name);

        // bool check_transaction(int id, string type, Customer* customer, Hotel* hotel);

        // void allocate_pointers(TravelAgency* travel_agency, Customer* customer, Hotel* hotel, Transactions* transaction, string type);
