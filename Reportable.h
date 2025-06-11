#ifndef REPORTABLE_H
#define REPORTABLE_H

#include <string>
using std::string;

// Abstract Base Class: holds common attributes for all reports (superclass)
class Reportable {
protected:
    string description;    // Description or type of report
    string dateReported;   // When report was submitted
    string status;         // "Pending", "Follow up", "Stand by", "Solved"

public:
    // Constructor initializes common attributes
    Reportable(const string& desc, const string& date)
        : description(desc), dateReported(date), status("Pending") {}

    // Pure virtual for specialized follow-up behavior (polymorphism)
    virtual void followUp() = 0;

    // Virtual method for status; default returns status attribute
    virtual string getStatus() const { return status; }

    // Accessors for common attributes
    virtual string getType() const { return description; }
    virtual string getDateReported() const { return dateReported; }

    // Allows subclasses or system to modify status
    void setStatus(const string& newStatus) { status = newStatus; }

    virtual ~Reportable() {}  // Virtual destructor for proper cleanup
};

#endif // REPORTABLE_H
