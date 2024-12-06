#include <iostream>

using namespace std;




class Stack {

    private:

        int top;

        int maxSize;

        int* stackArray;



    public:

        Stack(int size) {

            maxSize = size;

            stackArray = new int[maxSize];

            top = -1;

        }



        ~Stack() {

            delete[] stackArray;

        }



        bool isEmpty() {

            return top = -1;



        }

        bool isFull() {

            return top == maxSize - 1;



        }

        void push(int value) {

            if (top == maxSize - 1) {

                cout << "Stack is full" << endl;

            } else {

                top++;

                cout << "Pushed" << value << " on to the stack" << endl;

                stackArray[top] = value;

            }



        }

        void pop() {

            if (top == -1) {

                cout << "Stack is empty" << endl;

            } else {

                top--;

                cout << "Popped " << stackArray[top + 1] << " from the stack." << endl;

            }



        }

        int peek() {

            if (top == -1) {

                cout << "Stack is empty" << endl;

                return -1;

            } else {

                return stackArray[top];

            }



        }

};





int main() {

    Stack stack(5);



    if (stack.isEmpty()) {

        cout << "Is Empty? " << 1 << endl;

    } else {

        cout << "Is Empty? " << 0 << endl;

    }



    stack.push(10);

    stack.push(20);

    stack.push(30);

    stack.push(40);

    stack.push(50);



    cout << "Is Empty? 1" << stack.isEmpty() << endl;



}