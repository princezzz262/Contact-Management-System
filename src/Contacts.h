/*
 * Contacts.h
 *
 *  Created on: 8 May 2024
 *      Author: mensa
 */

#ifndef CONTACTS_H_
#define CONTACTS_H_

#include <string>

// Define the Contact struct
struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string cEmail;
};

// Function declarations
void newContact(Contact& contact);
void saveContact(const Contact& contact, const std::string& filename);

#endif /* CONTACTS_H_ */
