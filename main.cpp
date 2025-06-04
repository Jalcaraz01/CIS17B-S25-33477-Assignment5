//Templates Assignment, Justin Alcaraz
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>
using namespace std;

// Template class, representing a package that contains a single item of type T
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << " \n";
    }
};

// Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers, used specifically for double* in main
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

//Class template for a Box array, holding a certain number of strings
template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

//Function template and specialization, to print string, int, and different message for double
template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "°C\n";
}
//Main function
int main(){
    //Use of the Package class constructor to create Package<int> and Package<std::string>
    //Package<double*> created to use partial specialization for pointers
    Package<int> item1(1);
    Package<std::string> item2("C++ Primer");
    double d{2.1};
    Package item3 {&d};
    
    //.label() class function called to display the different outputs for each item's data type
    item1.label();
    item2.label();
    item3.label();
    
    //Box created with 3 spaces, 2 books are added using .addItem(), books in box displayed using .printItems()
    Box<std::string, 3> BookBox;
    BookBox.addItem("The Pragmatic Programmer");
    BookBox.addItem("Clean Code");
    BookBox.printItems();
    
    //calling shipItem with an int, std::string, and double displays the different outputs from the function template
    shipItem(2);
    shipItem("Desk");
    shipItem(88.5);
}
