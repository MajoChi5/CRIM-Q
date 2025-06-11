#include "System.h"
#include "User.h"
#include "Crime.h"
#include "Police.h"

void System::addUser(User* user) { users.push_back(user); }
void System::addCrime(Crime* crime) { crimes.push_back(crime); }
void System::assignToPolice(Police* officer, Crime* crime) { officer->assignCrime(crime); }
const vector<User*>& System::getUsers() const { return users; }
const vector<Crime*>& System::getCrimes() const { return crimes; }
System::~System() {
    for (User* u : users) delete u;
    for (Crime* c : crimes) delete c;
}
