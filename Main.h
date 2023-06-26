#pragma once
#include <iostream>
#include <string>
#include "AVLTREE.h"
#include "CIRCULAR.h"
#include "ROUTING.h"
using namespace std;
class Main {
private:
	CircularList obj;
public:
/************ Not manually not user defined values ****************/
// Display function for Automatic filling the Data  //
	void automatically() {
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Identifier space which is created automatically is = 32" << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Number of machine generated in it is = 5" << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		string  machine_name = "Machine007";
		int ID = 1;
		for (int x = 0; x < 5; x++) {
			obj.insertmachine(ID, machine_name);
			ID += 7;
		}
		obj.setspace(32);
		obj.setmachine(5,0);
		obj.sorting();
		cout << "CIRCULAR LINK LIST WHICH IS MADE FOR MACHINE NODE IS:" << endl;
		obj.Display(); cout << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		obj.setdata();
		string key[32] = { "Hammad","Abdullah","Kabir","Abeer","Khan",
						   "Haris","Ali","Ahmed","Saif-ul-llah","Haider",
						   "Mustafa","Jawad","Bob","James","Tom","Cruise",
						   "Daniel","Craig","Johnny","English","Salman",
						   "Shahrukh","mehmood","Amjad","Abid","Hussain",
						   "Maaz","Munir","Asad","Jawad","Daud","Kaleem" };

		string value[32] = { "0012","5658","1254","2542","5785",
							 "5488","5544","0100","1224","1252",
							 "1244","1211","0071","0091","2558",
							 "8988","0013","0014","0019","0099",
							 "0088","0077","0066","0011","0022",
							 "0033","0044","7788","2233","1122",
							 "0000","1111" };
		for (int x = 0; x < 32; x++) {
			cout << "* Inserting  key   --> " << key[x] << endl;
			cout << "* Inserting  value --> " << value[x] << endl;
			obj.insert_to_AVL(key[x], value[x], 32);
			cout << "-------------------------------------------------------------------------------" << endl;
		}
		char choice ='\0';
		do {
			cout << "Enter ('Y') if you want to see Traverse if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			obj.traverse();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Search a KEY if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Insert Key ID = ";
			string x;
			cin >> x;
			obj.findkey(x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see Routing Table FT if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Your FT table = ";
			obj.make_FT(5);
			obj.Display_FT();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Insert a new Machine if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Insert Machine ID = ";
			int x;
			cin >> x;
			obj.Insert_New("Machine007", x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see New Circular List if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			obj.Display();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Delete any Machine if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << " Enter Delete Machine ID = ";
			int x;
			cin >> x;
			obj.Delete_Machine(x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see circular List After Deletion if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Your Circular Link List is = ";
			obj.Display();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		
	}
	/************ Function for doing work manually *******************/
	// Display function for Displaying and Filling the data user definde....
	void manually() {
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Enter Number of Bit identifier space you want to make::";
		int n;
		cin >> n;
		obj.setspace(pow(2,n));
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Enter Number of Machinne Your want to make in identifier space of " << pow(2, n) << "::";
		int no_of_machines;
		cin >> no_of_machines;
		cout << "----------------------------------------------------------------------------------" << endl;
		for (int x = 0; x < no_of_machines; x++) {
			cout << "Enter Machine ID=";
			int ID;
			cin >> ID;
			obj.insertmachine(ID, "Machine007");
		}
		obj.setspace(pow(2, n));
		obj.setmachine(no_of_machines,pow(2,n));
		obj.sorting();
		cout << "----------------------------------------------------------------------------------" << endl;
		char choice = '\0';
		do {
			cout << "Enter ('Y') if you want to see Circular List if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Your Circular Link List is = ";
			obj.Display();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		obj.setdata();
		for (int x = 0; x < 32; x++) {
			string key=" ", value=" ";
			cout << "Enter Key = "; cin >> key;
			cout << "Enter Value = "; cin >> value;
			cout << "* Inserting  key   --> " << key << endl;
			cout << "* Inserting  value --> " << value << endl;
			obj.insert_to_AVL(key, value, 32);
			cout << "-------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see Traverse if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			obj.traverse();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Search a KEY if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Insert Key ID = ";
			string x;
			cin >> x;
			obj.findkey(x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see Routing Table FT if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Your FT table = ";
			obj.make_FT(n);
			obj.Display_FT();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Insert a new Machine if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Insert Machine ID = ";
			int x;
			cin >> x;
			obj.Insert_New("Machine007",x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see New Circular List if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			obj.Display();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to Delete any Machine if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << " Enter Delete Machine ID = ";
			int x;
			cin >> x;
			obj.Delete_Machine(x);
			cout << "----------------------------------------------------------------------------------" << endl;
		}
		do {
			cout << "Enter ('Y') if you want to see circular List After Deletion if not then enter ('N')::";
			cin >> choice;
			cout << "----------------------------------------------------------------------------------" << endl;

		} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
		if (choice == 'Y' || choice == 'y') {
			cout << "Your Circular Link List is = ";
			obj.Display();
			cout << "----------------------------------------------------------------------------------" << endl;
		}
	}
};