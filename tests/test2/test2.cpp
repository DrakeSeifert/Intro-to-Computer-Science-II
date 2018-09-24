#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string x;
	x = argv[1];
	cout << x << endl;	
	
	vector < vector <char> > meow;
	vector <char> z;
	char ch;
	int count = 0;

	ifstream my_file;
	my_file.open(x.data());

	if (!my_file) {
		cout << "File open error" << endl;
		exit(EXIT_FAILURE);
	}

	my_file.get(ch);
	while(!my_file.eof()) {
		if (ch == '\n')
			count++;
		my_file.get(ch);
	}

	my_file.close();
	my_file.open(x.data());

	if (!my_file) {
		cout << "File open error" << endl;
		exit(EXIT_FAILURE);
	}

	my_file.get(ch); 
	while (!my_file.eof()) {
		if (ch == '\n') {
			meow.push_back(z);
			if (meow.size() == count) {
				for (int i = 0; i < meow.size(); i++) {
					for (int j = 0; j < z.size(); j++) {
						cout << meow[i][j];
					}
					cout << endl;
				}
			}
			z.clear();
		}
		if (ch != ' ' && ch != '\n') {
			z.push_back(ch);
		}
		my_file.get(ch);
	}

	my_file.close();
	cout << endl;

	return 0;
}
