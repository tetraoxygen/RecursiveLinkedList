/**
* @file	LinkedListRecursion.cpp
* @author	Rich Albers, Charlie Welsh
* @version	1.0
*
*   Example Linked List class to demonstrate processing a linked list using recursion.
*
*   Note: All source code for the LL definition and implementation, as well as main() is 
*         included in this one file for ease of downloading.  This is atypical.
*/

#include <iostream>

struct Node {
  int data;
  Node* next;
};

class LL {
public:
  /**
  * Default Constructor - Initializes Member Variables
  */
  LL() {
    head = nullptr;
  }

  /**
  * Destructor - frees up all dynamically allocated memory
  */
  ~LL() {
    Node* current = head;

    while (current != nullptr) {
      Node* nodeToDelete = current;
      current = current->next;
      delete nodeToDelete;
      nodeToDelete = current;
    }

    head = nullptr;
  }

  /**
  *	Adds a new node at the beginning of the list
  *	@param value The value to place in the new node
  */
  void prepend(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    head = newNode;
  }

  /**
  * prints the list (space delimited) in order
  */
  void printList() {
    Node* curr = head;
    while (curr != nullptr) {
      std::cout << curr->data << ' ';
      curr = curr->next;
    }
    std::cout << "\n";
  }

  /**
  * prints the list in reverse order
  */
  void printListReverse() {
    printListReverseR(head);
    std::cout << "\n";
  }

  /**
  * finds average of values in nodes
  * @return the average of all the values in the nodes.
  */
  double average() {
    return averageR(head, 0, 0);
  }
  
  /**
  * prints the first, last, and then first again elements of a list.
  */
  void printFirstLastFirst(Node* current = nullptr) {
    if (current == nullptr) {
      current = head;
    }
    
    if (current->next == nullptr) {
      std::cout << head->data << " " << current->data << " " << head->data << std::endl;
    } else {
      printFirstLastFirst(current->next);
    }
  }

private:
  Node* head;

  /**
  *	recursive routine to print list in reverse order
  *	@param curr	current node to process
  */
  void printListReverseR(Node* curr) {
    if (curr == nullptr)
      return;
    printListReverseR(curr->next); // recursive traversal of the list
    std::cout << curr->data << ' ';
  }

  /**
  * recursive routine to compute the average
  * @param curr	current node to process
  * @param count	count of nodes processed so far
  * @param sum	sum of nodes processed so far
  */
  double averageR(Node* curr, int count, int sum) {
    if (curr == nullptr) 
      return static_cast<double>(sum) / count;
    return averageR(curr->next, count + 1, sum + curr->data);
  }
};

// ===============================================================================
int main() {
  LL numList;

  numList.prepend(8); 
  numList.prepend(4); 
  numList.prepend(2); 
  numList.prepend(1); 
  // List should now contain: 1,2,4, and 8)

  std::cout << "List in order: ";
  numList.printList();

  std::cout << "List in reverse order: ";
  numList.printListReverse();

  std::cout << "Average: " <<	numList.average() << "\n";

  std::cout << "First, Last, First: ";
  numList.printFirstLastFirst();

  return 0;
}

