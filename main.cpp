#include <iostream>
#include "Citizen.h"
#include "Police.h"
#include "Administrator.h"

int main() {
    Citizen* c1 = new Citizen(1, "Maria", "maria@mail.com", "133", "circuito andamaxei Street", "442-324-3467");
    Police* p1 = new Police(2, "Of.Juarez", "QroJuarez@police.com", "abc", "P100", "Homicide", "Sergeant");

    Administrator* a1 = new Administrator(4, "Jose", "admin@sys.com", "root", "Super");

    c1->login("maria@mail.com", "133");
    string infoC = c1->displayInfo();

    CrimeReport* r1 = c1->reportCrime("Theft", "Stolen bike", "Park", true);
    CrimeReport* r2 = c1->reportCrime("Robbery", "Mall");

    string assign1 = p1->assignReport(r1);
    string assign2 = p1->assignReport(vector<CrimeReport*>{r1, r2});

    a1->addUser(c1);
    a1->addUser(p1);
    string infoA = a1->displayInfo();

    cout << infoC << endl;
    cout << r1->getDetails() << endl;
    cout << r2->getDetails() << endl;
    cout << assign1 << endl;
    cout << assign2 << endl;
    cout << infoA << endl;

    delete c1;
    delete p1;
    delete a1;
    delete r1;
    delete r2;

    return 0;
}
