#include <iostream>
#include "DateTime.cpp"
#include "Location.cpp"
#include "Location.h"
#include "People.h"
#include "Activity.cpp"
#include "Base.cpp"
//#include "Project.h"
using namespace std;

string Location::file_name = R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)";
int main() {
    Location l1;
    cout<<l1.find_last_id(Location::file_name);
    return 0;
}
