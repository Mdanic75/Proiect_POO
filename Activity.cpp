//
// Created by Daniel on 11/10/2022.
//

#include "Activity.h"
#include "People.h"
#include "DateTime.h"
#include "string"
using namespace std;


Activity::Activity(const string &input_start_date, const string &input_end_date, const string &input_name, unsigned *participantsId,
                   unsigned input_participants_number){
    this->setStarDate(input_start_date);
    this->setEndDate(input_end_date);
    this->setName(input_name);
    this->participants_nr = input_participants_number;
    this->setParticipants(participantsId, input_participants_number);
}
Activity::Activity(unsigned id) {
    ifstream activity_file(activity_file_path, ios::in);
    string input_start_date, input_end_date, input_name;
    unsigned input_participants_number, *participantsId, input_id = 0;
    while(id != input_id){
        activity_file>>input_id>>input_start_date>>input_end_date>>input_name>>input_participants_number;
        participantsId = new unsigned[input_participants_number];
        for(int i=0;i<input_participants_number;i++)activity_file>>participantsId[i];
    }
    this->id = id;
    this->start_date = DateTime(input_start_date);
    this->end_date = DateTime(input_end_date);
    this->name = input_name;
    this->participants_nr = input_participants_number;
    this->setParticipants(participantsId, input_participants_number);
}

DateTime Activity::getStarDate() const {
    return start_date;
}

DateTime Activity::getEndDate() const {
    return end_date;
}

string Activity::getName() const {
    return name;
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

void Activity::setParticipants(unsigned *participants_id, unsigned participants_number) {
    this->participants = new People[participants_number];
    for(int i=0;i<participants_number;i++){
        this->participants[i] = People(R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)", participants_id[i]);
    }
}

ostream &operator<<(ostream &os, Activity &activity) {
    os << "start_date: " << activity.getStarDate().get_date_time_UTC() << " end_date: " << activity.getEndDate().get_date_time_UTC() << " name: " << activity.getName()
       << " participants: " << activity.participants << " participants_nr: " << activity.participants_nr << " id: "
       << activity.id << " activity_file_path: " << activity.activity_file_path;
    return os;
}
