// CRM in C++ CustomerDB.cpp
// EE 312 Project 7 submission by
// Adrian Gallegos
// ag76424
// Slip days used: 2
// Fall 2021
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    for (int i = 0; i < this->length; i++){
        if (data[i].name == name){
            return this->data[i];
        }
    }
    if (this->capacity == this->length){
        capacity*=2;
        Customer* new_data = new Customer[this->capacity];     // "new" signifies creation of data on the heap
        for (int i = 0; i < this->length; i++) {       // creates a new array of customers for the database
            new_data[i] = this->data[i];
        }
        new_data[length].name = name;
        delete[]data;
        data = new_data;
        length++;

        data[length-1].bottles = 0;
        data[length-1].diapers = 0;
        data[length-1].rattles = 0;

        return data[length-1];
    }
    else {
        data[length].name = name;
        length++;

        data[length-1].bottles = 0;
        data[length-1].diapers = 0;
        data[length-1].rattles = 0;

        return data[length-1];
    }
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    for (int i = 0; i < this->length; i++){
        if (data[i].name == name){
            return true;
        }
    }
    return false;
}
