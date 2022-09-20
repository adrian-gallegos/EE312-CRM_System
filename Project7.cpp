// CRM in C++ Project7.cpp
// EE 312 Project 7 submission by
// Adrian Gallegos
// ag76424
// Slip days used: 2
// Fall 2021
#include <stdio.h>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"
#include <iostream>

using namespace std;

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

int num_customers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // not done, your effort goes here
    UTString person;    // potential customer
    UTString stuff;     // customers desired item (bottles, rattles, diapers)
    readString(person);
    readString(stuff);
    UTString bottles = "Bottles";
    UTString rattles = "Rattles";
    UTString diapers = "Diapers";
    int S = 0;
    readNum(S);     // reads in the quantity of the desired item
    // check if person is in the customer database
    // flag = 1 -> person exists in the database   |   flag = 0 -> person not in the database
    if (database.isMember(person) == 0){
        if (stuff == bottles && num_bottles >= S)
            num_customers++;
        else if (stuff == rattles && num_rattles >= S)
            num_customers++;
        else if (stuff == diapers && num_diapers >= S)
            num_customers++;
    }
    // check if inventory has enough supply for person's purchase
    if (stuff == bottles){
        if (num_bottles >= S){
            num_bottles -= S;
            // create a new customer in customer database and add items
            // database[person];
            database[person].bottles += S;   // updates customers record
        } else {
            cout << "Sorry " << person.c_str() << ", we only have " << num_bottles;
            cout << " Bottles" << endl;
        }
    }
    if (stuff == rattles){
        if (num_rattles >= S){
            num_rattles -= S;
            // create a new customer in customer database and add items
            // database[person];
            database[person].rattles += S;   // updates customers record
        } else {
            cout << "Sorry " << person.c_str() << ", we only have " << num_rattles;
            cout << " Rattles" << endl;
        }
    }
    if (stuff == diapers){
        if (num_diapers >= S){
            num_diapers -= S;
            // create a new customer in customer database and add items
            // database[person];
            database[person].diapers += S;   // updates customers record
        } else {
            cout << "Sorry " << person.c_str() << ", we only have " << num_diapers;
            cout << " Diapers" << endl;
        }
    }
}

void processSummarize() {
    // not done, your effort goes here
    cout << "There are " << num_bottles << " Bottles, " << num_diapers << " Diapers and ";
    cout << num_rattles << " Rattles in inventory" << endl;
    cout << "we have had a total of " << num_customers << " different customers" << endl;
    if (findMax("Bottles") != NULL && findMax("Bottles")->bottles > 0) {
        cout << findMax("Bottles")->name.c_str() << " has purchased the most Bottles (" << findMax("Bottles")->bottles;
        cout << ")" << endl;
    } else {
        cout << "no one has purchased any Bottles" << endl;
    }
    if (findMax("Diapers") != NULL && findMax("Diapers")->diapers > 0) {
        cout << findMax("Diapers")->name.c_str() << " has purchased the most Diapers (" << findMax("Diapers")->diapers;
        cout << ")" << endl;
    } else {
        cout << "no one has purchased any Diapers" << endl;
    }
    if (findMax("Rattles") != NULL && findMax("Rattles")->rattles > 0) {
        cout << findMax("Rattles")->name.c_str() << " has purchased the most Rattles (" << findMax("Rattles")->rattles;
        cout << ")" << endl;
    } else {
        cout << "no one has purchased any Rattles" << endl;
    }
    num_customers = 0;
}

void processInventory() {
    // not done, your effort goes here
    // easiest
    int b = 0;
    int r = 0;
    int d = 0;
    UTString item = "Bottles";
    UTString bottles;
    // UTString rattles;
    // UTString diapers;
    readString(bottles);
    if (item == bottles){
        readNum(b);
    }
    item = "Rattles";
    // readString(rattles);
    if (item == bottles){
        readNum(r);
    }
    item = "Diapers";
    // readString(diapers);
    if (item == bottles){
        readNum(d);
    }
    num_bottles += b;
    num_rattles += r;
    num_diapers += d;
}
