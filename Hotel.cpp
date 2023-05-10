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

// bool add_customer();

// bool remove_customer();

// void remove_all_transactions();

// void remove_all_customers();

// void remove_travel_agencies(TravelAgency* travel_agency);

// bool add_transaction(Transactions* transaction);

// bool remove_transaction(Transactions* transaction);

// bool add_travel_agency(TravelAgency* travel_agency);

// bool remove_travel_agency(TravelAgency* travel_agency);

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