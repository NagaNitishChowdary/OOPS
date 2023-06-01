#include<bits/stdc++.h>
using namespace std ; 

// 1 --- METHOD OVERRIDING 
// OUTPUT --- B 

class A{
public:
    void function(){ cout << "A" ; }
};

class B:public A{
public:
    void function(){ cout << "B" ; }
};

int main(){
    B b ; 
    b.function() ; 
    return 0 ; 
}

// 2 --- FUNCTION OVERRIDING 
// OUTPUT --- B

class A{
public:
    void function(){ cout << "A" ; }
};

class C{
public:
    void function(){ cout << "C" ; }
};

class B:public A,C{
public:
    void function(){ cout << "B" ; }
};

int main(){
    B b ; 
    b.function() ; 
    return 0 ; 
}

// 3 --- METHOD OVERRIDING 
// OUTPUT --- ERROR AMBIGUOUS

class A{
public:
    void function(){ cout << "A" ; }
};

class C{
public:
    void function(){ cout << "C" ; }
};

class B:public A,C{
public:
    void fun2(){
        function() ; 
        cout << "B" ; 
    }
};

int main(){
    B b ; 
    b.fun2() ; 
    return 0 ; 
}

// 4 --- METHOD OVERRIDING 
// OUTPUT --- INFINITE RECURSION --- NOTHING IS PRINTED

class A{
public:
    void function(){ cout << "A" ; }
};

class C{
public:
    void function(){ cout << "C" ; }
};

class B:public A,C{
public:
    void function(){
        function() ; 
        cout << "B" ; 
    }
};

int main(){
    B b ; 
    b.function() ; 
    return 0 ; 
}

// 5 --- METHOD OVERRIDING 
// OUTPUT --- BASE CLASS

class B{
    int a ; 
public:
    void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B b = B() ;
    b.fun() ; 
    return 0 ; 
}


// 6 --- METHOD OVERRIDING 
// OUTPUT --- BASE CLASS

class B{
    int a ; 
public:
    void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B b = D() ; // ANY OBJECT OF BASE CLASS CAN HOLD OBJECT OF DERVIED CLASS 
    b.fun() ; 
    return 0 ; 
}

// 7 --- METHOD OVERRIDING 
// OUTPUT --- BASE CLASS

class B{
    int a ; 
public:
    virtual void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B obj1 ; 
    D obj2 ; 
    B *b = &obj1 ; 
    b -> fun() ;  
    return 0 ; 
}

// 8 --- METHOD OVERRIDING 
// OUTPUT --- DERIVED CLASS

class B{
    int a ; 
public:
    virtual void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B obj1 ; 
    D obj2 ; 
    B *b = &obj2 ; 
    b -> fun() ;  
    return 0 ; 
}

// 9 --- METHOD OVERRIDING 
// OUTPUT --- DERIVED CLASS

class B{
    int a ; 
public:
    virtual void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B obj1 ; 
    D obj2 ; 
    D *b = &obj2 ; 
    b -> fun() ;  
    return 0 ; 
}

// 10 --- METHOD OVERRIDING 
// OUTPUT --- ERROR --- INVALID CONVERSION TO B* TO D*

class B{
    int a ; 
public:
    virtual void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B obj1 ; 
    D obj2 ; 
    D *b = &obj1 ;  // BASE CLASS OBJECT CAN HOLD THE DERIVED CLASS OBJECT BUT NOT VICEVERSA
    b -> fun() ;  
    return 0 ; 
}

// 11 --- VIRTUAL FUNCTION CANNOT BE STATIC BECAUSE VIRTUAL FUNCTION IS INHERITED IN ANY OTHER CLASS THEN 2 STATIC DEFINITIONS CANNOT BE ALLOWED  
// OUTPUT --- ERROR --- member 'fun' cannot be declared both virtual and static

class B{
    int a ; 
public:
    static virtual void fun(){ 
        cout << "Base class" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    void fun(){
        cout << "Derived class" << endl ;
    }
};

int main(){
    B obj1 ; 
    D obj2 ; 
    B *b = &obj1 ;  
    b -> fun() ;  
    return 0 ; 
}

// 12 --- OUTPUT --- ERROR 
// 1ST ERROR --- WE CANNOT CREATE OBJECT FOR ABSTRACT CLASS
// 2ND ERROR --- THE CLASS INHERITING THE ABSTRACT CLASS SHOULD HAVE ALL DEFINITIONS OF THE ABSTARCT CLASS

class B{ // ANY CLASS WHICH HAS ATLEAST ONE PURE VIRTUAL FUNCTION IS ABSTRACT CLASS
    int a ; // ANY CLASS INHERITING THE ABSTRACT CLASS MUST HAVE ALL DEFINITIONS OF THE PURE VIRTUAL FUNCTIONS
public:
    virtual void fun() = 0 ; // PURE VIRTUAL FUNCTION 
    void fun2(){ 
        cout << "Hello World" << endl ; 
    }
};

class D:public B{
    int a; 
public:
    D(){ cout << "B" << endl ; }
};

int main(){
    B obj1 ; 
    obj1.fun() ; 
    return 0 ; 
}

// 13 --- OUTPUT --- DERIVED , BASE 
// IN CLASS B ONLY FUN1 IS OVERRIDDEN AND FUN2 IS NOT OVERRIDDEN 
// ONLY VIRTUAL FUNCTIONS ARE OVERRIDDEN 

class B{ 
public:
    virtual void fun1(){ cout << "Base " ; } 
    void fun2(){ cout << "Base " ; }
};

class D:public B{
public:
    void fun1(){ cout << "Derived " ; }
    void fun2(){ cout << "Derived " ; }
};

int main(){
    B *ptr ; 
    D obj ; 
    ptr = &obj ;
    ptr -> fun1() ;  
    ptr -> fun2() ; 
    return 0 ; 
}

// 14 --- OUTPUT --- BASE 

class B{ 
public:
    virtual void fun1(){ cout << "Base " ; } 
    void fun2(){ cout << "Base " ; }
};

class D:public B{
public:
    void fun2(){ cout << "Derived " ; }
};

int main(){
    B *ptr ; 
    D obj ; 
    ptr = &obj ;
    ptr -> fun1() ;  
    return 0 ; 
}

// 15 --- OUTPUT --- I am Base

class B{ 
public:
    virtual void fun1() = 0 ; 
    void fun2(){ cout << "I am Base" << endl ; }
};

class D:public B{
public:
    void fun1(){ cout << "Implemented pure virtual function" << endl ; }
};

int main(){
    D obj ; 
    obj.fun2() ; 
    return 0 ; 
}

// 16 --- OUTPUT --- I am base 

class B{ 
public:
    virtual void fun1() = 0 ; 
    void fun2(){ cout << "I am Base" << endl ; } // IF THIS FUNCTION IS VIRTUAL THEN OUTPUT CHANGES 
};

class D:public B{
public:
    void fun1(){ }
    void fun2(){ cout << "Implemented pure virtual function" << endl ; }
};

int main(){
    B *ptr ;
    D obj ; 
    ptr = &obj ;
    ptr -> fun2() ;  
    return 0 ; 
}

// 17.A --- OUTPUT --- I am Base

class A{ 
public:
    virtual void fun1() = 0 ; 
    void fun2(){ cout << "I am Base" << endl ; }
};

class B:public A{
public:
    void fun1(){ cout << "Implemented PVF A" << endl ; }
    virtual void fun3() = 0 ; 
};

class C:public B{
    void fun3(){ cout << "Implemented PVF B" << endl ; }
};

int main(){
    C obj ; 
    obj.fun2() ; 
    return 0 ; 
}

// 17.B --- OUTPUT --- ERROR 
// SINCE CLASS C IS INHERITING CLASS A AND FUN1 DEFINITION IS NOT DECLARED IN CLASS C

class A{ 
public:
    virtual void fun1() = 0 ; 
    void fun2(){ cout << "I am Base" << endl ; }
};

class B:public A{
public:
    void fun1(){ cout << "Implemented PVF A" << endl ; }
    virtual void fun3() = 0 ; 
};

class C:public B,A{
public:
    void fun3(){ cout << "Implemented PVF B" << endl ; }
};

int main(){
    C obj ; 
    obj.fun2() ; 
    return 0 ; 
}

// 18.A --- OUTPUT --- fun1() is ambuiguous 

class A{ 
public:
    virtual void fun1(){ cout << "A" << endl ; } 
};

class B:public A{ } ; 
class C:public A{ } ; 
class D:public B,C{
public:
    void fun2(){ 
        fun1() ; 
        cout << "D class" << endl ; 
    }
};

int main(){
    D obj ; 
    obj.fun1() ; 
    return 0 ; 
}

// 18.B --- OUTPUT --- A
// HERE A ACTS AS VIRTUAL BASE CLASS 
// HENCE IT BECOMES STATIC AND ONLY ONE COPY IS PRESENT

class A{ 
public:
    virtual void fun1(){ cout << "A" << endl ; } 
};

class B:virtual public A{ } ; 
class C:virtual public A{ } ; 
class D:public B,C{
public:
    void fun2(){ 
        fun1() ; 
        cout << "D class" << endl ; 
    }
};

int main(){
    D obj ; 
    obj.fun1() ; 
    return 0 ; 
}

// 18.C --- OUTPUT --- D CLASS

class A{ 
public:
    virtual void fun1(){ cout << "A" << endl ; } 
};

class B:public A{ } ; 
class C:public A{ } ; 
class D:public B,C{
public:
    void fun2(){  
        cout << "D class" << endl ; 
    }
};

int main(){
    D obj ; 
    obj.fun2() ; 
    return 0 ; 
}

// 19.A --- OUTPUT --- BC

class A{ 
public:
    virtual void fun1(){ cout << "A" ; } 
};

class B:public A{ 
public:
    void fun1(){ cout << "B" ; }
} ; 

class C:public B{ 
public:
    void fun1(){ cout << "C" ; }
} ; 

int main(){
    A *ptr ; 
    B b ; C c ;
    ptr = &b ; 
    ptr -> fun1() ; 
    ptr = &c ; 
    ptr -> fun1() ;  
    return 0 ; 
}

// 19.B --- OUTPUT --- BB

class A{ 
public:
    virtual void fun1(){ cout << "A" ; } 
};

class B:public A{ 
public:
    virtual void fun1(){ cout << "B" ; }
} ; 

class C:public B{ } ; 

int main(){
    A *ptr ; 
    B b ; C c ;
    ptr = &b ; 
    ptr -> fun1() ; 
    ptr = &c ; 
    ptr -> fun1() ;  
    return 0 ; 
}

