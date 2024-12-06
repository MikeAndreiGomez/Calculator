#include <iostream>
#include <string>
#include <queue> //includes the queue library to use the queue data structure
#include <thread> //Includes the 
#include <chrono> 
#include <vector>

using namespace std;

class Person {
public:
    string name;
    string ticketNumber;

    Person(const string& name, const string& ticketNumber) : name(name), ticketNumber(ticketNumber) {}
};

class TicketQueue {
private:
    queue<Person> ticketQueue;
    int ticketCount;

public:
    TicketQueue() : ticketCount(0) {}

    void enqueue(const string& name) {
        ticketCount++;
        string ticketNumber = "Ticket #" + to_string(ticketCount);
        ticketQueue.push(Person(name, ticketNumber));
        cout << name << " added to the queue with " << ticketNumber << endl;
        cout << "Queue size: " << ticketQueue.size() << endl;
    }

    void dequeue() {
        if (!ticketQueue.empty()) {
            Person p = ticketQueue.front();
            cout << "Dequeue: " << p.name << " received a ticket (" << p.ticketNumber << ")" << endl;
            ticketQueue.pop();
            cout << "Queue size: " << ticketQueue.size() << endl;

            if (!ticketQueue.empty()) {
                Person next = ticketQueue.front();
                cout << "Next in line: " << next.name << " (" << next.ticketNumber << ")" << endl;
            }
        } else {
            cout << "No one is in the queue." << endl;
        }
    }

    int getPosition(const string& name) {
        queue<Person> tempQueue = ticketQueue;
        int position = 0;
        while (!tempQueue.empty()) {
            position++;
            if (tempQueue.front().name == name) {
                return position;
            }
            tempQueue.pop();
        }
        return -1; // Not found
    }

    void run() {
        while (true) {
            if (!ticketQueue.empty()) {
                dequeue();
            }
            this_thread::sleep_for(chrono::minutes(1));
        }
    }
};

int main() {
    TicketQueue ticketQueue;
    string name;

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System" << endl;

    thread ticketThread(&TicketQueue::run, &ticketQueue);

    while (true) {
        cout << "\n\t1. Enqueue a person\n\t2. Check your position in the queue\n\t3. Exit\n\nChoose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the name: ";
            cin >> name;
            ticketQueue.enqueue(name);
        } else if (choice == 2) {
            cout << "Enter your name: ";
            cin >> name;
            int position = ticketQueue.getPosition(name);
            if (position != -1) {
                cout << name << " is currently at position " << position << " in the queue." << endl;
            } else {
                cout << name << " is not in the queue." << endl;
            }
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    ticketThread.detach(); // Detach the thread when exiting
    return 0;
}