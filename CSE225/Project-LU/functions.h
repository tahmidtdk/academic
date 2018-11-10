

void bar(){
    system("cls");
    cout<<"                               Equation Solver"<<endl;
    cout<<"                      Triangular Factorisation Methods [LU]"<<endl;
    cout<<"                    ========================================="<<endl;bl;bl;
}

int nav_bar(){
    bar();
    cout<<"\t1) Input Equations"<<endl;bl;
    cout<<"\t2) Print Equations As Matrix"<<endl;bl;
    cout<<"\t3) Triangular Factorisation"<<endl;bl;
    cout<<"\t0) Exit"<<endl;bl;
    int key;
    cin>>key;
    return key;
}


void debug_mat(double mat[row_col_sz][row_col_sz], string str){
    bar();
    cout<<"\t"<<str<<" Matrix :"<<endl;bl;
    rep(ro, 0, eqn_no){
           cout<<"\t";
            rep(co, 0, eqn_no){
                pf("%.2f  ", mat[ro][co]);
            }bl;
        }bl;bl;
}

void input_equation(){
    bar();
    memset(matrix, 0, sizeof(matrix));
    cout<<"Number of Equations: ";
    cin>>eqn_no;
//    fli();
    if(eqn_no){
            cout<<"Enter the Equations as matrix: \n";
        rep(ro, 0, eqn_no){
            rep(co, 0, eqn_no+1){
                cin>>matrix[ro][co];
            }
        }
    }
}

void print_matrix(){
    bar();
    if(eqn_no){
        cout<<"\t\tMatrix Expression of Equations:";bl;bl;
       rep(ro, 0, eqn_no){
           cout<<"\t";
            rep(co, 0, eqn_no+1){
                cout<<matrix[ro][co]<<"  ";
            }bl;
        }bl;bl;}
    else{
        cout<<"No equations found. Please input equations.";bl;bl;
    }
    cout<<"Prass any key to return...";
    getch();
}

int oparate_menu(){
    bar();
    cout<<"\t1) Print Upper Matrix";bl;bl;
    cout<<"\t2) Print Lower Matrix";bl;bl;
    cout<<"\t3) Calculate Solution";bl;bl;
    cout<<"\t0) Return To Main Menu";bl;bl;
    int key;
    cin>>key;
    return key;
}


void cal_upper_lower(){
    bar();
    memset(mat_U, 0, sizeof(mat_U));
    memset(mat_L, 0, sizeof(mat_L));
    rep(j, 0, eqn_no){
        mat_U[0][j]=matrix[0][j];
    }
    rep(i, 0, eqn_no){
        mat_L[i][i]=1;
    }
    rep(i, 1, eqn_no){
        mat_L[i][0]=matrix[i][0]/mat_U[0][0];
    }


    rep(j, 1, eqn_no){
        rep(i, 1, j+1){
            double sum=0;
            rep(k, 0, j){
                sum+=(mat_L[i][k]*mat_U[k][j]);
            }
            mat_U[i][j]=matrix[i][j]-sum;
        }
        rep(i, j+1, eqn_no){
            double sum=0;
            rep(k, 0, j){
                sum+=(mat_L[i][k]*mat_U[k][j]);
            }
            mat_L[i][j]=(1/mat_U[j][j])*(matrix[i][j]-sum);
        }
    }
}

void print_mat_U(){
    debug_mat(mat_U, "Upper");
    cout<<"Prass any key to return...";
    getch();
}

void print_mat_L(){
    debug_mat(mat_L, "Lower");
    cout<<"Prass any key to return...";
    getch();
}


void calculate_eqn(){
    bar();
    double z[row_col_sz];
    z[0]=matrix[0][eqn_no];
    rep(i, 1, eqn_no){
        double sum=0;
        rep(j, 0, i){
            sum+=(mat_L[i][j]*z[j]);
        }
        z[i]=matrix[i][eqn_no]-sum;
    }
    memset(X, 0, sizeof(X));
    X[eqn_no-1]=((z[eqn_no-1])/mat_U[eqn_no-1][eqn_no-1]);
    for(int i=eqn_no-2; i>=0; i--){
        double sum=0;
        rep(j, 0, eqn_no){
            sum+=(mat_U[i][j]*X[j]);
        }
        X[i]=(z[i]-sum)/mat_U[i][i];
    }
    cout<<"\tEquations :\n";bl;
    rep(r, 0, eqn_no){
        int k=1;
        cout<<"\t";
        rep(c, 0, eqn_no+1){
            if(c==eqn_no){
                pf("=");
            pf(" %.2f", matrix[r][c], k);
            }else
            pf(" %.2f[X%d] ", matrix[r][c], k);
            k++;
        }bl;
    }bl;bl;
    cout<<"  Values:";bl;bl;
    rep(i, 0, eqn_no){
        cout<<"   X"<<i+1<<" :"<<X[i]<<endl;
    }
    bl;bl;bl;
    cout<<"Prass any key to return...";
    getch();
}
