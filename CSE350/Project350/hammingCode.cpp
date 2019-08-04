#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

#define datasize 100

bool binary_indx(int val, int indx){
    int arr[datasize];
    memset(arr, 0, sizeof(arr));
    int i=1;
    while(val){
        arr[i] = val%2;
        val/=2;
        i++;
    }
    return arr[indx]==1?true:false;
}

void printDot(){
        for(int i=0; i<10; i++){
            cout<<".";
            Sleep(250);
        }
        cout<<endl;
}


class Sender{
    int message[datasize];
    char parityType;
    int codeWord[datasize*2];
    int msg_size;
    int codeword_size;
public:
    Sender(){
        memset(message, -1, sizeof(message));
        memset(codeWord, -1, sizeof(codeWord));
    }
    void setMsg_size(int si){
        msg_size = si;
    }

    int getCodeword_size(){
        return codeword_size;
    }

    void setMsg(string msg){
        int ind =1;
        for(int i=0; i<msg.size(); i++){
            message[ind]=msg[i]-'0';
            ind++;
        }
    }

    void setCodeword_size(){
        int r=0;
        while (msg_size + r + 1 > pow (2, r)){
          r++;
        }
        codeword_size=r+msg_size;
    }

    bool is_notparity(int val){
        for(int i=0; i<codeword_size; i++){
            if(pow(2,i)==val)
                return false;
        }
        return true;
    }

    int calculateParity(int parityIndex){
        int cont=0;
        for(int i=1; i<=codeword_size; i++){
            if(binary_indx(i, parityIndex) and codeWord[i]!=-1){
                if(codeWord[i])
                    cont++;
            }
        }
        return cont%2==1?1:0 ;
    }

    void generateCodeWord(){
        cout<<endl<<"Generating Codeword";
        printDot();
        setCodeword_size();
        int ind=1;
        //set msg to the codeword index
        for(int i=codeword_size; i>0; i--){
            if(is_notparity(i)){
                codeWord[i]=message[ind];
                ind++;
            }
        }

        //set parity bits
        int parityIndex =1;
        for(int i=codeword_size; i>0; i--){
            if(!is_notparity(i)){
                codeWord[i]=calculateParity(parityIndex);
                parityIndex++;
            }
        }

        reverse(codeWord+1, codeWord+codeword_size+1);

        cout<<endl<<"Generating Codeword is: ";
        for(int i=1; i<=codeword_size; i++){
            cout<<codeWord[i];
        }
        cout<<endl;
    }

    int* sendData(){
        srand (time(NULL));
        int randIndx = rand() % codeword_size + 1;
        // make randomly changed one bits
        if(codeWord[randIndx])
            codeWord[randIndx]=0;
        else
            codeWord[randIndx]=1;

        cout<<endl<<"Data is sending ";
        printDot();
        return codeWord;
    }

};

class Receiver{
    int message[datasize];
    char parityType;
    int codeWord[datasize*2];
    int msg_size;
    int codeword_size;
public:

    void printCodeword(){
        cout<<endl;
        for(int i=1; i<=codeword_size; i++){
            printf("%d ", codeWord[i]);
        }
        cout<<endl;
    }

    void receiveCodeword(int *arr, int arrSize){
        codeword_size = arrSize;
        cout<<endl<<"Receiver received data: ";
        for(int i=1; i<=arrSize; i++){
            codeWord[i]=arr[i];
            cout<<codeWord[i];
        }
        cout<<endl;
    }

    bool is_notparity(int val){
        for(int i=0; i<codeword_size; i++){
            if(pow(2,i)==val)
                return false;
        }
        return true;
    }

    int calculateParity(int parityIndex){
        int cont=0;
        for(int i=1; i<=codeword_size; i++){
            if(binary_indx(i, parityIndex) and codeWord[i]!=-1){
                if(codeWord[i])
                    cont++;
            }
        }
        return cont%2==1?1:0 ;
    }

    void generateMsg(){
        cout<<endl<<"Decoding Message";
        printDot();
        int ind=1;
        for(int i=1; i<=codeword_size; i++){
            if(is_notparity(i)){
                message[ind]=codeWord[i];
                ind++;
            }
        }
        msg_size=ind-1;
    }

    void printMsg(){
        cout<<endl<<"Message received: ";
        for(int i=1; i<=msg_size;i++){
            cout<<message[i];
        }
        cout<<endl;
    }

    void decodeCodeWord(){
        cout<<endl<<"Detecting errors";
        printDot();
        reverse(codeWord+1, codeWord+codeword_size+1);
        int parity_bits[datasize];
        int parityIndex=1;
        for(int i=codeword_size; i>0; i--){
            if(!is_notparity(i)){
                parity_bits[parityIndex] = calculateParity(parityIndex);
                parityIndex++;
            }
        }

        int error_index = 0, dec_comb=0;
        for(int i=1; i<=parityIndex-1; i++){
            if(parity_bits[i]){
                error_index+=pow(2, dec_comb);
            }
            dec_comb++;
        }
        cout<<endl<<"Error in bit index: "<<error_index<<endl;

        // correct the codeword in single index
        codeWord[error_index] = codeWord[error_index]?0:1;
        cout<<endl<<"Correct Codeword is: ";
        reverse(codeWord+1, codeWord+codeword_size+1);
        for(int i=1; i<=codeword_size; i++){
            cout<<codeWord[i];
        }
        cout<<endl;
        generateMsg();
    }

};


int main(int argc, char const *argv[]) {
    int num;
    string message;
    cout<<"Enter massage bit size: ";
    cin>>num;
    Sender sender;
    sender.setMsg_size(num);
    printf("Enter %d bits massage: ", num);
    cin>>message;
    sender.setMsg(message);
    sender.generateCodeWord();

    Receiver receiver;
    receiver.receiveCodeword(sender.sendData(), sender.getCodeword_size());
    receiver.decodeCodeWord();
    receiver.printMsg();
    return 0;
}
