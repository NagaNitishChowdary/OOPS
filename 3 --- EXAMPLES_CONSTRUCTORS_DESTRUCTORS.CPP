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

4 --- FUNCTION OVERLOADING 

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

5 --- DESTRUCTORS 

OUTPUT IS CONSTRUCTOR 1 , CONSTRUCTOR 2 , CONSTRUCTOR 3 
DESTRUCTOR 3 , DESTRUCTOR 2 , DESTRUCTOR 1 

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

6 --- A

OUTPUT IS CON 1 , CON 2 , CON 3 , CON 4 , DES 4 , CON 5 , DES 5
DES 3 , DES 2 , DES 1 

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

6 --- B
OUTPUT IS CON 1 , CON 2, CON 3 , CON 4 , MAIN ENDS HERE 
DES 3 , DES 2 , DES 1 , DES 4

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
