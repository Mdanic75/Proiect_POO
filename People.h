//
// Created by Daniel on 11/10/2022.
//

#ifndef PROJECT_OOP_PEOPLE_H
#define PROJECT_OOP_PEOPLE_H
#include "string"

class People {
    unsigned id;
    std::string name;
    std::string email;
    std::string phone_number;
    unsigned age;
    std::string profession;
    std::string type; // regular, business , vip (only for participants)
public:
    People(const std::string& input_name, const std::string& input_email, const std::string& input_phone_number,
           const std::string& input_profession, const std::string& input_type, unsigned input_age, unsigned input_id);

    People();

//    Setter
    void setId(unsigned input_id);
    void setName(const std::string& input_name);
    void setEmail(const std::string& input_email);
    void setPhoneNumber(const std::string& input_phone_number);
    void setProfession(const std::string& input_profession);
    void setType(const std::string& input_type);
    void setAge(unsigned input_age);
//    Getter
    std::string getName();
    std::string getEmail();
    std::string getPhoneNumber();
    std::string getProfession();
    std::string getType();
    unsigned getAge() const;
    unsigned getId() const;
};


#endif //PROJECT_OOP_PEOPLE_H
