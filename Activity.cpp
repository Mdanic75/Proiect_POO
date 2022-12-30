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
    this->setId();
    ofstream file(Activity::file_path, ios::app);
    file<<*this;
}
Activity::Activity(unsigned id) {
    ifstream activity_file(file_path, ios::in);
    Activity a;
    while((id != a.id) && (!activity_file.eof())) {
        activity_file>>a;
    }
    if (a.id == id){
    this->id = a.id;
    this->start_date = DateTime(a.start_date.get_date_time_UTC());
    this->end_date = DateTime(a.end_date.get_date_time_UTC());
    this->name = a.name;
    this->participants_nr = a.participants_nr;
    this->participants = new People[a.participants_nr];
    for(int i=0;i<this->participants_nr;i++)this->participants[i] = a.participants[i];}
    activity_file.close();
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
        this->participants[i] = People(participants_id[i]);
    }
}

ostream &operator<<(ostream &os, Activity &activity) {
    if(typeid(cout).name()==typeid(os).name()) {
        os << "start_date: " << activity.getStarDate().get_date_time_UTC() << " end_date: "
           << activity.getEndDate().get_date_time_UTC() << " name: " << activity.getName()
           << " participants_nr: " << activity.participants_nr << " id: "
           << activity.id<<endl<<"Participants: ";
        for (int i = 0; i < activity.participants_nr; i++)
            os << activity.participants[i].getName()<< " ";
        os<<endl;
    }
    else{
        os <<endl << activity.id<< " " << activity.getStarDate().get_date_time_UTC()<< " " << activity.getEndDate().get_date_time_UTC()<< " " << activity.getName()
        << " "  <<  activity.participants_nr << " ";
        for (int i=0; i<activity.participants_nr; i++)
        os<< activity.participants[i].getId()<<" ";
    }
    return os;

}

void Activity::setId() {
    this->id = Activity::find_last_id(Activity::file_path);
}

istream &operator>>(istream &os, Activity &activity) {
    string input_start_date, input_end_date, input_name;
    unsigned input_participants_number, *participantsId, input_id = 0;
    os>>input_id>>input_start_date>>input_end_date>>input_name>>input_participants_number;
    participantsId = new unsigned[input_participants_number];
    for(int i=0;i<input_participants_number;i++)os>>participantsId[i];
    activity.id = input_id;
    activity.start_date = DateTime(input_start_date);
    activity.end_date = DateTime(input_end_date);
    activity.name = input_name;
    activity.participants_nr = input_participants_number;
    activity.setParticipants(participantsId, input_participants_number);
    return os;
}

Activity::Activity(Activity &activity) {
    this->id = activity.id;
    this->start_date = DateTime(activity.start_date.get_date_time_UTC());
    this->end_date = DateTime(activity.end_date.get_date_time_UTC());
    this->name = activity.name;
    this->participants_nr = activity.participants_nr;
    this->participants = new People[activity.participants_nr];
    for(int i=0;i<this->participants_nr;i++)this->participants[i] = activity.participants[i];
}


void Activity::update_in_file() {
    Activity::delete_line(Activity::file_path, this->id);
    ofstream file(Activity::file_path, ios::app);
    file<<*this;
    file.close();
}

Activity &Activity::operator+(const People& p1) {
    auto *new_participants = new People[this->participants_nr+1];
    for(int i=0;i< this->participants_nr;i++)new_participants[i] = this->participants[i];
    new_participants[this->participants_nr] = p1;
    this->participants_nr++;
    this->participants = new People[this->participants_nr];
    for(int i=0;i< this->participants_nr;i++)this->participants[i]=new_participants[i];
    this->update_in_file();
    return *this;
}

Activity &Activity::operator=(const Activity &a) {
    if (this!=&a){
        this->id = a.id;
        this->start_date = a.start_date;
        this->end_date = a.end_date;
        this->name = a.name;
        this->participants_nr = a.participants_nr;
        this->participants = new People[a.participants_nr];
        for(int i=0;i<this->participants_nr;i++)this->participants[i] = a.participants[i];
    }
    return *this;
}

bool Activity::operator==(const Activity &a) const {
    if (this->id==a.id) return true;
    else return false;
}

Activity::operator int() const {
    return this->participants_nr;
}

Activity &Activity::operator-(unsigned int part_nr) {
    this->participants_nr = this->participants_nr - part_nr;
    auto *new_participants = new People[this->participants_nr];
    for(int i=0;i< this->participants_nr;i++)new_participants[i] = this->participants[i];
    this->participants = new People[this->participants_nr];
    for(int i=0;i< this->participants_nr;i++)this->participants[i]=new_participants[i];
    this->update_in_file();
    return *this;
}

unsigned Activity::operator%(const string& pass_type) {
    int nr = 0;
    for(int i=0;i< this->participants_nr;i++){
        if (this->participants[i].getType() == pass_type) nr++;
    }
    return nr;
}

