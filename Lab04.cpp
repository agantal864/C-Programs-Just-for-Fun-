#include <iostream>
#include "Invoice.h"
using namespace std;

int main() {
	int ch;
	
	do {
	string part_num_temp; 
	string part_descrip_temp;
	int quantity_temp;
	float price_temp;
	
	cout << "Part Number: ";
	cin >> part_num_temp;
	cout << "Part Description: ";
	cin >> part_descrip_temp;
	cout << "Quantity: ";
	cin >> quantity_temp;
	cout << "Price Per Item: ";
	cin >> price_temp;
	cout << endl << endl;
	
	Invoice invoice(part_num_temp, part_descrip_temp, quantity_temp, price_temp);
	
	cout << "Part Number: " << invoice.get_part_number() << endl;
	cout << "Part Description: " << invoice.get_part_description() << endl;
	cout << "Quantity: " << invoice.get_quantity() << endl;
	cout << "Price Per Item: " << invoice.get_price_per_item() << endl;
	cout << "Invoice Amount: " << invoice.get_invoice_amount() << endl;
	
	cout << endl << endl << "Again? [1/0]: ";
	cin >> ch;
	cout << endl;
	
	} while (ch == 1);

	return 0;	
}
