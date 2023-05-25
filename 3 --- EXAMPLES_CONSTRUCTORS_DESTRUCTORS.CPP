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
