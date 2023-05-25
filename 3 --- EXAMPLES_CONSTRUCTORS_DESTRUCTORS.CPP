#include<bits/stdc++.h>
using namespace std ; 

// 1 --- CONSTRUCTING DEFAULT CONSTRUCTOR AND IT'S MUST BE PUBLIC 

class myClass{
public:  // IF PUBLIC WAS NOT DECLARED IT'S AN ERROR 
    char ch ; 
    int a,b ; 
    myClass(){
        cout << "Default Constructor created" << endl ;
    }
};

int main(){
    myClass knnc ; 
    return 0 ; 
}

// 2 

class A{ // NO ERROR AS THE PARAMETERIZED CONSTRUCTOR IS EXECUTED 
private:
    A(){
        cout << "Default Constructor created" << endl ;
    }
public:
    int a ; 
    A(int a){
        this -> a = a ; 
    }
};

int main(){
    A a(10) ;
    cout << a.a << endl ;
    return 0 ; 
}

// 3 --- ERROR AT LINE [MYOBJ OBJ2 ;] BECAUSE THE COMPILER CREATES A DEFAULT CONSTRUCTOR IF NO OTHER CONSTRUCTER
// IS PRESENT IN THE CLASS IF THERE IS A CONSTRUCTOR IN THE CLASS THEN COMPILER DOES N'T CREATE ANY DEFAULT CONSTRUCTORS 

class myClass{
    int a ; 
public:
    myClass(int x){
        a = x ; 
        cout << "Constructor " << a << endl ;  
    }

    int getvalue(){
        return a ; 
    }
};

int main(){
    myClass obj1(1)  ; 
    obj1.getvalue() ;
    myClass obj2 ;   // ERROR 
    return 0 ; 
}

// 4 --- FUNCTION OVERLOADING 

class myClass{ 
public:
    char ch ; 
    int a,b ; 
    myClass(){
        a = 0 , b = 0 ;
        ch = 'a' ; 
    }
    myClass(char c){
        ch = c ; 
    }
    myClass(int x,int y){
        a = x ; 
        b = y ; 
    }
    void get(){
        cout << a << " " << b << " " << ch << endl ; 
    }
};

int main(){
    myClass ob1 , ob2('Z') , ob3(4,8)  ; 
    ob1.get() ;  // OUTPUT --- 0 , 0 , 'a'
    ob2.get() ;  // OUTPUT --- garbage , garbage , 'Z'
    ob3.get() ;  // OUTPUT --- 4 , 8 , garbage 
    return 0 ; 
}

// 5 --- DESTRUCTORS 
// OUTPUT IS CONSTRUCTOR 1 , CONSTRUCTOR 2 , CONSTRUCTOR 3 
// DESTRUCTOR 3 , DESTRUCTOR 2 , DESTRUCTOR 1 

class myClass{
    int a ; 
public:
    myClass(int x){
        a = x ;
        cout << "Constructor: " << a << endl ; 
    }

    ~myClass(){
        cout << "Destructor: " << a << endl ; 
    }
};

int main(){
    myClass obj1(1) , obj2(2) , obj3(3) ;
    return 0 ; 
}

// 6 --- A
// OUTPUT IS CON 1 , CON 2 , CON 3 , CON 4 , DES 4 , CON 5 , DES 5
// DES 3 , DES 2 , DES 1 

class myClass{
    int a ; 
public:
    myClass(int x){
        a = x ;
        cout << "Constructor " << a << endl ; 
    }
    ~myClass(){
        cout << "Destructor: " << a << endl ; 
    }
};

void myFun(int x){
    myClass obj1(x) ;
}

int main(){
    myClass obj1(1) , obj2(2) , obj3(3) ;
    myFun(4) ;
    myFun(5) ;
    return 0 ; 
}

// 6 --- B
// OUTPUT IS CON 1 , CON 2, CON 3 , CON 4 , MAIN ENDS HERE 
// DES 3 , DES 2 , DES 1 , DES 4

class myClass{
    int a ; 
public:
    myClass(int x){
        a = x ;
        cout << "Constructor " << a << endl ; 
    }
    ~myClass(){
        cout << "Destructor: " << a << endl ; 
    }
};

void myFun(int x){
    static myClass obj1(x) ;   // STATIC OBJECT DIES WHEN WHOLE PROGRAM ENDS
}

int main(){
    myClass obj1(1) , obj2(2) , obj3(3) ;
    myFun(4) ;
    cout << "MAIN ENDS HERE " << endl ;
    return 0 ; 
}

// 7 --- COPY CONSTRUCTORS

// 7 --- COPY CONSTRUCTOR 
// OUTPUT IS DEF 1- , COPY 11 , COPY 11 

class A{
    int a ;
public:
    A(){
        a = 10 ;
        cout << "Default constructor: " << a << endl ; 
    }

    A(const A &q){
        a = q.a ;
        cout << "Copy constructor: " << a << endl ; 
    }

    void set_a(int x){
        a = x ; 
    }
}; 

int main(){
    A obj;
    obj.set_a(11) ;
    A a1 = obj ;
    A a2(obj) ;
    return 0 ;
}

// 8 
// OUTPUT ---  CON CLASS A , HELLO , HELLO  

class A{
public:
    A(){
        cout << "Constructor class A" << endl ; 
    }
};

class myClass{
public:
    static A getvalue(){ // AS IT IS A STATIC FUNCTION , THERE IS ONLY ONE COPY OF IT IS PRESENT 
        // HENCE FOR ANY NUMBER OF OBJECTS THE CONSTRUCTOR IS CALLED ONLY ONCE 
        static A a ;
        cout << "Hello" << endl ;
        return a ; 
    }
};

int main(){
    myClass obj1 ;
    A obj2 = myClass::getvalue() ; 
    // STATIC FUNCTIONS CAN BE DIRECTLY ACCESSED THROUGH CLASS NAME 
    A obj3 = obj1.getvalue() ; 
    return 0 ; 
}

// 9 --- A
// OUTPUT --- ABAB 

class A{
public:
    A(){ cout << "A" ; }
    A(int x){ cout << x ; }
};

class B{
    A obj1 ;
public:
    B(){ cout << "B" ; }
};

int main(){
    B obj1 ; // WHEN AN OBJECT IS CREATED FIRSTLY MEMORY IS ALLOCATED FOR ITS ATTRIBUTES FOR LOCAL VARIABLES AND THEN CONSTRUCTORS ARE CALLED 
    B obj2 ; 
    return 0 ; 
}

// 9 --- B
// OUTPUT --- ABAB

class A{
public:
    A(){ cout << "A" ; }
    A(int x){ cout << x ; }
};

class B{
    A obj1 ;
public:
    static A ob ;  // HERE NO MEMORY IS CREATED FOR OB AS IT IS STATIC THE MEMORY IS CREATED WHEN IT IS USED
    // IT CAN USED VIA OUTSIDE THE CLASS AS THIS STATEMENT HERE IS OF NO USE 
    B(){ cout << "B" ; }
};

int main(){
    B obj1 ;
    B obj2 ; 
    return 0 ; 
}

// 9 --- C
// OUTPUT --- AABAB
// FIRST GLOBAL VARIABLES CREATED FIRST AND THEN MAIN FUNCTION IS EXECUTED 

class A{
public:
    A(){ cout << "A" ; }
    A(int x){ cout << x ; }
};

class B{
    A obj1 ;
public:
    static A ob ; 
    B(){ cout << "B" ; }
};

A B::ob ;  // OB BELONGS TO CLASS B WHICH IS OF TYPE A 

int main(){
    B obj1 ;
    B obj2 ; 
    return 0 ; 
}

// 10 --- 
// OUTPUT --- 1211

class A{
    int a ; 
public:
    A(){ a = 0 ; }
    A(int x){ a = x ; }
    void print(){ cout << a ; }
};

int main(){
    static A obj1 ;
    static A obj2(12) ;
    A a(11) ;
    A b = obj2 ;
    b.print() ; 
    obj1 = a ; 
    obj1.print() ;  
    return 0 ; 
}
