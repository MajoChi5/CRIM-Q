#include "Police.h"
#include "Crime.h"

Police::Police(const string& name, const string& email)
    : User(name, email) {}

void Police::assignCrime(Crime* crime) {
    assignedCrimes.push_back(crime);
}

void Police::followUpCrime(Crime* crime) {
    crime->followUp(); 
}

void Police::updateCrimeStatus(Crime* crime, const string& newStatus) {
    crime->setStatus(newStatus);
}

const vector<Crime*>& Police::getAssignedCrimes() const {
    return assignedCrimes;
}
