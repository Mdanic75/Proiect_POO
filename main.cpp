#include <iostream>
#include "DateTime.cpp"
#include "Location.cpp"
#include "Location.h"
#include "People.h"
#include "Activity.cpp"
#include "Base.cpp"
#include "ActivityOffline.h"
#include "Project.cpp"
#include "vector"
#include "set"
#include "queue"
using namespace std;

string Location::file_name = R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)";
string People::file_name = R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)";
string Activity::file_path = R"(C:\Users\Daniel\work_space\Proiect_POO\activity.txt)";
int main() {
////    Location test
    Location l_by_id(1), l_generated("Test1", "Bucuresti", "Bucuresti", "Strada test", 1, 20);
    cout<<l_by_id;
    cout<<l_generated;
////    People test
    People p_by_id(1), p_generated("Test", "test@gmail.com", "0735085897", "DEV", "Regular", 10);
    cout<<p_by_id;
    cout<<p_generated<<endl;
////    DateTime test
    DateTime d_from_utc("2022-12-25T09:31:43"),d_generated(2023, 1, 1, 0, 0, 0);
    cout<<d_from_utc.get_date_time_UTC()<<endl;
    cout<<d_generated.get_date_time_UTC()<<endl;
////    Activity test
    Activity  a_by_id(1), a_generated("2022-12-25T09:31:43", "2022-12-25T09:31:43", "Test", new unsigned [2]{1, 2}, 2);
    a_by_id = a_by_id + p_by_id;
    cout<<a_by_id;
    a_by_id = a_by_id - 1;
    cout<<a_by_id;
    string test = {"regular"};
    cout<<a_by_id%test;
////    Derived class test
    string weather_condition = {"test"}, catering = {"test"};
    ActivityOffline a1(l_by_id, weather_condition, catering, 1);
    cout<<a1<<endl;
    cout<<a1.return_file_path();
////    Template
    auto * activity_list  = new Activity[2];
    activity_list[0] = a_by_id;
    activity_list[1] = a_generated;
    Project<Activity>a_list(2, activity_list);
    a_list.append_object(a_generated);
    cout<<a_list.obj_number<<endl;
    a_list.delete_object(3);
    cout<<a_list.obj_number<<endl;
////    STL
    vector<Activity> secvential;
    set<Activity> asociativ;
    queue<Activity> adaptiv;
    int i=4;
    for(i=1; i <= 5; i++) {
        Activity read_a(i);
//        secvential.push_back(read_a);
//        asociativ.insert(read_a);
//        adaptiv.push(read_a);
    }
    return 0;
}
