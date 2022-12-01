//
// Created by Daniel on 11/10/2022.
//
#include "string"
#ifndef PROJECT_OOP_LOCATION_H
#define PROJECT_OOP_LOCATION_H

class Location {
    std::string name;
    std::string locality;
    std::string city;
    std::string street;
    int street_number = 0;
    int max_people = 0;
public:
    Location(const std::string& input_name, const std::string& input_locality, const std::string& input_city,
             const std::string& input_street, int input_street_number, int input_max_people);
//    Setters
    void setName(const std::string& input_name);
    void setLocality(const std::string& input_locality);
    void setCity(const std::string& input_city);
    void setStreet(const std::string& input_street);
    void setStreet_number(int input_street_number);
    void setMax_people(int input_max_people);
//    Getters
    std::string getName();
    std::string getLocality();
    std::string getCity();
    std::string getStreet();
    int getStreet_number() const;
    int getMax_people() const;

};


#endif //PROJECT_OOP_LOCATION_H
