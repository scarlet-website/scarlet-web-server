#include <iostream>
#include <string>
#include <vector>
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

bool check_type(string unit_type) {
    return unit_type == "km" || unit_type == "m" || unit_type == "cm" || unit_type == "ton" ||
           unit_type == "kg" || unit_type == "g" || unit_type == "hour" || unit_type == " min" ||
           unit_type == "sec" || unit_type == "USD" || unit_type == "LIS";
}

int main() {

    int n, i = 0;;
    cout << "Please enter the number of unit to use: ";
    cin >> n;
    cout << endl;

    vector<NumberWithUnits> units;

    while(i < n) {

        double unit_value;
        string unit_type;

        cout << "Please enter the value (double) of the unit: ";
        cin >> unit_value;
        cout << endl;

        cout << "Please enter the type of the unit:" << endl;
        cout << "(Types can be: km, m, cm, ton, kg, g, hour, min, sec, USD and ILS)" << endl;
        cin >> unit_type;

        bool b = check_type(unit_type);

        while(!b) {
            cout << "Invalid type of unit! please try again:" << endl;
            cin >> unit_type;
            b = check_type(unit_type);
        }
        cout << endl;

        units.push_back(NumberWithUnits{unit_value, unit_type});

        i++;
    }

    int index = 0;
    cout << "the list of units:" << endl;
    for(vector<NumberWithUnits>::iterator iter = units.begin(); iter != units.end(); iter++) {
        cout << '(' << index << ") " << * iter << endl;
        index++;
    }

    cout << endl;

    while(true) {

        int number_of_units;
        cout << "Please enter '1' for making operations on single unit number or enter '2' for making operatoions on two units number:";
        cin >> number_of_units;

        bool valid_number_of_units = number_of_units == 1 || number_of_units == 2;
        unsigned long i, j;
        string operation = "";

        // single unit
        if(number_of_units == 1) {
            cout << "Enter the index of the unit:";
            cin >> i;
            cout << "Enter the operation for the single unit:" << endl;
            cout << "(the operations are: *, *=, --, ++)" << endl;
            cin >> operation;
        } else if(number_of_units == 2) {
            cout << "Enter the index of unit 1:";
            cin >> i;
            cout << "Enter the index of unit 2:";
            cin >> j;
            cout << "Enter the operation between units:" << endl;
            cout << "(the operations are: +, -, +=, -=, ==, !=, >, <, >=, <=)" << endl;
            cin >> operation;
            
        } else {
            cout << "Wrong input, please try again" << endl;
            continue;
        }

        if(operation == "+") {
            cout << (units[i] + units[j]) << endl;
        } else if(operation == "-") {
            cout << (units[i] - units[j]) << endl;
        } else if(operation == "*") {
            cout << (units[i] * units[j]) << endl;
        } else if(operation == "+=") {
            cout << (units[i] += units[j]) << endl;
        } else if(operation == "-=") {
            cout << (units[i] -= units[j]) << endl;
        } else if(operation == "*=") {
            cout << (units[i] *= units[j]) << endl;
        } else if(operation == "==") {
            cout << (units[i] == units[j]) << endl;
        } else if(operation == "!=") {
            cout << (units[i] != units[j]) << endl;
        } else if(operation == ">") {
            cout << (units[i] > units[j]) << endl;
        } else if(operation == "<") {
            cout << (units[i] < units[j]) << endl;
        } else if(operation == ">=") {
            cout << (units[i] >= units[j]) << endl;
        } else if(operation == "<=") {
            cout << (units[i] <= units[j]) << endl;
        } else if(operation == "++") {
            cout << (units[i]++);
        } else if(operation == "--") {
            cout << (units[i]--);
        } else {
            cout << "Invalid operation inpute, please try again" << endl;
            continue;
        }

    }
    

    return 0;
}
