#include <iostream>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    string company;
    int age;

    // Mark this method as 'const' because it doesn't modify any member variables
    void introduceYourSelf() const {
        cout << "\n Name - " << name << endl;
        cout << " Company - " << company << endl;
        cout << " Age - " << age << endl;
    }

    // Corrected Constructor
    Employee(string name, string company, int age) {
        cout << "\n An employee was created!";
        cout << "\n Name - " << name << endl;
        this->name = name;
        this->company = company;
        this->age = age;
    }

    Employee() {
        cout << "\n An employee was created without any initial data";
        cout << "\n Name - " << name << endl;
    }

    Employee(string name) {
        cout << "\n An employee was created with a name only.!";
        this->name = name;
        cout << "\n Name - " << name << endl;

    }
};

int main() {
    cout << "OOP Practice" << endl;

    Employee employee1;
    Employee employee2;

    employee1.age = 25;
    employee1.company = "YouTuber";
    employee1.name = "John";

    employee2.age = 33;
    employee2.company = "Amazon";
    employee2.name = "Saldina";

    employee1.introduceYourSelf();
    cout << "\n\n";
    employee2.introduceYourSelf();

    // Create an employee with a constructor
    Employee employee3("Dennis");

    // Avoid using raw pointers; use stack allocation
    Employee anEmployee("Name Needed");
    anEmployee.introduceYourSelf();

    // Create an employee with this fields
    Employee aThreeFieldEmployee("Three","Field", 99);
    aThreeFieldEmployee.introduceYourSelf();

    // Create an Employee using a pointer.
    Employee* pEmployee = new Employee("New Employee");
    pEmployee->introduceYourSelf();
    cout << "\n The new employee's name is: " << pEmployee->name << endl;
    cout << "\n The new employee's company is: " << pEmployee->company << endl;
    cout << "\n The new employee's age is: " << pEmployee->age << endl;

    // Create a vector (list of objects) to store Employee objects
    vector<Employee> employeesLoop;

    // Create a pointer for my employees
    Employee* pEmpList;
    for (int i=0; i < 10; i++) {
        cout << "\n in the for loop and i is " << i << endl;
        pEmpList = new Employee("New Employee in my list ");
        pEmpList->introduceYourSelf();
        // Add this objcet to our vector list.
        employeesLoop.push_back(*pEmpList);
    }

    // Use a for : each loop to output the list
    for (const auto& item : employeesLoop) {
        item.introduceYourSelf(); // No more error because the method is const
    }



    // Create a vector to store Employee objects
    vector<Employee> employees;

    // Add employees to the vector using constructor
    employees.push_back(Employee("John", "YouTuber", 25));
    employees.push_back(Employee("Saldina", "Amazon", 33));
    employees.push_back(Employee("Dennis", "Fresno City College", 40));
    employees.push_back(Employee("Another", "A company", 22));

    // Loop through and introduce each employee
    // This is how you loop through a vector list
    for (const auto& employee : employees) {
        employee.introduceYourSelf(); // No more error because the method is const
    }

    return 0;
}
