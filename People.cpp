//
// Created by Daniel on 11/10/2022.
//

#include "People.h"
#include "regex"
People::People(const std::string &input_name, const std::string &input_email, const std::string &input_phone_number,
               const std::string &input_profession, const std::string &input_type, unsigned input_age, unsigned input_id) {
    this->setName(input_name);
    this->setEmail(input_email);
    this->setPhoneNumber(input_phone_number);
    this->setProfession(input_profession);
    this->setType(input_type);
    this->setAge(input_age);
    this->setId(input_id);
}

void People::setName(const std::string &input_name) {
    this->name = input_name;
}

void People::setEmail(const std::string &input_email) {
    std::regex email_regex (R"(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/)");
    if (std::regex_match(input_email, email_regex)) this->email = input_email;
    else throw_with_nested("It's not a valid email");
}

void People::setPhoneNumber(const std::string &input_phone_number) {
    std::regex phone_number_regex (R"(^(\+\d{1,2}\s)?\(?\d{3}\)?[\s.-]?\d{3}[\s.-]?\d{4}$)");
    if (std::regex_match(input_phone_number, phone_number_regex)) this->phone_number = input_phone_number;
    else throw_with_nested("It's not a valid phone_number") ;
}

void People::setProfession(const std::string &input_profession) {
    this->profession=input_profession;
}

void People::setType(const std::string &input_type) {
    std::string valid_types[4] = {"Regular", "Business", "VIP", ""};
    bool valid = false;
    for(auto & valid_type : valid_types){
        if (input_type == valid_type) valid = true;
    }
    if (!valid) this->type = input_type;
    else throw_with_nested("It's not a valid type") ;
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

void People::setId(unsigned int input_id) {
    this->id = input_id;
}

unsigned People::getId() const {
    return this->id;
}


