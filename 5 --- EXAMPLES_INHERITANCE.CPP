#include<bits/stdc++.h>
using namespace std ; 

// 1 --- INHERITANCE WITH CONSTRUCTORS  
// OUTPUT --- AB 

class A{
public:
    A(){ cout << "A" ; }
};

class B : public A{
public:
    B(){ cout << "B" ; }
};

int main(){
    B obj ;  // WHEN U ARE CREATING A OBJECT THEN BOTH CONSTRUCTORS ARE CALLED 
    // AND FIRST BASE CONSTRUCTOR IS CALLED AND THEN DERIVED CONSTRUCTOR IS CALLED 
    return 0 ;
}

// 2 --- OUTPUT --- A4B5

class A{
public:
    A(int y){ cout << "A" << y ; }
};

class B : public A{
public:
    B(int x,int y) : A(x){
        cout << "B" << y ; 
    }
};

int main(){
    B obj(4,5) ;  
    return 0 ;
}

// 3 --- OUTPUT ---  CAB

class A{
public:
    A(){ cout << "A" ; }
};

class C{
public:
    C(){ cout << "C" ; }
};

class B : public C,A{
public:
    B(){ cout << "B" ; }
};

int main(){
    B obj ;  
    return 0 ;
}

// 4 --- OUTPUT --- A5C2B9

class A{
public:
    A(int x){ cout << "A" << x ; }
};

class C{
public:
    C(int x){ cout << "C" << x ; }
};

class B : public A,C{ // THE CONSTRUCTORS ARE CALLED ACCORDING TO INHERITED ORDER 
public:
    B(int x,int y,int z) : C(x) , A(y){
        cout << "B" << z ; 
    }
};

int main(){
    B obj(2,5,9) ;  
    return 0 ;
}

// 5 --- A
// OUTPUT --- ERROR BECAUSE WE NEED TO DECLARE B(int x) : A(x) as it is not declared hence the compiler tries to find the default constructor
// and hence no default constructor and compiler unable to create as already parameterized constructor is present in class A
class A{
public:
    A(int x){ cout << "A" << x ; }
};

class B : public A{
public:
    B(int x){
        cout << "B" << x ; 
    }
};

int main(){
    B obj(12) ;  
    return 0 ;
}

// 6 --- A 
// OUTPUT --- A DERIVED CLASS CAN ONLY CALL THE CONSTRUCTOR OF WHICH WE ARE DIRECTLY INHERITING
// AND CANNOT CALL THE MULTI LEVEL INHERITED CLASS

class A{
public:
    A(int x){ cout << "A" << x ; }
};

class B : public A{
public:
    B(int x){
        cout << "B" << x ; 
    }
};

class C : public B{
    C(int x,int y,int z) : A(y) , B(z){ // WE CAN ONLY CALL CONSTRUCTORS WE ARE DIRECTLY INHERITING
        cout << "C" << x ; 
    }
}

int main(){
    C obj(2,5,9) ; 
    return 0 ;
}

// 6 --- B 
// OUTPUT --- A9B5C2

class A{
public: 
    A(int x){ cout << "A" << x ; }
};

class B : public A{
public:
    B(int x,int y):A(y){
        cout << "B" << x ; 
    }
};

class C : public B{
public:
    C(int x,int y,int z) : B(y,z){
        cout << "C" << x ; 
    }
};

int main(){
    C obj(2,5,9) ; 
    return 0 ;
}

// 6 --- C 
// OUTPUT --- A9B5 HELLO WORLD C2

class A{
public: 
    A(int x){ cout << "A" << x ; }
    void get(){ cout << " HELLO WORLD " ; }
};

class B : public A{
public:
    B(int x,int y):A(y){
        cout << "B" << x ; 
    }
};

class C : public B{
public:
    C(int x,int y,int z) : B(y,z){
        get() ; 
        cout << "C" << x ; 
    }
};

int main(){
    C obj(2,5,9) ;
    return 0 ; 
}

// 7 --- A
// OUTPUT --- A9B5 HELLO WORLD C2
// HERE WE ARE CALLING GET IN WHICH IT IS IN CLASS A WHICH IS PUBLIC
// AND WHEN IT COMES TO B IT IS PROTECTED AND THEN C IT IS STILL PROTECTED 
// HENCE WE CAN ACCESS PROTECTED METHODS WITH IN THE CLASS 
// THERE IS AN ERROR WE CREATE OBJECT AND CALL THE GET FUNCTION 

class A{
public: 
    A(int x){ cout << "A" << x ; }
    void get(){ cout << " HELLO WORLD " ; }
};

class B : protected A{
public:
    B(int x,int y):A(y){
        cout << "B" << x ; 
    }
};

class C : public B{
public:
    C(int x,int y,int z) : B(y,z){
        get() ; 
        cout << "C" << x ; 
    }
};

int main(){
    C obj(2,5,9) ; 
    return 0 ; 
}

// 7 --- B 
// OUTPUT --- A5 HELLO WORLD 
// AS IN CLASS A GET FUNCTION IN PUBLIC HENCE WE CAN USE IT OUTSIDE THE FUNCTION 
class A{
public: 
    A(int x){ cout << "A" << x ; }
    void get(){ cout << " HELLO WORLD " ; }
};

class B : protected A{
public:
    B(int x,int y):A(y){
        cout << "B" << x ; 
    }
};

class C : public B{
public:
    C(int x,int y,int z) : B(y,z){
        get() ; 
        cout << "C" << x ; 
    }
};

int main(){
    A obj1(5) ;
    obj1.get() ; 
    return 0 ; 
}

// 7 --- C 
// ERROR --- BECAUSE GET FUNCTION IN CLASS A IS PUBLIC AND SAME GET FUNCTION IN CLASS B AND C IS PROTECTED 
// HENCE IT CAN ONLY BE INHERITED AND USED IN THE SAME CLASS AND WE CANNOT ACCESS IT FROM OUTSIDE THE CLASS 
class A{
public: 
    A(int x){ cout << "A" << x ; }
    void get(){ cout << " HELLO WORLD " ; }
};

class B : protected A{
public:
    B(int x,int y):A(y){
        cout << "B" << x ; 
    }
};

class C : public B{
public:
    C(int x,int y,int z) : B(y,z){
        get() ; 
        cout << "C" << x ; 
    }
};

int main(){
    B obj1(5,6) ;
    obj1.get() ; 
    return 0 ; 
}

// 8 --- DESTRUCTORS WITH INHERITANCE 
// OUTPUT --- CBA
class A{
public:
    ~A(){ cout << "A" ; }
};

class B{
public:
    ~B(){ cout << "B" ; }
};

class C:public A,B{   // if class C : public B,A then ouput is --- CAB
public:
    ~C(){ cout << "C" ; }
};

int main(){
    C c ;
    return 0 ; 
}

// 9 --- OUTPUT --- 80 
// size of class == sum of size of elements in it 
class base{  // 80 bytes
public:
    int arr[10] ;
};

class b1:public base{} ; // 80 bytes

class b2:public base{} ; // 80 bytes

class derived: public b1,public b2{} ; // 80 + 80 = 160 bytes

int main(){
    cout << sizeof(derived) ;
    return 0 ; 
}

// 10 --- A 
// WHICH SPECIFIER MAKES ALL THE DATA MEMBERS AND FUNCTIONS 
// OF THE BASE CLASS INACCESSIBLE BY THE DERIVED CLASS ?

// ANS --- PRIVATE 

// 10 --- B 
// OUTPUT --- 15 , 10 
class A{
public:
    int a ;
    void change(int i){ a = i ; }
    void value_of_a(){ cout << a << endl ; }
};

class B : public A{
    int a = 15 ; 
public:
    void print(){ cout << a << endl ; } 
};

int main(){
    B b ;
    b.change(10) ;
    b.print() ; 
    b.value_of_a() ; 
    return 0 ; 
}
