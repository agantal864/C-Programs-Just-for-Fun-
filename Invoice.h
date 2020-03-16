#include <string>
using namespace std;

class Invoice {
	public: 
		Invoice(string, string, int, float);
		void set_part_number(string);
		string get_part_number();
		void set_part_description(string);
		string get_part_description();
		void set_quantity(int);
		int get_quantity();
		void set_price_per_item(float);
		float get_price_per_item();
		
		float get_invoice_amount();
	private:
		string part_number;
		string part_description;
		int quantity;
		float price_per_item;
};
