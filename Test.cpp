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
#include <bits/stdc++.h>
#include "doctest.h"
#include "NumberWithUnits.hpp"

// namespaces
using namespace std;
using namespace ariel;

// range of amounts
const int MAX_AMOUNT = INT_MAX - 1;
const int MIN_AMOUNT = INT_MIN + 1;

// casting values constants variables
const int M_TO_KM = 1000;
const int CM_TO_M = 100;
const int KG_TO_TON = 1000;
const int G_TO_KG = 1000;
const int MIN_TO_HOUR = 60;
const int SEC_TO_MIN = 60;
const double LIS_TO_USD = 3.33;

// units text file
ifstream units_file{"units.txt"};

// returning a random double between bottom and top doubles
// taken from https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c/9324796
double rand_double(double bottom, double top) {
    double f = (double)rand() / RAND_MAX;
    return bottom + f * (top - bottom);
}

// returning a random integer between bottom and top integers
// taken from https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int rand_int(int bottom, int top) {
    return bottom + (rand() % (top - bottom + 1));
}

// return x <= amount
// int get_slice(int value) {
//     return value - rand_double(0, value);
// }

/** km and m tests **/
TEST_CASE("{km, m}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "m";
    string big = "km";
    int mul = M_TO_KM;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    
    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}

TEST_CASE("{km, m}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{km, m}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{km, m}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{km, m}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{km, m}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{km, m}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** m and cm tests **/
TEST_CASE("{m, cm}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "cm";
    string big = "m";
    int mul = CM_TO_M;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{m, cm}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{m, cm}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{m, cm}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{m, cm}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{m, cm}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{m, cm}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** ton and kg tests **/
TEST_CASE("{ton, kg}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "kg";
    string big = "ton";
    int mul = KG_TO_TON;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{ton, kg}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{ton, kg}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{ton, kg}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{ton, kg}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{ton, kg}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{ton, kg}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** kg and g tests **/
TEST_CASE("{kg, g}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "g";
    string big = "kg";
    int mul = G_TO_KG;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{kg, g}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{kg, g}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{kg, g}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{kg, g}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{kg, g}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{kg, g}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** hour and min tests **/
TEST_CASE("{hour, min}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "min";
    string big = "hour";
    int mul = MIN_TO_HOUR;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{hour, min}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{hour, min}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{hour, min}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{hour, min}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{hour, min}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{hour, min}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** min and sec tests **/
TEST_CASE("{min, sec}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "sec";
    string big = "min";
    int mul = SEC_TO_MIN;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{min, sec}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{min, sec}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{min, sec}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{min, sec}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{min, sec}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{min, sec}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}

/** USD and ILS tests **/
TEST_CASE("{USD, ILS}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";
    double mul = LIS_TO_USD;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    double value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value*mul, small} == NumberWithUnits{value, big});
}
TEST_CASE("{USD, ILS}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{USD, ILS}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{USD, ILS}: arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{USD, ILS}: arithmetic operators { +, += ") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{USD, ILS}: arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
}
TEST_CASE("{USD, ILS}: arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
}
