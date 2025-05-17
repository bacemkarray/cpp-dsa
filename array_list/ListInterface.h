#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H


template <typename E>
class List {
    public:
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void add(int index, const E& element) = 0;
        virtual E get(int index) = 0;
        virtual E remove(int index) = 0;
        virtual E set(int index, const E& element) = 0;
};

#endif

