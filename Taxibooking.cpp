#include <bits/stdc++.h>

using namespace std;

struct trip
{
    int bookingId;
    int customerID;
    char from;
    char to;
    int pickuptime;
    int droptime;
    int amount;
};

struct Taxi
{
    int id;
    char location;
    int freetime;
    int earning;
    vector<trip> trips;

    Taxi(int i){
        id=i;
        location='A';
        freetime=0;
        earning=0;
    }
};

int traveltimehours(char a,char b){
    return abs(a-b)*1;
};


// int distance
int choosetaxi(vector<Taxi>& taxies,char pickup,int pickupTime){
    int best=-1;
    int mindistance=INT_MAX;
    int minearning=INT_MAX;
   
    for(int i=0;i<taxies.size();i++){
        Taxi &t=taxies[i];
        int reachtime=t.freetime+traveltimehours(t.location,pickup);
        if (reachtime>pickupTime) continue;
        int dist=abs(t.location-pickup);
        if(dist<mindistance || (dist==mindistance && t.earning<minearning) ||  (dist==mindistance && t.earning==minearning && t.id<taxies[best].id)){
            best=i;
            mindistance=dist;
            minearning=t.earning;
        }
    }
    return best;
}

int distanceINkm(char from,char to){
    return abs(from-to)*15;
}
int calculateflare(int km){
    if(km<=5) return 100;
    return 100+(km-5)*10;
}
int travelTimeInHours(char from,char to){
    return abs(from-to)*1;
}
void printTaxiDetails(vector<Taxi>& taxies){
    for(auto &t :taxies){
        cout<<"Taxi-"<<t.id<<"Total Earnings: Rs. "<<t.earning<<"\n";  
        for(auto &tr :t.trips){
            cout<<tr.bookingId<<"\t";
            cout<<tr.customerID<<"\t";
            cout<<tr.from<<"\t";
            cout<<tr.to<<"\t";
            cout<<tr.pickuptime<<"\t";
            cout<<tr.droptime<<"\t";
            cout<<tr.amount<<"\t\n";
        }
        cout<<"---------------------\n";
    }
}


int main() {
    int n=4;
    vector<Taxi> taxies;
    for(int i=1;i<=n;i++){
        taxies.push_back(Taxi(i));
    }
    int bookingId=1;
    while(true){
        cout<<"\n 1.booking a taxi. \n 2.Display taxi Details \n 3.exit \n choice: \n";
        int ch;cin>>ch;

        if(ch==3)break;
        if(ch==1) {
            int cusID,pickuptiming;
            char from,to;
            cout<<"Customer Id: ";cin>>cusID;
            cout<<"Pickup Time: ";cin>>pickuptiming;
            cout<<"From: ";cin>>from;
            cout<<"To: ";cin>>to;
            int idx= choosetaxi(taxies,from,pickuptiming);
            if(idx==-1){
                cout<<"no Taxi can be alloated.\n";
                continue;
            }
            Taxi &t=taxies[idx];
            int km=distanceINkm(from,to);
            int fare=calculateflare(km);
            int dropTime=pickuptiming + travelTimeInHours(from,to);

            t.location=to;
            t.freetime=dropTime;
            t.earning+=fare;
            
            trip tr{bookingId,cusID,from,to,pickuptiming,dropTime,fare};
            t.trips.push_back(tr);
            bookingId++;
            cout<<"Taxis can Be allocated. \n";
            cout<<"Taxi -"<<t.id<<"is allotted";
        }   
        if(ch==2)
        {
        printTaxiDetails(taxies);   
        }
    }    
   
    return 0;
}