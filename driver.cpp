#include "LinkedList.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {

    //creating integer linked list
    LinkedList<int> Num;
    
    cout << "Length of empty linked list: " << Num.getLength() << endl;
    
    //appending in empty list
    Num.append(19);
    cout << "Length appended to empty linked list: " << Num.getLength() << endl;

    //appending additional numbers
    Num.append(67);
    Num.append(911);

    //getting element and printing it
    int number1 = Num.getElement(1);
    cout << "Element 1: " << number1 << endl;

    //trying getElement as an invalid operation
    try {
       cout<< "Trying to get element of postion 3 but only 1 elment in linked list error message: ";
       Num.getElement(3);
    }
    catch (const string& e) {
        cout << e << endl;
    }


    try {
       cout<< "Trying to get element of postion -1 but only 1 element in linked list error message: ";
       Num.getElement(-1);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //printing an element before and after replacing it
    cout << "Element 2: " << Num.getElement(2) << endl;
    Num.replace(2, 100);
    cout << "Element 2 that was replaced: " << Num.getElement(2) << endl;

    //trying replace as an invalid operation- negative position)
    try {
        Num.replace(-1,100);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //trying replace as an invalid operation- position larger then length
    try {
        Num.replace(8, 90);
    }
    catch (const string& e) {
        cout << e << endl;
    }

    //appending another number, and checking the length
    cout << "Length before new append: " << Num.getLength() << endl;
    Num.append(130);
    cout << "Length after new append: " << Num.getLength() << endl;
    
  //printing string linked list using overload
    cout << "all numbers in linked list, printed using overloaded operator: " << Num  << endl;

    //clearing the linked list and checking
    Num.clear();
    cout << "After clearing: ";

    if (Num.isEmpty()) {
        cout << "The list is empty." << endl;
    }
    else {
        cout << "The list is not empty." << endl;
    }


    


    //creating a string type linked list
    LinkedList<string> review;
    review.append("I am working.");
    review.append("On Linked Lists!");
    review.append("The logic is fun.");
    review.append("The execution and refrencing the correct adresses/elements in the node are harder :/ ");

    //getting element 1
    cout << "Element 3 from the string linked list: " << endl<< review.getElement(3) << endl;
   

    //printing string linked list using overload
    cout << "\n String linked list, printed using overloaded operator: "<<endl << review << endl;
}