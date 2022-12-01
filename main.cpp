#include <iostream>
#include "Location.cpp"
#include "DateTime.cpp"
using namespace std;

int main() {
    Location l(R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)");
    cout<<l;
    return 0;
}
