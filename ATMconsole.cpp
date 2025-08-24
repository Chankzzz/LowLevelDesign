#include <bits/stdc++.h>
using namespace std;

class account{
    string cardno;
    string pin;
    double balance;
    vector<string> transaction;
public:
    account(string c,string p,double b){
        cardno=c;
        pin=p;
        balance=b;
    }

    bool authentication(string c, string p){
        if(c== cardno && p==pin) return true;
        return false;
    }

    double getbalance(){
        return balance;
    }

    void deposit(double amt){
        balance=amt+balance;
        transaction.push_back("Deposited"+to_string(amt));
        cout<<"Deposited";
    }

    void withdrawl(double amt){
        if(amt>balance){
            cout<<"Insuffecient balance";
            return ;
        }
        balance=balance-amt;
        transaction.push_back("Withdrawn:"+to_string(amt));
        return ;
    }
    void printministatement(){
        cout<<"\n------Statement-----\n";
        if(transaction.empty()){
            cout<<"NO TRANSACTION";
        }
        else{
            for(auto &i:transaction){
                cout<<i<<"\n";
            }
        }
        cout<<"current balance: "<<balance<<"\n";

    }
};

int main(){
    vector<account> accounts={
        account("1234","1111",50000), 
        account("4567","2222",50000)
    };
    string card,pin;
    cout<<"Enter the card Number: \n";
    cin>>card;
    cout<<"Enter PIN \n";
    cin>>pin;
    account *loginpointer=nullptr;
    for(auto &acc:accounts){
        if(acc.authentication(card, pin)){
            loginpointer=&acc;
            break;
        }
    }
    if(!loginpointer){
        cout<<"Invalid pin";
        return 0;
    }

    int choice;
    do{
        cout << "\n===== ATM Menu =====\n";
        cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Mini Statement\n5. Exit\n";
        cout << "Enter choice: ";
        cin>>choice;
        switch(choice){        
        case 1:{
            cout<< "Balance" << loginpointer->getbalance() <<"\n";
            break;
        }
        case 2 :{
            double amt;
            cout<<"Enter Amount to Deposit";
            cin >> amt;
            loginpointer->deposit(amt);
            break;
        }
        case 3:{
            double amt;
            cout<<"Enter Amount to withdraw:";
            cin>> amt;
            loginpointer->withdrawl(amt);
            break;
        }
        case 4:{
            loginpointer->printministatement();
            break;
        }
        case 5:{
            cout<< "Thank you\n";
            break;
        }
        default:{
            cout<<"Invalid choice! \n";
            }
        }
    }while (choice!=5);
};

