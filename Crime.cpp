#include "Crime.h"

// Initialize Reportable(desc, date) and Crime-specific location
Crime::Crime(const string& desc, const string& loc, const string& date)
    : Reportable(desc, date), location(loc) {}

// Overriding: set status and record follow-up date
void Crime::followUp() {
    status = "Follow up";
    dateFollowUp = "2025-06-08"; // Example static follow-up date
}

// Override: return current status
string Crime::getStatus() const {
    return status;
}

// Overload: optionally return follow-up date
string Crime::getStatus(bool showDate) const {
    return (status == "Follow up" && showDate) ? dateFollowUp : getStatus();
}

// Operator overloading: compare by description
bool Crime::operator==(const Crime& other) const {
    return description == other.description;
}

Crime::~Crime() {}
