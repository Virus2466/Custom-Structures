#pragma once
#include <cstddef>
#ifndef VECTOR_IMPL
#define VECTOR_IMPL

#include<initializer_list>


    template <typename T>
    class mvector{
        public:
            mvector() = default;
            mvector(std::initializer_list<T> data);

            // copy constructor
            mvector(const mvector& rhs);



            
            // insertions methods
            void push_back();
            void pop_back();   
            
            // index
            void begin();
            void end();

            // capacity methods       
            void get_size();

        private:
            T *data;
            size_t size;
            size_t capacity;
    };


template <typename T>
mvector<T>::mvector(std::initializer_list<T> list){
    size = list.size();
    capacity = size;
    data = new T[capacity];

    size_t i = 0;
    for(const auto& val : list){
        data[i++] = val;
    }
}


    
#endif