#include<bits/stdc++.h>
using namespace std ; 

// FUNCTION OVERRIDING --- RUN TIME POLYMORPHIHSM 
// OR DYNAMIC POLYMORPHISM --- LATE BINDINNG 

// 1 --- OUTPUT --- DERIVED FUNCTION , BASE FUNCTION

class B{
public:
    void print(){
        cout << "Base Function" << endl ;
    }
};

class D:public B{
public:
    void print(){
        cout << "Derived Function" << endl ; 
    }
};

int main(){
    D d1,d2 ; 
    d1.print() ; 
    d2.B::print() ; 
    return 0 ; 
}

// 2 --- OUTPUT --- BASE FUNCTION 

class B{
public:
    void print(){
        cout << "Base Function" << endl ;
    }
};

class D:public B{
public:
    void print(){
        cout << "Derived Function" << endl ; 
    }
};

int main(){
    D d1 ; 
    B* ptr = &d1 ;
    ptr -> print() ;  
    return 0 ; 
}

// 3 --- VIRTUAL FUNCTION --- USED TO ENSURE THAT THE FUNCTION IS REDEFINED 
// OUTPUT --- DERIVED FUNCTION

class B{
public:
    virtual void print(){
        cout << "Base Function" << endl ;
    }
};

class D:public B{
public:
    void print(){
        cout << "Derived Function" << endl ; 
    }
};

int main(){
    D d1 ; 
    B* ptr = &d1 ;
    ptr -> print() ;  
    return 0 ; 
}

// 4 --- 
