//
// Created by Daniel on 12/3/2022.
//

#ifndef PROJECT_OOP_ACTIVITYOFFLINE_H
#define PROJECT_OOP_ACTIVITYOFFLINE_H
#include "string"
#include "Activity.h"
#include "Location.h"
#include "DateTime.h"

class ActivityOffline: Activity {
    Location location;
    std::string weather_condition;
    std::string catering_company;

public:
    ActivityOffline(const Location &location, const std::string &weatherCondition,
                    const std::string &cateringCompany, Location location1);

};


#endif //PROJECT_OOP_ACTIVITYOFFLINE_H
