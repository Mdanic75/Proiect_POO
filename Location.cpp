//
// Created by Daniel on 11/10/2022.
//

#include "Location.h"
#include "string"
using namespace std;

void Location::setName(const string& input_name) {
    this->name = input_name;
}
void Location::setLocality(const string &input_locality){
    this->locality = input_locality;
}
void Location::setCity(const string &input_city){
    this->city = input_city;
}
void Location::setStreet(const string &input_street){
    this->street = input_street;
}
void Location::setStreet_number(int input_street_number){
    this->street_number = input_street_number;
}
void Location::setMax_people(int input_max_people){
    this->max_people = input_max_people;
}
Location::Location(const string &input_name, const string &input_locality, const string &input_city,
                   const string &input_street, int input_street_number, int input_max_people) {
    this->setName(input_name);
    this->setMax_people(input_max_people);
    this->setCity(input_city);
    this->setLocality(input_locality);
    this->setStreet_number(input_street_number);
    this->setStreet(input_street);
}

std::string Location::getName() {
    return this->name;
}

std::string Location::getCity() {
    return this->city;
}

std::string Location::getStreet() {
    return this->street;
}

int Location::getStreet_number() const {
    return this->street_number;
}

int Location::getMax_people() const {
    return this->max_people;
}

std::string Location::getLocality() {
    return this->locality;
}



