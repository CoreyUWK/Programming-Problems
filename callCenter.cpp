/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

enum EmployeeType {
    Respondent = 1,
    Manager = 2,
    Director = 3,
    NumberOfEmployeeTypes
}

class Employee {
    Rank rank; // Equal to EmployeeType
    Call currentCall;
    
    Employee() : currentCall(NULL) {}
    
    void receiveCall(Call call) {}
    void callCompleted() {}
    void escalateAndReassign() {}
    bool assignNewCall() {}
}

class Respondent : Employee {
    Respondent() : rank(Respondent);
}
class Manager : Employee {
    Manager() : rank(Manager);
}
class Director : Employee {
    Director() : rank(Director);
}

class Caller {
    
}

class Call {
    Rank rank;
    Employee handler;
    Caller caller;
    
    Call(Caller c) : rank(Respondent), caller(c) {}
    
    void setHandler(Employee emp) {employee = emp;}
    void reply(String msg) {}
    void disconnect() {}
}

class CallHandler {
    static CallHandler instance;
    
    const int Levels = NumberOfEmployeeTypes;
    const int NumberOfRespondents = 3;
    const int NumberOfManagers = 2;
    const int NumberOfDirectors = 1;
    
    std::vector<std::vector<Employee>> levels;
    std::vector<std::queue<Call>> callQueues;
    
    static CallHandler getInstance() {
        if (instance == NULL) 
            instance = new CallHandler;
        return instance;
    }
    
    Employee getHandlerForCall(Call call) {}

    void DispatchCaller(Caller caller) {
        Call = new Call(caller);
        DispatchCall(call);
    }
    
    void DispatchCall(Call call) {
        Employee emp = getHandlerForCall(call);
        if (NULL != emp) {
            emp.receiveCall(call);
            call.setHandler(emp);
        }
        else {
            call.reply("Wait to be serviced");
            callQueues[call.rank].push_back(call);
        }
    }
    
    bool assignCall(Employee emp) {} // Assign free Employee
    
}


// Call -> Employee {Lowest to Highest free Employee}
// DispatchCall() -> assigns call to first free Employee



int main()
{
    cout<<"Hello World";

    return 0;
}
