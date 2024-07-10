#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <sstream>
#include "row.cpp"

using namespace std;

void rename_files(string csv_name, string vsi_name, string destination);
string* parse_data(string row_data);
void copy_rename(row r, string source, string destination);

int main() {
    ifstream file_names("file_names.txt");
    string csv_file;
    string source_files;
    string destination;
    getline(file_names, csv_file); //todo: exception handling
    getline(file_names, source_files);
    getline(file_names, destination);
    file_names.close();

    rename_files(csv_file, source_files, destination);
}

void rename_files(string csv_name, string vsi_name, string destination) {
    ifstream csv(csv_name);
    string row_data;

    getline(csv, row_data); //skip header

    while(getline(csv, row_data)) { //iterate through each row
        string* parsed_data = parse_data(row_data);
        row r(parsed_data[0], parsed_data[1], parsed_data[2], parsed_data[3], parsed_data[4], parsed_data[5], parsed_data[6]);

        copy_rename(r, vsi_name, destination);
        //delete parsed_data;
    }
    csv.close();
}

string* parse_data(string row_data) {
    //parse the data with delimiter ", "
    string *parsed_data = new string[sizeof(string) * 7];
    char delimiter = ',';
    int i = 0;
    istringstream stream(row_data);
    string t;
    while (getline(stream, t, delimiter)) {
        parsed_data[i++] = t;
    }
    return parsed_data;

}

void copy_rename(row r, string source, string destination) {
    string source_path = "\"" + source + "\\" + r.get_file_name() + "\"";
    string dest_path = "\"" + destination + "\\" + r.get_rename() + "\"";
    //todo: copy source file to the destination
    mkdir(destination.c_str());
    string command = "copy " + source_path + " " + dest_path;
    system(command.c_str());
    ifstream validate;
    validate.open(dest_path);
    if(!validate) {
        cout << source_path + " TO " + dest_path + " FAILED TO COPY";
    }
    else {
        validate.close();
    }
}