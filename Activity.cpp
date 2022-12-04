//
// Created by Daniel on 11/10/2022.
//

#include "Activity.h"
#include "People.h"
#include "string"
using namespace std;


Activity::Activity(const string &input_start_date, const string &input_end_date, const string &input_name,
                   unsigned location_id, unsigned *participantsId, unsigned input_participants_number){
    this->setStarDate(input_start_date);
    this->setEndDate(input_end_date);
    this->setName(input_name);
    this->setLocation(location_id);
    this->participants_nr = input_participants_number;
    this->setParticipants(participantsId, input_participants_number);
}

const DateTime &Activity::getStarDate() const {
    return start_date;
}

const DateTime &Activity::getEndDate() const {
    return end_date;
}

const string &Activity::getName() const {
    return name;
}

const Location &Activity::getLocation() const {
    return location;
}

People *Activity::getParticipants() const {
    return participants;
}

void Activity::setStarDate(const string &starDate) {
    start_date = DateTime(starDate);
}

void Activity::setEndDate(const string &endDate) {
    end_date = DateTime(endDate);
}

void Activity::setName(const string &input_name) {
    Activity::name = input_name;
}

void Activity::setLocation(unsigned location_id) {
    Activity::location = Location(R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)", location_id);
}

void Activity::setParticipants(unsigned *participants_id, unsigned participants_number) {
    this->participants = new People[participants_number];
    for(int i=0;i<participants_number;i++){
        this->participants[i] = People(R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)", participants_id[i]);
    }
}
