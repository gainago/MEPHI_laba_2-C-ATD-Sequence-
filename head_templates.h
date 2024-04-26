#pragma once
template<typename Type>
class DynamicArray;
template<typename Type>
class LinkedList;
template<typename Type> 
class Sequence{
    public:
    virtual ~Sequence() =0;
    virtual Sequence<Type>* GetSubsequence(int start,int end)  = 0;//включая границы
    virtual void Print() const {};
    virtual Type GetFirst() const = 0;
    virtual Type GetLast() const = 0;
    virtual Type GetIndex(int index) const = 0;//нумерация с ноля
    virtual int GetLength() const = 0;
    virtual Sequence<Type>* Append(Type data) = 0;
    virtual Sequence<Type>* Prepend(Type item) = 0;
    virtual Sequence<Type>* Concat(Sequence<Type>* list)  = 0;
    virtual Sequence<Type>* DeleteIndex(int index) = 0;
    
    bool is_equal(Sequence<Type> const * arr) const
    {
        
        if(this->GetLength() != arr->GetLength())
            return false;
        for(int i = 0;i < this->GetLength();i++)
            if(arr->GetIndex(i) != this->GetIndex(i))
                return false;
        return true;
    }
    
    
};

template<typename T>
Sequence<T>:: ~Sequence() {};
template<class Type>
class ArraySequence : public Sequence<Type>
{
    private:
    
    DynamicArray<Type>* items;
    public:
 
    void Print() const
    {
        items->ShowDynamicArray();
    }
    ArraySequence(Type* items1,int count);
    ArraySequence(ArraySequence<Type> const &array);
    ArraySequence();
    Type GetFirst() const;
    Type GetLast() const;
    Type GetIndex(int index) const;
    ArraySequence<Type>* GetSubsequence(int start,int end) ;
    int GetLength() const;
    ArraySequence<Type>* Append(Type data) ;
    ArraySequence<Type>* Prepend(Type data) ;
    ArraySequence<Type>* InsertAt(Type item,int index) ;
    Sequence<Type>* Concat(Sequence<Type>* list) ;
    ~ArraySequence();
    ArraySequence<Type>* DeleteIndex(int index);
    

};
template<typename Type>
class ListSequence : public Sequence<Type>
{
    protected:
    LinkedList<Type>* items;
    public:
    void Print() const
    {
        items->ShowLinkedList();
    }
    
    ListSequence(Type *data,int size);
    ListSequence();
    ListSequence(ListSequence<Type> const & list);
    Type GetFirst() const;
    Type GetLast() const;
    Type GetIndex(int index) const;
    int GetLength() const;
    ListSequence<Type>* GetSubsequence(int start,int end) 
    {
        return Clone()->GetSubsequenceInternal(start,end);
    }
    ListSequence<Type>* Append(Type data) 
    {
        return Inctance()->AppendInternal(data);
    }
    ListSequence<Type>* Prepend(Type data) 
    {
        return Inctance()->PrependInternal(data);
    }
    ListSequence<Type>* InsertAt(Type data,int index) 
    {
        return Inctance()->InsertAtInternal(data,index);
    }
    Sequence<Type>* Concat(Sequence<Type>* list) 
    {
        ListSequence<Type>* ptr = Inctance();
        //return Inctance()->ConcatInternal(list);
        return ptr->ConcatInternal(list);
    }
    ListSequence<Type>* DeleteIndex(int index)
    {
        return Inctance()->DeleteIndexInctance(index);
    }
    ~ListSequence();
    protected:
    virtual ListSequence<Type>* Inctance() = 0;
    ListSequence<Type>* GetSubsequenceInternal(int start,int end) ;
    ListSequence<Type>* AppendInternal(Type data) ;
    ListSequence<Type>* PrependInternal(Type data) ;
    ListSequence<Type>* InsertAtInternal(Type data,int index) ;
    Sequence<Type>* ConcatInternal(Sequence<Type>* list) ;
    ListSequence<Type>* DeleteIndexInctance(int index);
    virtual ListSequence<Type>* Clone() = 0;
    
};
template<typename Type>
class MutableListSequence : public ListSequence<Type>
{   public:
    MutableListSequence(Type* arr,int size) : ListSequence<Type>(arr,size){}
    MutableListSequence() : ListSequence<Type>(){}
    MutableListSequence(MutableListSequence<Type> const &list) 
    {
        this->items = new LinkedList<Type>(*(list.items));
    }
    protected:
   ListSequence<Type>* Inctance() override
   {
        return this;
   }
   ListSequence<Type>* Clone()
    {
        ListSequence<Type>* ptr = new MutableListSequence<Type>(*this);
        return ptr;
    }
};
template<typename Type>
class ImmutableListSequence : public ListSequence<Type>
{  public:
    ImmutableListSequence(Type* arr,int size) : ListSequence<Type>(arr,size){}
    ImmutableListSequence() : ListSequence<Type>(){}
    ImmutableListSequence(ImmutableListSequence<Type> const &list) 
    {
        this->items = new LinkedList<Type>(*(list.items));
    }
    protected:
    ListSequence<Type>* Inctance() override
    {
        return this->Clone();
    }
    ListSequence<Type>* Clone()
    {
        ListSequence<Type>* ptr = new ImmutableListSequence<Type>(*this);
        return ptr;
    }
};