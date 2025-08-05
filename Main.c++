#include <iostream>
#include "Core/clsDblLinkedList.h" // Use relative path
using namespace std;


int main()
{
    clsDblLinkedList <int> MyDblLinkedList;
    
    
    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);
    
    /*
    // Find
    clsDblLinkedList<int>::Node* N1 = MyDblLinkedList.Find(2);
    if (N1 != NULL)
    cout << "\nNode with value 2 is Found :-)\n";
    else
    cout << "\nNode Is not found :-(\n";
    
    // Insert after
    MyDblLinkedList.InsertAfter(N1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MyDblLinkedList.PrintList();
    
    // Insert at end
    MyDblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MyDblLinkedList.PrintList();
    
    // Delete a node
    clsDblLinkedList<int>::Node* N2 = MyDblLinkedList.Find(4);
    MyDblLinkedList.DeleteNode(N2);
    cout << "\nAfter Deleting 4:\n";
    MyDblLinkedList.PrintList();
    
    // Delete First node
    MyDblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MyDblLinkedList.PrintList();
    
    // Delete Last node
    cout << "\nAfter Deleting Last Node:\n";
    MyDblLinkedList.DeleteLastNode();
    MyDblLinkedList.PrintList();
    
        if (MyDblLinkedList.IsEmpty())
        {
            cout << "\n\nYes List is Empty!.\n";
        }
        else
        {
            cout << "\n\nNot, List is NOT Empty!";
        }
        
        //    cout << "\nNumber Of items of the linked list is: " << MyDblLinkedList.Size();
            
        //    // Clear 
        //    cout << "\n\nExcuting Clear....\n"; 
        //    MyDblLinkedList.Clear();
        
        //     cout << "\nNumber Of items of the linked list is: " << MyDblLinkedList.Size();
                    
        // Print list before reverse
        MyDblLinkedList.PrintList();
     
        // excuteing the reverse
        MyDblLinkedList.Reverse();
     
        //print list after reverse
        MyDblLinkedList.PrintList();
        
        clsDblLinkedList <int> ::Node * N;
        N = MyDblLinkedList.GetNode(10);
        
        cout << "\nNode Value is: " << N->Value;
        cout << "\nLinked List content: \n";
        MyDblLinkedList.PrintList();
        
        cout << "\nItem(2) Value is: " << MyDblLinkedList.GetItem(2);

        MyDblLinkedList.UpdateItem(2,500);
    */
   
    cout << "\nLinked List content:\n";
    MyDblLinkedList.PrintList();
    
    MyDblLinkedList.InsertAfter(6,500);

    cout << "\nAfter insert:\n";
    MyDblLinkedList.PrintList();
    return 0;
}