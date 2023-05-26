#include<bits/stdc++.h>
using namespace std ; 

// 1 --- SINGLE INHERITANCE 

class Base{
public:
    float salary = 50000 ; 
};

class Derived : public Base{
public:
    float bonus = 2000 ; 
};

int main(){
    Derived d1 ;
    cout << "Salary: " << d1.salary << endl ;
    cout << "Bonus: " << d1.bonus << endl ;
}
