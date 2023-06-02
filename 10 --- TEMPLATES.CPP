#include<bits/stdc++.h>
using namespace std ; 

// 1 --- FUNCTION TEMPLATE 

template<class T>
T Large(T n1,T n2){
    return (n1 > n2) ? n1 : n2 ; 
}

int main(){
    int i1,i2 ; cin >> i1 >> i2 ; 
    float f1,f2 ; cin >> f1 >> f2 ; 
    char c1,c2 ;  cin >> c1 >> c2 ;
    cout << Large(i1,i2) << endl ;
    cout << Large(f1,f2) << endl ; 
    cout << Large(c1,c2) << endl ;
}

// 2 --- OUTPUT --- 5.5

template<class T1,class T2>
T2 add(T1 n1,T2 n2){
    return n1 + n2 ; 
}

int main(){
    float knnc = add(2,3.5) ;
    cout << knnc << endl ;
}

// 3 --- OUTPUT --- 3 , HELLOWORLD

template<class T>
class Calculator{
private:
    T num1,num2 ; 
public:
    Calculator(T n1,T n2){
        num1 = n1 ; 
        num2 = n2 ; 
    }
    T add(){ return num1 + num2 ; }
    T subtract(){ return num1 - num2 ; }
    T multiply(){ return num1 * num2 ; }
};

int main(){
    Calculator<int> c1(1,2) ;
    cout << c1.add() << endl ;
    Calculator<string> c2("Hello","World") ;
    cout << c2.add() << endl ; 
    return 0 ; 
}
