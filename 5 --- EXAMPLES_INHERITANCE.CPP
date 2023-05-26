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

class B : public A,C{
public:
    B(int x,int y,int z) : C(x) , A(y){
        cout << "B" << z ; 
    }
};

int main(){
    B obj(2,5,9) ;  
    return 0 ;
}
