#include "head.h"
#include "head_templates.h"

template<typename Type>
ListSequence<Type> :: ListSequence(Type* data, int size)
    {
        items = new LinkedList<Type>(data,size);
    }
template <typename Type>
ListSequence<Type> :: ListSequence()
    {
        items = new LinkedList<Type>;

    }

template <typename Type>
ListSequence<Type> :: ListSequence(ListSequence<Type> const & list)
    {
        items = new LinkedList<Type>(*list.items);
    }
    template <typename Type>
    Type ListSequence<Type> :: GetFirst() const
    {
        if(items->GetLength() == 0)
            throw "error: index out of range\n";
        return items->GetFirst();
    }
    template <typename Type>
    Type ListSequence<Type> :: GetLast() const
    {
        if(items->GetLength() == 0)
            throw "error: index out of range\n";
        return items->GetLast();
    }
    template <typename Type>
     Type ListSequence<Type> :: GetIndex(int index) const
    {
        if(index < 0 || index >= items->GetLength())
            throw "error: index out of range";
        return items->GetIndex(index);
    }
    template <typename Type>
    int ListSequence<Type> :: GetLength() const
    {
        return items->GetLength();
    }
    template <typename Type>
    ListSequence<Type>*  ListSequence<Type> :: GetSubsequenceInternal(int start,int end) //const
    {
        if(start < 0 || end >= this->GetLength() || start > end)
        throw "error: index out of range\n";
        MutableListSequence<Type> mut;
        ListSequence<Type>* ptr = & mut;
        //ListSequence<Type>* ptr;
        ptr->items = items->GetSubList(start,end);
        delete this->items;
        this->items = ptr->items;
        ptr->items = 0;
        return this;
    }
    template <typename Type>
    ListSequence<Type>* ListSequence<Type> :: AppendInternal(Type data) //const
    {
        //ListSequence<Type>* ptr = new ListSequence<Type>(*this);
        //ptr->items->Append(data);
        this->items->Append(data);
        return this;
    }
    template <typename Type>
    ListSequence<Type>* ListSequence<Type> :: PrependInternal(Type data) //const
    {
        //ListSequence<Type>* ptr = new ListSequence<Type>(*this);
        //ptr->items->Prepend(data);
        this->items->Prepend(data);
        return this;
    }
    template <typename Type>
   ListSequence<Type>* ListSequence<Type> :: InsertAtInternal(Type data,int index) //const
    {
        //ListSequence<Type>* ptr = new ListSequence<Type>(*this);
        //ptr->items->InsertAt(data,index);
        this->items->InsertAt(data,index);
        return this;
    }
    template <typename Type>
     Sequence<Type>* ListSequence<Type> :: ConcatInternal(Sequence<Type>* list) //const
    {
        /*ListSequence<Type>* ptr = new ListSequence<Type>;
        ArraySequence<Type>* curr_ptr = 0;*/
        
        for(int i = 0;i < list->GetLength();i++)
        {
            //ptr->items->Append(this->items->GetIndex(i));
            this->items->Append(list->GetIndex(i));
        }
        /*for(int i = 0;i < list->GetLength();i++)
        {
           
            //ptr->items->Append(this->items->GetIndex(i));
            this->items->Append(this->items->GetIndex(i));
        }*/
        return this;
    }
    template <typename Type>
    ListSequence<Type> *ListSequence<Type>::DeleteIndexInctance(int index)
    {   if(index < 0 || index >= this->GetLength())
        throw "error\n";
        this->items->DeleteIndex(index);
        return this;
    }
    template <typename Type>
    ListSequence<Type> :: ~ListSequence()
    {
        delete this->items;
    }