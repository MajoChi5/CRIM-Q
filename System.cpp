#include "System.h"
#include "User.h"
#include "Crime.h"
#include "Police.h"

void System::addUser(User* user) { users.push_back(user); } // Add user to the system

void System::addCrime(Crime* crime) { crimes.push_back(crime); }// Add crime to the system

void System::assignToPolice(Police* officer, Crime* crime) { officer->assignCrime(crime); } // Assign crime to police officer

const vector<User*>& System::getUsers() const { return users; } // Get all users

const vector<Crime*>& System::getCrimes() const { return crimes; }// Get all crimes

System::~System() {// Destructor to clean memory
    for (User* u : users) delete u;
    for (Crime* c : crimes) delete c;
}
