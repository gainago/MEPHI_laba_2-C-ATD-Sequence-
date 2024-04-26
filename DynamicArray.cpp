#include <iostream>
#include "head.h"

template<typename Type>

   DynamicArray<Type>:: DynamicArray(Type *items, int count)
    {
        if(count<0)
        {
           std:: cout<<"недопустимое количество элементов\n";
            return;
        }
        if(items == NULL && count >0)
        {
            std::cout<<"недопустимое значение указателя\n";
            return;
        }
        arr = new Type [count + count/10];
        for(int i=0;i<count;i++)
            arr[i] = items[i];
        size = count;
        capacity = count + count/10;

    }
    template<typename Type>
   DynamicArray<Type>:: DynamicArray(int size)
    {
        if(size<1)
        {
           std:: cout<<"недопустимое количество элементов\n";
            return;
        }
        arr = new Type [size + size/10];
        this->size = size;
        capacity = size + size/10;
    }
    template<typename Type>
    DynamicArray<Type>::DynamicArray(DynamicArray<Type> const & dynamicArray)
    {
        arr = new Type[dynamicArray.capacity];
        size = dynamicArray.size;
        capacity = dynamicArray.capacity;
        for(int i=0;i<size;i++)
            arr[i] = dynamicArray.arr[i];
    }
    template<typename Type>
    DynamicArray<Type> & DynamicArray<Type>:: operator=(DynamicArray<Type> const & dynamicArray)
    {   
        delete []this->arr;
        arr = new Type[dynamicArray.capacity];
        size = dynamicArray.size;
        capacity = dynamicArray.capacity;
        for(int i=0;i<size;i++)
            arr[i] = dynamicArray.arr[i];
            return *this;
    }
    template<typename Type>
   Type &  DynamicArray<Type>::operator[](int index) const
    {
        if(index < 0|| index >= size)
            throw "error position\n";
        
        return  *(arr + index);

    }
    template<typename Type>
   int DynamicArray<Type>:: GetSize() const
    {
        return size;
    }
    template<typename Type>
   Type  DynamicArray<Type>:: Get(int index) const
    {
          if(index < 0|| index >= size)
            throw "error position\n";
        
        return  *(arr + index);
    }
    template<typename Type>
  void  DynamicArray<Type>:: Set(int index, Type value)
    {
        if(index < 0|| index >= size)
            throw "error position\n";
        
        *(arr + index) = value;
    }
    template<typename Type>
    void DynamicArray<Type>:: Resize(int newSize)
    {
        
        Type* arr2 = new Type[newSize + newSize/10];

        for(int i=0;i<size&&i<newSize;i++)
            arr2[i] = arr[i];
        size = newSize;
        capacity = newSize + newSize/10;
        delete []arr;
        arr = arr2;
        
       
    }
    template<typename Type>
   void DynamicArray<Type>:: ShowDynamicArray() const
    {
        for(int i=0;i<size;i++)
            std::cout << i << "\t";
            std::cout << "\n";
        for(int i=0;i<size;i++)
            //std::cout << arr[i] <<"\t";
            Print(arr[i]);
        std::cout << "\n";
    }
    template<typename Type>
    DynamicArray<Type>::  ~DynamicArray()
    {
        delete [] this->arr;
        this->size = 0;
        this->capacity = 0;
    }

    template <typename Type>
    void DynamicArray<Type>::DeleteIndex(int index)
    {
        if(index < 0 || index >= this->size)
            throw "error: index out of range\n";
        DynamicArray<Type>* curr_ptr = new DynamicArray<Type>(this->size - 1);
        for( int i = 0; i < index ;i++)
            curr_ptr->Set(i,this->Get(i));
        for(int i = index + 1;i < this->size;i++)
            curr_ptr->Set(i -1,this->Get(i));
        delete this->arr;
        this->arr = curr_ptr->arr;
        this->size = curr_ptr->size;
        this->capacity = curr_ptr->capacity;
    }
