// 1 --- PUBLIC AND WITH OUT PUBLIC DIFFERENCE

#include<bits/stdc++.h>
using namespace std ; 

class A{
public:   // IF PUBLIC IS NOT MENTIONED THEN IT DEFAULTLY TAKES AS PRIVATE AND GIVES ERROR WHEN ACCESSING OUTSIDE THE CLASS  
    int a;
    void modify_a(int x){
        a = x ; 
    }
};

// OR 

class A{
public:
    int a;
    void modify_a(int a){
        this -> a = a ; 
    }
};

int main(){
    A a ;
    a.modify_a(10) ; 
    cout << a.a << endl ; 
    return 0 ;
}

// 2 --- CONSTRUTOR AND POINTER WITH OBJECT 

class A{
public:
    int a,b ;
    A(int a,int b){
        this -> a = a ;
        this -> b = b ; 
    }
    int getSum(){
        return a+b ; 
    }
};

int main(){
    A obj1(3,7) ;
    A *ptr ; 
    ptr = &obj1 ;
    // *ptr.a = 5 ; // THIS IS AN ERROR BECAUSE . OPERATOR HAS HIGHEST PRECEDENCE
    (*ptr).a = 5 ;  // OR   ptr -> a = 5 ; 
    cout << obj1.getSum() << endl ; 
    return 0 ;
}


// 3 --- FRIEND METHODS 

class A{
    int a ; 
public:
    A(){
        a = 5 ; 
    }
    friend void modify() ; 
};

void modify(){
    A knnc; 
    cout << knnc.a << endl ; 
}

int main(){
    modify() ;  
    return 0 ;
}

// 4 --- FRIEND METHODS 

class Distance{
private:
    int meter ;
    friend int addFive(Distance) ;
public:
    Distance(){
        meter = 0 ; 
    }
};

int addFive(Distance d){
    d.meter += 5 ;
    return d.meter ; 
}

int main(){
    Distance d ; 
    cout << addFive(d) << endl ;
}

// 5 --- FRIEND METHOD 

class A{  // OUTPUT IS 5,5 AS IT IS PASS BY VALUE 
private:
    int a ;
    friend void modify(A ob) ;
public:
    A(){ a = 5 ; }
    void get(){
        cout << a << endl ; 
    }
};

void modify(A ob){
    ob.a += 13 ; 
}

class A{ // OUTPUT IS 5,18 AS IT IS PASS BY REFERENCE 
private:
    int a ;
    friend void modify(A &ob) ;
public:
    A(){ a = 5 ; }
    void get(){
        cout << a << endl ; 
    }
};

void modify(A &ob){
    ob.a += 13 ; 
}

int main(){
    A obj ;
    obj.get() ; 
    modify(obj) ;
    obj.get() ; 
    return 0 ; 
}

// 6 --- CONSTRUCTORS 

class A{  // ERROR AS CONST VARIABLES CANNOT BE MODIFIED
private:
    const int a = 5 ; ; 
    int b ;
public:
    A(int x,int y){
        a = x ;
        b = y ;
        cout << "Initialized " << endl ; 
    }
};

int main(){
    A obj(2,4) ; 
    return 0 ; 
}

// 7 --- STATIC VARIABLE 

class A{  // OUTPUT IS 13 , 13 , 13
public:
    static int a ;
    void increment(){ a++ ; }
    int get(){ return a ; }
};

int A::a = 10 ;

int main(){
    A obj1 , obj2 , obj3 ;
    obj1.increment() ;
    obj2.increment() ;
    obj3.increment() ;
    cout << obj3.get() << " " << obj2.get() << " " << obj1.get() << endl ;
    return 0 ; 
}

// 8 --- STATIC VARIABLE AND STATIC FUNCTION 
// STATIC FUNCTIONS CAN ONLY ACCESS STATIC VARIABLES 
// BUT STATIC VARIABLES CAN BE ACCESSED BY ANY OTHER FUNCTIONS 

class A{ // OUTPUT IS 13
public:
    static int a ;
    static void increment(){ a++ ; }
    static int get(){ return a ; }
};

int A::a = 10 ;

int main(){
    A obj1 , obj2 , obj3 ;
    obj1.increment() ;
    obj2.increment() ;
    A::increment() ; // ONLY STATIC FUNCTIONS CAN BE CALLED DIRECTLY WITH THE CLASS 
    cout << obj3.get() << endl ;
    return 0 ; 
}

// 9 --- STATIC FUNCTIONS AND METHODS  

class A{  // OUTPUT IS 32 
public:
    static int a ;
    static void increment(){ a += 3 ; }
    int get(A obj){ return a+obj.a ; }
};

int A::a = 10 ;

int main(){
    A obj1 , obj2 ;
    obj1.increment() ;
    obj2.increment() ;
    cout << obj2.get(obj1) << endl ;
    return 0 ; 
}
