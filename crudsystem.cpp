#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

const int maxrow = 15;

string Event[maxrow] = {};
string TimeSched[maxrow] = {};

void AddPlan(){

    string event;
    string sched;

    

    cout << "Time Schedule: ";
    getline(cin, sched);
    cout << "Event Name: ";
    getline(cin, event);

    for (int i = 0; i < maxrow; i++){

        if(TimeSched[i].empty()){
            TimeSched[i] = sched;
            Event[i] = event;
            
            break;

        }

    }

}

void ListPlan(){

    system("CLS");
    cout << "Current Plan" << endl;
    cout << "======================================" << endl;

    int counter = 0;
    cout << " No.  |  Time Schedule  | Event Name " << endl << "--------------------------------------\n";
    for (int i = 0; i < maxrow; i++){

        if (!TimeSched[i].empty()){

            counter++;
            cout << " " << counter << "    |       " << TimeSched[i] << "     | " << Event[i] << endl;

        }

    }

    if (counter == 0){

        cout << "No Plan Found!" << endl;

    }

    cout << "======================================" << endl;

}

int main() {

    std::cout << "MENU\n";
    int option;
    system("CLS");

    do {

        cout << "1 - Create Event Plan" << endl;
        cout << "2 - Update Event Plan" << endl;
        cout << "3 - Delete Event Plan" << endl;
        cout << "4 - Search Event Plan" << endl;
        cout << "5 - Display Event Plan" << endl;
        cout << "6 - Exit and Save to Text file" << endl;
        cout << "======================================" << endl;

        cout << "Select Option >>";
        cin >> option;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (option) {

            case 1: AddPlan();
                system("CLS");
                break;
            
            case 5: ListPlan();
                break;

        }

    } while (option != 6);

}