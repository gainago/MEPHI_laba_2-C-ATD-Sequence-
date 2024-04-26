#include "head.h"
#include "head_templates.h"

template <class Type>
ArraySequence<Type>::ArraySequence(Type *items1, int count)
    {
        items = new DynamicArray<Type>(items1,count);
    }
template <class Type>
ArraySequence<Type>::ArraySequence(ArraySequence<Type> const &array)
{
    items = new DynamicArray<Type>(*array.items);
    }

template <class Type>
ArraySequence<Type>::ArraySequence()
{
    items = new DynamicArray<Type>(nullptr, 0);
    }

template <class Type>
Type ArraySequence<Type>::GetFirst() const
{
    try
    {
        Type t1 = items->Get(0);
        return t1;
        }
        catch(char const * str){}
        throw "error";
    }

template <class Type>
Type ArraySequence<Type>::GetLast() const
{
    try
    {
        return items->Get(items->GetSize() - 1);
        }
        catch(...){}
        throw "error\n";
}



template <typename Type>
Type ArraySequence<Type>::GetIndex(int index) const
{
    try
    {
        return items->Get(index);
    }
    catch (...)
    {
    }
    throw "error\n";
}
template<typename Type>
int ArraySequence<Type> :: GetLength() const
    {
        return items->GetSize();
    }
template <class Type>
ArraySequence<Type> *ArraySequence<Type>::Append(Type data) 
    {
        ArraySequence<Type>* arr = new ArraySequence<Type>(*this);
        arr->items->Resize(arr->items->GetSize() + 1);
        arr->items->Set(arr->items->GetSize() -1,data);
        return arr;
    } 

template <class Type>
ArraySequence<Type> *ArraySequence<Type>::Prepend(Type data) 
{
            ArraySequence<Type>* arr = new ArraySequence<Type>(*this);
        arr->items->Resize(arr->items->GetSize() + 1);
        for(int i = 0;i <arr->items->GetSize() - 1;i++)
            arr->items->Set(arr->items->GetSize() - i -1,arr->items->Get(arr->items->GetSize() - i - 2));
        arr->items->Set(0,data);
        return arr;
}

template <class Type>
ArraySequence<Type> *ArraySequence<Type>::InsertAt(Type item, int index) 
{
            if(index < 0 || index > this->GetLength())
            throw "error: invalid index\n";
        ArraySequence<Type>* arr = new ArraySequence<Type>(*this);
        arr->items->Resize(arr->items->GetSize() + 1);
        for(int i = 0;i <arr->items->GetSize() - 1 - index;i++)
            arr->items->Set(arr->items->GetSize() - i -1,arr->items->Get(arr->items->GetSize() - i - 2));
        arr->items->Set(index,item);
        return arr;
}

template <class Type>
Sequence<Type> *ArraySequence<Type>::Concat(Sequence<Type> *list) 
{
    ArraySequence<Type>* ptr = new ArraySequence<Type>;
        ArraySequence<Type>* curr_ptr = 0;
        ptr->items->Resize(list->GetLength() + this->items->GetSize());
        for(int i = 0;i < this->items->GetSize();i++)
        {
            ptr->items->Set(i,this->items->Get(i));
        }
        for(int i = 0;i < list->GetLength();i++)
        {
           
            ptr->items->Set(i + this->GetLength(),list->GetIndex(i));
        }
        return ptr;
}

template<typename Type>
ArraySequence<Type>* ArraySequence<Type>::GetSubsequence(int start,int end) 
{
    if(start < 0 || end <0 || end >= this->items->size)
        throw "error: incorrect index\n";
    ArraySequence<Type>* arr = new ArraySequence<Type>(this->items->arr + start, end - start + 1);
    return arr;

}

template <typename Type>
ArraySequence<Type>::~ArraySequence()
{
    delete this->items;
}
template <class Type>
ArraySequence<Type> *ArraySequence<Type>::DeleteIndex(int index)
{
    ArraySequence<Type>* ptr = new ArraySequence<Type>(*this);
    if(index < 0 || index >= this->GetLength())
        throw "error: index out of range\n";
    ptr->items->DeleteIndex(index);
    return ptr;

}