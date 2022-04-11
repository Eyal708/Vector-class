#ifndef ITERATORS__LINKED_LIST_H_
#define ITERATORS__LINKED_LIST_H_

#include <iostream>

class LinkedList {

  // Nested private class - only used to save the elements of the list
  struct Node {
	int data_;
	Node* next_;
	Node(int data, Node *next) : data_(data), next_(next) {}
  };

public:
    LinkedList() : head_(nullptr) {}

    void push(int data) { head_ = new Node(data, head_); }

    void erase(int data) {
      Node *cur_node = head_;
      
      if(head_->data_ == data) {
            head_ = cur_node->next_;
            delete cur_node;
            return;
      }
      
      Node* last_node = nullptr;
      while (cur_node) {
        if (cur_node->data_ == data && last_node) {
            last_node->next_ = cur_node->next_;
            delete cur_node;
            break;
        }
        last_node = cur_node;
        cur_node = cur_node->next_;
      }
    }

    ~LinkedList() {
      Node *cur_node = head_, *next_node;
      while (cur_node) {
        next_node = cur_node->next_;
        delete cur_node;
        cur_node = next_node;
      }
    }
    
    
  class ConstIterator;

  /* Iterator class */
  class Iterator {
  private:
    friend class ConstIterator; // to allow Conversion constructor from Iterator to ConstIterator
    Node *node_;

  public:
    /* ITERATOR TRAITS - must be defined (and public) in the iterator, for it to work with all STL algorithms.
     * Comment this out and attempt to call std::find with this iterator to watch the runtime error
     * you will get if you don't define iterator traits */
    typedef int value_type;
    typedef int &reference;
    typedef int *pointer;
    typedef std::ptrdiff_t difference_type; // irrelevant here, as we have no difference - but still required
    typedef std::forward_iterator_tag iterator_category;

    Iterator(Node *node) : node_(node) {}

    Iterator &operator++() {
      node_ = node_->next_;
      return *this;
    }

    Iterator operator++(int) {
      Iterator it(node_);
      node_ = node_->next_;
      return it;
    }

    bool operator==(const Iterator &rhs) const { return node_ == rhs.node_; }

    bool operator!=(const Iterator &rhs) const { return node_ != rhs.node_; }

    reference operator*() { return node_->data_; }

    pointer operator->() { return &(operator*()); }
  };

  /* const iterator class - allows iteration without allowing changing of elements */
  class ConstIterator {
    Node *node_;
  public:
    typedef int value_type;
    typedef const int &reference; // note the difference between the const and non-const
    typedef const int *pointer; // note the difference between the const and non-const
    typedef std::ptrdiff_t difference_type; // irrelevant here, as we have no difference - but still required
    typedef std::forward_iterator_tag iterator_category;

    ConstIterator(Node *node) : node_(node) {}

    // Conversion ctor
    ConstIterator(const Iterator &it) : node_(it.node_) {}

    ConstIterator &operator++() {
      node_ = node_->next_;
      return *this;
    }

    ConstIterator operator++(int) {
      ConstIterator it(node_);
      node_ = node_->next_;
      return it;
    }

    bool operator==(const ConstIterator &rhs) const { return node_ == rhs.node_; }

    bool operator!=(const ConstIterator &rhs) const { return node_ != rhs.node_; }

    value_type operator*() { return node_->data_; }

    pointer operator->() { return &(node_->data_); }
  };

  Node *head_;

public:

  using iterator = Iterator; // same as typedef Iterator iterator;
  using const_iterator = ConstIterator;



  /* Iterator functions section - begin, end, etc
     begin will return an iterator or a const_iterator depending on the const-qualification of the object it is called on.
     cbegin will always return a const_iterator */
  iterator begin() {  return Iterator(head_); }
  const_iterator begin() const { return ConstIterator(head_); }
  const_iterator cbegin() const { return ConstIterator(head_); }
  iterator end() { return Iterator(nullptr); }
  const_iterator end() const { return ConstIterator(nullptr); }
  const_iterator cend() const {	return ConstIterator(nullptr);
  }

};

#endif //ITERATORS__LINKED_LIST_H_
