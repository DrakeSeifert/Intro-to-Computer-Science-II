#include <iostream>
#include "./PatientAccount.h"
using namespace std;
//private:
//int days();
//const int daily_rate();
//int total_charge();

PatientAccount::PatientAccount() {
	days = 0;
	daily_rate = 10;
	total_charge = 0;	
}

PatientAccount::~PatientAccount() {

}

PatientAccount::PatientAccount(PatientAccount &other) {

}

int PatientAccount::calc_charge() {

}
