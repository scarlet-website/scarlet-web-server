/**
 * 
 * Assignment #3
 * COURSE:   Systems Programming 2 Ariel University
 * AUTHORS:  Kfir Goldfarb
 * https://www.github.com/kggold4
 * YEAR: 2021
 * 
 * */

// includes
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "NumberWithUnits.hpp"

// namespaces
using namespace std;
using namespace ariel;

// implement ariel namespace
namespace ariel {

    static map<string, map<string, double>> T;
    const double EPS = 0.00001;
    const int ZERO = 0;

    // implement constructor
    NumberWithUnits::NumberWithUnits(double value, const string& unit) {
        this->value = value;
        this->unit = unit;
    }

    // implement read_units function
    void NumberWithUnits::read_units(ifstream& units_file) {
        double amount_1 = 0;
        double amount_2 = 0;
        string unit_1;
        string unit_2;
        string mark;
        while(units_file >> amount_1 >> unit_1 >> mark >> amount_2 >> unit_2) {
            if(amount_1 == 0 || amount_2 == 0 || unit_1.empty() || unit_2.empty()) { continue; }
        }
        T[unit_1][unit_2] = amount_2 / amount_1;
        T[unit_2][unit_1] = amount_1 / amount_2;
        for(auto &p : T[unit_1]) {
            if(unit_2 != p.first) {
                T[unit_2][p.first] = p.second / (amount_1 * amount_2);
                T[p.first][unit_2] = (amount_1 / amount_2) / p.second;
            }
        }
        for(auto &p : T[unit_2]) {
            if(unit_1 != p.first) {
                T[unit_1][p.first] = p.second / (amount_1 / amount_2);
                T[p.first][unit_1] = (amount_1 / amount_2) / p.second;
            }
        }
    }

    static double casting(const string& from_unit, const string& to_unit, double value) {
        double ans = 0;
        if(from_unit == to_unit) { ans = value; }
        else if(from_unit.empty() || to_unit.empty()) { throw invalid_argument{"unit cannot be empty"}; }
        else {
            try { ans = value * T.at(from_unit).at(to_unit); }
            catch(const exception& e) {
                throw invalid_argument{"unit " + from_unit + " cannot casting to " + to_unit};
            }
        }
        return ans;
    }

    static int compare_units(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        int ans = 0;
        if(unit_number_1.getValue() - casting(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) > EPS) { ans = 1; }
        else if(casting(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) - unit_number_1.getValue() > EPS) { ans = -1; }
        return ans;
    }

    // implement getValue method
    double NumberWithUnits::getValue() const { return this->value; }

    // implement getType methods
    string NumberWithUnits::getType() const { return this->unit; }


    /** overloading in and out operators */

    // >> operator
    istream& operator>>(istream& ist, NumberWithUnits& unit_number) {
        string str;
        ist >> unit_number.value >> str >> unit_number.unit;
        return ist;
    }

    // << operator
    ostream& operator<<(ostream& ost, const NumberWithUnits& unit_number) {
        ost << unit_number.value << '[' << unit_number.unit << ']';
        return ost;
    }

    /** overloading arithmetic operators */

    // + operators
    NumberWithUnits operator+(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting(unit_number_2.unit, unit_number_1.unit, unit_number_2.value);
        return NumberWithUnits(unit_number_1.value + temp, unit_number_1.unit);
    }

    NumberWithUnits operator+(const NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.value + number, unit_number.unit);
    }

    // ++ operators
    NumberWithUnits operator++(NumberWithUnits& unit_number, int) {
        return NumberWithUnits(unit_number.value + 1, unit_number.unit);
    }
    NumberWithUnits operator++(NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.value + 1, unit_number.unit);
    }

    // += operator
    NumberWithUnits operator+=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        unit_number_1.value = unit_number_1.value + casting(unit_number_2.unit, unit_number_1.unit, unit_number_2.value);
        return unit_number_1;
    }

    // - operators
    NumberWithUnits operator-(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting(unit_number_2.unit, unit_number_1.unit, unit_number_2.value);
        return NumberWithUnits(unit_number_1.value-temp, unit_number_1.unit);
    }
    NumberWithUnits operator-(const NumberWithUnits& unit_number) {
        return NumberWithUnits(-unit_number.value, unit_number.unit);
    }

    // -- operators
    NumberWithUnits operator--(NumberWithUnits& unit_number, int) {
        return NumberWithUnits(unit_number.value - 1, unit_number.unit);
    }
    NumberWithUnits operator--(NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.value - 1, unit_number.unit);
    }

    // -= operator
    NumberWithUnits operator-=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting(unit_number_2.unit, unit_number_1.unit, unit_number_2.value);
        return NumberWithUnits(unit_number_1.value = unit_number_1.value - temp, unit_number_1.unit);
    }

    // * operators
    NumberWithUnits operator*(NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.value *number, unit_number.unit);
    }
    NumberWithUnits operator*(double number, NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.value * number, unit_number.unit);
    }

    // *= operators
    NumberWithUnits operator*=(NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.value = unit_number.value * number, unit_number.unit);
    }
    NumberWithUnits operator*=(double number, NumberWithUnits& unit_number) {
        return NumberWithUnits(number * unit_number.value, unit_number.unit);
    }

    /** equality operators */

    // == operator
    bool operator==(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) == ZERO;
    }

    // != operator
    bool operator!=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) != ZERO;
    }

    // < and <= operators
    bool operator<(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) < ZERO;
    }
    bool operator<=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) <= ZERO;
    }

    // > and >= operators
    bool operator>(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) > ZERO;
    }
    bool operator>=(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        return compare_units(unit_number_1, unit_number_2) >= ZERO;
    }
}
