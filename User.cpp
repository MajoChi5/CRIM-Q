#include "User.h"
#include "Crime.h"

User::User(const string& name, const string& email)
    : name(name), email(email) {}

void User::reportCrime(Crime* crime) {
    reports.push_back(crime);
}

const vector<Crime*>& User::getReports() const {
    return reports;
}

string User::getName() const {
    return name;
}

User::~User() {
    for (Crime* c : reports) delete c;
}
