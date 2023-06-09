#include "Hotel.h"

Hotel::Hotel()
{
	this->name = "";
	this->adress = "";
	this->room_type = "";
	this->stay_nights = 0;
	this->price = 0;
}

Hotel::Hotel(string name, string adress, string room_type, int stay_nights, float price)
{
	this->name = name;
	this->adress = adress;
	this->room_type = room_type;
	this->stay_nights = stay_nights;
	this->price = price;
}

Hotel::~Hotel()
{
	travel_agencies.clear();
	customers.clear();
	transactions.clear();
}

string Hotel::get_name()
{
	return this->name;
}

string Hotel::get_adress()
{
	return this->adress;
}

string Hotel::get_room_type()
{
	return this->room_type;
}

int Hotel::get_stay_nights()
{
	return this->stay_nights;
}

float Hotel::get_price()
{
	return this->price;
}

void Hotel::set_name(string name)
{
	this->name = name;
}

void Hotel::set_adress(string adress)
{
	this->adress = adress;
}

void Hotel::set_room_type(string room_type)
{
	this->room_type = room_type;
}

void Hotel::set_stay_nights(int stay_nights)
{
	this->stay_nights = stay_nights;
}

void Hotel::set_price(float price)
{
	this->price = price;
}

Customer *Hotel::find_customer(string name)
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

Transactions *Hotel::find_transaction(int id)
{
	for (auto &c : transactions)
	{
		if (c->get_id() == id)
		{
			return c;
		}
	}
	return nullptr;
}

TravelAgency *Hotel::find_travel_agency(string name)
{
	for (auto &c : travel_agencies)
	{
		if (c->get_name() == name)
		{
			return c;
		}
	}
	return nullptr;
}

bool Hotel::add_customer(Customer *new_customer)
{
	if (new_customer == nullptr)
	{
		return false;
	}
	if (find_customer(new_customer->get_name()))
	{
		return false;
	}
	customers.emplace_back(new_customer);
	return true;
}

bool Hotel::remove_customer(string name)
{
	for (auto it = customers.begin(); it != customers.end(); ++it)
	{
		if ((*it)->get_name() == name)
		{
			customers.erase(it);
			return true;
		}
	}
	return false;
}

bool Hotel::add_travel_agency(TravelAgency *travel_agency)
{
	if (travel_agency == nullptr)
	{
		return false;
	}
	if (find_travel_agency(travel_agency->get_name()))
	{
		return false;
	}
	travel_agencies.emplace_back(travel_agency);
	return true;
}

bool Hotel::remove_travel_agency(TravelAgency *travel_agency)
{
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

bool Hotel::add_transaction(Transactions *transaction)
{
	if (transaction == nullptr)
	{
		return false;
	}
	if (find_transaction(transaction->get_id()))
	{
		return false;
	}
	transactions.emplace_back(transaction);
	return true;
}

bool Hotel::remove_transaction(Transactions *transaction)
{
	if (transaction == nullptr)
	{
		return false;
	}

	transactions.remove(transaction);
	return true;
}

void Hotel::remove_all_transactions()
{
	transactions.clear();
}

void Hotel::remove_all_customers()
{
	customers.clear();
}

void Hotel::remove_travel_agencies(TravelAgency *travel_agency)
{
	auto it = travel_agencies.begin();
	travel_agencies.erase(
		remove_if(
			travel_agencies.begin(),
			travel_agencies.end(),
			[travel_agency](auto t)
			{ return t == travel_agency; }),
		travel_agencies.end());
}
