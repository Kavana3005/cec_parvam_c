#include<iostream>
#include<string>
using namespace std;
template <typename t>
t getmax(t a, t b){
    return (a> b)? a : b;
}
template <typename t, typename u>
auto add(t a,u b)->decltype(a+b){
    return(a+b);
}
int main(){
    cout<<"max of 10 and 20:"<<getmax(10,20)<<endl;
    cout<<"max of 3.14 and 2.71:"<<getmax(3.14,2.71)<<endl;
    cout<<"max of 'a',and 'z':"<<getmax('a','z')<<endl;
    cout<<"max (explicit double):"<<getmax<double>(5,7.5)<<endl;
    cout<<"add int + double:"<<add(10,3.5)<<endl;
    cout<<"add  string +string:"<<add(to_string(42),to_string(100))<<endl;
    return 0;
}
