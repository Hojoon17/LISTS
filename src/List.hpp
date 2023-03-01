/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
#include <iostream>

template <class T>
List<T>::List() { 
  // @TODO: graded in mp_lists part 1
    head_ = NULL; 
    tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in mp_lists part 1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in mp_lists part 1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in mp_lists part 1
  while (head_ != NULL) {
    // deleting each of the node inside the ll
    ListNode* tmp = head_ -> next; // move it to next node before deleting
    delete head_;  // delete the head
    head_ = tmp; // initialize head as next head
  } 
  // checking head and tail to be null
  head_ = NULL; 
  tail_ = NULL;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in mp_lists part 1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  // newNode -> prev -> next
  
  if (head_ != NULL) {
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  // declare the head_
  head_ = newNode;
  length_++;
  // std::cout << length_ << std::endl; 
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in mp_lists part 1
  ListNode * newn = new ListNode(ndata); // to insert the node inside the linked list
  //ListNode * dupl = head_;
  
  if (tail_ != NULL) {
    tail_ -> next = newn;
    newn -> next = NULL;  
    newn -> prev = tail_;
    tail_ = newn; 
  } 
  else if (tail_ == NULL) {
    head_ = tail_ = newn;
  }
  // tail_->next == *(tail_).next
  length_++; 
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in mp_lists part 1
  // before doing it, compare splitpoint and length (including equal since there is nothing in the subhead)
  // should consider the edge cases
  // if (start == nullptr) {
  //   return nullptr;
  // }

  // if (splitPoint >= length_) {
  //   return head_; 
  // }
  // if (splitPoint >= length_) {
  //   return nullptr; 
  // }
  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != nullptr; i++) {
    curr = curr->next;
  }
  if (curr != NULL) {
      // updating the tail before disconnecting
      // tail_ = curr -> prev;
      if (curr -> prev == NULL) {
        return curr;
      }
      curr->prev->next = NULL;
      curr->prev = NULL; 
  } 
  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in part 1
  ListNode * curr = head_;
  // std::cout << i << std::endl; 
  // std::cout << curr -> data << std::endl; 
  // std::stringstream nname;
  // print(nname);
  // std::cout << nname.str() << std::endl; 
  while (curr != nullptr) {
    tail_ -> next = curr -> next;
    tail_ -> next -> prev = tail_; 
    curr -> next = curr -> next -> next; 
    curr -> next -> prev = curr; 
    tail_ -> next -> next = NULL; 
    tail_ = tail_ -> next; 
    

    curr = curr -> next;
    // std::cout << i << std::endl; 
    // std::cout << curr -> data << std::endl; 
    // std::stringstream nname;
    // print(nname);
    // std::cout << nname.str() << std::endl; 
    if (curr -> next == tail_) {
      break;
    }
  }
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in mp_lists part 2
  ListNode* upstart = startPoint;
  ListNode* prest = startPoint -> prev;
  ListNode* upend = endPoint;
  ListNode* predend = endPoint -> next; 

  while (upstart != predend) {
      ListNode* tmpchange = upstart -> next;
      upstart -> next = upstart -> prev; 

      upstart -> prev = tmpchange; 
      // update where upstart is
      upstart = tmpchange; 
  }   
  upend -> prev = prest; 
  startPoint -> next = predend;
  if (prest != NULL) {
    prest -> next = upend;
  }
  if (predend != NULL) {
    predend -> prev = startPoint;
  }
  std::swap(startPoint,endPoint);
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in mp_lists part 2

   ListNode* curr = head_;
   ListNode* currend = head_;
  
  for (int j = 0; j <= length_/n; j++) {
    int i = 0;
    while (i < n - 1 && currend -> next != NULL) { // i < n - 1
        
      currend = currend -> next; 
      i++;

      // std::cout << "Inside while loop" << std::endl;
    }
    reverse(curr,currend); 
    //std::cout << curr ->data << std::endl;
    //std::cout << currend ->data << std::endl;
    // print();
    if (j == 0) {
      head_ = curr; 
    }
    //print();
    if (currend -> next != nullptr) {
      curr = currend -> next;
      currend = curr; 
    } else {
      tail_ = currend;
      break;
    }
    // std::cout << "Inside for loop" << std::endl;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in mp_lists part 2
  ListNode* result = nullptr;
  if (first == NULL) {
    return second; 
  }
  if (second == NULL) {
    return first; 
  }

  if (first -> data  < second -> data) {
    // inserting first into the node; 
    result = first; 
    first = first -> next; 
  } else {
    result = second;  
    
    second = second -> next;  
  }

  ListNode * dummy  = result;
  while (first != nullptr && second != nullptr) {
    if (first -> data  < second -> data) {
    // inserting first into the node; 
      first -> prev = dummy;  
      dummy -> next = first; 

      first = first -> next; 
    } else {
      second -> prev = dummy;  
      dummy -> next = second; 

      second = second -> next;   
    }
    dummy = dummy -> next; 
  }
  if (first == NULL) {
    dummy -> next = second; 
    second -> prev = dummy; 
  }
  if (second == NULL) {
    dummy -> next = first; 
    first -> prev = dummy; 
  }


  return result;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in mp_lists part 2
  // Base Case 
  ListNode * result = nullptr; 
  if (chainLength == 1 || chainLength == 0) {
    return start; 
  }
  // Split the current list into two smaller, more manageable parts (Maybe use split?)
  int dhalf = chainLength/2;
  ListNode* half = split(start, dhalf); // second list after splitting the list
  // Sort the two halves (this should be a recursive call) (Use the sort function given to us?)
  ListNode * firstn = mergesort(start, dhalf); 
  ListNode * secondn = mergesort(half, chainLength - dhalf);
  
  // Merge the two sorted halves back together into a single list
  result = merge(firstn, secondn); 

  return result;
  //return NULL;
}
