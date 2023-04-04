#include "Classes.h"

using namespace std;
int main() {

	unique_ptr<Employee> ptr_e1 =  make_unique<Employee>();
	ptr_e1->dept_name = "FrontEndTeam";
}