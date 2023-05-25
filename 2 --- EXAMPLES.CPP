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
