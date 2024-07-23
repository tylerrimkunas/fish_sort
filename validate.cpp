#include "validate.hpp"

bool validate_csv(string s) {
    path p(s);
    if(p.extension().compare(".csv")) {
        return false;
    }

    return exists(p);
}

bool validate_source_dir(string s) {
    return is_directory(path p(s));
}

bool validate_destination_dir(string s) {
    path p(s);
    if(!is_directory(p)) {
        if(!create_directory(p)) {
            return false;
        }
    }
    return true;
}