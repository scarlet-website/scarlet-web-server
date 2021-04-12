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
#include "doctest.h"
#include "NumberWithUnits.hpp"

// namespaces
using namespace std;
using namespace ariel;

// units text file
ifstream units_file{"units.txt"};

/** km and m tests **/
TEST_CASE("{km, m}: Comparison operators { ==, != }") {
    NumberWithUnits::read_units(units_file);
    string small = "m";
    string big = "km";
    int mul = 1000;
    
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
