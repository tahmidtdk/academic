void display_grid();
bool nqueen(int col);
void print_navbar(){
    system("cls");
    textattr(11 );
    cout<<setw(50)<<"N - Queens"<<endl;
}


int main_menu(){

        print_navbar();
        string menu[] = { "Solve N Queens", "Exit"};
        char key = menu_dy(menu, 2);\
        if(key=='A'){
        //Solve N Queens algo
        print_navbar();
        cout<<"Enter the Size of Board: ";
        cin>>board_size;
        cout<<"\n\n";
        nqueen(0);
            display_grid();
        }
        else if(key=='B'){
            //exit
          return -1;
        }
}


void display_grid(){
    print_navbar();
    ofstream myfile;
    myfile.open ("output.txt");
    for(int i=0; i<board_size; i++){
        for(int j=0; j<board_size; j++){
            myfile <<grid[i][j]<<" ";
            cout <<grid[i][j]<<" ";
        }
        myfile <<endl;
        cout <<endl;
    }
    myfile.close();
    cout<<endl<<endl<<"The board is saved in file!!!\nEnter to return ";
    _getch();
}

bool isSafe(int row, int col){

    for (int i = 0; i < col; i++)
        if (grid[row][i])
            return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (grid[i][j])
            return false;
    for (int i=row, j=col; j>=0 && i<board_size; i++, j--)
        if (grid[i][j])
            return false;
    return true;
}

bool nqueen(int col){
    if(col>=board_size)
        return true;

    for(int i=0; i<board_size; i++){
        if(isSafe(i, col)){
            grid[i][col]=1;
            if(nqueen(col+1))
                return true;

            grid[i][col]=0;
        }
    }
    return false;
}
