#include <iostream>
#include <string>
#include <fstream>
#include "sha1.hpp"
#include "CIRCULAR.h"
#include "AVLTREE.h"
#include "ROUTING.h"
#include "Main.h"
using namespace std;
/************ MAIN TO RUN THE CODE ******************/
int main() {
	Main obj;
	char choice = '\0';
	do {
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Enter ('Y') if you want to enter manually if not then Enter ('N')::";
		cin >> choice;
	} while (!(choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'));
	if (choice == 'N' || choice == 'n') {
		obj.automatically();
	}
	else if (choice == 'Y' || choice == 'y') {
		obj.manually();
	}
	return 0;
}
