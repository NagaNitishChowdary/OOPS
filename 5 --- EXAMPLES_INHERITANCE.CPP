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
