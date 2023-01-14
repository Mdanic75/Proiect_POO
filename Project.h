//
// Created by Daniel on 12/1/2022.
//

#ifndef PROJECT_OOP_PROJECT_H
#define PROJECT_OOP_PROJECT_H
#include "string"
#include "Base.h"

template <typename T>
class Project{
public:
    T* element_list;
    unsigned obj_number;
    Project(unsigned obj_num, T* list);
    Project();
    void append_object(T new_object);
    void delete_object(unsigned index);
    friend std::ostream& operator<<(std::ostream& output, Project<T>& objects);
    friend std::istream& operator>>(std::istream& output, Project<T>& objects);
};


#endif //PROJECT_OOP_PROJECT_H
