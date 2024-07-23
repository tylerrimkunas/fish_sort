#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <sstream>
#include <experimental/filesystem>

#include "row.cpp"
#include "validate.hpp"

namespace fs = std::experimental::filesystem;

using namespace std;

void rename_files(string csv_name, string vsi_name, string destination);
string* parse_data(string row_data);
void copy_rename(row r, string source, string destination);

int main() {
    ifstream file_names("file_names.txt");
    if(file_names.fail()) {
        cout << "\nfile_names.txt not found, please create files_names.txt and follow the format given in the readme\n";
        getchar();
        return -1;
    }
    string csv_file;
    string source_files;
    string destination;
    getline(file_names, csv_file); //todo: exception handling
    if(!validate_csv(csv_file)) {
        cout << "\nThe 1st line of file_names.txt is not a csv file. Please fix and rerun program\n";
        getchar();
        return -1;
    }
    getline(file_names, source_files);
    if(!validate_source_dir(source_files)) {
        cout << "\nThe 2nd line of file_names.txt is not a correct directory. Please fix and rerun the program\n";
        getchar();
        return -1;
    }
    getline(file_names, destination);
    if(!validate_destination_dir(destination)) {
        cout << "\nThe 3rd line of file_names.txt cannot be a destination directory. Please fix and rerun the program\n";
        getchar();
        return -1;
    }
    file_names.close();

    rename_files(csv_file, source_files, destination);
    cout << "\nPlease check for errors then press any button to close\n";
    getchar();


    /*
    New format of main.cpp
    int main() {
    Open file_names.txt if doesn't open, return error message and end program.
    Get the three file names. validate all are correct format and also exist.
    close file_names.txt

    create the destination directory

    open the csv file
    call get_row()

    call copy_rename()

    convert files to tiff (temp)

    create power point
    8 images per slide
    have variable indicating fish number
    if next file's first character differs than the fish number create new slide
    
    Once done, delete temp files
    }

    row get_row() {
    getline from csv file
    call parse_data()
    create new row and return row
    }

    string* parse_data() {
    stays the same as already implemented
    }

    bool copy_rename() {

    }
    */
}

void rename_files(string csv_name, string vsi_name, string destination) {
    ifstream csv(csv_name);
    string row_data;

    getline(csv, row_data); //skip header

    while(getline(csv, row_data)) { //iterate through each row
        string* parsed_data = parse_data(row_data);
        row r(parsed_data[0], parsed_data[1], parsed_data[2], parsed_data[3], parsed_data[4], parsed_data[5], parsed_data[6]);

        copy_rename(r, vsi_name, destination);
        delete[] parsed_data;
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
    // ifstream validate;
    // validate.open(dest_path);
    // if(!validate) {
    //     cout << "\n" + source_path + " TO " + dest_path + " FAILED TO COPY\n";
    // }
    // else {
    //     validate.close();
    // }
}