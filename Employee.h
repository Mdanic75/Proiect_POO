//
// Created by Daniel on 11/10/2022.
//

#ifndef PROJECT_OOP_EMPLOYEE_H
#define PROJECT_OOP_EMPLOYEE_H
#include "People.cpp"
#include "string"

class Employee: public People {
    std::string department;
    unsigned superior_id;
    unsigned salary;
    float seniority; //in age
public:
    Employee();
//    Setters
    void setDepartment(const std::string& input_department);
    void setSuperiorId(unsigned input_superior_id);
    void setSalary(unsigned input_salary);
    void setSeniority(unsigned input_seniority);
//    Getters
    std::string getDepartment();
    unsigned getSuperiorId();
    unsigned getSalary();
    float getSeniority();
};


#endif //PROJECT_OOP_EMPLOYEE_H
