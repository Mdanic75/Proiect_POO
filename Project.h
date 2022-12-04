//
// Created by Daniel on 12/1/2022.
//

#ifndef PROJECT_OOP_PROJECT_H
#define PROJECT_OOP_PROJECT_H
#include "string"
#include "DateTime.h"
#include "Location.h"
#include "People.h"
#include "Activity.h"

class Project {
    std::string name;
    DateTime start_date;
    DateTime end_date;
    Activity *activities;
    People *participants;
};


#endif //PROJECT_OOP_PROJECT_H
