//
// Created by Daniel on 11/10/2022.
//

#include "Location.h"
#include "cstring"
#include "fstream"
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
                   const string &input_street, int input_street_number, int input_max_people){
    this->setName(input_name);
    this->setMax_people(input_max_people);
    this->setCity(input_city);
    this->setLocality(input_locality);
    this->setStreet_number(input_street_number);
    this->setStreet(input_street);
    this->setId();
    ofstream file_output(R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)", std::ios::app);
    file_output<<*this;
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

Location::Location(const string &file_path, unsigned id) {
    ifstream locations_file(file_path, ios::in);
    string input_name, input_locality, input_city, input_street;
    int input_street_number, input_max_people;
    unsigned input_id = 0;
    while(input_id!=id and !locations_file.eof())
    {
        locations_file>>input_id>>input_name>>input_locality>>input_city>>input_street>>input_street_number>>input_max_people;
    }
    this->setName(input_name);
    this->setMax_people(input_max_people);
    this->setCity(input_city);
    this->setLocality(input_locality);
    this->setStreet_number(input_street_number);
    this->setStreet(input_street);
    this->id = input_id;
}

void Location::setId() {
    unsigned min=0, i;
    string test;
    ifstream file_input(R"(C:\Users\Daniel\work_space\Proiect_POO\locations.txt)");
    while(!file_input.eof()){
        file_input>>i>>test>>test>>test>>test>>test>>test;
        if (i>min) min=i;
    }
    this->id = min+1;
//    this->id = input_id;
}

unsigned Location::getId() const {
    return this->id;
}

std::ostream &operator<<(ostream &output, Location &l) {
    if(typeid(cout).name()==typeid(output).name()) output<<endl<<"Id:"<<l.getId()<<" ,Name:"<<l.getName()<<" ,Locality:"<<l.getLocality()<<" ,City:"<<l.getLocality()<<
    " ,Street:"<<l.getStreet()<<" ,StreetNumber:"<<l.getStreet_number()<<" ,MaxPeople:"<<l.getMax_people();
    else output<<endl<<l.getId()<<" "<<l.getName()<<" "<<l.getLocality()<<" "<<l.getLocality()<<" "<<l.getStreet()<<" "<<l.getStreet_number()<<
    " "<<l.getMax_people();
    return output;
}




