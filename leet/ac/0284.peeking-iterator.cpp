/**
 * Below is the interface for Iterator, which is already defined for
 * you. **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *      struct Data;
 *      Data* data;
 *      Iterator(const vector<int>& nums);
 *      Iterator(const Iterator& iter);  // this is important, I can
 *                                       // copy it
 *
 *      // Returns the next element in the iteration.
 *      int next();
 *
 *      // Returns true if the iteration has more elements.
 *      bool hasNext() const;
 *  };
 **/

class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the
    // iterator.
    int peek() {
        // It allows me to copy the iterator, copy it and return copy's
        // next
        return Iterator(*this).next();
    }

    // hasNext() and next() should behave the same as in the Iterator
    // interface. Override them if needed.

    // Not needed to override

    // int next() {}
    // bool hasNext() const {}
};
