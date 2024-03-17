#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>


int main() {
    std::stringstream   ss;
    ss << "2009-01-02";
    int year, month, day;
    char d1, d2;
    if (!(ss >> year >> d1 >> month >> d2 >> day) || !ss.eof()) {
        exit(1);
    }
    if (year < 0 || day < 0 || month < 0)
        exit(1);
    std::cout << year << "-" << month << "-" << day << std::endl;
    // yyyy-mm-dd
}