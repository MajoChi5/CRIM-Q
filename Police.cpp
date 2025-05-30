#include "Police.h"
// Constructor 
Police::Police(int id, string name, string email, string pass, string badge, string dept, string rank)
    : User(id, name, email, pass), badgeNumber(badge), department(dept), rank(rank) {}

Police::~Police() {}
//
bool Police::login(string email, string password) {
    if (validateCredentials(email, password)) {
        isLoggedIn = true;
        return true;
    }
    return false;
}

void Police::logout() {
    isLoggedIn = false;
}
// Display info this is a method that will display the info of the police officer and the reports that they have been assigned to
string Police::displayInfo() const {
    return "Police: " + name + " | Department: " + department + " | Rank: " + rank;
}

string Police::assignReport(CrimeReport* report) {
    assignedReports.push_back(report);
    return "Assigned report ID: " + to_string(report->getID()) + " to " + name;
}

string Police::assignReport(vector<CrimeReport*> reports) {
    string result;
    for (auto* report : reports)
        result += assignReport(report) + "\n";
    return result;
}
