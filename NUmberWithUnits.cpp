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
    NumberWithUnits::NumberWithUnits(double value, const string& type) {
        this->unit_value = value;
        this->unit_type = type;
    }

    // implement read_units function
    void NumberWithUnits::read_units(ifstream& units_file) {
        
        double amount_1 = 0;
        double amount_2 = 0;
        string unit_1;
        string unit_2;
        string mark;

        while(units_file >> amount_1 >> unit_1 >> mark >> amount_2 >> unit_2) {
            T[unit_1][unit_2] = amount_2;
            T[unit_2][unit_1] = 1 / amount_2;
            for(const auto& kv: T[unit_2]) {
                const auto& key = kv.first;
                const auto& value = kv.second;
                double ans = T[unit_1][unit_2] * value;
                T[unit_1][key] = ans;
                T[key][unit_1] = 1/ans;
            }
            for(const auto& kv: T[unit_1]) {
                const auto& key = kv.first;
                const auto& value = kv.second;
                double ans = T[unit_2][unit_1] * value;
                T[unit_2][key] = ans;
                T[key][unit_2] = 1/ans;
            }
        }

        // while(units_file >> amount_1 >> unit_1 >> mark >> amount_2 >> unit_2) {
        //     if(amount_1 == 0 || amount_2 == 0 || unit_1.empty() || unit_2.empty()) { continue; }
        // }
        // T[unit_1][unit_2] = amount_2 / amount_1;
        // T[unit_2][unit_1] = amount_1 / amount_2;
        // for(auto &p : T[unit_1]) {
        //     if(unit_2 != p.first) {
        //         T[unit_2][p.first] = p.second / (amount_1 * amount_2);
        //         T[p.first][unit_2] = (amount_1 / amount_2) / p.second;
        //     }
        // }
        // for(auto &p : T[unit_2]) {
        //     if(unit_1 != p.first) {
        //         T[unit_1][p.first] = p.second / (amount_1 / amount_2);
        //         T[p.first][unit_1] = (amount_1 / amount_2) / p.second;
        //     }
        // }
    }

    static double casting_units(const string& from_unit, const string& to_unit, double value) {
        double ans = 0;
        if(from_unit == to_unit) { ans = value; }
        else if(from_unit.empty() || to_unit.empty()) { throw invalid_argument{"unit cannot be empty"}; }
        else {
            try {
                std::cout << "out!: " << T.at(from_unit).at(to_unit) << endl;
                ans = value * T.at(from_unit).at(to_unit);
                
            }
            catch(const exception& e) {
                throw invalid_argument{"unit " + from_unit + " cannot casting to " + to_unit};
            }
        }
        return ans;
    }

    static int compare_units(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        int ans = 0;
        if(unit_number_1.getValue() - casting_units(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) > EPS) { ans = 1; }
        else if(casting_units(unit_number_2.getType(), unit_number_1.getType(), unit_number_2.getValue()) - unit_number_1.getValue() > EPS) { ans = -1; }
        return ans;
    }

    // implement getValue method
    double NumberWithUnits::getValue() const { return this->unit_value; }

    // implement getType methods
    string NumberWithUnits::getType() const { return this->unit_type; }


    /** overloading in and out operators */

    // >> operator
    istream& operator>>(istream& ist, NumberWithUnits& unit_number) {
        string str;
        ist >> unit_number.unit_value >> str >> unit_number.unit_type;
        return ist;
    }

    // << operator
    ostream& operator<<(ostream& ost, const NumberWithUnits& unit_number) {
        ost << unit_number.unit_value << '[' << unit_number.unit_type << ']';
        return ost;
    }

    /** overloading arithmetic operators */

    // + operators
    NumberWithUnits operator+(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return NumberWithUnits(unit_number_1.unit_value + temp, unit_number_1.unit_type);
    }

    NumberWithUnits operator+(const NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value + number, unit_number.unit_type);
    }

    // ++ operators
    NumberWithUnits operator++(NumberWithUnits& unit_number, int) {
        return NumberWithUnits(unit_number.unit_value + 1, unit_number.unit_type);
    }
    NumberWithUnits operator++(NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.unit_value + 1, unit_number.unit_type);
    }

    // += operator
    NumberWithUnits operator+=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        unit_number_1.unit_value = unit_number_1.unit_value + casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return unit_number_1;
    }

    // - operators
    NumberWithUnits operator-(const NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return NumberWithUnits(unit_number_1.unit_value-temp, unit_number_1.unit_type);
    }
    NumberWithUnits operator-(const NumberWithUnits& unit_number) {
        return NumberWithUnits(-unit_number.unit_value, unit_number.unit_type);
    }

    // -- operators
    NumberWithUnits operator--(NumberWithUnits& unit_number, int) {
        return NumberWithUnits(unit_number.unit_value - 1, unit_number.unit_type);
    }
    NumberWithUnits operator--(NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.unit_value - 1, unit_number.unit_type);
    }

    // -= operator
    NumberWithUnits operator-=(NumberWithUnits& unit_number_1, const NumberWithUnits& unit_number_2) {
        double temp = casting_units(unit_number_2.unit_type, unit_number_1.unit_type, unit_number_2.unit_value);
        return NumberWithUnits(unit_number_1.unit_value = unit_number_1.unit_value - temp, unit_number_1.unit_type);
    }

    // * operators
    NumberWithUnits operator*(NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value *number, unit_number.unit_type);
    }
    NumberWithUnits operator*(double number, NumberWithUnits& unit_number) {
        return NumberWithUnits(unit_number.unit_value * number, unit_number.unit_type);
    }

    // *= operators
    NumberWithUnits operator*=(NumberWithUnits& unit_number, double number) {
        return NumberWithUnits(unit_number.unit_value = unit_number.unit_value * number, unit_number.unit_type);
    }
    NumberWithUnits operator*=(double number, NumberWithUnits& unit_number) {
        return NumberWithUnits(number * unit_number.unit_value, unit_number.unit_type);
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
