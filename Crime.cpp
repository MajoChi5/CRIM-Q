#include "Crime.h"

// Constructor
Crime::Crime(const string& desc, const string& loc, const string& date)
    : Reportable(desc, date), location(loc) {}

// Overriding to set status and record follow-up date
void Crime::followUp() {
    status = "Follow up";
    dateFollowUp = "2025-06-08"; 
}

// Override
string Crime::getStatus() const {
    return status;
}

// Overload 
string Crime::getStatus(bool showDate) const {
    return (status == "Follow up" && showDate) ? dateFollowUp : getStatus();
}

// Operator overloading compare descriptions
bool Crime::operator==(const Crime& other) const {
    return description == other.description;
}

Crime::~Crime() {}
