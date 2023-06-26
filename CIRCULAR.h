#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "sha1.hpp"
#include "AVLTREE.h" 
#include "ROUTING.h"
using namespace std;
/* Node which is Gonna use in CircularList Class*/
struct Machine_Node {
public:
	int machine_ID;
	string machine_Name;
	Machine_Node* next, * pre;
	AVL tree;//Object of AVL to be used in Circular List Class....
	FT table;
	~Machine_Node() {
		delete next;
	}
};
/* Class made for Circular Link List*/
class CircularList {
private:
	Machine_Node* head;
	int no_of_machines, space;
	int* line;
public:
	CircularList() {
		head = NULL;
		//l = NULL;
		no_of_machines = 0, space = 0;
	}
	/*---------------------------------------- INSERTION OF MACHINE TO CIRCULAR LIST------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	void insertmachine(int machine_ID, string machine_Name) { //for inserting machine in the circular-link list.....
		Machine_Node* temp = new Machine_Node;
		Machine_Node* last = head;
		temp->machine_ID = machine_ID;
		temp->machine_Name = machine_Name;
		no_of_machines++;
		temp->next = head;
		if (head == NULL) {
			temp->next = temp;
		}
		else
		{
			while (last->next != head) {
				last = last->next;
			}
			last->next = temp;
		}
		head = temp;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*------------------------------------------ FUNCTION FOR SORTING---------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	//Function made to sort the Given Circular List so that it can be easy for us to compare......
	void sorting() {
		Machine_Node* current = head, * index = NULL;
		int  temp;
		while (current->next != head) {
			index = current->next;
			while (index != head) {

				if (current->machine_ID > index->machine_ID) {
					temp = current->machine_ID;
					current->machine_ID = index->machine_ID;
					index->machine_ID = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*-------------------------------- Get Filename from the Fuction----------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*for creating the file for storing key value and filepath in it.......
	* Here Machine number is passed to make a file according to it and sending its name
	*to insert to avl function for File handling and the passing it avl tree..
	*/
	string filename(int machine_code) {
		string str = to_string(machine_code);
		string name = "file";
		string format = ".txt";
		name += str;
		name += format;
		return name;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*------------------------------ Function for getting the Line Number-----------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*for getting the line number on which the given data is stored in file.txt....
	* Here Machine number is passed to increase in that line
	*/
	int GETLINE(int machine) {
		Machine_Node* current = head;
		cout << "Number of machines=" << no_of_machines <<endl;
		for (int x = 0; x < no_of_machines; x++) {
			if (current->machine_ID == machine) {
				line[x] += 1;
				return line[x];
			}
			current = current->next;
		}
	}
	void setspace(int s){
		 space=s;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*--------------------------------- Function for Inserting the (KEY,VALUE) TO AVL TREE -----------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/* A void function for entering the given data to AVL TREE......
	* Using SHA-1 Library in the function to get the HASH key ...
	* Doing File handling in it to store the Node os machine in it....
	* and then after File handling inserting it into AVL TREE.........
	*/
	void insert_to_AVL(const string key, const string value, int identifier_space) {// A function which is used to insert data in AVL in tree
		Machine_Node* temp = head;
		//********* sha-1 ****************
		SHA1 checksum;
		checksum.update(key);
		const string hash = checksum.final();

		//********** Changing to integer ***************
		int ID = convertToASCII(hash, identifier_space);

		int lines = 0;
		bool check = true;

		Machine_Node* last = head;
		for (int x = 0; x < no_of_machines - 1; x++) {
			last = last->next;
		}
		while (temp != NULL) {
			if (check == true) {
				if (ID > last->machine_ID) {
					ID %= last->machine_ID;
				}
				if (ID <= temp->machine_ID) {
					cout << "* Stored in machine no: =" << temp->machine_ID << endl;
					string filepath = filename(temp->machine_ID);
					// create and open a text file
					lines = GETLINE(temp->machine_ID);
					ofstream myfile(filepath, ios_base::app);
					// writing  to the file
					myfile << lines << "," << filepath << "," << key << "," << value << endl;
					// close the file
					myfile.close();
					cout << lines << " " << filepath << "  " << key << " " << value << " " << ID << endl;
					temp->tree.Insert(key, value, filepath, ID, lines);
					check = false;
					break;
				}
			}
			temp = temp->next;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*---------------------- Conversion of Letter to ASCII--------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	//For converting Hash key into integer and  get mod of number....
	int convertToASCII(string letter, int mod) {
		int sum = 0;
		for (int i = 0; i < letter.length(); i++)
		{
			char x = letter.at(i);
			sum += int(x);
		}
		sum = sum % mod;
		//cout << sum << endl;
		return sum;
	}
	int convertToASCII(string letter) {
		int sum = 0;
		for (int i = 0; i < letter.length(); i++)
		{
			char x = letter.at(i);
			sum += int(x);
		}

		return sum;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*----------------------------- Display Function For Circular Link List---------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	//Function for displaying the given Circular List ....
	void Display() {
		Machine_Node* ptr = head;
		do {
			cout << ptr->machine_ID;
			if (ptr->next != head) {
				cout << "->";
			}
			ptr = ptr->next;
		} while (ptr != head);
		cout << endl;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*-------------------------------- Function for Traversing The AVL TREE---------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	void traverse() {
		Machine_Node* temp = head;
		cout << "In-order Traversal" << endl;
		for (int x = 0; x < no_of_machines; x++) {
			temp->tree.inorder(temp->tree.getroot());
			cout << endl;
			temp = temp->next;
		}
		temp = head;
		cout << "Pre-order Traversal" << endl;
		for (int x = 0; x < no_of_machines; x++) {
			temp->tree.preorder(temp->tree.getroot());
			cout << endl;
			temp = temp->next;
		}
		temp = head;
		cout << "Post-order Traversal" << endl;
		for (int x = 0; x < no_of_machines; x++) {
			temp->tree.postorder(temp->tree.getroot());
			cout << endl;
			temp = temp->next;
		}
		return;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*------------------------------- Setter of Class CircularList------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	void setmachine(int n,int s) {
		no_of_machines = n;
	}
	void setdata() {
		line = new int[no_of_machines];
		for (int x = 0; x < no_of_machines; x++) {
			line[x] = 0;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*-------------------- Fuction Written in-order to Remove key from the AVL TREE-------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	void RemoveData(string key) {
		Machine_Node* temp = head;
		//********* sha-1 ****************
		SHA1 checksum;
		checksum.update(key);
		const string hash = checksum.final();
		//********** Changing to integer ***************
		int ID = convertToASCII(hash);
		bool check = true;
		Machine_Node* last = head;
		for (int x = 0; x < no_of_machines - 1; x++) {
			last = last->next;
		}
		while (temp != NULL) {
			if (check == true) {
				if (ID > last->machine_ID) {
					ID %= last->machine_ID;
				}
				if (ID <= temp->machine_ID) {
		             temp->tree.Delete_Leaf(temp->tree.getroot(), 11);
					}
				}
			}

	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*------------------------------------- FUNCTION FOR Making the FT table--------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*
	* A function written to make routing Finger table
	* in -order to make your search easier
	* according to formulaa provided to us by Universtity
	* Here we are using Object of FT class in order to
	* insert it into FT Doubly-link list
	*/
	void make_FT(int identifier_space) {
		Machine_Node* temp = head;
		Machine_Node* search = head;
		Machine_Node* last = head;
		int size = pow(2, identifier_space);
		for (int x = 0; x < no_of_machines - 1; x++) {
			last = last->next;
		}
		int p = 0;
		for (int x = 0; x < no_of_machines; x++) {
			for (int y = 1; y <= identifier_space; y++) {
				int succ = temp->machine_ID + pow(2, y - 1);
				for (int z = 0; z < no_of_machines; z++) {
					if (succ > last->machine_ID && succ < size) {
						p = head->machine_ID;
						break;
					}
					if (succ > size) {
						succ = succ % size;
					}
					if (succ <= search->machine_ID) {
						p = search->machine_ID;
						break;
					}
					search = search->next;
				}
				temp->table.Insert_to_FT(y, p);
			}
			temp = temp->next;
			search = head;
		}
	}
	void Display_FT() {
		Machine_Node* temp = head;
		for (int x = 0; x < no_of_machines; x++) {
			temp->table.display();
			temp = temp->next;
			cout << "------------" << endl;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*-------------------------------------------Function for the Insertion of new Machine -----------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*
	* A function written to make a insert a new machine to your
	* Ciruclar list and identifier space so it here we make new
	* machine then open previous files and link then to new inserted
	* machines
	*/
	void Insert_New(string machine_Name, int machine_ID) {
		Machine_Node* temp = new Machine_Node;
		Machine_Node* last = head;
		temp->machine_ID = machine_ID;
		temp->machine_Name = machine_Name;
		setmachine(no_of_machines + 1,0);
		temp->next = head;
		if (head == NULL) {
			temp->next = temp;
		}
		else
		{
			while (last->next != head) {
				last = last->next;
			}
			last->next = temp;
		}
		int ID = machine_ID;
		cout << ID << endl;
		head = temp;
		string   key, value;
		Machine_Node* current = head;
		int count = 0;
		sorting();
		setdata();
		for (int x = 1; x < no_of_machines; x++) {
			cout << current->machine_ID << endl;
			string file = filename(current->machine_ID);
			if (ID == current->machine_ID) {
				current = current->next;
				file = filename(current->machine_ID);
			}
			ifstream data;
			string a;
			data.open(file);
			while (!data.eof()) {
				getline(data, a);
				count = 0;
				key = ""; value = "";
				for (int x = 0; a[x] != '\0'; x++) {
					if (a[x] == ',') {
						count++;
						x++;
					}
					if (count == 3) {
						value += a[x];
					}
					else if (count == 2) {
						key += a[x];
					}
				}
				insert_to_newAVL(key, value, space);
				cout << key << value << endl;
			}

			current = current->next;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*------------------- Insertion AFTER NEW MACHINE IS MADE IN LIST FOR LINKING IT AGAIN------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	// A function which is used to insert data in AVL in tree...
	//making avl tree fir new machine which is inserted in the Circular List.....
	void insert_to_newAVL(const string key, const string value, int identifier_space) {
		Machine_Node* temp = head;
		//********* sha-1 ****************
		SHA1 checksum;
		checksum.update(key);
		const string hash = checksum.final();
		//********** Changing to integer ***************
		int ID = convertToASCII(hash, identifier_space);

		int lines = 0;
		bool check = true;

		Machine_Node* last = head;
		for (int x = 0; x < no_of_machines - 1; x++) {
			last = last->next;
		}
		while (temp != NULL) {
			if (check == true) {
				if (ID > last->machine_ID) {
					ID %= last->machine_ID;
				}
				if (ID <= temp->machine_ID) {
					cout << "* Stored in machine no: =" << temp->machine_ID << endl;
					string filepath = filename(temp->machine_ID, "new");
					// create and open a text file
					lines = GETLINE(temp->machine_ID);
					ofstream myfile(filepath, ios_base::app);
					// writing  to the file
					myfile << lines << " , " << filepath << " , " << key << " , " << value << endl;
					// close the file
					myfile.close();
					cout << lines << " " << filepath << "  " << key << " " << value << " " << ID << endl;
					temp->tree.Insert(key, value, filepath, ID, lines);
					check = false;
					break;
				}
			}
			temp = temp->next;
		}
	}
	string filename(int machine_code, string New) {
		string str = to_string(machine_code);
		string name = "file";
		string format = ".txt";
		name += str;
		name += New;
		name += format;
		return name;
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

    /*----------------------------------- A Function for Deletion of OLD MACHINE IN THE CIRCULAR LIST-------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*
	* A Function Written to Delete the
	* old machine from the Circular List
	* and making link with successor and predecessor
	*/
	void Delete_Machine(int machine_ID) {
		Machine_Node* temp = head;
		int count = 0;
		string key, value;
		string found = " ";
		string nextfile = " ";
		while (temp != NULL) {
			if (temp->machine_ID == machine_ID) {
				temp->machine_ID = 100;
				nextfile = filename(temp->next->machine_ID);
				sorting();
				deleteNode();
				found = filename(machine_ID);
				break;
			}
			temp = temp->next;
		}
		cout << nextfile << " " << found << endl;
		ifstream data;
		string a;
		data.open(found);
		while (!data.eof()) {
			getline(data, a);
			count = 0;
			key = ""; value = "";
			for (int x = 0; a[x] != '\0'; x++) {
				if (a[x] == ',') {
					count++;
					x++;
				}
				if (count == 3) {
					value += a[x];
				}
				else if (count == 2) {
					key += a[x];
				}

			}

			SHA1 checksum;
			checksum.update(key);
			const string hash = checksum.final();
			//********** Changing to integer ***************
			int ID = convertToASCII(hash, 32);
			int lines = 0;
			lines = GETLINE(15);
			ofstream myfile(nextfile, ios_base::app);
			// writing  to the file
			myfile << lines << " , " << nextfile << " , " << key << " , " << value << endl;
			// close the file
			myfile.close();
			cout << lines << " " << nextfile << "  " << key << " " << value << " " << ID << endl;
			temp->tree.Insert(key, value, nextfile, ID, lines);
		}
	}
	void deleteNode() {
		if (head != NULL) {
			if (head->next == head) {
				head = NULL;
				cout << "Deleted" << endl;
			}
			else {
				Machine_Node* temp = head;
				while (temp->next->next != head)
					temp = temp->next;
				Machine_Node* lastNode = temp->next;
				temp->next = head;
				free(lastNode);
				cout << "Deleted" << endl;
			}
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/

	/*---------------------------------------------- A function to Find Key in AVL -------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	void findkey(string key) {
		Machine_Node* temp = head;
		bool check = true;
		bool o = false;
		//********* sha-1 ****************
		SHA1 checksum;
		checksum.update(key);
		const string hash = checksum.final();
		int ID = convertToASCII(hash, 32);
		Machine_Node* last = head;
		for (int x = 0; x < no_of_machines - 1; x++) {
			last = last->next;
		}
		while (temp != NULL) {
			if (check == true) {
				if (ID > last->machine_ID) {
					ID %= last->machine_ID;
				}
				if (ID <= temp->machine_ID) {
					cout << "In loop" << endl;
					o=temp->tree.FIND_KEY(temp->tree.getroot(),key);
					if (o == true) {
						cout << "FOUND" << endl;
						break;
					}
					else
						cout << "Not Found" << endl;
						break;
				}
			}
			temp = temp->next;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	/*------------------------------------------------------------------------------------------------------------------------------------------*/
	~CircularList() {

	}
};