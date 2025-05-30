#include "Citizen.h"
// Constructor
Citizen::Citizen(int id, string name, string email, string pass, string addr, string phone)
    : User(id, name, email, pass), address(addr), phone(phone) {}
// Destructor
Citizen::~Citizen() {}
// Methods for logging in and out of the system so we are using the credentials and the methods from the User class so its a good idea to use the User class
bool Citizen::login(string email, string password) {
    if (validateCredentials(email, password)) {
        isLoggedIn = true;
        return true;
    }
    return false;
}

void Citizen::logout() {
    isLoggedIn = false;
}

string Citizen::displayInfo() const {
    return "Citizen: " + name + " | Email: " + email + " | Address: " + address;
}

CrimeReport* Citizen::reportCrime(string t, string d, string l, bool pub) {
    CrimeReport* cr = new CrimeReport(myReports.size() + 1, t, d, l, pub);
    myReports.push_back(cr);
    return cr;
}

CrimeReport* Citizen::reportCrime(string t, string l) {
    return reportCrime(t, "No description", l, true);
}
