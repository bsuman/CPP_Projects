#pragma once
#include<iostream>
using namespace std;

class Employee {
	int employee_age;
	string name;
public: 
	string dept_name;
	Employee():employee_age(0), name(""), dept_name(""){
	
	}
	virtual ~Employee() {

	}

	bool setManager(Manager m) {
		this->reporting_manager = m.getname();
	}
	string getdeptname() {
		return this->dept_name;
	}

	bool isSameDept(Employee e1, Employee e2);

protected: 
	string reporting_manager;
};

class Manager :protected Employee {
	string mname;
public:
	Manager(string im_name):mname(im_name){

	}
	virtual ~Manager() {

	}
	string getname() {
		return this->mname;
	}
	bool isSameManager(Manager m1, Manager m2);
};


bool Employee::isSameDept(Employee e1, Employee e2)
{
	return e1.dept_name == e2.dept_name;
}

bool Manager::isSameManager(Manager m1, Manager m2)
{
	return m1.reporting_manager == m2.reporting_manager;
}