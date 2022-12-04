#include <iostream>
#include "DateTime.cpp"
#include "Location.cpp"
#include "People.h"
#include "Activity.cpp"
//#include "Project.h"
using namespace std;

int main() {
    Location l1("test", "Bucuresti", "Bucuresti","Test", 1, 1);
    cout<<l1;
    return 0;
}
