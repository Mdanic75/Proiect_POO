//
// Created by Daniel on 11/10/2022.
//
#include "string"
#include "DateTime.h"
#include "stdlib.h"
using namespace std;
DateTime::DateTime(unsigned int input_year, unsigned int input_month, unsigned int input_day, unsigned int input_hour,
                   unsigned int input_minute, unsigned int input_second) {
    this->setYear(input_year);
    this->setMonth(input_month);
    this->setDay(input_day);
    this->setHour(input_hour);
    this->setMinute(input_minute);
    this->setSecond(input_second);
}
void DateTime::setYear(unsigned int input_year) {
    this->year=input_year;
}
void DateTime::setMonth(unsigned int input_month) {
    if (input_month<=12) this->month=input_month;
    else throw ;
}
void DateTime::setDay(unsigned int input_day) {
    if (input_day<=31 && input_day>0) this->day=input_day;
    else throw ;
}
void DateTime::setHour(unsigned int input_hour) {
    if (input_hour<24) this->hour=input_hour;
    else throw ;
}
void DateTime::setMinute(unsigned int input_minute) {
    if (input_minute<60) this->minute=input_minute;
    else throw ;
}
void DateTime::setSecond(unsigned int input_second) {
    if (input_second<60) this->second=input_second;
    else throw ;
}
unsigned DateTime::getYear() {
    return this->year;
}
unsigned DateTime::getMonth() {
    return this->month;
}
unsigned DateTime::getDay() {
    return this->day;
}
unsigned DateTime::getHour() {
    return this->hour;
}
unsigned DateTime::getMinute() {
    return this->minute;
}
unsigned DateTime::getSecond() {
    return this->second;
}
string DateTime::get_date_time_UTC() {
    string year_string = to_string(this->getYear());
    string month_string = to_string(this->getMonth());
    string day_string = to_string(this->getDay());
    string hour_string = to_string(this->getHour());
    string minute_string = to_string(this->getMinute());
    string second_string = to_string(this->getSecond());
    string time_utc = year_string + "-" + month_string + "-" + day_string + "T" + hour_string + ":" + minute_string +
            ":" + second_string;
    return time_utc;
}

DateTime::DateTime(const string& date_time_utc) {
    string year_str = date_time_utc.substr(0,4);
    string month_str = date_time_utc.substr(5,2);
    string day_str = date_time_utc.substr(8,2);
    string hour_str = date_time_utc.substr(11,2);
    string minute_str = date_time_utc.substr(14,2);
    string second_str = date_time_utc.substr(17,2);
    this->setYear(stoi(year_str));
    this->setMonth(stoi(month_str));
    this->setDay(stoi(day_str));
    this->setHour(stoi(hour_str));
    this->setMinute(stoi(minute_str));
    this->setSecond(stoi(second_str));
}
