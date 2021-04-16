/**
 * 
 * Assignment #3
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

// define header file
#pragma once

// include
#include <iostream>
#include <string>

// namespaces
using namespace std;

// define ariel namespace
namespace ariel {

    // define NumberWithUnits class
    class NumberWithUnits {

        // private variables and methods
        private:
            double unit_value;
            string unit_type;

        // public variables and methods
        public:
            // define constructor
            NumberWithUnits(double value, const string& type);

            // default constructor
            NumberWithUnits() {}

            // deconstructor
            ~NumberWithUnits() {}

            // define value and type getters methods
            double getValue() const;
            string getType() const;

            // define read_units function
            static void read_units(ifstream& units_file);

            /** overloading in and out operators */

            // >> operator
            friend istream& operator>>(istream& ist, NumberWithUnits& unit_number);

            // << operator
            friend ostream& operator<<(ostream& ost, const NumberWithUnits& unit_number);

            /** overloading arithmetic operators */

            // + operators
            friend NumberWithUnits operator+(const NumberWithUnits& unit_number, double number);
            friend NumberWithUnits operator+(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // ++ operators
            friend NumberWithUnits operator++(NumberWithUnits& unit_number);
            friend NumberWithUnits operator++(NumberWithUnits& unit_number, int);

            // += operator
            friend NumberWithUnits operator+=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // - operators
            friend NumberWithUnits operator-(const NumberWithUnits& unit_number);
            friend NumberWithUnits operator-(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // -- operators
            friend NumberWithUnits operator--(NumberWithUnits& unit_number);
            friend NumberWithUnits operator--(NumberWithUnits& unit_number, int);

            // -= operator
            friend NumberWithUnits operator-=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // * operators
            friend NumberWithUnits operator*(NumberWithUnits& unit_number, double number);
            friend NumberWithUnits operator*(double num, NumberWithUnits& unit_number);

            // *= operators
            friend NumberWithUnits operator*=(NumberWithUnits& unit_number, double number);
            friend NumberWithUnits operator*=(double number, NumberWithUnits& unit_number);

            /** Comparison operators */

            // == operator
            friend bool operator==(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // != operator
            friend bool operator!=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // < and <= operators
            friend bool operator<(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);
            friend bool operator<=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);

            // > and >= operators
            friend bool operator>(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);
            friend bool operator>=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2);
    };
}
