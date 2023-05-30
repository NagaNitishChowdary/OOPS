#include<bits/stdc++.h>
using namespace std;

// FUNCTION OVERLOADING --- WHEN THERE ARE MULTIPLE FUNCTIONS WITH SAME NAME 
// BUT DIFFERENT PARAMETERS THEN THESE FUNCTIONS ARE SAID TO BE OVERLOADED .

void solve(){
    cout << "solve with no parameters" << endl ; 
}

void solve(int a){
    cout << "solve with one parameter" << endl ; 
}

int main() {
    solve() ; 
    solve(1);
    return 0;  
} 

// 1 --- COMPILE TIME POLYMORPHISM  
// OUTPUT --- AB

class A{
public:
    void function(){ cout << "A" ; } 
};

class B{
public:
    void function(){ cout << "B" ; }
};

int main(){
    A a ; 
    a.function() ; 
    B b ;
    b.function() ; 
    return 0 ;
}

// 2 --- ANSWER --- C 

// WHICH OF THE FOLLOWING OPERATOR CAN BE OVERLOADED ?
// A) ::(SCOPE RESOLUTION)
// B) .(MEMBER SELECTION)
// C) +=(SHORTHAND ASSIGNMENT)
// D) .*

// 3 --- ANSWER --- C
// TERNARY OPERATOR CANNOT BE OVERLOADED  
// WHICH OF THE FOLLOWING OPERATOR CANNOT BE OVERLOADED ?
// A) >=
// B) <= 
// C) ?:
// D) *

// 4 --- OUTPUT --- BA
class A{
public:
    void function(){ cout << "A" ; } 
};

class B{
public:
    void function(){
        A a ;  
        cout << "B" ;
        a.function() ;  
    }
};

int main(){
    B b ;
    b.function() ; 
    return 0 ;
}

// 5 --- FUNCTION OVERLOADING 
// OUTPUT --- 246 , b , 12.4 , 54

class A{
public:
    int function(int x){ return 2*x ; }
    int function(int x,int y){ return x+10*y ; }
    char function(char x){ return x+1 ; }
    double function(double x){ return x ; }
};

int main(){
    A a ;
    cout << a.function(123) << endl ;
    cout << a.function('a') << endl ;
    cout << a.function(12.4) << endl ;
    cout << a.function(4,5) << endl ; 
    return 0 ; 
}

// 6 --- OPERATOR OVERLOADING 
// OUTPUT --- 3 , 14

class A{
    int a,b; 
public:
    A(int x,int y){
        a = x ; 
        b = y ; 
    }

    A operator+(A const&obj){ // obj2's reference is passed here
        A temp(0,0) ; 
        temp.a = a + obj.a ; // a = 2 
        temp.b = b + obj.b ; // b = 6 
        return temp ; 
    }
    void print(){
        cout << a << " " << b << endl ;
    }
};

int main(){
    A obj1(2,6) , obj2(1,8) ;
    A obj3 = obj1 + obj2 ; // (OR) = obj1.operator+(obj2)
    obj3.print() ; 
    return 0 ; 
}

// 7 --- OUTPUT --- 3 , 14    , 1, 8 

class A{
    int a,b; 
public:
    A(int x,int y){
        a = x ; 
        b = y ; 
    }

    void operator+(A const&obj){
        a += obj.a ;
        b += obj.b ; 
    }
    void print(){
        cout << a << " " << b << endl ;
    }
};

int main(){
    A obj1(2,6) , obj2(1,8) ;
    obj1 + obj2 ;  // same as obj1.operator+(obj2) and passed with reference
    obj1.print() ;
    obj2.print() ;  
    return 0 ; 
}

// *8 --- OUTPUT --- ERROR : A::a in read only object 
// BECAUSE THERE IS CONST  

class A{
    int a,b; 
public:
    A(int x,int y){
        a = x ; 
        b = y ; 
    }

    void operator+(A const&obj){
        obj.a += a ;
        obj.b += b ; 
    }
    void print(){
        cout << a << " " << b << endl ;
    }
};

int main(){
    A obj1(2,6) , obj2(1,8) ;
    obj1 + obj2 ;  // same as obj1.operator+(obj2) and passed with reference
    obj1.print() ;
    obj2.print() ;  
    return 0 ; 
}

// 9 --- OUTPUT --- 12,13,10

class A{
public:
    int add(int x,int y){ return x+y ; }
    int add(int x,int y,int z){ return x+y+z ; }
    int add(int *arr,int n){
        int sum = 0 ;
        for(int i=0 ; i<n ; i++){ sum += arr[i] ; }
        return sum ; 
    }
};

int main(){
    int a=3 , b=9 , c=1 ; 
    int arr[] = {1,2,3,4} ;
    A obj ; 
    cout << obj.add(a,b) << endl ;
    cout << obj.add(a,b,c) << endl ; 
    cout << obj.add(arr,4) << endl ;   
    return 0 ; 
}

// 10 --- OUTPUT --- AMBUIGUITY OCCURS 

class A{
public:
    int add(int x=0,int y=0){ return x+y+20 ; }
    int add(int x,int y){ return x+y ; }
};

int main(){
    int a=2 , b=16 ;
    A obj ; 
    cout << obj.add() << endl ;
    cout << obj.add(a,b) << endl ;    
    return 0 ; 
}

// 11 --- OUTPUT --- AMBUIGUITY OCCURS  

class A{
public:
    int add(int x,int y,int z=0){ return x+y+z ; }
    int add(int x,int y){ return x+y ; }
};

int main(){
    int a=2 , b=16 , c=1 ;
    A obj ; 
    cout << obj.add(a,b,c) << endl ;
    cout << obj.add(a,b) << endl ;    
    return 0 ; 
}

//  12 --- OUTPUT --- AMBUIGUOUS 

class A{
public:
    int fun(int x){ return x*x ; }
    int fun(int &x){ return x*10 ; }
};

int main(){
    int a=2 ;
    A obj ; 
    cout << obj.fun(a) << endl ;   
    return 0 ; 
}

// 13 --- OUTPUT --- ERROR 

class A{
    int a ; 
public:
    A(){ a = 0 ; }
    // SYNTAX OF PRE INCREMENT OPERATOR 
    void operator++(){ a += 3 ; }  // NO ERROR IF IT IS VOID OPERATOR++(INT)
    void print(){ cout << a << endl ; }
};

int main(){
    A obj ; 
    for(int i=0 ; i<5 ; i++) obj++ ; // NO ERROR IF IT IS ++OBJ ; 
    obj.print() ;  
    return 0 ; 
}

// 14 --- OUTPUT --- 15
// PRE INCREMENT

class A{
    int a ; 
public:
    A(){ a = 0 ; }
    void operator++(){ a += 3 ; }
    void print(){ cout << a << endl ; }
};

int main(){
    A obj ; 
    for(int i=0 ; i<5 ; i++) ++obj ; 
    obj.print() ;  
    return 0 ; 
}

// 15 --- OPERATOR OVERLOADING --- POST INCREMENT  
// OUTPUT --- 15

class A{
    int a ; 
public:
    A(){ a = 0 ; }
    void operator++(int){ a += 3 ; }
    void print(){ cout << a << endl ; }
};

int main(){
    A obj ; 
    for(int i=0 ; i<5 ; i++) obj++ ; 
    obj.print() ;  
    return 0 ; 
}

// 16 --- OPERATOR OVERLOADING (==)
// OUTPUT --- 1 , 0 

class A{
    int a,b ; 
public:
    A(){ a = 0 ; b = 0 ; }
    void set(int x,int y=4){ a=x , b=y ; }
    bool operator==(const A&obj){
        if(a == (obj.a+2) && b == (obj.b)) return true ; 
        else return false ; 
    }
};

int main(){
    A obj1 , obj2 ; 
    obj1.set(4,6) ;  obj2.set(2,6) ; 
    cout << (obj1 == obj2) << endl ;
    obj2.set(6,6) ; 
    cout << (obj1 == obj2) << endl ; 
    return 0 ; 
}

