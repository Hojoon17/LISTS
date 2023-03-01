
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
  private:
    // @TODO: graded in mp_lists part 1
    ListNode* position_;
    ListNode* tail_;

  public:
    ListIterator() : position_(NULL) { }
    ListIterator(ListNode* x) : position_(x) { }


    // Pre-Increment, ++iter
    ListIterator& operator++() {
        // @TODO: graded in mp_lists part 1
        position_ = position_->next;
        return *this;
    }
    
    // Post-Increment, iter++
    ListIterator operator++(int) {
        // @TODO: graded in mp_lists part 1
        ListIterator incre = *this;
        position_ = position_->next;
        return incre;
    }

    // Pre-Decrement, --iter
    ListIterator& operator--() {
        // @TODO: graded in mp_lists part 1
        // if (position_ == tail_ -> next) {
        //     return tail_;
        // }
        position_ = position_-> prev;
        return *this;
    }

    // Post-Decrement, iter--
    ListIterator operator--(int) {
        // @TODO: graded in mp_lists part 1
        // if (position_ == tail_ -> next) {
        //     return tail_;
        // }
        ListIterator decre = *this;
        position_ = position_-> prev;
        return decre;
    }
    
    bool operator!=(const ListIterator& rhs) {
        // @TODO: graded in mp_lists part 1
        if (position_ != rhs.position_) {
            return true;
        }
        return false;
    }
    bool operator==(const ListIterator& rhs) {
        return !(*this != rhs);
    }

    const T& operator*() {
        return position_->data;
    }

    const T* operator->() {
        return &(position_->data);
    }
};
