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
    DateTime start_date;
    DateTime end_date;
    std::string name;
    Location location;
    People *participants;
    unsigned participants_nr;
    unsigned id=0;
public:
    Activity(const std::string &input_start_date, const std::string &input_end_date, const std::string &input_name, unsigned location_id,
             unsigned *participants_id, unsigned input_participants_number);

    const DateTime &getStarDate() const;

    const DateTime &getEndDate() const;

    const std::string &getName() const;

    const Location &getLocation() const;

    People *getParticipants() const;
    void setStarDate(const std::string &starDate);

    void setEndDate(const std::string &endDate);

    void setName(const std::string &input_name);

    void setLocation(unsigned location_id);

    void setParticipants(unsigned *participants_id, unsigned participants_number);

};


#endif //PROJECT_OOP_ACTIVITY_H
