template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (head == nullptr)
        return; // Danh sách rỗng

    bool swapped;
    Node *ptr1;
    Node *lptr = nullptr;

    do
    {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
        if (swapped)
        {
            printList(); // In danh sách sau mỗi lần hoán đổi
        }
    } while (swapped);
}