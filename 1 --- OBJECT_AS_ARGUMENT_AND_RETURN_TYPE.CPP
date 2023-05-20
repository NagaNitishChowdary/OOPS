#include<bits/stdc++.h>
#define nline "\n" ;
using namespace std ;

class myClass{
    public : 
        int height, weight , size ;
        
        // OBJECT AS AN ARGUMENT 
        void add(myClass c) {
            height = height + c.height ; 
            weight = weight + c.weight ; 
            size = size + c.size ; 
        } 

        // OBJECT AS AN RETURN TYPE 
        myClass add(myClass c1,myClass c2){
            myClass c3 ;
            c3.height = c1.height + c2.height ; 
            c3.weight = c1.weight + c2.weight ; 
            c3.size = c1.size + c2.size ; 
            return c3 ; 
        }
};

int main(){
    myClass myObj1 ;
    myObj1.height = 56 ;
    myObj1.weight = 50 ;
    myObj1.size = 10 ; 

    myClass myObj2 ;
    myObj2.height = 57 ; 
    myObj2.weight = 75 ;
    myObj2.size = 13 ; 

    myObj2.add(myObj1) ; 

    cout << myObj1.height << " " << myObj1.weight << " " << myObj1.size << endl ; 
    cout << myObj2.height << " " << myObj2.weight << " " << myObj2.size << endl ; 

    myClass myObj3 ;
    myObj3 = myObj3.add(myObj1,myObj2) ;
    cout << myObj3.height << " " << myObj3.weight << " " << myObj3.size << endl ; 

    return 0 ; 
}
