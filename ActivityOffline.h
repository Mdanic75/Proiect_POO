//
// Created by Daniel on 12/3/2022.
//

#ifndef PROJECT_OOP_ACTIVITYOFFLINE_H
#define PROJECT_OOP_ACTIVITYOFFLINE_H

#include <ostream>
#include "string"
#include "Activity.h"
#include "Location.h"
#include "DateTime.h"

class ActivityOffline: public Activity {
    Location location;
    std::string weather_condition;
    std::string catering_company;

public:
    ActivityOffline(Location& location, const std::string &weatherCondition, const std::string &cateringCompany,
                    unsigned activity_id): Activity(activity_id){
        this->location = location;
        this->weather_condition = weatherCondition;
        this->catering_company = cateringCompany;
    };

    Location &getLocation() {
        return location;
    }

    const string &getWeatherCondition() const {
        return weather_condition;
    }

    const string &getCateringCompany() const {
        return catering_company;
    }

    string return_file_path() override {
        return "ActivityOffline does not have file_path";
    }

    friend ostream &operator<<(ostream &os, ActivityOffline &offline) {

        os <<"activity id: "<< offline.getId() << " weather_condition: " << offline.weather_condition << " catering_company: " << offline.catering_company
                << " location: " << offline.location;
        return os;
    }

};


#endif //PROJECT_OOP_ACTIVITYOFFLINE_H
