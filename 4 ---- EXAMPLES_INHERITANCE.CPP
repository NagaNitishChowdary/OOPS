#include<bits/stdc++.h>
using namespace std ; 

// 1 --- SINGLE INHERITANCE 
// OUTPUT --- SALARY = 50000 , BONUS = 2000
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

// 2 --- 
// OUTPUT --- 80
class Base{
public:
    int mul(int a,int b){  // function mul is public in Base class
        // we can access this mul function in any other class or outside the class 
        return a*b ; 
    }
};

class Derived : public Base{
public:
    int f(int a,int b){ 
        return mul(a,b) ;  // function mul becomes private in Derived class
        // we cannot access mul function outside the Derived class   
    }
};

int main(){
    Derived d1 ;
    cout << d1.f(10,8) << endl ;
    // d1.mul(10,8) is an error because mul function became private in derived class
}
