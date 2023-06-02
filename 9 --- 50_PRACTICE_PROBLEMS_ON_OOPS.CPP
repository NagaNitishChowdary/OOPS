#include<bits/stdc++.h>
using namespace std ; 

// 1 --- ANSWER --- B 

// WHICH OF THE FOLLOWING IS NOT A FEATURE OF OOPS
// A) ENCAPSULATION
// B) POINTERS
// C) DATA HIDING
// D) INHERITANCE 
// E) POLYMORPHISM

// 2 --- ANSWER --- C 

// WHICH OF THE FOLLOWING IS TRUE FOR A CLASS . A CLASS IS 
// A) PARENT OF AN OBJECT 
// B) INSTANCE OF AN OBJECT --- OBJECT IS INSTANCE OF CLASS 
// C) BLUEPRINT OF AN OBJECT 
// D) SCOPE OF AN OBJECT 

// 3 --- ANSWER --- D 

// WHICH CLASS CANNOT CREATE ITS INSTANCE
// A) VIRTUAL CLASS 
// B) NESTED CLASS
// C) DERIVED VIRTUAL CLASS
// D) ABSTRACT CLASS --- CONTAINS ATLEAST ONE PURE VIRTUAL CLASS

// 4 --- ANSWER --- C 

// WHICH OF THE FOLLOWING IS NOT CONSIDERED AS MEMBER OF CLASS
// A) PURE VIRTUAL FUNCTION --- A CLASS WHICH CONTAINS IT IS ABSTRACT CLASS AND THE OBJECT CANNOT BE CREATED FOR ABSTARCT CLASS
// B) CONST FUNCTION --- WE CANNOT MODIFY ANYTHING
// C) FRIEND FUNCTION --- A FUNCTION WHICH CAN ACCESS PRIVATE MEMBERS OF THE CLASS
// D) STATIC FUNCTION --- IT ALLOCATES SINGLE MEMORY

// 5 --- ANSWER --- 36
// WHEN WE CREATE A POINTER AND ASSIGN OBJECT OF INHERITED ONE THEN OVERRIDING WILL TAKE PLACE 
// NOW JUST DEFAULT COPYING OCCURS HENCE BASE CLASS IS EXECUTED 
// PRECEDENCE : (++) > (+) > (>> (OR) <<)

class One{
public:
    virtual int fun(int x,int y){
        return (x++ + ++y + x<<2) ; 
    }
};

class Two:public One{
public:
    int fun(int x,int y){
        return (++x + y++ + y>>2) ;
    }
};

int main(){
    One obj = Two() ; 
    cout << obj.fun(2,3) << endl ; 
}

// 6 --- OUTPUT --- 2 

class One{
public:
    virtual int fun(int x,int y){
        return (x++ + ++y + x<<2) ; 
    }
};

class Two:public One{
public:
    int fun(int x,int y){
        return (++x + y++ + y>>2) ;
    }
};

int main(){
    One *ptr ; 
    Two obj ; 
    ptr = &obj ; 
    cout << ptr -> fun(2,3) << endl ;
}

// 7 --- OUTPUT --- 1,2,2  1,4,4  1,5,2
// HERE PRECEDENCE OF *(DEREFERENCE) AND ++ IS SAME 
// AND THE ASSOCIAVITY IS FROM RIGHT TO LEFT 

int main(){
    int a[] = {1,2,3,4,5,6,7} ;  // a = 100 , *a = 1
    int *p[] = {a+1,a+3,a,a+5,a+4} ; // p = 200 
    int **q = p ;
    // address of a = 100 , b = 200 , c = 300 
    // a = [100,104,108,112,116,120,124]
    // p = [104,112,100,120,116]
    // q = [200]
    cout << *a << " " << **p << " " << **q << endl ; 
    ++*++*q ; // ++(*(++(*q)))
    // p = [108,112,100,120,116]
    // a = [1,2,4,4,5,6,7]  
    // here q = 200 , &q = 300 , *q = 108 , *q = p 
    cout << *a << " " << **p << " " << **q << endl ;
    ++++*p ; // ++(++(*p)) --- p = 200 , *p = 108 
    // p = [116,112,100,120,116]
    ++*++++q ; // ++(*(++(++q))) ---> ++(*(208)) ---> q = 208
    // p = [116,112,104,120,116]
    cout << *a << " " << **p << " " << **q << endl ; 
    return 0 ; 
}

// 8 --- OUTPUT --- IS LLO NNC HIS 

char *p[] = {"HELLO" , "THIS" , "IS" , "KNNC"} ; 
// p = [100,104,108,112] --- > 100 = ['H','E','L','L','O','\N'] , 104 = ['T','H','I','S','\N'] ...
// p = [10 , 20 , 30 , 40]
//     100  200   300  400
char **q[] = {p+3 , p+2 , p+1 , p} ;
// q = [112 , 108 , 104 , 100]
//      200   204   208   212
char ***r = q ; 
// r = [200]
//      300 

int main(){
    cout << **++r << " " ;  // *(*(++r)) ---> *(*(204)) --> *(108) ---> 30 ---> "IS" 
    // r = [204]
    //      300
    cout << *--*++r+2 << " " ; // (*(--(*(++r))))+2 
    // r = [208]
    //      300
    // q = [112 , 108 , 100 , 100]
    //      200   204   208   212
    cout << *r[-2]+1 << " " ; // r[-2] = (r-2) = 200 , *r[-2] = 112 
    // r = [208]
    //      300
    cout << r[-1][-1]+1 << endl ; // r[-1] = *(r-1) = 108 ---> *(104) ---> 20+1 ---> 21
    return 0 ; 
}

// 9 --- OUTPUT --- A

// WHAT MEMBERS OF THE BASE ARE NEVER ACCESSIBLE TO THE CHILD
// A) PRIVATE MEMBERS
// B) PROTECTED MEMBERS
// C) BOTH PRIVATE AND PROTECTED MEMBERS 
// D) NONE OF THE ABOVE 

// 10 --- OUTPUT --- C
// ALL TYPES OF ASSIGHMENTS CAN BE OVERLOADED 

// WHICH OF THE FOLLOWING OPERATORS CAN BE OVERLOADED ?
// A) ::(SCOPE RESOLUTION)
// B) .(MEMBER SELECTION)
// C) += (SHORTHAND ASSIGNMENT)
// D) .*(MEMBER SELECTION THROUGH POINTER TO FUNCTION)
// E) SIZEOF(DATATYPE)

// 11 --- OUTPUT --- D

// A CLASS IS TAGGED ABSTRACT , IF IT HAS 
// A) EXACTLY ONE VIRTUAL METHOD 
// B) ATLEAST ONE VIRTUAL METHOD
// C) EXACTLY ONE PURE VIRTUAL METHOD 
// D) ATLEAST ONE PURE VIRTUAL METHOD 

// 12 --- CONSTRUCTORS 
// OUTPUT --- ERROR AS CLASS B IS INHERITING PRIVATELY 
// HENCE THE CONSTRUCTOR CANNOT BE PRICATE 
// ERROR --- CANNOT CAST 'D' TO ITS PRIVATE BASE CLASS 'B'

class B{
public:
    B(){ cout << "Class B" << endl ; }
};

class C{
public:
    C(){ cout << "Class C" << endl ; }
};

class D:public C,B{
public:
    D(){ cout << "Class D" << endl ; }
};

int main(){
    B *b = new D() ; 
    return 0 ; 
}

// 13 --- OUTPUT --- ERROR --- WE CANNOT CREATE OBJECT FOR ABSTRACT CLASS

class One{
public:
    virtual int fun(int x,int y){
        return (x++ + ++y + x<<2) ; 
    }
};

class Two:public One{ // abstract class
public:
    int fun(int x,int y){
        return (++x + y++ + y>>2) ; 
    }
    virtual int fun2() = 0 ; // pure virtual function 
};

int main(){
    One *ptr ; 
    Two obj ; 
    ptr = &obj ; 
    cout << ptr -> fun(2,3) << endl ; 
    return 0 ; 
}

// 14 --- DESTRUCTORS 
// OUTPUT --- DERIVED DESTRUCTORS , C VIRTUAL FUNCTION , B VIRTUAL FUNCTION

class B{
public:
    virtual ~B(){ cout << "B virtual function" << endl ; }
};

class C{
public:
    virtual ~C(){ cout << "C virtual function" << endl ; }
};

class D:public B,public C{
public:
    ~D(){ cout << "Derived destructor" << endl ; }
};

int main(){
    B *b = new D() ; 
    delete b ;
    return 0 ;
}

// 15 --- DESTRUCTORS 
// OUTPUT --- A CLASS CANNOT HOLD ANY OTHER'S CLASS CONSTRUCTOR OR DESTRUCTOR


class B{ // ABSTRACT CLASS  
public:
    virtual ~B() = 0 ; // PURE VIRTUAL DESTRUCTOR 
};

class D:public B{
public:
    ~D(){ cout << "Derived destructor" << endl ; }
    ~B(){ cout << "Implemented PVF" << endl ; }
};

int main(){
    B *b = new D() ; 
    delete b ;
    return 0 ;
}

// 16 --- DESTRUCTORS 
// OUTPUT --- DERIVED DESTRUCTOR , IMPLEMENTED PVF 

class B{ // ABSTRACT CLASS  
public:
    virtual ~B() = 0 ; // PURE VIRTUAL DESTRUCTOR 
};

B::~B(){ cout << "Implemented PVF" << endl ; }

class D:public B{
public:
    ~D(){ cout << "Derived destructor" << endl ; }
};

int main(){
    B *b = new D() ; 
    delete b ;
    return 0 ;
}

// 17 --- OUTPUT --- D

// WHICH OF THE FOLLOWING FALLS UNDER THE STATIC(COMPILE TIME) POLYMORPHISM
// A) TEMPLATES
// B) FUNCTION OVERLOADING
// C) OPERATOR OVERLOADING
// D) ALL OF THE ABOVE

// 18 --- OUTPUT --- D 

// WHAT ROLE A CONSTRUCTOR PLAYS IN THE CLASS ?
// A) CONSTRUCTS A NEW CLASS
// B) CONSTRUCTS A NEW OBJECT 
// C) CONSTRUCTS A NEW FUNCTION 
// D) INITIALIZES AN OBJECT

// 19 --- OUTPUT --- HELLO

class Foo{
public:
    Foo(int i=0){ _i = 1 ;}
    void f(){ cout << "Hello!" << endl ; }
private:
    int _i ; 
};

int main(){
    Foo *p = 0 ; // NULL POINTER OF FOO CLASS WE CAN ACCESS ANY FUNCTION IN FOO CLASS WITH THIS POINTER 
    p -> f() ; 
    return 0 ; 
}

 // 20 --- OUTPUT --- HELLO WORLD

class Foo{
public:
    int f(string str){
        cout << str << endl ;
        return 1 ;  
    }
};

int main(){
    int (Foo::*fptr) (string) = &Foo::f ; // *fptr = f  ---> fptr is pointer to class Foo and points to fucntion which has argument string 
    Foo obj ; 
    (obj.*fptr)("Hello") ;
    Foo* p = &obj ;
    (p -> *fptr)("World") ; 
    return 0 ; 
}
