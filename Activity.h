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
#include "Base.h"

class Activity: Base {
    DateTime start_date;
    DateTime end_date;
    std::string name;
    People *participants;
    unsigned participants_nr;
    unsigned id=0;
public:
    void setId();
    static string file_path;
    Activity(const std::string &input_start_date, const std::string &input_end_date, const std::string &input_name,
             unsigned *participants_id, unsigned input_participants_number);
    Activity(){};
    ~Activity(){
//        delete this->participants;
    };
    Activity(Activity &activity);
    Activity(unsigned input_id);
    DateTime getStarDate() const;

    DateTime getEndDate() const;

    std::string getName() const;


    People *getParticipants() const;
    void setStarDate(const std::string &starDate);

    void setEndDate(const std::string &endDate);

    void setName(const std::string &input_name);

    unsigned int getId() const;
    void setParticipants(unsigned *participants_id, unsigned participants_number);
//    Operators
    friend ostream &operator<<(ostream &os, Activity &activity);
    friend istream &operator>>(istream &os, Activity &activity);

    virtual Activity &operator+(const People& p1);
    Activity &operator-(unsigned part_nr);
    Activity &operator=(const Activity& a);
    bool operator==(const Activity& a) const;
    explicit operator int() const; // returneaza nr de participanti
    unsigned operator%(const std::string& pass_type); //returneaza nr de participanti cu biletul de tipul
    //    Methods
    void update_in_file();
    string return_file_path() override;
};


#endif //PROJECT_OOP_ACTIVITY_H
