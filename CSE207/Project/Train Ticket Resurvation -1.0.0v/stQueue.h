
template<class T>class Queue{
    public:
        Queue();
        bool isEmpty();
        void enqueue(T data);
        void dequeue();
        T front();

    private:
        struct Node{
            T date;
            Node *next;
        };

        Node *frontPtr;
        Node *backPtr;
        int count;

};


template<class T>Queue<T>::Queue(): frontPtr(NULL), backPtr(NULL), count(0){
//    defult constructor
}

template<class T>bool Queue<T>::isEmpty(){
    return(count == 0);
}

template<class T>void Queue<T>::enqueue(T data){
    Node *newOne = new Node;
    newOne->date = data;
    newOne->next = NULL;
    if(isEmpty()){
        frontPtr = newOne;
    }
        else{
            backPtr->next = newOne;
        }
        backPtr = newOne;
        count++;
}

template<class T>void Queue<T>::dequeue(){
    if(isEmpty()){
        cout << "Nothing inside" << endl;
    }
        else{
            Node *temp = frontPtr;
            if(frontPtr == backPtr){
                frontPtr = NULL;
                backPtr = NULL;
            }
            else{
                frontPtr = frontPtr->next;
            }
            delete temp;
            count--;
        }
}

template<class T>T Queue<T>::front(){
    return frontPtr->date;
}


