
int main();
void displaybar();               ///declear parameter for below use
void account_bar();
void disadmin_bar();
void disusr_usr_bar();
void containgshr();
string userna_global="Not logged in...";  /// global variable

void gettime_date(){                                    ///return time and date
    time_t t=time(NULL);
    char tmstr[100];
    if(strftime(tmstr, sizeof(tmstr), "%A %c", localtime(&t))){
        cout<<setw(75)<<tmstr<<endl<<endl;
    }
}

void displaybar(){                                       ///display name-tag & time-date
    system("cls");
    cout<<setw(50)<<"DSE Simulator"<<endl<<endl;
    cout<<setw(52)<<"------------------"<<endl;

    cout<<setw(60)<<"User: "<<userna_global<<endl<<endl;
}

void login_admin(){                                     ///login panal for admin
    displaybar();
    cout<<endl<<setw(20)<<"Login Panel"<<endl<<endl;
    string usrid;
    cout<<"Admin ID:";
    cin>>usrid;
    if(usrid=="admin"){
       string pass ="";
       char ch;
       cout << "Enter password: ";
       ch = _getch();
       while(ch != 13){//character 13 is enter
          pass.push_back(ch);
          cout << '*';
         ch = _getch();
       }
       if(pass == "1234"){
          int o=33, p=33, q=33, r=33, s=33;
          for( ; ; ){
                displaybar();
                printf("\nAccess granted %c %c %c %c %c\n", q, o, p, r, s);
                //Sleep(2);
                if(q<46){
                    q++;
                }
                else if(q==46 && o<46)
                    o++;
                else if(q==46 && o==46 && p<46)
                    p++;
                else if(q==46 && o==46 && p==46 && r<46)
                    r++;
                else if(q==46 && o==46 && p==46 && r==46 && s<46)
                    s++;
                else
                    break;


          }
       }else{
          cout << "\nAccess aborted...\n";
          Sleep(800);
           login_admin();
       }
}else{
        cout<<"Wrong user ID"<<endl;
        Sleep(800);
        login_admin();
}
}

void dis_share(){                                       ///display single share searching
    {
                    displaybar();
                    int id, lot;
                    double price;
                    string name;
                    ifstream share_file("shares.txt");
                    int id_check;
                    bool flag=false;
                    cout<<"Enter share ID: ";
                    cin>>id_check;
                    cout<<endl<<"[Share ID]"<<setw(20)<<"[Trading Code]"<<setw(20)<<"[Face/per value]"<<setw(30)<<"[Last trading price]"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(share_file >> id >> name >> lot >> price){
                        if(id_check==id){
                            cout<<id<<setw(25)<<name<<setw(16)<<lot<<setw(30)<<price<<endl<<endl;
                            flag=true;
                        }

                    }
                    if(!flag)
                        cout<<endl<<id_check<<" Share id is not found in database"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    share_file.close();}
}

void dis_all_shares(){                                ///display all shares
                        {
                    displaybar();
                    int id, lot;
                    double price;
                    string name;
                    ifstream share_file("shares.txt");
                    cout<<endl<<"[Share ID]"<<setw(20)<<"[Trading Code]"<<setw(20)<<"[Face/per value]"<<setw(30)<<"[Last trading price]"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(share_file >> id >> name >> lot >> price){
                        cout<<id<<setw(25)<<name<<setw(16)<<lot<<setw(30)<<price<<endl<<endl;
                    }
                    cout<<"================================================================================"<<endl;
                    share_file.close();}
}

void disshr_info(){
    displaybar();
    cout<<"1) Share entry"<<endl<<endl;
    cout<<"2) Display share information"<<endl<<endl;
    cout<<"3) Display all share information"<<endl<<endl;
    cout<<"4) Delete all share information"<<endl<<endl;
    cout<<"5) Return admin menu"<<endl<<endl;
    int k;
                cin>>k;
                switch(k){
                case 1:
                    //share entry
                    {
                    ofstream sharefile;
                    sharefile.open("shares.txt", ios::app);
                    shares sh;
                    sh.read_share();
                        sharefile<<sh.get_shrid();
                        sharefile<<" ";
                        sharefile<<sh.get_shrname();
                        sharefile<<" ";
                        sharefile<<sh.get_shrlot();
                        sharefile<<" ";
                        sharefile<<sh.get_shrprice();
                        sharefile<<"\n";
                    sharefile.close();
                    }
                    cout<<endl<<"Successfully added share. Press [enter] to return"<<endl;
                    if(_getch())
                        disshr_info();
                case 2:
                    //display share information
                    dis_share();
                    cout<<endl<<"Press [enter] to return"<<endl;
                    if(_getch())
                        disshr_info();
                    break;
                case 3:
                    //display all share information
                    dis_all_shares();
                    cout<<endl<<"Press [enter] to return"<<endl;
                    if(_getch())
                        disshr_info();
                    break;
                case 4:
                    //delete all share information
                    {
                        ofstream sharefile;
                        sharefile.open("shares.txt");
                        sharefile.close();
                    }
                    cout<<endl<<"Successfully deleted shares. Press [enter] to return"<<endl;
                    if(_getch())
                        disshr_info();
                case 5:
                      //return main
                      disadmin_bar();
                      break;
                default:
                    cout<<endl<<"Wrong keyword [Enter] to continue"<<endl<<endl;
                    if(_getch())
                        disshr_info();
                    break;
    }
}

void dis_user(){
    {
                    displaybar();
                    int id, acc_no;
                    int pas;
                    string name;
                    ifstream userfile("userfile.txt");
                    int id_check;
                    bool flag=false;
                    cout<<"Enter User ID[2016xxxx]: ";
                    cin>>id_check;
                    cout<<endl<<"[User ID]"<<setw(25)<<"[Username]"<<setw(25)<<"[Account Number]"<<setw(20)<<"[Password]"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(userfile >> id >> name >> acc_no >> pas){
                        if(id_check==id){
                            cout<<id<<setw(26)<<name<<setw(23)<<acc_no<<setw(20)<<pas<<endl<<endl;
                            flag=true;
                            break;
                        }

                    }
                    if(!flag)
                        cout<<endl<<id_check<<" User id is not found in database"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    userfile.close();}
}


void dis_all_users(){
                    {

                    displaybar();

                    int id, acc_no;
                    int pas;
                    string name;
                    ifstream userfile("userfile.txt");
                    cout<<endl<<"[User ID]"<<setw(25)<<"[Username]"<<setw(25)<<"[Account Number]"<<setw(20)<<"[Password]"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(userfile >> id >> name >> acc_no >> pas){
                        cout<<id<<setw(26)<<name<<setw(23)<<acc_no<<setw(20)<<pas<<endl<<endl;
                    }
                    cout<<"================================================================================"<<endl;
                    userfile.close();
                    }
}

void market_info(){

    displaybar();
    cout<<"1) Display Current Market"<<endl<<endl;
    cout<<"2) Top 10 Shares"<<endl<<endl;
    cout<<"3) Return user menu"<<endl<<endl;
    int key;
    cin>>key;
    if(key==1){
        dis_all_shares();
        cout<<endl<<"Press [Enter] to return"<<endl;
        if(_getch())
            market_info();
    }
    else if(key==2){

        displaybar();
        cout<<endl<<setw(30)<<"Today's top 10 shares"<<endl<<endl;
        vector<double>pr;
        int id, lot;
        double price;
        string name;
        ifstream share_file;
        share_file.open("shares.txt");
        while(share_file >> id >> name >> lot >> price){
                        pr.push_back(price);                               ///pr[i]=price
                    }
        sort(pr.begin(), pr.end());
        reverse(pr.begin(), pr.end());
        int i=0;
        share_file.close();
        cout<<endl<<"[Share ID]"<<setw(20)<<"[Trading Code]"<<setw(20)<<"[Face/per value]"<<setw(30)<<"[Last trading price]"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(i<10){
                    share_file.open("shares.txt");
                    while(share_file >> id >> name >> lot >> price){
                        if(pr[i]==price)
                            cout<<id<<setw(25)<<name<<setw(16)<<lot<<setw(30)<<price<<endl<<endl;
                    }
                    i++;
                    share_file.close();
                    if(pr.size()<i)
                            break;
                    }
                    cout<<"================================================================================"<<endl;
                    cout<<endl<<"Press [Enter] to return"<<endl;
                    share_file.close();
                    if(_getch())
                        market_info();
    }
    else if(key==3)
        disusr_usr_bar();
    else{
        cout<<endl<<"Wrong keyword [Enter] to continue"<<endl<<endl;
        if(_getch())
            market_info();
    }
}


void user_login(){

    displaybar();
    cout<<endl<<setw(20)<<"Login Panel"<<endl<<endl;
    int usrid;
    cout<<"User ID [2016xxxx]:";
    cin>>usrid;
    int id, acc_no;
    string pas;
    string name;
    ifstream userfile("userfile.txt");
    bool check=false;
    string psrd;
    while(userfile >> id >> name >> acc_no >> pas){
                        if(id==usrid){
                            psrd=pas;
                            check=true;
                            break;
                        }
                    }
    if(check){
       string pass ="";
       char ch;
       cout << "Enter password: ";
       ch = _getch();
       while(ch != 13){//character 13 is enter
          pass.push_back(ch);
          cout << '*';
         ch = _getch();
       }
       if(pass == psrd){
            userna_global=name;
          int o=33, p=33, q=33, r=33, s=33;
          for( ; ; ){

                displaybar();
                printf("\nAccess granted %c %c %c %c %c\n", q, o, p, r, s);
                //Sleep(2);
                if(q<46){
                    q++;
                }
                else if(q==46 && o<46)
                    o++;
                else if(q==46 && o==46 && p<46)
                    p++;
                else if(q==46 && o==46 && p==46 && r<46)
                    r++;
                else if(q==46 && o==46 && p==46 && r==46 && s<46)
                    s++;
                else
                    break;


          }
       }else{
          cout << "\nAccess aborted...\n";
          Sleep(800);
           user_login();
       }
}else{
        cout<<"Wrong user ID"<<endl;
        Sleep(800);
        user_login();
}
}

void account(){                                         ///user account display

                    displaybar();
                    int id, acc_no;
                    string pas;
                    string name;
                    ifstream userfile("userfile.txt");
                    cout<<endl<<setw(45)<<"Profile information"<<endl<<endl;
                    cout<<"================================================================================"<<endl;
                    while(userfile >> id >> name >> acc_no >> pas){
                        if(userna_global==name){
                            cout<<"User ID: "<<id<<endl<<endl
                                  <<"User Name: "<<name<<endl<<endl
                                  <<"Account No: "<<acc_no<<endl<<endl
                                  <<"Password: "<<pas<<endl<<endl<<endl;
                            break;
                        }

                    }
                    cout<<"Press [Enter] to return";
                    if(_getch())
                        disusr_usr_bar();
}
void dis_news(){

      displaybar();
      ifstream newsfile;

      newsfile.open("news.txt");
      string news;
      while(newsfile){
        getline(newsfile, news);
        cout<<news<<"\n\n";
      }
      newsfile.close();
}

void newsfeed_bar(){

    displaybar();
    cout<<"1) Display current news feeds"<<endl<<endl;
    cout<<"2) Update news feeds"<<endl<<endl;
    cout<<"3) Return admin menu"<<endl<<endl;
    int key;
    cin>>key;
    if(key==1){
        dis_news();
        cout<<"Press [enter] to return"<<endl;
        if(_getch())
            newsfeed_bar();
    }else if(key==2){
        ofstream newsfile;
        newsfile.open("news.txt");
        string news="";
        string k="";
        int i=1;
        cout<<"Type news[-1] to exit:"<<endl;
         while(k!="-1"){
            cin>>k;
            if(k!="-1")
                news+=" "+k+" ";
            if(i%6==0)
                news+="\n";
            i++;
         }
         news+="\n";

        newsfile<<news;
        newsfile.close();
        newsfeed_bar();
    }else{
        disadmin_bar();
    }
}

void sell_share(){
    {
                    displaybar();
                    containgshr();
                    int id;
                    string name;
                    vector<string>vcname;
                    vector<int>vcid;
                    ifstream con_file("contain.txt");
                    int id_check;
                    bool flag=false;
                    cout<<"Enter share ID [-1] if no share available: ";
                    cin>>id_check;
                    int pp=0;
                    while(con_file >> name >> id){
                        if(id_check!=id){
                            vcname.push_back(name);
                            vcid.push_back(id);
                        }
                        if(id_check==id){
                            flag=true;

                        }
                    }
                    con_file.close();
                    if(!flag)
                        cout<<endl<<id_check<<" Share id is not found in database"<<endl<<endl;
                    cout<<"================================================================================"<<endl<<endl;
                    ofstream co_file;
                    co_file.open("contain.txt");
                    int l=0;
                    while(l<vcid.size()){
                        co_file<<vcname[l]<<" ";
                        co_file<<vcid[l]<<"\n";
                        l++;
                    }
                    co_file.close();
                    if(!flag){
                        cout<<endl<<"Press [Enter] to return"<<endl;
                        if(_getch())
                            disusr_usr_bar();
                    }

                    cout<<endl<<endl<<"Are you sure to sale this share ?"<<endl<<"1) yes"<<endl<<"2) No"<<endl;
                    int kp;
                    cin>>kp;
                    if(kp==1){
                        ofstream sellfile;
                        sellfile.open("sell.txt", ios::app);
                        sellfile<<userna_global<<" "<<id_check<<endl;
                        sellfile.close();
                        cout<<"Successfully requested for sale this share. Press [Enter] to return"<<endl;
                            if(_getch())
                                disusr_usr_bar();
                        }else{
                            disusr_usr_bar();
                        }
                }
}


void buy_shares(){
    displaybar();
    cout<<setw(30)<<"Requested selling shares"<<endl<<endl;
    int share_id[200];
    int i=0;
    int d;
    bool check=false;
    ifstream sellfile;
    string n;
    sellfile.open("sell.txt");
    while(sellfile>>n>>d){
        if(n!=userna_global){
            share_id[i]=d;
            check=true;
        i++;
        }
    }
    sellfile.close();
    ifstream sharefile;

    int j=0;
    int id, lot;
    string name;
    double price;
    cout<<endl<<"[Share ID]"<<setw(20)<<"[Trading Code]"<<setw(20)<<"[Face/per value]"<<setw(30)<<"[Last trading price]"<<endl<<endl;
    cout<<"================================================================================"<<endl;
    while(j<i){
            sharefile.open("shares.txt");

            while(sharefile>>id>>name>>lot>>price){
                    if(share_id[j]==id && name!=userna_global && check){
                    cout<<id<<setw(25)<<name<<setw(16)<<lot<<setw(30)<<price<<endl<<endl;
                    }

            }j++;
            sharefile.close();
    }

    if(!check){
        cout<<"No share is available to buy"<<endl<<endl;
    }
     cout<<"================================================================================"<<endl;
    if(!check){
        cout<<"Press [Enter] to return"<<endl;
        if(_getch())
            disusr_usr_bar();
    }
    cout<<"Enter share_id to buy share: ";
    int id_buy;
    cin>>id_buy;
    vector <string> vc_name;
    vector<int>vc_shid;
    sellfile.open("sell.txt");
    string nn;
    int iid;
    bool flag=false;
    while(sellfile>>nn>>iid){
        if(id_buy==iid)
                flag=true;
        if(id_buy!=iid){
            vc_name.push_back(nn);
            vc_shid.push_back(iid);
        }
    }
    sellfile.close();
    if(!flag){
        cout<<id_buy<<" Share is not available to buy now. Press [Enter] to return"<<endl;
        if(_getch())
            disusr_usr_bar();
    }

    i=0;
    cout<<"Are you sure to buy this share?"<<endl<<endl<<"1) Yes"<<endl<<endl<<"2) No"<<endl;
    int hh;
    cin>>hh;
    if(hh==1){
        ofstream sellsfile;
    sellsfile.open("sell.txt");
    while(i<vc_shid.size()){
        sellsfile<<vc_name[i]<<" ";
        sellsfile<<vc_shid[i]<<"\n";
        i++;
    }
    sellsfile.close();
    ofstream containfile;
    containfile.open("contain.txt", ios::app);
    containfile<<userna_global<<" "<<id_buy<<endl;
    containfile.close();
    cout<<"Successfully bought this share. Press [Enter] to return"<<endl;
                            if(_getch())
                                disusr_usr_bar();
    }else{
        disusr_usr_bar();
    }
}

void containgshr(){
    displaybar();
    cout<<setw(30)<<"Your shares:"<<endl<<endl;
    ifstream myshares;
    myshares.open("contain.txt");
    int sh_id, lot, id, shr_lot;
    double price;
    bool check=false;
    string hldrname, shrname;
    ifstream sharefile;
    cout<<endl<<"[Share ID]"<<setw(20)<<"[Trading Code]"<<setw(20)<<"[Face/per value]"<<setw(30)<<"[Last trading price]"<<endl<<endl;
    cout<<"================================================================================"<<endl;
    while(myshares>>hldrname>>sh_id){
        sharefile.open("shares.txt");
        while(sharefile>>id>>shrname>>shr_lot>>price){
            if(sh_id==id && userna_global==hldrname){
                    check=true;
                  cout<<id<<setw(25)<<shrname<<setw(16)<<shr_lot<<setw(30)<<price<<endl<<endl;
                  break;
            }
        }
        sharefile.close();
    }
    myshares.close();
    if(!check)
        cout<<"You donot have any shares"<<endl<<endl;
    cout<<"================================================================================"<<endl<<endl;
}


void disusr_adm_bar(){                                ///admin user information menu

    displaybar();
    cout<<"1) New user entry"<<endl<<endl;
    cout<<"2) Display user information"<<endl<<endl;
    cout<<"3) Display all user information "<<endl<<endl;
    cout<<"4) Delete all user information "<<endl<<endl;
    cout<<"5) Return admin menu"<<endl<<endl;
    int ko;
    cin>>ko;
                switch(ko){
                case 1:
                    //new user entry
                    {
                    ofstream userfile;
                    userfile.open("userfile.txt", ios::app);
                    user u;
                    u.read_newusr();
                    userfile<<u.get_usrid();
                    userfile<<" ";
                    userfile<<u.get_usrname();
                    userfile<<" ";
                    userfile<<u.get_accountno();
                    userfile<<" ";
                    userfile<<u.get_pass();
                    userfile<<"\n";
                    userfile.close();
                    }
                     cout<<endl<<"Your user id is: "<<user_id_fixed()<<" Please remember it for future login."<<endl;
                     cout<<endl<<"Successfully added user. Press [enter] to return"<<endl;
                    if(_getch())
                        disusr_adm_bar();
                        break;
                case 2:
                    //display user  information
                    dis_user();
                    cout<<"Press [enter] to return"<<endl;
                    if(_getch())
                        disusr_adm_bar();
                    break;
                case 3:
                    {       //display all user data
                        dis_all_users();
                        cout<<"Press [enter] to return"<<endl;
                        if(_getch())
                            disusr_adm_bar();
                    }
                    break;
                case 4:
                    //delete all user information
                      {
                        ofstream userfile;
                        userfile.open("userfile.txt");
                        userfile.close();
                        cout<<"Successfully deleted all user information. ";
                        cout<<"Press [enter] to return"<<endl;
                        if(_getch())
                            disusr_adm_bar();
                    }
                      break;
                case 5:
                    // return main
                    disadmin_bar();
                default:
                    cout<<"Wrong keyword"<<endl;
                    Sleep(500);
                    disusr_adm_bar();
                }
}

void disusr_usr_bar(){

    displaybar();
    cout<<"1) Account"<<endl<<endl;
    cout<<"2) Sale shares"<<endl<<endl;
    cout<<"3) Buy shares"<<endl<<endl;
    cout<<"4) My shares"<<endl<<endl;
    cout<<"5) Market highlights"<<endl<<endl;
    cout<<"6) Shares information"<<endl<<endl;
    cout<<"7) News feeds"<<endl<<endl;
    cout<<"8) Logout/Main menu"<<endl<<endl;
    int ko;
    cin>>ko;
                switch(ko){
                case 1:
                    //Account display
                    account();
                case 2:
                    //sell shares
                    sell_share();
                case 3:
                    // buy shares
                    buy_shares();
                case 4:
                    //containing shares
                    {
                    containgshr();
                    cout<<"Press [Enter] to return"<<endl;
                            if(_getch())
                                disusr_usr_bar();
                    }
                case 5:
                    market_info();
                    //Containing shares
                case 6:
                    //Shares information
                    displaybar();
                    dis_share();
                    cout<<"Press [enter] to return"<<endl;
                        if(_getch())
                            disusr_usr_bar();
                case 7:
                      //News feeds
                      {
                          dis_news();
                          cout<<"Press [enter] to return"<<endl;
                            if(_getch())
                                disusr_usr_bar();
                      }
                      break;
                case 8:
                    //return main
                    main();
                    break;
            }
}

void disadmin_bar(){    ///admin menu

    displaybar();
    cout<<"1) Share Information"<<endl<<endl;
    cout<<"2) Users Information"<<endl<<endl;
    cout<<"3) News feeds"<<endl<<endl;
    cout<<"4) Logout/Main menu"<<endl<<endl;
    int mo;
            cin>>mo;
            if(mo==1){
                disshr_info();

            }else if(mo==2){
                //user information by admin
                disusr_adm_bar();

            }else if(mo==4)
                    main();
            else if(mo==3)
                newsfeed_bar();
             else{
                cout<<"Wrong keyword for security logging out..."<<endl;
                Sleep(900);
                main();
             }
}
