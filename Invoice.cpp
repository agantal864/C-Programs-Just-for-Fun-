#include <iostream>
#include <string>
#include "Invoice.h"
using namespace std;

Invoice::Invoice(string num, string description, int count, float price) {
	set_part_number(num);
	set_part_description(description);
	set_quantity(count);
	set_price_per_item(price);
}

void Invoice::set_part_number(string num) {
	part_number = num;
}

string Invoice::get_part_number() {
	return part_number;
}

void Invoice::set_part_description(string description) {
	if (description.size() <= 30) {
		part_description = description;
	} else {
		description.resize(30);
		part_description = description;
	}
}

string Invoice::get_part_description() {
	return part_description;
}

void Invoice::set_quantity(int count) {
	if (count > 0) {
		quantity = count;
	} else if (count <= 0) {
		quantity = 0;
		cout << "\nQuantitiy is negative. It is set to 0.\n";
	}
}

int Invoice::get_quantity() {
	return quantity;
}

void Invoice::set_price_per_item(float price) {
	if (price > 0) price_per_item = price;
	else if (price <= 0) {
		price_per_item = 0;
		cout << "\nPrice per item is negative. It is set to 0.\n";
	}
}

float Invoice::get_price_per_item() {
	return price_per_item;
}

float Invoice::get_invoice_amount() {
	return get_quantity() * get_price_per_item();
}	

