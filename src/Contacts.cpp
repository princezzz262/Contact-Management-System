/*
 * Contacts.cpp
 *
 *  Created on: 8 May 2024
 *      Author: mensa
 */

#include "Contacts.h"
#include <iostream>
#include <fstream>
#include <regex>

void newContact(Contact& contact) { // Pass Contact object as a parameter
    std::cout << "Enter name: ";
    std::getline(std::cin, contact.name); // Access name through the Contact object
    std::cout << "Enter phone number: ";
    std::getline(std::cin, contact.phoneNumber);
    std::string email;
    std::regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    bool isValid = false;
    int attempts = 0;

    while (!isValid && attempts < 3) {
        std::cout << "Enter email: ";
        std::getline(std::cin, email);

        // Comparing Regex pattern with email
        isValid = std::regex_match(email, emailPattern);
        if (!isValid) {
            std::cout << "Invalid email format. Please try again." << std::endl;
        }
        attempts++;
    }
    if (isValid) {
        std::cout << "Done." << std::endl;
        contact.cEmail = email; // Assign to the member variable cEmail
        // Save the contact
        std::cout << "Save? Yes (y) or No (n): ";
        char Save;
        std::cin >> Save;
        std::cin.ignore();
        switch (Save) {
            case 'y':
                saveContact(contact, "contacts.txt"); // Pass contact object to saveContact function
                std::cout << "Contact saved successfully." << std::endl;
                break;
            case 'n':
                std::cout << "Contact not saved." << std::endl;
                break;
            default:
                std::cout << "Invalid input. Contact not saved." << std::endl;
        }
    } else {
        std::cout << "Failed to enter a valid email after 3 attempts." << std::endl;
    }
}

void saveContact(const Contact& contact, const std::string& filename) {
    // Create an fstream object
    std::fstream file;

    // Try to open the file in read mode to check if it exists
    file.open(filename, std::ios::in);
    bool fileExists = file.is_open();
    file.close(); // Close the file if it was opened

    // Open the file in write mode (std::ios::app will create the file if it doesn't exist)
    file.open(filename, fileExists ? std::ios::app : std::ios::out);

    if (file.is_open()) {
        // Write the contact's details to the file
        file << contact.name << "," << contact.phoneNumber << "," << contact.cEmail << "\n";
        file.close(); // Close the file after writing
    } else {
        std::cerr << "Unable to open or create file for writing." << std::endl;
    }
}



