#pragma once
#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include <algorithm>

namespace Andi
{
    #pragma region LinkedList

    #pragma region LinkedListDef
    template <typename Type>
    class LinkedList
    {
    private:
        struct Node
        {
            Type *__value;
            Node *__next;

            Node();
            Node(Type const &value);
            ~Node();
        };
        Node *__head;
        Node *__tail;

        size_t __count;

    public:
        LinkedList();
        ~LinkedList();

        void add(Type const &value);
        bool remove(Type const &value);
        Type &removeHead();
        Type &removeTail();
        bool contains(Type const &value) const noexcept;
        void clear();
        void copyTo(Type *array, size_t start_pos) const;
        void copyTo(Type *array) const;
        size_t count() const noexcept;

        Type &const operator[](size_t pos) const;
    };
    #pragma endregion

    #pragma region NodeImpl
    template <typename Type>
    LinkedList<Type>::Node::Node()
    {
        this->__value = nullptr;
        this->__next = nullptr;
    }
    template <typename Type>
    LinkedList<Type>::Node::Node(Type const &value)
    {
        this->__value = new Type(value);
        this->__next = nullptr;
    }
    template <typename Type>
    LinkedList<Type>::Node::~Node()
    {
        delete this->__value;
        delete this->__next;
    }
    #pragma endregion

    #pragma region LinkedListImpl
    template <typename Type>
    LinkedList<Type>::LinkedList()
    {
        this->__head = nullptr;
        this->__tail = nullptr;
        this->__count = 0;
    }
    template <typename Type>
    LinkedList<Type>::~LinkedList()
    {
        this->clear();
    }

    template <typename Type>
    void LinkedList<Type>::add(Type const &value)
    {
        Node *node = new Node(value);
        if (this->__head == nullptr)
        {
            this->__head = node;
            this->__tail = node;
        }
        else
        {
            this->__tail->__next = node;
            this->__tail = node;
        }
        ++this->__count;
    }
    template <typename Type>
    bool LinkedList<Type>::remove(Type const &value)
    {
        Node *previous = nullptr;
        Node *current = this->__head;
        while (current != nullptr)
        {
            if (*current->__value == value)
            {
                if (previous != nullptr)
                {
                    previous->__next = current->__next;
                    if (current->__next == nullptr)
                        this->__tail = previous;
                    delete current;
                }
                else
                {
                    this->__head = current->__next;
                    if (this->__head == nullptr)
                        this->__tail = nullptr;
                    delete current;
                }
                --this->__count;
                return true;
            }
            previous = current;
            current = current->__next;
        }
        return false;
    }
    template <typename Type>
    Type &LinkedList<Type>::removeHead()
    {
        if (this->__head != nullptr)
        {
            Node *temp = this->__head;
            Node *current = this->__head->__next;
            this->__head->__next = nullptr;
            delete this->__head;
            this->__head = current;
            --this->__count;
            return temp;
        }
    }
    template <typename Type>
    Type &LinkedList<Type>::removeTail()
    {
        if (this->__tail != nullptr)
        {
            Node *temp = this->__tail;
            if (this->__tail == this->__head)
            {
                delete this->__head;
                this->__head = nullptr;
                this->__tail = nullptr;
                --this->__count;
            }
            else
            {
                Node *current = this->__head;
                for (size_t t = 0; t < this->__count - 2; ++t)
                    current = current->__next;
                current->__next = nullptr;
                delete this->__tail;
                this->__tail = current;
                --this->__count;
            }
            return temp;
        }
    }
    template <typename Type>
    bool LinkedList<Type>::contains(Type const &value) const noexcept
    {
        Node *current = this->__head;
        while (current != nullptr)
        {
            if (*current->__value == value)
                return true;
            current = current->__next;
        }
        return false;
    }
    template <typename Type>
    void LinkedList<Type>::clear()
    {
        delete this->__head;
        this->__head = nullptr;
        this->__tail = nullptr;
        this->__count = 0;
    }
    template <typename Type>
    void LinkedList<Type>::copyTo(Type *array, size_t start_pos) const
    {
        Node *current = this->__head;
        for (size_t t = 0; t < start_pos; ++t)
            current = current->__next;
        size_t it = 0;
        while (current != nullptr)
        {
            array[it++] = *current->__value;
            current = current->__next;
        }
    }
    template <typename Type>
    void LinkedList<Type>::copyTo(Type *array) const
    {
        Node *current = this->__head;
        size_t it = 0;
        while (current != nullptr)
        {
            array[it++] = *current->__value;
            current = current->__next;
        }
    }
    template <typename Type>
    size_t LinkedList<Type>::count() const noexcept
    {
        return this->__count;
    }

    template <typename Type>
    Type &const LinkedList<Type>::operator[](size_t pos) const
    {
        Node *current = this->__head;
        for (size_t t = 0; t < pos; ++t)
            current = current->__next;
        return *current->__value;
    }
    #pragma endregion
    #pragma endregion
};

#endif //__LINKEDLIST__