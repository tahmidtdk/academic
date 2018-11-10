
void proccess_logic(string logic);
void nav_var(){
    system("cls");
    pf("                               Propositional Logic Calculator");bl;
    pf("                               ------------------------------");bl;bl;
}

int main_nav(){     //main page navigation
    nav_var();
    pf("1. Input a Propositional Logic.");
    bl;bl;
    pf("2. Input variables for Proposition.");
    bl;bl;
    pf("3. Show Truth Table.");
    bl;bl;
    pf("4. Judge Proposition.");
    bl;bl;
    pf("5. Exit.");
    bl;bl;
    int key;
    cin>>key;
    return key;
}

void input_proposition(){
    nav_var();
    pf("[User Guide: This model will use the propositional atoms p, q, r (small letter) . The [NOT] operator");bl;
    pf("(for negation), the [AND] operator (for conjunction), the [OR] operator (for disjunction),");bl;
    pf("the [IMPLIES] operator (for implication), and the [IFF] operator (for bi-implication),");bl;
    pf("and the parentheses to state the precedence of the operators] & all are without space. Nested parentheses and multiple");bl;
    pf("parentheses are not allowed.");bl;bl;
    pf("Enter Your Propositional Logic:\n");
    char str[500];
    string logic;
//    sf("%[^\n]s", str);
    cin>>logic;
    proccess_logic(logic);
}



void proccess_logic(string logic){
    int upper_id=-1, lower_id=-1;
    int var_cont=0;
    bool check=false;
    for(int i=0; i<logic.size(); i++){
        if(logic[i]=='('){
            upper_id=i;
            check=true;
        }
        if(logic[i]==')'){
            lower_id=i;
            check=false;
        }
        if(upper_id!=-1 and check){
            data[i].priority=1;
        }
        if(logic[i]>='a' and logic[i]<='z'){
            data[var_cont].ch=logic[i];
            var_cont++;
        }
    }
}


void input_variables(){
    nav_var();
    pf("Enter the values: [1 for true & 0 for false]");
    for(int i=0; ; i++){
        if(data[i].ch=='0')
            break;
        pf("%c: ", data[i].ch);
        sf("%d", &data[i].value);
    }
}

int search_data(char cha){
    for(int i=0; ; i++){
        if(data[i].ch==cha){
            return i;
            break;
        }
    }
    return -1;
}

void proccess_calculation(string logic){
    int upper_id=-1, lower_id=-1;
    int var_cont=0;
    bool check=false;
    for(int i=0; i<logic.size(); i++){
        if(logic[i]=='('){
            upper_id=i;
            check=true;
        }
        if(logic[i]==')'){
            lower_id=i;
            check=false;
        }
        if(check){
            if(search_data(logic[i])!=-1){
                //calculation
            }else{
                pf("Exception: found a bug.\n");
            }
        }
    }
}
