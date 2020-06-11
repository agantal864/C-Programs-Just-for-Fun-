#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<conio.h>
#include<string>
#include<sstream>
#include<time.h>
using namespace std;


//This is the NODE class for the student
class Node {
	private:
		string StudentNumber;
		string LastName;
		string FirstName;
		string MiddleName;
		string Course;
		string Seniority;
		string Standing;
		int BirthYear;
		int BirthMonth;
		int BirthDay;
		int Age;		
		double Gwa;
		
		// This is only used when updating the date of birth
		string Birthdate; 
		char ch; 
		
		
	public:
		Node *next;
		//Constructors
		Node();
		Node(string s, string l, string f, string md, string c, int y, int m, int d, double g) {
			set_StudentNumber(s);
			set_LastName(l);
			set_FirstName(f);
			set_MiddleName(md);
			set_Course(c);
			set_Age(y,m,d);
			set_Seniority(s);
			set_Standing(g);
		}
			
		//Start of Mutator Methods
		void set_StudentNumber(string s) {
			StudentNumber = s;	
		}
		
		void set_LastName(string l) {
			LastName = l;
		}
		
		void set_FirstName(string f) {
			FirstName = f;
		}
		
		void set_MiddleName(string md) {
			MiddleName = md;
		}
		
		void set_Course(string c) {
			Course = c;
		}
		
		void set_Age(int y, int m, int d) {
			BirthYear = y;
			BirthMonth = m;
			BirthDay = d;
			//Calculate current time using time.h
			time_t now = time(0);
			tm *ltm = localtime(&now);
			//current year
			int current_year = 1900 + ltm->tm_year;
			//current month
			int current_month = 1 + ltm->tm_mon;
			//current day
			int current_day = ltm->tm_mday;
		    if(BirthMonth > current_month){
			    current_year = current_year - 1;
			}  
		    Age = current_year - BirthYear;
		}
		
		void set_Seniority(string s) {
			//s variable pertains to the student number
			char bin[4]; //This will store the first 4 characters of the student number
			int year; //This is where we'll save the converted 4 characters to 4 ints  
			for (int i=0; i < 4; i++) {
				bin[i] = s[i]; 
			}
			//converts the characters to integer using streams
			std::istringstream(bin) >> year;
			
			if (year == 2019) Seniority = "1st Year";
			else if (year == 2018) Seniority = "2nd Year";  
			else if (year == 2017) Seniority = "3rd Year";
			else if (year <= 2016 && year >= 2010) Seniority = "4th Year"; //We assume that all student number with a year from 2010 to 2016 are 4th year students
			else Seniority = "Invalid Student Number";
		}
		
		void set_Standing(double g) {
			Gwa = g;
			if (Gwa > 3) Standing = "Fail";
			else if (Gwa <= 1) Standing = "Invalid Gwa";
			else if (Gwa > 1 && Gwa <= 1.20) Standing = "Summa cum laude";
			else if (Gwa > 1.20 && Gwa <= 1.45) Standing = "Magna cum laude";
			else if (Gwa > 1.45 && Gwa <= 1.75) Standing = "Cum laude";
			else Standing= "Pass";
		}
		//End of Mutator Methods
		
		//Start of Accessor Methods
		string get_StudentNumber() {
			return StudentNumber;
		}
		
		string get_LastName() {
			return LastName;
		}
		
		string get_FirstName() {
			return FirstName;
		}
		
		string get_MiddleName() {
			return MiddleName;
		}
		
		string get_Course() {
			return Course;
		}
		
		string get_Seniority() {
			return Seniority;
		}
		
		string get_Standing() {
			return Standing;
		}
		
		int get_Age() {
			return Age;
		}
		
		double get_Gwa() {
			return Gwa;
		}
		//End of Accessor Methods
		
		//Utility Methods
		//Update Info of Student
		void Update_LastName(string Lname) {	
			cout << "Existing Last Name: " << Lname << endl;
			cout << "New Last Name: ";
			cin >> LastName;
			cout << endl;
		}
		
		void Update_FirstName(string Fname) {	
			cout << "Existing First Name: " << Fname << endl;
			cout << "New First Name: ";
			cin >> FirstName;
			cout << endl;
		}
		
		void Update_MiddleName(string Mname) {	
			cout << "Existing Middle Name: " << Mname << endl;
			cout << "New Middle Name: ";
			cin >> MiddleName;
			cout << endl;
		}
				
		void Update_Course(string Course) {	
			cout << "Existing Course: " << Course << endl;
			cout << "New Course: ";
			cin >> Course;
			cout << endl;
		}
	
		void Update_Birthdate(int Year, int Month, int Day) {
			cout << "Existing Date of Birth: " << Year << "-" << Month << "-" << Day << endl;
			cout << "New Date of Birth (Format: YYYY-MM-DD): ";
			cin >> Birthdate; // input can be 2005-03-09 or 2005/04/02 
			stringstream ss(Birthdate);
			ss >> BirthYear >> ch >> BirthMonth >> ch >> BirthDay;
		}
		
		void Update_Gwa(double grade) {
			cout << "Existing GWA: " << grade << endl;
			cout << "New GWA: ";
			cin >> Gwa;
		}
		
		//Print Student Information
		void print_info() {
			cout << get_StudentNumber() << endl;
			cout << "Name: " << get_LastName() << ", ";
			cout << get_FirstName() << " ";
			cout << get_MiddleName() << endl;
			cout << "Course: " << get_Course() << endl;
			cout << "Age: " << get_Age() << " years old" << endl;
			cout << "Seniority: " << get_Seniority() << endl;
			cout << "Standing: " << get_Gwa() << " - " << get_Standing() << endl <<endl; 	
		}		
		
};




class List {
	
	public:
		Node *head;
		
		//Constructor
		List() {
			head = NULL;
		}	
		List(Node *n) {
			head = n;
		} 
		
		//Accessor method to read number of elements in the list
		int getCount() {
			int count = 0;
			Node *temp;
			temp = head;
			while (temp != NULL) {
				count++;
				temp = temp->next; 
			}
			return count;
		}
		
		//Check if node exists using Student Number
		Node *nodeExists(string k) {
			Node *temp = NULL;
			Node *ptr = head;
			while (ptr != NULL) { 
				if (ptr->get_StudentNumber() == k) {
					temp = ptr;
				}
				ptr = ptr->next;
			}
			return temp;
		}
		
		//Start of Mutator Methods
		//Insert node in ascending order by Student Number
		void InsertNode(Node *n) {
			
			int count = 0;
			Node *ptr = head;
			Node *ptr2 = head;
			
			if(nodeExists(n->get_StudentNumber()) != NULL) {
				cout << "Student Number Already Exist!" << endl;
				cout << "Press any key to continue...";
				getch();
				return;
			} 
			
			//Insert Node in the head if the List is empty
			if (head == NULL) {
				head = n;
				cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
				cout << "Press any key to continue...";
				getch();
			} else {
				//Insert Node in Ascending Order by Student Number
				int CurrentStudent, NewStudent; // The two student number in int that will be compared will be stored here
				std::string s1 (ptr->get_StudentNumber()); 
				std::string s2 (n->get_StudentNumber());
				s1.erase(4,1); // removes the hyphen '-' sign in the string
				s2.erase(4,1); // removes the hyphen '-' sign in the string
				std::istringstream(s1) >> CurrentStudent; // convert s1 to int and saved to CurrentStudent
				std::istringstream(s2) >> NewStudent; // convert s2 to int and saved to NewStudent
				
				//When the new NODE < Current NODE 		
				if (CurrentStudent > NewStudent) {
					n->next = head;
					head = n;
					count++;
					cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
					cout << "Press any key to continue...";
					getch();
					return;
				} 
				
				//When the new NODE > Current NODE 
				Node *ptr2;
				while (ptr != NULL) {
					if (CurrentStudent < NewStudent) {
						ptr2 = ptr;
					}
					ptr = ptr->next;
					if (ptr != NULL) {
						std::string s1 (ptr->get_StudentNumber());
						s1.erase(4,1);
						std::istringstream(s1) >> CurrentStudent;
					}	
				}
				n->next = ptr2->next;
				ptr2->next = n;
				cout << endl << "Student Number "<< n->get_StudentNumber() << " is added!" <<endl << endl;
				cout << "Press any key to continue...";
				getch();			
			}
		}
		
		//Deletes the Student NODE from the list by Student Number
		void DeleteNode(string k) {
			if (head == NULL) {
				cout << "There is no list to delete." << endl;
				cout << "Press any key to continue...";
				getch();
			}
			else if (nodeExists(k) == NULL) {
				cout << "The student number " << k << " does not exist in the list." << endl;
				cout << "Press any key to continue...";
				getch();
			}
			else {
				Node *temp = head;
				Node *ptr = head;
				//If there is only NODE with the student number specified
				if(temp != NULL && (temp->get_StudentNumber() == k)) {
					head = temp->next;
					free(temp); //Free memory
					cout << "Student number " << k << " is removed from the list" << endl;
					cout << "Press any key to continue...";
					getch();
					return;
				}
				//If there are multiple NODES -- the pointer temp will find the variable to delete
				while (temp != NULL && (temp->get_StudentNumber() != k)) {
					ptr = temp;
					temp = temp->next;
				}
				//unlink the node temp (the node with the given student number) from the list
				ptr->next = temp->next;
				free(temp); //Free memory
				cout << "Student number " << k << " is removed from the list" << endl;
				cout << "Press any key to continue...";
				getch();
			}
		}
		
		

		//End of Mutator Methods
		
		//Utility Method
		//Prints the list of students
		void printlist() {
			
			if(head == NULL) {
				cout << "NO NODES FOUND." << endl;
				cout << "Press any key to continue...";
				getch();
			} else {
				Node *temp = head;
				while (temp != NULL) {
					temp->print_info();
					temp = temp->next;
				}
			}
			
			cout << "Press any key to continue...";
			getch();	
		}
		
		
		
		
		
};








int main() {
	
	//User-defined Variables
	string num, Lname, Fname, Mname, Course, Birthdate; double Gwa; 	
	char ch; //This is used for the birthday '-' separator 
 	int Year, Month, Day; // Date of Birth YYYY-MM-DD
	
	int option;
	List mylist;

	do {
	
		cout << "STUDENT INFORMATION" << endl << endl;
		cout << "[1]Add a Student" << endl;
		cout << "[2]Update Information" << endl;
		cout << "[3]Remove a Student" << endl;
		cout << "[4]Sort Students" << endl;
		cout << "[5]Display Students" << endl;
		cout << "[6]Exit" << endl << endl;
		cout << "Option: ";
		cin >> option;
		cout << endl << endl;
		switch(option) {
			case 1:  {
			
				//User input (getline function is used here to read the space character of the input e.g Juan Cruz)
				fflush(stdin);
				cout << "Student Number (Format: 20XX-XXXXX): ";
				getline(cin, num);
				cout << "Last Name: ";
				getline(cin, Lname); 
				cout << "First Name: ";
				getline(cin, Fname);
				cout << "Middle Name: ";
				getline(cin, Mname);
				cout << "Course: ";
				getline(cin, Course);
				cout << "Date of Birth (Format: YYYY-MM-DD): ";
				cin >> Birthdate; // input can be 2005-03-09 or 2005/04/02 
				stringstream ss(Birthdate);
				ss >> Year >> ch >> Month >> ch >> Day;
				cout << "GWA: ";
				cin >> Gwa;
				//End of User input
				
				//Create new Node to be added in the List
				Node *n1 = new Node(num, Lname, Fname, Mname, Course, Year, Month, Day, Gwa);
				mylist.InsertNode(n1);
				system("cls");
				break;
			}
			case 2 : {
				
				break;
			}
			case 3 : {
			
				cout << "Enter student number to delete: ";
				cin >> num;
				mylist.DeleteNode(num);
				system("cls");
				break;
			}
			case 4: {
			
				int choice;
				cout << "Sort Student Information" << endl;
				cout << "[1]Sort by Student Number" << endl;
				cout << "[2]Sort by Last Name" << endl;
				cout << "[3]Sort by GWA" << endl<<endl;
				cout << "Enter choice: ";
				cin >> choice;
				
				switch(choice) {
					case 1: {
						break;
					}
					case 2: {
						break;
					}
				}	
				system("cls");
				break;
			}	
			case 5 : {
				mylist.printlist();
				system("cls");
				break;
			}
			case 6: {
				exit(0);
				break;
			}
			
				
			
			
				
				
				
				
				
				
				
		}
	} while (1);
	
}


/*

		int count = 0; // This count will determine if there is a sorting happening
				int x = 0;
				Node *counter = head;
				while (counter != NULL) {
					
					Node *temp = head; 
					temp = temp->next;
					Node *ptr = temp->next;
					Node *newHead = ptr;
					
					string a = temp->get_LastName();
					string b = ptr->get_LastName();
					std::transform(a.begin(), a.end(), a.begin(), ::toupper); // This will uppercase all letters in string A
					std::transform(b.begin(), b.end(), b.begin(), ::toupper); // This will uppercase all letters in string A
					
				
					
					//Comparing first NODE's -> Last Name to the other NODES   
					Node *ptr2;
					if (strcmp(a.c_str(), b.c_str()) > 0) {
						while (ptr != NULL) {
							x++;
							count++; // This count will determine if there is a sorting happening
							if (strcmp(a.c_str(), b.c_str()) > 0) {
								ptr2 = ptr;
							}
							ptr = ptr->next;
							if (ptr != NULL) {
								b = ptr->get_LastName();
								std::transform(b.begin(), b.end(), b.begin(), ::toupper); // This will uppercase all letters in string A	
							}	
						}
						head = newHead;
						temp->next = ptr2->next;
						ptr2->next = temp;
					
					}
					counter = counter->next;
				}
				
				if (count > 0) {
					cout << endl << "Students are sorted by Last Name!" <<endl << endl;
					cout << "Press any key to continue...";
					getch();
				}
				if (count == 0) {
					cout << endl << "Students are already sorted by Last Name" <<endl << endl;
					cout << "Press any key to continue...";
					getch();
				}
*/
 
