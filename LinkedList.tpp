template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* myNode = new Node(elem);
       
    if (head==nullptr){
        head=myNode;
     }
    else{
        Node* pointing = head;
        while(pointing->next!=nullptr){
            pointing = pointing -> next;
            }
            pointing-> next = myNode;
        }
    
    this->length+=1;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;
    while(head!=nullptr){
        prev = head;
        head = head -> next;
        delete prev;
    }
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if ((position < 0) || (position >= getLength())){
        throw string("position does not exist, out of bounds");
    }
    Node* pointing = head;
    int count=0;
    while(count < position){
        if(pointing == nullptr){ //check in case length is not right
            throw string("position does not exist, out of bounds 2");
            }
        pointing = pointing -> next; 
        count++;
    }

    return pointing->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    Node* pointing = head;
    int count=0;
    if ((position < 0) || (position >= getLength())){
        throw string ("Error: Index is out of Bounds");
    
    }
    while(count < position && count > -1){
        if(pointing == nullptr){
            throw string("position does not exist, out of bounds");
        }
        pointing = pointing -> next;
      
        count++;
    }

    pointing->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
