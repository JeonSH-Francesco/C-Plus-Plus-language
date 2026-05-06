#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main() {
	cout << "Test" << endl;
	Employee emp;
	emp.setFirstName("John");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
	emp.setSalary(50000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();
	return 0;
}
