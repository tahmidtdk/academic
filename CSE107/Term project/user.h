class user{
    static int user_id;
    string usr_name;
    int account_no;
    string pass;
    //int share_id[100];
public:
    user(string na, int acc, string pa):usr_name(na), account_no(acc), pass(pa){
        user_id++;
    }
    user():usr_name("None"), account_no(0), pass(" "){
        user_id++;
    }
    void read_newusr(){
    cout<<"Enter you user name: ";
    cin>>usr_name;
    cout<<"Enter your account no: ";
    cin>>account_no;
    cout<<"Enter your password: ";
    cin>>pass;
    }
    string get_usrname(){return usr_name;}
    int get_accountno(){return account_no;}
    string get_pass(){return pass;}
    int get_usrid(){return user_id;}

    void display_user(){
        cout<<user_id<<setw(30)<<usr_name<<setw(28)<<account_no<<setw(30)<<pass<<endl;
    }

};

    int user_id_fixed(){
    ifstream userfile("userfile.txt");
                    int id, lot, k;
                    double price;
                    string name;
                    while(userfile >> id >> name >> lot >> price){
                                k=id;
                    }
                    if(k>20160300 || k<20160000)
                        k=20160000;
                    userfile.close();
                return k;
                }

int user::user_id=user_id_fixed();

