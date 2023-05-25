// 1 --- 

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

// 2 --- 

#include<bits/stdc++.h>
using namespace std ; 

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
