#include <iostream>
#include "DateTime.cpp"
#include "Location.cpp"
#include "Location.h"
#include "People.h"
#include "Activity.cpp"
#include "Base.cpp"
using namespace std;

string Location::file_name = R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)";
string People::file_name = R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)";
string Activity::file_path = R"(C:\Users\Daniel\work_space\Proiect_POO\activity.txt)";
int main() {
////    Location test
//    Location l_by_id(1), l_generated("Test1", "Bucuresti", "Bucuresti", "Strada test", 1, 20);
//    cout<<l_by_id;
//    cout<<l_generated;
////    People test
    People p_by_id(1);
//    , p_generated("Test", "test@gmail.com", "0735085897", "DEV", "Regular", 10);
//    cout<<p_by_id;
//    cout<<p_generated<<endl;
////    DateTime test
//    DateTime d_from_utc("2022-12-25T09:31:43"),d_generated(2023, 1, 1, 0, 0, 0);
//    cout<<d_from_utc.get_date_time_UTC()<<endl;
//    cout<<d_generated.get_date_time_UTC()<<endl;
////    Activity test
    Activity  a_by_id(1), a_generated("2022-12-25T09:31:43", "2022-12-25T09:31:43", "Test", new unsigned [2]{1, 2}, 2);
    a_by_id = a_by_id + p_by_id;
    cout<<a_by_id;
    a_by_id = a_by_id - 1;
    cout<<a_by_id;
    string test = {"regular"};
    cout<<a_by_id%test;
    return 0;
}
