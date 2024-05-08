/*
 * Interface.cpp
 *
 *  Created on: 8 May 2024
 *      Author: mensa
 */

#include <iostream>
#include "Interface.h"
#include "Contacts.h" // Include Contacts.h to use the Contact struct

using namespace std;

// Display user interface
void Interface() {
    // Display visual information
    std::cout << "   ****CONTACT MANAGEMENT SYSTEM***** \n ________________________________________" << std::endl;
    std::cout << "\n>>> choose an operation to continue: \nNew: (n) \nFind: (f) \nRemove: (r)" << std::endl;
    char choice;
    // Collect user choice or decision
    std::cout << ">...Enter Here: ";
    std::cin >> choice;
    std::cin.ignore();

    Contact contact;

    // Calling functions based on user's choice
    switch (choice) {
        case 'n':
            std::cout << "New domain selected" << std::endl;
            // Call the newContact function to create a new contact

            newContact(contact);
            break;
        case 'f':
            std::cout << "Retrieve domain selected" << std::endl;
            // Add functionality to retrieve a contact
            break;
        case 'r':
            std::cout << "Delete domain selected" << std::endl;
            // Add functionality to delete a contact
            break;
        default:
            std::cout << "\n>...You are required to enter either n, f, or r to proceed" << std::endl;
    }
}




