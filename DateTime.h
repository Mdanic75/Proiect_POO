//
// Created by Daniel on 11/10/2022.
//
#include "string"
#ifndef PROJECT_OOP_DATETIME_H
#define PROJECT_OOP_DATETIME_H


class DateTime {
    unsigned year;
    unsigned month;
    unsigned day;
    unsigned hour;
    unsigned minute;
    unsigned second;
public:
    DateTime(unsigned input_year, unsigned input_month, unsigned input_day, unsigned input_hour, unsigned input_minute,
             unsigned input_second);
    DateTime(const std::string& date_time_utc);
    DateTime(){};
//    Setter
void setYear(unsigned input_year);
void setMonth(unsigned input_month);
void setDay(unsigned input_day);
void setHour(unsigned input_hour);
void setMinute(unsigned input_minute);
void setSecond(unsigned input_second);
//    Getter
unsigned getYear();
unsigned getMonth();
unsigned getDay();
unsigned getHour();
unsigned getMinute();
unsigned getSecond();
//    Methods
std::string get_date_time_UTC();
};


#endif //PROJECT_OOP_DATETIME_H
