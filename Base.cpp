//
// Created by Daniel on 12/22/2022.
//

#include "Base.h"
#include "fstream"

using namespace std;


unsigned Base::find_last_id(const std::string& filename) {
    ifstream file(filename, ios::in);
    int id, max=0;
    while(!file.eof()){
        string a;
        getline(file, a);
        id = stoi(a);
        if(id>max) max=id;
    }
    return max+1;
}

void delete_line_from_file(const string& file_name, int n)
{
    ifstream is(file_name, ios::in);
    ofstream ofs;
    ofs.open(R"(C:\Users\Daniel\work_space\Proiect_POO\temp.txt)", ofstream::out);
    string c;
    int line_no = 1;
    while (!is.eof())
    {
        getline(is, c);
        if (line_no != n) {
            if (line_no == 1) ofs << c;
            else ofs << endl << c;
        }
        line_no++;
    }
    ofs.close();
    is.close();
    remove(file_name.c_str());
    rename(R"(C:\Users\Daniel\work_space\Proiect_POO\temp.txt)", file_name.c_str());
}

void Base::delete_line(const string &filename, unsigned int object_id) {
    ifstream file(filename);
    int id, line_num=0;
    string a;
    while(!file.eof() and id!=object_id){
        getline(file, a);
        id = stoi(a);
        line_num++;
    }
    file.close();
    if(id==object_id){
        delete_line_from_file(filename, line_num);
    }
}
