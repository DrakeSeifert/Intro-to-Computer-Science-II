#ifndef PATIENTACCOUNT_H
#define PATIENTACCOUNT_H

class PatientAccount {
	friend class Surgery;
	friend class Pharmecy;
	public:
		int calc_charge();
		PatientAccount(); //default constructor
		~PatientAccount(); //deconstructor
		PatientAccount(PatientAccount &other); //copy constructor
	private:
		int days;
		int daily_rate;
		int total_charge;
};

#endif
