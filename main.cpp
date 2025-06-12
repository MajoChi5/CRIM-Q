#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "System.h"
#include "User.h"
#include "Police.h"
#include "Crime.h"

using namespace std;

int main() {
    System crimq;

    // Create a default citizen and police officers
    User* citizen = new User("User", "user@example.com");
    Police* officer1 = new Police("Officer Jose Perez", "jperez@police.qro");
    Police* officer2 = new Police("Officer Maria Lopez", "mlopez@police.qro");
    crimq.addUser(citizen);
    crimq.addUser(officer1);
    crimq.addUser(officer2);
    vector<Police*> officers = { officer1, officer2 };

    vector<Crime*> allCrimes;
    int choice;
    do {
        cout << "\n--- CRIM-Q Menu ---\n";
        cout << "1. Report a crime\n";
        cout << "2. Assign crime to officer\n";
        cout << "3. Follow up on a crime\n";
        cout << "4. Show all crime statuses\n";
        cout << "5. Exit\n";
        cout << ">> ";
        cin >> choice;

        if (choice == 1) {
            string desc, loc, date;
            cout << "Description: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, desc);
            cout << "Location: ";
            getline(cin, loc);
            cout << "Date (YYYY-MM-DD): ";
            getline(cin, date);
            Crime* crime = new Crime(desc, loc, date);
            citizen->reportCrime(crime);
            crimq.addCrime(crime);
            allCrimes.push_back(crime);
            cout << "Crime reported.\n";
        } else if (choice == 2) {
            if (allCrimes.empty()) {
                cout << "No crimes to assign.\n";
                continue;
            }
            cout << "Select crime (0-" << allCrimes.size()-1 << "): ";
            size_t idx;
            cin >> idx;
            cout << "Select officer (1: Jose, 2: Maria): ";
            int o;
            cin >> o;
            Police* selected = (o == 1 ? officer1 : officer2);
            crimq.assignToPolice(selected, allCrimes[idx]);
            cout << "Crime assigned to " << selected->getName() << ".\n";
        } else if (choice == 3) {
            cout << "Select officer for follow-up (1: Jose, 2: Maria): ";
            int o;
            cin >> o;
            Police* selected = (o == 1 ? officer1 : officer2);
            const auto& assigned = selected->getAssignedCrimes();
            if (assigned.empty()) {
                cout << "No crimes assigned to this officer.\n";
                continue;
            }
            cout << "Select assigned crime (0-" << assigned.size() << "): ";
            size_t idx;
            cin >> idx;
            selected->followUpCrime(assigned[idx]);
            cout << "Follow-up completed.\n";
        } else if (choice == 4) {
            cout << "\nAll crime statuses:\n";
            for (Police* off : officers) {
                for (Crime* crime : off->getAssignedCrimes()) {
                    cout << "Crime: " << crime->getType()
                         << ", Status: " << crime->getStatus()
                         << ", Officer: " << off->getName() << "\n";
                }
            }
        }
    } while (choice != 5);

    // Cleanup
    delete citizen;
    delete officer1;
    delete officer2;
    for (Crime* crime : allCrimes) {
        delete crime;
    }
    return 0;
}
