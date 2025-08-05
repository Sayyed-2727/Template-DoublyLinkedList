#pragma once
#include <iostream>
using namespace std;

template  <class T> 
class clsDblLinkedList  
{
protected:
    
    int _Size =0;

public:

    class Node
    {
    public:
        T Value;
        Node* Next;
        Node* prev;
    };

    Node* Head = NULL;
    
    void InsertAtBeginning(T Value)
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

       Node* NewNode = new Node();
       NewNode->Value = Value;
       NewNode->prev = NULL;
       NewNode->Next = Head;
       
       if (Head != NULL)
       {
           Head->prev = NewNode;
        }
        
        Head = NewNode;
        _Size ++;
    }

    void InsertAfter(Node* Current, T value)
    {
        Node* NewNode = new Node();
        NewNode->Value = value;
        NewNode->Next = Current->Next;
        NewNode->prev = Current;
        if (Current->Next != NULL)
        {
            Current->Next->prev = NewNode;
        }
        
        Current->Next = NewNode;
        _Size ++;
    }
    
    bool InsertAfter(int Index, T value)
    {
        Node* ItemNode = GetNode(Index);
        
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode,value);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void InsertAtEnd(T value)
    {
        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */

       Node* newNode = new Node();
       newNode->Value = value;
       newNode->Next = NULL;
       if (Head == NULL) {
           newNode->prev = NULL;
           Head = newNode;
        }
        else {
            Node* current = Head;
            while (current->Next != NULL) {
                current = current->Next;
            }
            current->Next = newNode;
            newNode->prev = current;
        }
        _Size ++;
    }

    void PrintList()
    {
        Node* Current = Head;

        while (Current != NULL) {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";
        delete Current;
    }
    
    Node* Find(T Value)
    {
        Node* Current = Head;

        while (Current != NULL)
        {
            if ( Current->Value == Value)
            {
                return Current;
            }

            Current = Current->Next;
        }
        
        return NULL;
    }
    
    void DeleteNode(Node*& NodeToDelete)
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */
       if (Head == NULL || NodeToDelete == NULL)
       {
           return;
        }
        if (Head == NodeToDelete)
        {
            Head = NodeToDelete->Next;
        }
        if (NodeToDelete->Next != NULL)
        {
            NodeToDelete->Next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->Next = NodeToDelete->Next;
        }
        delete NodeToDelete;
        _Size --;
    }
    
    void DeleteFirstNode()
    {
        if (Head == NULL)
        {
            return;
        }

        Node* N = Head;
        Head = N->Next;
        if (Head != NULL )
        {
            Head->prev = NULL;
        }
        delete N;
        _Size --;        
    }
        
    void DeleteLastNode()
    {
        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */
    
        Node * Curr = Head;
        Node * Prev = Head;
        
        if (Head == NULL)
        {
            return; // Empty list, nothing to do.
        }

        // Case: Only one node in the list.
        if (Head->Next == NULL)
        {
            delete Head;
            Head = NULL; // Important: Update Head to NULL. // List is now empty.
            return;
        }
        
        while (Curr->Next != NULL)
        {   Prev = Curr;
            Curr = Curr->Next;      // Traverse to the last node.
        }

        Prev->Next = NULL;          // Disconnect the last node.
        delete Curr;                // Free memory.
        _Size --;
    }

    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return !_Size;
    }

    void Clear()
    {
        while (!this->IsEmpty())
        {
            this->DeleteFirstNode();
        }
        
    }

    void Reverse()
    {
        Node* current = Head;
        Node* temp = nullptr;

        while (current!= nullptr)
        {
            temp = current->prev;
            current->prev = current->Next;
            current->Next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
        {
            Head = temp->prev;
        }
    }    

    Node* GetNode(int Index)
    {
        short counter = 0;

        if (Index > _Size - 1 || Index < 0)
        {
            return NULL;
        }
        
        Node* current = Head;
        while (current!= NULL)
        {
            if (counter == Index)
            {
                return current;
            }
            current = current->Next;
            counter++;
        }
            return NULL;
    }

    T GetItem(int Index)
    {
        Node * ItemNode = GetNode(Index);
        return (ItemNode == NULL)? NULL :  ItemNode->Value;
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);
        if (ItemNode != NULL)
        {
            ItemNode->Value = NewValue;
            return true;
        }
        else
        {
            return false;
        }
         
        
    }


};