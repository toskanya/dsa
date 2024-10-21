template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node *temp = new Node(e);
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
    
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count)
        throw out_of_range("Index is out of range!");
    
    Node *temp = new Node(e); 
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else if (index == 0)
    {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
    else if (index == count)
    {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
    else
    {
        Node *move = head;
        for (int i = 0; i < index - 1; i++)
        {
            move = move->next;
        }
        
        temp->previous = move;
        temp->next = move->next;
        move->next->previous = temp;
        move->next = temp;
    }
    
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}