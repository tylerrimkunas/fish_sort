#include <experimental/filesystem>
using namespace std;

/*
These functions are meant to confirm the existence and correct formatting of the file names in file_names.txt

validate_csv confirms that the csv file exists and that it is a csv file and not any other type of file

validate_source_dir confirms the existence of the source directory

validate_destination_dir confirms that the directory exists, and if not then attempts to create directory
*/
bool validate_csv(string s);
bool validate_source_dir(string s);
bool validate_destination_dir(string s);