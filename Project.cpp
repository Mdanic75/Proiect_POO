//
// Created by Daniel on 12/1/2022.
//

#include "Project.h"

using namespace std;
template<typename T>
Project<T>::Project(unsigned int obj_num, T *list) {
    this->element_list = new T[obj_num];
    for(int i=0; i<obj_num; i++)
        this->element_list[i] = list[i];
    this->obj_number = obj_num;
}

template<typename T>
Project<T>::Project() = default;

template<typename T>
void Project<T>::append_object(T new_object) {
    T* list = new T[this->obj_number+1];
    for(unsigned i=0; i< this->obj_number;i++)
        list[i] = this->element_list[i];
    list[this->obj_number] = new_object;
    this->obj_number = this->obj_number +1;
    this->element_list = new T[this->obj_number];
    for(int i=0;i< this->obj_number;i++)
        this->element_list[i] = list[i];
    delete [] list;
}

template<typename T>
void Project<T>::delete_object(unsigned int index) {
    T* list = new T[this->obj_number-1];
    int skip_element = 0;
    for(unsigned i=0; i< this->obj_number-1;i++) {
        if (i==index) skip_element=1;
        list[i] = this->element_list[i+skip_element];
    }
    this->obj_number = this->obj_number - 1;
    this->element_list = new T[this->obj_number];
    for(int i=0;i< this->obj_number;i++)
        this->element_list[i] = list[i];
}

template<typename T>
std::istream &operator>>(istream &input, Project<T> &objects) {
    T object;
    T* list = new T[objects->obj_number+1];
    for(unsigned i=0; i< objects->obj_number;i++)
        list[i] = objects->element_list[i];
    objects->obj_number = objects->obj_number + 1;
    input>>object;
    list[objects->obj_number] = object;
    objects->element_list = new T[objects->obj_number];
    for(int i=0;i< objects->obj_number;i++)
        objects->element_list[i] = list[i];
    return input;
}

template<typename T>
std::ostream &operator<<(ostream &output, Project<T> &objects) {
    cout<<"1";
    for(int i=0;i<objects.obj_number;i++)
        output<<objects.element_list[i];
    return output;
}