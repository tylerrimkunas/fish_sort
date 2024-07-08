#include <string>

using namespace std;
class row
{
private:
    /* data */
    string scan_date,
    cut_date,
    nissl_date,
    slide_number,
    slide_extension,
    fish_number,
    slide_name;

public:
    row(string new_scan_date, string new_cut_date, string new_nissl_date, string new_slide_name, string new_slide_number, string new_slide_extension, string new_fish_number);
    string get_scan_date();
    string get_cut_date();
    string get_slide_name();
    string get_slide_number();
    string get_slide_extension();
    string get_fish_number();

    string get_file_name();
    string get_rename();
};

row::row(string new_scan_date, string new_cut_date, string new_nissl_date, string new_slide_name, string new_slide_number, string new_slide_extension, string new_fish_number) {
    scan_date = new_scan_date;
    cut_date = new_cut_date;
    nissl_date = new_nissl_date;
    slide_name = new_slide_name;
    slide_number = new_slide_number;
    slide_extension = new_slide_extension;
    fish_number = new_fish_number;
}

string row::get_scan_date() {
    return scan_date;
}

string row::get_cut_date() {
    return cut_date;
}

string row::get_slide_name() {
    return slide_name;
}

string row::get_slide_number() {
    return slide_number;
}

string row::get_slide_extension() {
    return slide_extension;
}

string row::get_fish_number() {
    return fish_number;
}

string row::get_file_name() {
    string file_name = "";
    if(slide_name.find("5dpf") == std::string::npos) {
        int i_space = slide_name.find(" ");
        slide_name = slide_name.substr(0, i_space) + " 5dpf" + slide_name.substr(i_space);
    }
    file_name.append(slide_name).append(" slide ").append(slide_number).append("_");
    if(slide_extension.length() < 2) {
        file_name.append("0");
    }
    return file_name.append(slide_extension).append(".vsi");
}

string row::get_rename() {
    string file_name = "";
    if(slide_name.find("DM") != std::string::npos) {
        file_name.append("DM_");
    }
    else if(slide_name.find("WT") != std::string::npos) {
        file_name.append("WT_");
    }
    file_name.append(fish_number).append("_").append(slide_number).append("_");
    if(slide_extension.length() < 2) {
        file_name.append("0");
    }
    return file_name.append(slide_extension).append(" ").append(get_file_name());
}
