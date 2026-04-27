#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    string role;
    Employee(int eid, string ename, string erole)
    {
        id = eid;
        name = ename;
        role = erole;
    }
};

class EmployeeModel
{
private:
    vector<Employee> employees;

public:
    void addEmployee(Employee emp)
    {
        employees.push_back(emp);
    }
    void editEmployee(int eid, string ename, string erole)
    {
        for (int i = 0; i < employees.size(); i++)
        {
           if( employees[i].id == eid)
            {
                employees[i].name = ename;
                employees[i].role = erole;
                break;
            }
        }
    }
 vector<Employee> getEmployees()
    {
        return employees;
    }
};
class EmployeeView
{
public:
    void displayEmployees(vector<Employee> employees)
    {
        for (int i = 0; i < employees.size(); i++)
        {
            cout << "ID: " << employees[i].id << " Name: " << employees[i].name << " Role: " << employees[i].role << endl;
        }
    }
};
class EmployeeController
{
private:
    EmployeeModel model;
    EmployeeView view;

public:
    void addEmployee(int id, string name, string role)
    {
        Employee emp(id, name, role);
        model.addEmployee(emp);
    }
    void editEmployee(int id, string name, string role)
    {
        model.editEmployee(id, name, role);
    }
    void displayEmployees()
    {
        vector<Employee> employees = model.getEmployees();
        view.displayEmployees(employees);
    }
};
int main()
{
    EmployeeController controller;
    controller.addEmployee(1, "Menna", "Manager");
    controller.addEmployee(2, "salma", "Developer");
    controller.addEmployee(3, "Ahmed", "Designer");

    cout << "Employees:\n";
    controller.displayEmployees();

    cout << "\nEditing salma's role to 'Senior Developer'\n";
    controller.editEmployee(2, "salma", "Senior Developer");

    cout << "\nUpdated Employees:\n";
    controller.displayEmployees();

    return 0;
}