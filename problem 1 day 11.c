#include <stdio.h>
using namespace std;

struct Employee {
    string designation;
    Employee* left;
    Employee* right;

    Employee(string name) {
        designation = name;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    Employee* CEO = new Employee("CEO");
    Employee* Manager1 = new Employee("Manager1");
    Employee* Manager2 = new Employee("Manager2");
    Employee* TeamLead1 = new Employee("TeamLead1");
    Employee* TeamLead2 = new Employee("TeamLead2");

    CEO->left = Manager1;
    CEO->right = Manager2;

    Manager1->left = TeamLead1;
    Manager1->right = TeamLead2;

    cout << "CEO: " << CEO->designation << endl;
    cout << "Left Manager: " << CEO->left->designation << endl;
    cout << "Right team lead under manager1: "
         << CEO->left->right->designation << endl;

    return 0;
}
