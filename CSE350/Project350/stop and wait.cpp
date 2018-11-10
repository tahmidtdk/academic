#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#define sfi(n) scanf("%d", &n)
#define sf scanf
#define pf printf
#define bl printf("\n")
#define repe(i, n, test) for(int i=n; i<=test; i++)
#define rep(i, n, test) for(int i=n; i<test; i++)
#define Index 100
#define sleepTime 500
using namespace std;



struct Data{
	int dataFrame, dataRecieved, extractedDatavar, data[Index], *Sn, *Rn, frame, deliverDat, turn = true;
	bool input = true, Event = true, canSent = true, Extrachk = true, Extrachk1 = true;
}object;


//Functions of Sender-Side
void waitForEvent(){
	pf("Waiting for event");
    rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
    }bl;
}


void getData(int sizeOfData){
	cout << "(Network Layer Sender Side) \n Enter the data(Numeric): ";
	rep(i, 0, sizeOfData){
		cin >> object.data[i];
	}

	cout << "(Data Link Layer Sender Side) Making Frame";
	rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
	}bl;
}
void makeFrame() {
	if (object.Extrachk == true) {
		object.Sn = object.data;
		object.Extrachk = false;
	}

	object.frame = *(object.Sn);


}
int sendFrame() {
	cout << "(Physical Layer Sender Side)Sending Frame";
	rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
	}bl;

	object.dataFrame = object.frame;
	object.turn = false;

	return object.dataFrame;
}

void ackFrame() {
	cout << "(FROM RECEIVER SIDE TO SENDER SIDE)Note: Acknowledgement Send to receiver..." << endl;
}

//Functions of Reciver-Side
int recieveFrame() {
	if (object.Extrachk1 == true) {
		object.Rn = object.data;
		object.Extrachk1 = false;
	}
	cout << "(Physical Layer Receiver side) Receiving Frame";
	rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
	}bl;

	if (*(object.Sn) == *(object.Rn)) {
		object.dataRecieved = object.dataFrame;
	}
	object.Sn++;
	object.Rn++;

	return object.dataRecieved;
}

int extractData() {
	cout << "(Data Link Layer Receiver Side) Extracting the Data";
	rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
	}bl;
	object.extractedDatavar = object.dataRecieved;

	return object.extractedDatavar;
}

int deliverData() {

	if (object.turn == false) {
		object.turn == true;
	}
	object.deliverDat = object.extractedDatavar;
	cout << "(Data Link Layer Receiver) Delivering Data";
	rep(i, 0, 7){
        Sleep(sleepTime);
        cout << ".";
	}bl;
	cout << "Note:(Network Layer Receiver Side) Data delivered..." << endl;
	cout << "Recieved Data: " << object.deliverDat<<endl<<endl<<endl;
	return object.deliverDat;
}

int main() {
	time_t start=0, end=0;
	double difference;
    int data_size;
    pf("Enter the size of data: ");
    sfi(data_size);
	object.canSent = true;
	rep(i, 0, data_size){
		//Sender-side code
		while (object.turn == true and object.canSent == true) {
			waitForEvent();
			time(&start);
			if (object.Event == true){
				if (object.input == true){
					getData(data_size);
					object.input = false;
				}
				makeFrame();
				sendFrame();
				object.canSent = false;
			}

			break;
		}

		//Reciever side code
		while (object.turn == false) {
			if (object.Event == true) {
				recieveFrame();
				waitForEvent();
				//Reciever to Sender code
				ackFrame();
				time(&end);
				difference = difftime(end,start);
				cout << "Time take :" << difference << endl;
				object.canSent = true;

				extractData();
				deliverData();
				object.turn = true;
				break;
			}
		}

	}
	pf("Successfully data send....\n");
	return 0;
}
