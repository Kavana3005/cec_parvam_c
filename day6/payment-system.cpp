#include<iostream>
#include<string>
#include<vector>
using namespace std;
class payment{
    protected:
     double amount;
     string transactionid;
    public:
    payment(double amt,string id):amount(amt),transactionid(id){}
    virtual void process()=0;
    virtual string gettype() const =0;
    virtual ~payment() {}
};
class creditcardpayment : public payment{
    private:
    string cardnumber;
    public:
    creditcardpayment(double amt,string id,string card)
    :payment(amt,id),cardnumber(card){}
    void process() override {
     cout<<" processing credit card payment of $"<<amount<<endl;
    cout<<"card ending in :"<<cardnumber.substr(cardnumber.length() - 4)<< endl;
    cout<<"transaction :"<<transactionid<<"-approved"<<endl;
}
    
string gettype() const override {
    return "credit card";
}
};
class paypalpayment : public payment{
    private:
    string email;
    public:
    paypalpayment(double amt,string id,string e)
    :payment(amt,id),email(e){}
    void process() override {
        cout<<"processing paypal payment of $"<<amount<<endl;
        cout<<"paypal account:"<<email<<endl;
        cout<<"transaction id:"<<transactionid<<"-approved"<<endl;
    }
    string gettype() const override {
        return "paypal";
    }
};
class cryptocurrencypayment : public payment{
    private:
    string walletadderess;
    public:
    cryptocurrencypayment(double amt,string id,string wallet)
    :payment(amt,id),walletadderess(wallet){}
    void process() override {
        cout<<"processing cryptocurrency payment of $"<<amount<<endl;
        cout<<"wallet address:"<<walletadderess.substr(0,10)<<"..."<<endl;
        cout<<"transaction id:"<<transactionid<<"-confirmed"<<endl;
    }
    string gettype() const override {
        return "cryptocurrency";
    }
};
int main() {
vector<payment*> payments;
payments.push_back(new creditcardpayment(100.0,"txn12345","1234-5678-9012-3456"));
payments.push_back(new paypalpayment(50.0,"txn67890","arjun@email.com"));
payments.push_back(new cryptocurrencypayment(200.0,"txn54321","1A2b3C4d5E6f7G8h9I0j"));
for (payment* p : payments){
    cout<< "\n==="<<p->gettype() <<"==="<<endl;
    p->process();
}
for (payment* p : payments){
    delete p;
}
return 0;
}

    
        
        



