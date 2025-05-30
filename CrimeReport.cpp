#include "CrimeReport.h"
// Constructor
CrimeReport::CrimeReport(int id, string t, string d, string l, bool pub)
    : reportID(id), title(t), description(d), location(l), isPublic(pub) {}
// Getter methods
string CrimeReport::getDetails() const {
    return "Report #" + to_string(reportID) + ": " + title + " at " + location;
}

int CrimeReport::getID() const { return reportID; }
