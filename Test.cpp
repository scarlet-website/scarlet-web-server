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
const int MAX_AMOUNT = DBL_MAX - 1;
const int MIN_AMOUNT = DBL_MIN + 1;

// casting values constants variables
const int M_TO_KM = 1000;
const int CM_TO_M = 100;
const int KG_TO_TON = 1000;
const int G_TO_KG = 1000;
const int MIN_TO_HOUR = 60;
const int SEC_TO_MIN = 60;
const double ILS_TO_USD = 3.33;

// epsilon constans
const double  EPS1 = 0.001;
const double  EPS2 = EPS1 * 10;
const double  EPS3 = EPS2 * 10;
const double  EPS4 = EPS3 * 10;
const double  EPS5 = EPS4 * 10;
const double  EPS6 = EPS5 * 10;
const double  EPS7 = EPS6 * 10;

// units text file
ifstream units_file{"units.txt"};

// returning a random double between bottom and top doubles
// taken from https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c/9324796
double rand_double(double bottom, double top) {
    double f = (double)rand() / RAND_MAX;
    if(bottom > 0) { return abs(floor((bottom + f * (top - bottom)) * 1000.) / 1000.); }
    else return floor((bottom + f * (top - bottom)) * 1000.) / 1000.;
}

// returning a random integer between bottom and top integers
// taken from https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int rand_int(int bottom, int top) {
    return bottom + (rand() % (top - bottom + 1));
}

/**
 * 
 * For each couple of units type: { {km, m}, {m, cm}, {ton, kg}, {hour, min}, {min, sec}, {USD, ILS} }
 * have a 7 TEST_CASES:
 * 
 * Comparison operators { ==, != }
 * Comparison operators { <=, < }
 * Comparison operators { >=, > }
 * Arithmetic operators { ++, -- }
 * Arithmetic operators { +, += }
 * Arithmetic operators { -, -= }
 * Arithmetic operators { *, *= }
 * 
 * */

/** km and m tests */
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
    string small = "m";
    string big = "km";
    int mul = M_TO_KM;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{km, m}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{km, m}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{km, m}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "m";
    string big = "km";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{km, m}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "m";
    string big = "km";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{km, m}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "m";
    string big = "km";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
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

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}
TEST_CASE("{m, cm}: Comparison operators { <=, < }") {
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
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{m, cm}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{m, cm}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
    
}
TEST_CASE("{m, cm}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "cm";
    string big = "m";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{m, cm}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "cm";
    string big = "m";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{m, cm}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "cm";
    string big = "m";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
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

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}
TEST_CASE("{ton, kg}: Comparison operators { <=, < }") {
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
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{ton, kg}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{ton, kg}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{ton, kg}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "kg";
    string big = "ton";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{ton, kg}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "kg";
    string big = "ton";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{ton, kg}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "kg";
    string big = "ton";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
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

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}
TEST_CASE("{kg, g}: Comparison operators { <=, < }") {
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
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{kg, g}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{kg, g}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{kg, g}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "g";
    string big = "kg";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{kg, g}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "g";
    string big = "kg";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{kg, g}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "g";
    string big = "kg";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
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

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}
TEST_CASE("{hour, min}: Comparison operators { <=, < }") {
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
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{hour, min}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{hour, min}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{hour, min}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "min";
    string big = "hour";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{hour, min}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "min";
    string big = "hour";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{hour, min}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "min";
    string big = "hour";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
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

    // check !=
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value, big});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} != NumberWithUnits{value - 1, small});
}
TEST_CASE("{min, sec}: Comparison operators { <=, < }") {
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
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{min, sec}: Comparison operators { >=, > }") {
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
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{min, sec}: Arithmetic operators { ++, -- }") {
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
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{min, sec}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "sec";
    string big = "min";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{min, sec}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "sec";
    string big = "min";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{min, sec}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "sec";
    string big = "min";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
}

/** USD and ILS tests **/
TEST_CASE("{USD, ILS}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";
    double mul = ILS_TO_USD;

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
TEST_CASE("{USD, ILS}: Comparison operators { <=, < }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";
    int mul = ILS_TO_USD;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    
    // checking if small unit is small than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value, big});

    // cheking same unit small than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS1, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS2, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS3, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS4, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS5, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS6, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value, small} < NumberWithUnits{value + EPS7, small});
}
TEST_CASE("{USD, ILS}: Comparison operators { >=, > }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";
    int mul = ILS_TO_USD;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    
    // checking if small unit is bigger than big unit but the same value
    double value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_A));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_B));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_C));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_D));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_E));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});
    value = abs(rand_double(0, INT_F));
    CHECK(NumberWithUnits{value, big} > NumberWithUnits{value, small});

    // cheking same unit bigger than same unit but plus epsilon
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS1, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_A);
    CHECK(NumberWithUnits{value + EPS2, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_B);
    CHECK(NumberWithUnits{value + EPS3, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_C);
    CHECK(NumberWithUnits{value + EPS4, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_D);
    CHECK(NumberWithUnits{value + EPS5, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_E);
    CHECK(NumberWithUnits{value + EPS6, small} > NumberWithUnits{value, small});
    value = rand_double(0, INT_F);
    CHECK(NumberWithUnits{value + EPS7, small} > NumberWithUnits{value, small});
}
TEST_CASE("{USD, ILS}: Arithmetic operators { ++, -- }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";
    int mul = ILS_TO_USD;

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_B = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_C = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_D = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_E = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const int INT_F = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    
    // ++
    double value = rand_double(0, INT_A);
    NumberWithUnits a{value, small};
    a++;
    CHECK(a <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits b{value, small};
    b++;
    CHECK(b <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits c{value, small};
    c++;
    CHECK(c <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits d{value, small};
    d++;
    CHECK(d <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits e{value, small};
    e++;
    CHECK(e <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits f{value, small};
    f++;
    CHECK(f <= NumberWithUnits{value+1, small});

    // --
    value = rand_double(0, INT_B);
    NumberWithUnits g{value, small};
    g++;
    CHECK(g <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_B);
    NumberWithUnits h{value, small};
    h++;
    CHECK(h <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_C);
    NumberWithUnits i{value, small};
    i++;
    CHECK(i <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_D);
    NumberWithUnits j{value, small};
    j++;
    CHECK(j <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_E);
    NumberWithUnits k{value, small};
    k++;
    CHECK(k <= NumberWithUnits{value+1, small});
    value = rand_double(0, INT_F);
    NumberWithUnits m{value, small};
    m++;
    CHECK(m <= NumberWithUnits{value+1, small});
}
TEST_CASE("{USD, ILS}: Arithmetic operators { +, += }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // +
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a+b;
    CHECK(c == NumberWithUnits{value1+value2, small});

    // +=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d+=e;
    CHECK(d == NumberWithUnits{value3+value4, big});
}
TEST_CASE("{USD, ILS}: Arithmetic operators { -, -= }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);

    // -
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, small};
    NumberWithUnits c = a-b;
    CHECK(c == NumberWithUnits{value1-value2, small});

    // -=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits d{value3, big};
    double value4 = rand_double(0, INT_A);
    NumberWithUnits e{value4, big};
    d-=e;
    CHECK(d == NumberWithUnits{value3-value4, big});
}
TEST_CASE("{USD, ILS}: Arithmetic operators { *, *= }") {
    NumberWithUnits::read_units(units_file);
    string small = "ILS";
    string big = "USD";

    const int INT_A = rand_int(MIN_AMOUNT, MAX_AMOUNT);
    const double mull = rand_double(0, INT_A);

    // *
    double value1 = rand_double(0, INT_A);
    NumberWithUnits a{value1, small};
    CHECK(a*mull == NumberWithUnits{value1*mull, small});
    double value2 = rand_double(0, INT_A);
    NumberWithUnits b{value2, big};
    CHECK(b*mull == NumberWithUnits{value2*mull, big});

    // *=
    double value3 = rand_double(0, INT_A);
    NumberWithUnits c{value3, small};
    c*=mull;
    CHECK(c == NumberWithUnits{value3*mull, small});
    double value4 = rand_double(0, INT_A);
    NumberWithUnits d{value4, big};
    d*=mull;
    CHECK(d == NumberWithUnits{value4*mull, big});
}
