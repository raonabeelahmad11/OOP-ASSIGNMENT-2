#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    static int count;
    static const string company;

    // Constructor
    Employee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
        count++;
    }

    // Copy Constructor
    Employee(const Employee& e) {
        name = e.name;
        id = e.id;
        salary = e.salary;
        count++;
    }

    // Destructor
    ~Employee() {
        count--;
    }

    // Show Function
    void show() const {
        cout << "\nCompany : " << company;
        cout << "\nName    : " << name;
        cout << "\nID      : " << id;
        cout << "\nSalary  : " << salary << endl;
    }

    // Setter Function
    void setName(string n) {
        name = n;
    }

    // Getter Function
    string getName() const {
        return name;
    }

    // Static Function
    static void showCount() {
        cout << "\nTotal Employees : " << count << endl;
    }
};

// Static Members Initialization
int Employee::count = 0;
const string Employee::company = "Tech Solutions";

// Pass by Value Function
void passByValue(Employee e) {
    cout << "\n-- Pass by Value --";
    e.show();
}

// Pass by Reference Function
void passByRef(Employee& e) {
    cout << "\n-- Pass by Reference --";
    e.show();
    e.setName("Jazim");
}

// Function that returns an Employee
Employee makeEmp() {
    Employee temp("Usman", 999, 800);
    return temp;
}

int main() {
    // Object through pointer
    Employee* e1 = new Employee("Nabeel", 140, 300);
    e1->show();
    Employee::showCount();

    passByValue(*e1);
    passByRef(*e1);

    cout << "\nAfter Reference Update:";
    e1->show();

    // Object returned by function
    Employee e2 = makeEmp();
    cout << "\nReturned Object:";
    e2.show();

    // Deep Copy Example
    Employee e3 = *e1;
    cout << "\nDeep Copy Object:";
    e3.show();

    // Changing original to test deep copy
    e1->setName("Ali ");
    cout << "\nAfter Changing Original:";
    e1->show();

    cout << "\nDeep Copy Remains Same:";
    e3.show();

    delete e1;
    Employee::showCount();

    cout << endl;
    return 0;
}
