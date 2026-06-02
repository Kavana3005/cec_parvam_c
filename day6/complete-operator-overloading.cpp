#include<iostream>
#include<string>
using namespace std;
class animal{
    public:
    virtual void speak(){
        cout<<"animal makes a sound"<<endl;
    }
    void eat (){
        cout<<"animal eats food"<<endl;
    }
    virtual ~animal() {}
};
class dog : public animal{
    public:
    void speak() override {
        cout<<"dog barks:woof"<<endl;
    }

    void eat() {
        cout<<"dog eats kibble "<<endl;
    }
};
class cat:public animal{
    public:
    void speak() override {
        cout<<"cat meows:meow!"<<endl;
    }
};
int main(){
animal* animals[3];
animals[0]=new animal();
animals[1]=new dog();
animals[2]=new cat();
cout<<"====virtual function(polymorphism)===="<<endl;
for (int i =0;i < 3;i++){
    animals[i]->speak();
}
cout<<"\n====non-virtual function (not polymorphic)===="<<endl;
for (int i =0;i < 3;i++){
    animals[i]->eat();
}
for (int i =0;i < 3;i++){
    delete animals[i];
}
return 0;
}




