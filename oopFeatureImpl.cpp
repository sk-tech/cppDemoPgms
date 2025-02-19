/*
Demo of 
    Encapsulation
    Abstraction
    Inheritance
    Polymorphism
*/
#include <iostream>
#include <cstring>
using namespace std;

#define NAME_LEN 32
#define DESIG_LEN 32
#define DEPT_LEN 32

//Encapsulation achieved using class
class employee {
  public:
    employee(const char* namearg,const char* desig, float sal) {
        strcpy(name, namearg);
        strcpy(designation, desig);
        salary = sal;
    }
    float getSalary() {
        return salary;
    }
    void setSalary(float sal) {
        salary = sal;
    }
    char* getEmpName() {
        return name;
    }
    void setEmpName(char* empname) {
        strcpy(name, empname);
    }
    char* getEmpDesignation() {
        return designation;
    }
    void setEmpDesignation(char* desig) {
        strcpy(designation, desig);
    }
    virtual void displayEmployeeInfo() {
        cout << "Name: " << name << endl;
        cout << "designation: " << designation << endl;
    }
  private:
    float salary = 0.0;
    char name[NAME_LEN] = {'\0'};
    char designation[DESIG_LEN] = {'\0'};
};

//Inheritance achieved by inheriting class employee into class department
class department:public employee {
    public:
        department(const char* dep,const char* name,const char* desig, float sal): employee(name, desig, sal) {
            strcpy(dept, dep);
        }
        void setDept(const char* dep) {
            strcpy(dept, dep);
        }
        char* getDept() {
            return dept;
        }
        //Polymorphism achieved by calling displayEmployeeInfo() using department and employee class
        void displayEmployeeInfo() override {
            employee::displayEmployeeInfo();
            cout << "Department:" << dept << endl;
        }
    private:
        char dept[DEPT_LEN] = {'\0'};
};
int main()
{
    cout << "Hello world" << endl;

    //Abstraction achieved by calling constructor to instantiate without
    //bothering to know about internal details of class
    
    cout << "using department class" << endl;

    department d1("Mech", "Sushant", "Supervisor", 20000.0f);
    
    d1.displayEmployeeInfo();

    cout << "using employee class" << endl;

    employee e1("Amar", "Leader", 25000.0f);

    e1.displayEmployeeInfo();
    
    return 0;
}
