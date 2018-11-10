#include<bits/stdc++.h>

using namespace std;
class shares{
    static int share_id;
    string share_na;
    int share_lots;
    double share_price;
public:

    shares(string name, int lots, double pri): share_lots(lots), share_price(pri), share_na(name){
        share_id++;
    };
    shares():share_lots(0), share_price(0.00), share_na("none"){
        share_id++;
    };

    void display_shares(){
        cout<<setw(20)<<share_id<<setw(20)<<share_na<<setw(20)<<share_lots<<setw(20)<<share_price<<endl;
    }
    void read_share(){
        cout<<"Enter share name[Trading Code]: ";
        cin>>share_na;
        cout<<"Enter share lots: ";
        cin>>share_lots;
        cout<<"Enter share price: ";
        cin>>share_price;
    }
    void set_share(string name, int lot, double price){
        share_na=name;
        share_lots=lot;
        share_price=price;
    }

    int get_shrid(){return share_id;}
    int get_shrlot(){return share_lots;}
    string get_shrname(){return share_na;}
    double get_shrprice(){return share_price;}
};
    int share_id_fixed(){
    ifstream share_file("shares.txt");
                    int id, lot, k, i=0;
                    double price;
                    string name;
                    while(share_file >> id >> name >> lot >> price){
                                k=id;
                    }
                    if(k>1300 || k<1000)
                        k=1000;
                    share_file.close();
                return k;
                }

int shares::share_id=share_id_fixed();
