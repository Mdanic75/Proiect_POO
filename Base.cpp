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
