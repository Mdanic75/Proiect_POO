//
// Created by Daniel on 11/10/2022.
//

#ifndef PROJECT_OOP_ACTIVITY_H
#define PROJECT_OOP_ACTIVITY_H

#include <ostream>
#include "string"
#include "DateTime.h"
#include "Location.h"
#include "People.cpp"

class Activity {
private:
    DateTime start_date;
    DateTime end_date;
    std::string name;
    People *participants;
    unsigned participants_nr;
    unsigned id=0;
public:
    string activity_file_path = R"(C:\Users\Daniel\work_space\Proiect_POO\activity.txt)";
    Activity(const std::string &input_start_date, const std::string &input_end_date, const std::string &input_name,
             unsigned *participants_id, unsigned input_participants_number);
    Activity(){};
    Activity(unsigned input_id);
    DateTime getStarDate() const;

    DateTime getEndDate() const;

    std::string getName() const;


    People *getParticipants() const;
    void setStarDate(const std::string &starDate);

    void setEndDate(const std::string &endDate);

    void setName(const std::string &input_name);


    void setParticipants(unsigned *participants_id, unsigned participants_number);
    friend ostream &operator<<(ostream &os, Activity &activity);

};


#endif //PROJECT_OOP_ACTIVITY_H
