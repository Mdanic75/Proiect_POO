//
// Created by Daniel on 11/10/2022.
//

#include "People.h"
#include "regex"

People::People(const std::string &input_name, const std::string &input_email, const std::string &input_phone_number,
               const std::string &input_profession, const std::string &input_type, unsigned input_age) {
    this->setName(input_name);
    this->setEmail(input_email);
    this->setPhoneNumber(input_phone_number);
    this->setProfession(input_profession);
    this->setType(input_type);
    this->setAge(input_age);
    this->setId();
    ofstream file_output(R"(C:\Users\Daniel\work_space\Proiect_POO\people.txt)", std::ios::app);
    file_output<<*this;
}

void People::setName(const std::string &input_name) {
    this->name = input_name;
}

void People::setEmail(const std::string &input_email) {
    std::regex email_regex (R"(^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$)");
    if (std::regex_match(input_email, email_regex)) this->email = input_email;
    else throw ;
}

void People::setPhoneNumber(const std::string &input_phone_number) {
    std::regex phone_number_regex (R"(^(\+\d{1,2}\s)?\(?\d{3}\)?[\s.-]?\d{3}[\s.-]?\d{4}$)");
    if (std::regex_match(input_phone_number, phone_number_regex)) this->phone_number = input_phone_number;
    else throw ;
}

void People::setProfession(const std::string &input_profession) {
    this->profession=input_profession;
}

void People::setType(const std::string &input_type) {
    std::string valid_types[4] = {"Regular", "Business", "VIP", "employee"};
    bool valid = false;
    for(auto & valid_type : valid_types){
        if (input_type.compare(valid_type)) valid = true;
    }
    if (valid) this->type = input_type;
    else throw;
}

void People::setAge(unsigned input_age) {
    this->age = input_age;
}

std::string People::getName() {
    return this->name;
}

std::string People::getEmail() {
    return this->email;
}

std::string People::getPhoneNumber() {
    return this->phone_number;
}

std::string People::getProfession() {
    return this->profession;
}

std::string People::getType() {
    return this->type;
}

unsigned People::getAge() const {
    return this->age;
}

void People::setId() {
    this->id = People::find_last_id(People::file_name);
}

unsigned People::getId() const {
    return this->id;
}

People::People(unsigned id) {
    ifstream file_input(People::file_name);
    unsigned input_id, input_age;
    string input_name, input_email, input_phone_number, input_profession, input_type;
    while(input_id!=id and !file_input.eof()){
        file_input>>input_id>>input_name>>input_email>>input_phone_number>>input_age>>input_profession>>input_type;
    }
    this->setName(input_name);
    this->setEmail(input_email);
    this->setPhoneNumber(input_phone_number);
    this->setProfession(input_profession);
    this->setType(input_type);
    this->setAge(input_age);
    this->id = input_id;
}
std::ostream &operator<<(ostream &output,People &l) {
    if(typeid(cout).name()==typeid(output).name()) output<<endl<<"Id:"<<l.getId()<<" ,Name:"<<l.getName()<<" ,Email:"<<l.getEmail()<<" ,PhoneNumber:"<<l.getPhoneNumber()<<
          " ,Age:"<<l.getAge()<<" ,Profession:"<<l.getProfession()<<" ,Type:"<<l.getType();
    else output<<endl<<l.getId()<<" "<<l.getName()<<" "<<l.getEmail()<<" "<<l.getPhoneNumber()<<" "<<l.getAge()<<" "<<l.getProfession()<<" "<<l.getType();
    return output;
}




