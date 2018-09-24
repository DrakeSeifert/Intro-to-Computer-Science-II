#include <iostream>
#include "./PatientAccount.h"
#include "./Surgery.h"
#include "./Pharmecy.h"
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	class PatientAccount P1;
	class Surgery P2;
	class Pharmecy P3;

	int d;
	string s;
	string p;

	cout << "How many days in the hospital?: ";
	cin >> d;

	cout << "Enter surgery type: ";
	cin >> s;

	cout << "Enter medication: ";
	cin >> p;
	
	fstream output;

	output.open("hospital.txt", ios::app);

	/*output << p.get_name();
	output << "|pharm|";
	output << p.get_pharm_med(0);
	output << '|';
	output << p.get_pharm_med_cost(0);
	//...
	output << endl;

	output.close();*/

	return 0;
}
