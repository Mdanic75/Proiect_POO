#include <iostream>
#include "Location.cpp"
#include "DateTime.cpp"
#include "People.cpp"
using namespace std;

int main() {
    People p(R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)");
    cout<<p;
    return 0;
}
