#include "validate.hpp"

bool validate_csv(string s) {
    fs::path p(s);
    if(p.extension().compare(".csv")) {
        return false;
    }

    return fs::exists(p);
}

bool validate_source_dir(string s) {
    fs::path p(s);
    return fs::is_directory(p);
}

bool validate_destination_dir(string s) {
    fs::path p(s);
    if(!fs::is_directory(p)) {
        if(!fs::create_directory(p)) {
            return false;
        }
    }
    return true;
}