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

string* parse_data(string row_data);
bool copy_rename(row* r, string source, string destination);
row* get_row(ifstream& csv);

int main() {
    ifstream file_names("file_names.txt");
    if(file_names.fail()) {
        cout << "\nfile_names.txt not found, please create files_names.txt and follow the format given in the readme\n";
        getchar();
        return -1;
    }
    string csv_name;
    string source_name;
    string destination;
    getline(file_names, csv_name);
    if(!validate_csv(csv_name)) {
        cout << "\nThe 1st line of file_names.txt is not a csv file. Please fix and rerun program\n";
        getchar();
        return -1;
    }
    getline(file_names, source_name);
    if(!validate_source_dir(source_name)) {
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

    ifstream csv_file(csv_name);
    if(csv_file.fail()) {
        cout << "\nError when opening csv file. Terminating program.\n";
        getchar();
        return -1;
    }
    string temp;
    getline(csv_file, temp); // skip header
    row* r = get_row(csv_file);
    while(r != NULL) {
        if(!copy_rename(r, source_name, destination)) {
            cout << "\nERROR file name: " + r->get_file_name() + "\n";
        }
        delete r;
        r = get_row(csv_file);
    }
    csv_file.close();
    cout << "\nPlease check for errors then press any button to close\n";
    getchar();


    /*
    New format of main.cpp
    int main() {
    Open file_names.txt if doesn't open, return error message and end program.
    Get the three file names. validate all are correct format and also exist.
    close file_names.txt

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

row* get_row(ifstream& csv) {
    string row_data;
    if(!getline(csv, row_data)) { //reaches end of line
        return NULL;
    }
    string* parsed_data = parse_data(row_data);
    row* r = new row(parsed_data[0], parsed_data[1], parsed_data[2], parsed_data[3], parsed_data[4], parsed_data[5], parsed_data[6]);
    delete[] parsed_data;
    return r;
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

bool copy_rename(row* r, string source, string destination) {
    fs::path source_path = "\"" + source + "\\" + r->get_file_name() + "\"";
    fs::path dest_path = "\"" + destination + "\\" + r->get_rename() + "\"";
    try {
        return fs::copy_file(source_path, dest_path);
    } catch(exception e) {
        return false;
    }
}