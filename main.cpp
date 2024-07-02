#include <iostream>
#include <fstream>
#include "row.cpp"
#include <filesystem>

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
        row r(parsed_data[0], parsed_data[1], parsed_data[2], parsed_data[3], parsed_data[4], parsed_data[5]);

        copy_rename(r, vsi_name, destination);
    }
    csv.close();
}

string* parse_data(string row_data) {
    //parse the data with delimiter ", "
}

void copy_rename(row r, string source, string destination) {
    string source_path = source + "\\" + r.get_file_name();
    string dest_path = destination + "\\" + r.get_rename();
    //todo: copy source file to the destination
}