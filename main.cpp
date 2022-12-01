#include <iostream>
#include "Location.cpp"
#include "DateTime.cpp"
#include "People.h"
#include "Employee.h"
using namespace std;

int main() {
    DateTime t(2002, 12, 20, 12, 12, 12);
    cout<< t.get_date_time_UTC();
    return 0;
}
