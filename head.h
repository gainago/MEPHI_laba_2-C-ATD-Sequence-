
#pragma once

template<typename Type>
class DynamicArray {
    public:
    DynamicArray(Type *items, int count);
    DynamicArray(int size);
    DynamicArray(DynamicArray<Type> const & dynamicArray);
    DynamicArray& operator=(DynamicArray<Type> const & dynamicArray);
    Type & operator[](int index) const;
    int GetSize() const;
    Type Get(int index) const;
    void Set(int index, Type value);
    void Resize(int newSize);
    void ShowDynamicArray() const;
    friend ArraySequence<Type>* ArraySequence<Type>::GetSubsequence(int start,int end);
    DynamicArray(){}
    ~DynamicArray();
    void DeleteIndex(int index);
    private:
    Type *arr{NULL};
    size_t size{0};
    size_t capacity{0};


};
template<typename Type>
class LinkedList 
{
    public:
    LinkedList(Type* items, int count);
    void ShowLinkedList() const;
    LinkedList();
    LinkedList(LinkedList<Type> const & LL);
    Type GetFirst() const;
    Type GetLast() const;
    Type GetIndex(int index) const;
    int GetLength() const;
    void Append(Type T);
    LinkedList<Type> * GetSubList(int start, int end) const;
    void Prepend(Type type);
    void InsertAt(Type data, int index);
    LinkedList<Type> * Concat(LinkedList<Type>* LL ) const;
    ~LinkedList()
    {   Node* curr;
        for(int i = 0;i < size;i++)
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    void DeleteIndex(int index);
    private:

    class Node
    {   public:
        Node(Type value);
        Type value;
        Node *next;
    };
    Node* head{0};
    Node* tail{0}; 
    size_t size{0};

};


