#ifndef ROW_HPP
#define ROW_HPP
/*
 */
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

#endif // ROW_HPP