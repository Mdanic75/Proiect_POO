//
// Created by Daniel on 12/22/2022.
//

#ifndef PROJECT_OOP_BASE_H
#define PROJECT_OOP_BASE_H
#include <utility>

#include "string"

class Base {
public:
    Base(){};
    static unsigned find_last_id(const std::string& file_name);
    static void delete_line(const std::string& file_name, unsigned object_id);
};


#endif //PROJECT_OOP_BASE_H
