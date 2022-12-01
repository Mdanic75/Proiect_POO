//
// Created by Daniel on 11/10/2022.
//

#ifndef PROJECT_OOP_ACTIVITY_H
#define PROJECT_OOP_ACTIVITY_H
#include "string"
#include "DateTime.h"
#include "Location.h"
#include "People.cpp"

class Activity {
    DateTime star_date;
    DateTime end_date;
    std::string name;
    Location location;
    People *participants;
};


#endif //PROJECT_OOP_ACTIVITY_H
