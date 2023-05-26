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
