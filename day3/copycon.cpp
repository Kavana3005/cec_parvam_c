#include<iostream>
#include<cstring>
using namespace std;
class student {
    public:
    char* name;
    int age;
    student(const char* n,int a){
        age = a;
        name=new char[strlen(n)+1];
        strcpy(name,n);                                                                                                                                             
    }
    student(const student& s){
        age = s.age;
        name=new char[strlen(s.name)+1];
        strcpy(name,s.name);                                                                                                                                             
        cout<<name<<" copy constructor called"<<endl;
    }
    void display(){
        cout<<name<<"("<<age<<")"<<endl;                    

    }  
       ~student(){
        delete[] name;
        
    }                                                                           
};
int main(){
    student s1("Alice",20);
    s1.display();
    student s2 = s1; // copy constructor called
    s2.display();
    s2.name[0] = 'p';
    cout<<"After modifying s2's name:"<<endl;           
     s1.display(); // s1's name should remain unchanged      
s2.display();
    return 0;                                                                   

}
   
