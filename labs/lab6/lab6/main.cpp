#include <stdexcept>
#include <iostream>
using namespace std;

int main() {
	string name;

	try {
		cout << "Hello " << name.at(0) << endl;
	}
	catch (out_of_range &e) {
		cout << "Errroaaarrrr" << endl;
	}

	return 0;
}
