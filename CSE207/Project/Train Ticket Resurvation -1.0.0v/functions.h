bool user_menu();
int main();
void admin_menu();

HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);  //global variable

void textattr(int color)
{
	SetConsoleTextAttribute(con, color);
}

void gettime_date(){                                    ///return time and date
    time_t t=time(NULL);
    char tmstr[100];
    if(strftime(tmstr, sizeof(tmstr), "%A %c", localtime(&t))){
        cout<<setw(75)<<tmstr<<endl<<endl;
    }
}





void displaybar(){                                       ///display name-tag & time-date

    system("cls");
    textattr(11);
    cout<<setw(50)<<"Train Ticket Reservation"<<endl<<endl;
    cout<<setw(52)<<"----------------------------"<<endl;
    gettime_date();
    cout<<setw(60)<<"User: "<<userna_global<<endl<<endl;
}


void gotoxy(int x,int y)
{
	COORD Coord;
	Coord.X=x;
	Coord.Y=y;

	SetConsoleCursorPosition(con,Coord);
}



char menu_dy(string *menu_list, int MaxNo_Menu){
    //


    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );

    int i,
      xpos = 10,
      ypos[MaxNo_Menu];
      int j=10;
      for(int i=0; i<MaxNo_Menu; i++){
        ypos[i] = j;
        j+=3;
      }

      for (i=0; i< MaxNo_Menu; ++i){
		gotoxy(xpos, ypos[i] );
		textattr(14);
//		printf("%s",menu_list[i] );
		cout<<menu_list[i];
	}

	i=0;
	while(1)
	{
		gotoxy(xpos, ypos[i]);
		textattr(12 );
//		printf("%s",menu_list[i] );

		cout<<menu_list[i];

		/* note : 72 -> UP button
			75 -> RIGHT button
            77 -> LEFT button
            80 -> DOWN button
		*/

	switch( _getch() )
    {
		case 72: if(i>0) {
       		gotoxy(xpos,ypos[i] );
            textattr(14);
//            printf("%s", menu_list[i] );
            cout<<menu_list[i];
            --i;
            }
            break;

		case 80: if(i< MaxNo_Menu-1 )
			{
       			gotoxy(xpos,ypos[i] );
                textattr(14);
//                printf("%s", menu_list[i] );
                cout<<menu_list[i];
                ++i;
                }
        break;

		case 13:
            for(int k=0; k<MaxNo_Menu; k++){
                if(i==k){
                    int chr=0;
                    gotoxy (10,1);
                    return 'A'+i;

                }
            }
            break;
	}
	}

}

    //main menu
int main_Menu(){
    displaybar();
    int key;
    string menu_1[]={"User", "Admin", "Exit"};
    char ch=menu_dy(menu_1, 3);
    if(ch=='A') return 1;
    else if(ch=='B') return 2;
    else if(ch=='C') return 99;

    cin>>key;
    return key;
}


bool admin_login(string admin_id, string admin_pass){
    displaybar();
    cout<<endl<<setw(20)<<"Login Panel"<<endl<<endl;
    string usrid;
    cout<<"Admin ID: ";
    textattr(15);
    cin>>usrid;
    textattr(11);
    if(usrid==admin_id){
       string pass ="";
       char ch;
       cout << "Enter password: ";
       textattr(15);
       ch = _getch();
       while(ch != 13){//character 13 is enter
          pass.push_back(ch);
          cout << '*';
         ch = _getch();
       }
       textattr(11);
       if(pass == admin_pass){
            userna_global="admin";
          int o=33, p=33, q=33, r=33, s=33;
          textattr(10);
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
          admin_menu();
       }else{
           textattr(12);
          cout <<endl<< "\nAccess aborted...\n";
          Sleep(800);
          return false;

       }
}else{
        textattr(12);
        cout<<endl<<"Wrong user ID"<<endl;
        Sleep(800);
        return false;
}
return true;

}


bool user_login(){

    displaybar();
    cout<<endl<<setw(20)<<"Login Panel"<<endl<<endl;
    string usrid;
    cout<<"User ID: ";
    textattr(15);
    cin>>usrid;
    string fn_no;
    string id;
    string pas;
    string name;
    ifstream userfile("userfile.txt");
    bool check=false;
    string psrd;
    while(userfile >> id >> pas >>fn_no){
                            if(id==usrid){
                            psrd=pas;
                            check=true;
                            break;
                        }
                    }
    if(check){
       string pass ="";
       char ch;
       textattr(11);
       cout << "Enter password: ";
       textattr(15);
       ch = _getch();
       while(ch != 13){//character 13 is enter
          pass.push_back(ch);
          cout << '*';
         ch = _getch();
       }

       if(pass == psrd){
            userna_global=usrid;
          int o=33, p=33, q=33, r=33, s=33;
          textattr(10);
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
          userfile.close();
          return true;
          textattr(11);
       }else{
        textattr(12);
          cout << endl<<"\nAccess aborted...\n";
          Sleep(800);
          userfile.close();
          user_menu();
       }
}else{
        textattr(12);
        cout<<"Wrong user ID"<<endl;
        Sleep(800);
          userfile.close();
        user_menu();
    }
}

void user_reg(){
    displaybar();
    string usr_id, usr_pass, usr_moNo;
    cout<<endl<<setw(20)<<"Create New Account"<<endl<<endl;
    cout<<"Enter User ID: ";
    textattr(15);
    cin>>usr_id;
    textattr(11);
    cout<<"Enter Password: ";
    textattr(15);
    cin>>usr_pass;
    textattr(11);
    cout<<"Enter Mobile Number: ";
    textattr(15);
    cin>>usr_moNo;
    textattr(11);
    ofstream userfile("userfile.txt", ios::app);
    userfile<<usr_id<<" "<<usr_pass<<" "<<usr_moNo<<endl;
    userfile.close();
    system("cls");
    displaybar();
    cout<<endl<<endl;
    textattr(10);
    cout<<"Registration Completed"<<endl;
    Sleep(700);
}




bool print_tickets(string user_name, Train t_na, int seats){
    displaybar();
    cout<<endl<<endl<<endl<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<"|          Bangladesh Railway           |"<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<"| Train Name: "<<setw(27)<<t_na.t_name+" |"<<endl;
    cout<<"| Train ID: "<<setw(29)<<t_na.t_id+" |"<<endl;
    cout<<"|---------------------------------------|"<<endl;
    cout<<"|       Departure Time Per Station      |"<<endl;
    rep(i, 0, t_na.t_stations.size()){
        cout<<"| "<<t_na.t_stations[i]+": "<<setw(37-t_na.t_stations[i].size())<<t_na.t_time_mp[t_na.t_stations[i]]+" |"<<endl;
    }
    cout<<"|---------------------------------------|"<<endl;
    cout<<"| Total Seats: "<<setw(24)<<seats<<" |"<<endl;
    cout<<"| Total Amount: "<<setw(9)<<"[ "<<t_na.fares<<" x "<<seats<<"] = "<<seats*t_na.fares<<" |"<<endl;
    cout<<"|---------------------------------------|"<<endl;


    cout<<endl<<endl;
    cout<<"Are You Sure To Buy ? [Y]Yes  [N]No";
    char choice = _getch();
    if(choice=='Y' or choice=='y'){
        ofstream ticket_file("User_tickets/"+user_name+"_tickets.txt", ios::app);
        ticket_file<<"|---------------------------------------|"<<endl;
        ticket_file<<"|          Bangladesh Railway           |"<<endl;
        ticket_file<<"|---------------------------------------|"<<endl;
        ticket_file<<"| Train Name: "<<setw(27)<<t_na.t_name+" |"<<endl;
        ticket_file<<"| Train ID: "<<setw(29)<<t_na.t_id+" |"<<endl;
        ticket_file<<"|---------------------------------------|"<<endl;
        ticket_file<<"|       Departure Time Per Station      |"<<endl;
        rep(i, 0, t_na.t_stations.size()){
            ticket_file<<"| "<<t_na.t_stations[i]+": "<<setw(37-t_na.t_stations[i].size())<<t_na.t_time_mp[t_na.t_stations[i]]+" |"<<endl;
        }
        ticket_file<<"|---------------------------------------|"<<endl;
        ticket_file<<"| Total Seats: "<<setw(24)<<seats<<" |"<<endl;
        ticket_file<<"| Total Amount: "<<setw(9)<<"[ "<<t_na.fares<<" x "<<seats<<"] = "<<seats*t_na.fares<<" |"<<endl;
        ticket_file<<"|---------------------------------------|"<<endl;
        ticket_file.close();
        displaybar();
        textattr(10);
        cout<<endl<<endl<<"\tYou have successfully buy"<<endl;
        cout<<endl<<"\tHappy Journey"<<endl;
        Sleep(600);
        return true;
    }
    else
        return false;
}


void buy_tickets(){
    displaybar();
    string _from, _to;
    set<string>all_sta;
    string tr_na, tr_id, tr_st, tr_ti;
    int tr_se, n, tak;
    vector<string>tr_sta;
    ifstream Trainfile ("trainFile.txt");
    Queue<Train>tr_que;
    int ind_t=0;
    while(Trainfile>>tr_na>>tr_id>>tr_se>>n>>tak){
            tr_sta.clear();
            int no=n;
            map<string, string>time_mp;
        while(n--){
            Trainfile>>tr_st>>tr_ti;
            all_sta.insert(tr_st);
            tr_sta.pb(tr_st);
            time_mp[tr_st]=tr_ti;
        }
        Train T1(tr_na, tr_id, tr_se, no, tak, tr_sta, time_mp);
        T1.t_numOfStaions=no;
        T1.fares=tak;
        ind_t++;
        tr_que.enqueue(T1);
        tr_sta.clear();
    }
    Trainfile.close();
    string from_menu[100];
    int i=0;
    for (set<string>::iterator it=all_sta.begin(); it!=all_sta.end(); ++it){
        from_menu[i]=*it;
        i++;
    }
    cout<<"Select The Station From: ";
    char ch = menu_dy(from_menu, i-1);

    displaybar();
    cout<<"Select Destination: ";
    cout<<endl<<endl<<endl<<endl<<setw(60)<<"From: "<<from_menu[ch-'A'];
    char ch2 = menu_dy(from_menu, i-1);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<setw(60)<<"To: "<<from_menu[ch2-'A'];
    //check fare
    string src_t = from_menu[ch-'A'];
    string des_t = from_menu[ch2-'A'];
    Sleep(500);

    queue<Train>T_find;
    queue<Train>tra_q;
    while(!tr_que.isEmpty()){
        Train T3 = tr_que.front();
        tr_que.dequeue();
        tra_q.push(T3);
        bool check_src=false, check_des=false;
        rep(i, 0, T3.t_stations.size()){
            if(src_t==T3.t_stations[i])
                check_src=true;
            if(T3.t_stations[i]==des_t)
                check_des=true;
        }
        if(check_src and check_des)
            T_find.push(T3);
    }

    displaybar();
    textattr(10);
    cout<<"ID"<<setw(5)<<"|"<<setw(15)<<"Train Name"<<setw(24)<<"|  Departure Station"<<setw(20)<<"|  Departure Time"<<setw(20)<<"|  Available Seats"<<endl<<endl;
    while(!T_find.empty()){
        Train T2 = T_find.front();
        T_find.pop();
        textattr(12);
        cout<<T2.t_id<<setw(3)<<"|"<<setw(16)<<T2.t_name<<endl;;
        rep(i, 0, T2.t_stations.size()){
                textattr(11);
                if(src_t==T2.t_stations[i])
                    textattr(13);
                if(des_t==T2.t_stations[i])
                    textattr(13);
                if(T2.t_stations[i].size()>7){
                    cout<<setw(40)<<T2.t_stations[i]<<setw(20)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                }else if(T2.t_stations[i].size()<5){
                    cout<<setw(40)<<T2.t_stations[i]<<setw(21-T2.t_stations[i].size()+i)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                }else
                    cout<<setw(40)<<T2.t_stations[i]<<setw(25-T2.t_stations[i].size()+i)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                if(!i)
                    cout<<T2.t_seats<<endl;
                else{
                    cout<<setw(3)<<endl;
                }
                textattr(11);
        }
        cout<<endl;
    }
    string buy_id;
    int numOfseats;
    cout<<"Enter Train ID To Buy: ";
    cin>>buy_id;
    cout<<"Enter Number OF Seats: ";
    cin>>numOfseats;

    ofstream TrainFile ("trainFile.txt");
    while(!tra_q.empty()){
        Train T2=tra_q.front();
        tra_q.pop();
        if(T2.t_id==buy_id){
            bool chkkk=print_tickets(userna_global, T2, numOfseats);
            if(chkkk)
                T2.t_seats-=numOfseats;
        }
        TrainFile<<T2.t_name<<" "<<T2.t_id<<" "<<T2.t_seats<<" "<<T2.t_numOfStaions<<" "<<T2.fares<<endl;
        int i= 0;
        while(i<T2.t_stations.size()){
            TrainFile<<T2.t_stations[i]<<" "<<T2.t_time_mp[T2.t_stations[i]]<<endl;
            i++;
        }
    }
}

void display_all_tickets(){
    ifstream Ticket_file("User_tickets/"+userna_global+"_tickets.txt");
    string line;
    cout<<endl<<endl<<endl;
    cout<<endl<<endl<<endl;
    int k=0;
    while(getline(Ticket_file, line)){
        cout<<"\t\t"<<line<<endl;
        k++;
    }
    cout<<endl;
    Ticket_file.close();
    if(k<3)
        cout<<"No Tickets Available"<<endl<<endl;
    cout<<"Press Any To Return ";
    _getch();
}

void account_info(){
    displaybar();
    textattr(10);
    string usr_na, mobl, pass;
    ifstream userfile("userfile.txt");
    while(userfile>>usr_na>>pass>>mobl){
        if(usr_na==userna_global) break;
    }
    cout<<"Username: "<<usr_na<<endl;
    cout<<"Mobile Number: "<<mobl<<endl;
    cout<<endl<<"Press Any To Return ";
    _getch();
}

void user_nav_menu(){
    string usr_nav[]={"Buy Tickets", "Check Own Tickets", "Account Info", "Logout"};
    displaybar();
    char ch = menu_dy(usr_nav, 4);
    if(ch=='A'){
        //Buy Tickes
        buy_tickets();
        user_nav_menu();
    }else if(ch=='B'){
        //Check own
        display_all_tickets();
        user_nav_menu();
    }else if(ch=='C'){
        //Cancel Tickets
        account_info();
        user_nav_menu();
    }else if(ch=='C'){
        main();
    }
}

bool user_menu(){
    string usr_menu[] = {"Login", "Registration New Account", "Back To Main Menu"};

    displaybar();
    char ch = menu_dy(usr_menu, 3);
    if(ch=='A'){
        //login panel
        bool checker=user_login();
        user_nav_menu();
        if(checker){
            //login success
        }
    }else if(ch=='B'){
        //Registration new account
        user_reg();

    }else if(ch=='C') return true;

}

void add_train(){
    displaybar();
    string t_n, t_id, t_st, t_ti;
    int t_se, t_sop;
    textattr(11);
    cout<<"Train Name: ";
    textattr(15);
    cin>>t_n;
    textattr(11);
    cout<<"Train ID: ";
    textattr(15);
    cin>>t_id;
    textattr(11);
    cout<<"Available Seats: ";
    textattr(15);
    cin>>t_se;
    textattr(11);
    cout<<"Number of Stoppage: ";
    textattr(15);
    cin>>t_sop;
    textattr(11);
    cout<<"Enter Station Root and time: [-1 to end]"<<endl;

    ofstream Trainfile("trainFile.txt", ios::app);

    Trainfile<<endl<<t_n<<" "<<t_id<<" "<<t_se<<" "<<t_sop<<endl;

    while(t_sop--){
        textattr(15);
        cin>>t_st>>t_ti;
        debug(t_sop);
        Trainfile<<t_st<<" "<<t_ti<<endl;

    }
    Trainfile.close();
    displaybar();
    cout<<"Successfully Added Train"<<endl;
    Sleep(700);
}

void edit_time(){
    displaybar();
    string edi_tr_id, tr_na, tr_id, tr_st, tr_ti;
    int tr_se, n, tak;
    vector<string>tr_sta;
    cout<<"Enter Train ID: ";
    cin>>edi_tr_id;
    ifstream Trainfile ("trainFile.txt");
    Stack<Train>tr_stk;

    while(Trainfile>>tr_na>>tr_id>>tr_se>>n>>tak){
            tr_sta.clear();
            int no=n;
        map<string, string>mp;
        while(n--){
            Trainfile>>tr_st>>tr_ti;
            tr_sta.pb(tr_st);
            mp[tr_st]=tr_ti;
        }
        Train T1(tr_na, tr_id, tr_se, no, tak, tr_sta, mp);
        T1.t_numOfStaions=no;
        T1.fares=tak;
        tr_stk.push(T1);
        tr_sta.clear();
    }
    Trainfile.close();

    ofstream Trainfile2("trainFile.txt");
    while(!tr_stk.isEmpty()){
        Train T2 = tr_stk.Top();
        tr_stk.pop();
        if(T2.t_id==edi_tr_id){
            textattr(12);
            cout<<"Train Name: "<<T2.t_name<<endl;
            cout<<"Train Seats: "<<T2.t_seats<<endl;
            cout<<"Edit Seats: ";
            textattr(15);
            cin>>T2.t_seats;
            textattr(10);
            cout<<"Stations"<<setw(15)<<"| "<<"Departure Time"<<setw(15)<<"| "<<"New Departure Time"<<endl<<endl;
            int ind=0;
            while(ind<T2.t_stations.size()){
                cout<<T2.t_stations[ind]<<setw(23-T2.t_stations[ind].size())<<"| "<<T2.t_time_mp[T2.t_stations[ind]]<<setw(22)<<"| ";
                textattr(11);
                cin>>T2.t_time_mp[T2.t_stations[ind]];
                textattr(10);
                ind++;
            }
        }
        Trainfile2<<T2.t_name<<" "<<T2.t_id<<" "<<T2.t_seats<<" "<<T2.t_numOfStaions<<" "<<T2.fares<<endl;
        int i= 0;
        while(i<T2.t_stations.size()){
            Trainfile2<<T2.t_stations[i]<<" "<<T2.t_time_mp[T2.t_stations[i]]<<endl;
            i++;
        }
    }

    textattr(10);
    cout<<"Successfully Edited"<<endl;
    Sleep(600);
}

void print_ava_seats(){
    displaybar();
    string tr_na, tr_id, tr_st, tr_ti;
    int tr_se, n, tak;
    vector<string>tr_sta;
    ifstream Trainfile ("trainFile.txt");
    Queue<Train>tr_que;

    while(Trainfile>>tr_na>>tr_id>>tr_se>>n>>tak){
            tr_sta.clear();
            int no=n;
        map<string, string>mp;
        while(n--){
            Trainfile>>tr_st>>tr_ti;
            tr_sta.pb(tr_st);
            mp[tr_st]=tr_ti;
        }
        Train T1(tr_na, tr_id, tr_se, no, tak, tr_sta, mp);
        T1.t_numOfStaions=no;
        T1.fares=tak;
        tr_que.enqueue(T1);
        tr_sta.clear();
    }
    Trainfile.close();
    textattr(10);
    cout<<"ID"<<setw(5)<<"|"<<setw(15)<<"Train Name"<<setw(24)<<"|  Departure Station"<<setw(20)<<"|  Departure Time"<<setw(20)<<"|  Available Seats"<<endl<<endl;
    while(!tr_que.isEmpty()){
        Train T2 = tr_que.front();
        tr_que.dequeue();
        textattr(12);
        cout<<T2.t_id<<setw(3)<<"|"<<setw(16)<<T2.t_name<<endl;;
        rep(i, 0, T2.t_stations.size()){
                textattr(11);
                if(T2.t_stations[i].size()>7){
                    cout<<setw(40)<<T2.t_stations[i]<<setw(20)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                }else if(T2.t_stations[i].size()<5){
                    cout<<setw(40)<<T2.t_stations[i]<<setw(21-T2.t_stations[i].size()+i)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                }else
                    cout<<setw(40)<<T2.t_stations[i]<<setw(25-T2.t_stations[i].size()+i)<<T2.t_time_mp[T2.t_stations[i]]<<setw(15);
                if(!i)
                    cout<<T2.t_seats<<endl;
                else{
                    cout<<setw(3)<<endl;
                }
        }
        cout<<endl;
    }
    cout<<endl<<endl<<"Press Enter To Return"<<endl;
    getch();
}


void admin_menu(){
    if(userna_global=="Not logged in...") return;
    string adm_menu[]={"Add A New Train", "Edit Time Table & Seats", "Check Schedule", "Add New User", "Logout"};
    displaybar();
    char ch = menu_dy(adm_menu, 5);
    if(ch=='A'){
        //add new train
        add_train();
        admin_menu();
    }else if(ch=='B'){
        //edit time table
        edit_time();
        admin_menu();
    }else if(ch=='C'){
        //available seats
        print_ava_seats();
        admin_menu();
    }else if(ch=='D'){
        //add new user
        user_reg();
    }else if(ch=='E'){
//        logout
        main();
    }
}



