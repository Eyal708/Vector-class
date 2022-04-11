//
// Created by eyal7 on 6/19/2021.
//
#define STATIC_CAP 16
#define INCREASE_FACTOR 1.5
#include <iostream>
#include <algorithm>
#ifndef _VL_VECTOR_H_
#define _VL_VECTOR_H_
enum MemoryState {
    STATIC,
    DYNAMIC
};
template<class T, size_t Cap = STATIC_CAP>
class vl_vector {
 public:
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
  iterator begin ()
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[0];
      }
    return &_dynamic_arr[0];
  }
  iterator end ()
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[_size];
      }

    return &_dynamic_arr[_size];

  }
  const_iterator begin () const
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[0];
      }

    return &_dynamic_arr[0];
  }
  const_iterator end () const
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[_size];
      }

    return &_dynamic_arr[_size];
  }
  const_iterator cbegin () const
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[0];
      }

    return &_dynamic_arr[0];
  }
  const_iterator cend () const
  {
    if (_mem_state == STATIC)
      {
        return &_static_arr[_size];
      }

    return &_dynamic_arr[_size];
  }
  reverse_iterator rbegin ()
  {
    return reverse_iterator(end());

  }
  reverse_iterator rend()
  {
    return reverse_iterator(begin());
  }
  const_reverse_iterator rbegin () const
  {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator rend() const
  {
   return const_reverse_iterator(begin());
  }

  const_reverse_iterator crbegin () const
  {
    return const_reverse_iterator(end());
  }
  const_reverse_iterator crend() const
  {
    return const_reverse_iterator(begin());
  }
  /**
   * constructs an empty vector
   */
  vl_vector<T, Cap> ()
      : _mem_state (STATIC), _size (0),
        _capacity (Cap), _static_capacity (Cap), _dynamic_arr (nullptr)
  {}

  /**
   * copy constructor
   * @param vec the vector to copy
   */
  vl_vector<T, Cap> (const vl_vector<T, Cap> &other) :
      _mem_state (other._mem_state), _size (other._size),
      _capacity (other._capacity), _static_capacity (other._static_capacity),
      _dynamic_arr (nullptr)
  {
    if (other._mem_state == DYNAMIC)
      {
        this->_dynamic_arr = new T[this->_capacity];
      }
    std::copy (other.begin (), other.end (), this->begin ());
  }
/**
 * sequence based constructor, inserts all the elements in sequence to the
 * vector
 * @param first an iterator to the start of the sequence
 * @param last and iterator to the end of the sequence
 */
 template<class ForwardIterator>
  vl_vector<T, Cap> (ForwardIterator first, ForwardIterator last) :
      _mem_state (STATIC),
  _size (0), _capacity (Cap), _static_capacity (Cap),
  _dynamic_arr (nullptr)
  {
    int count = std::distance (first, last);
    if (count > this->_capacity)
      {
        increase_capacity (count);
      }
    _size = count;
    std::copy (first, last, this->begin ());
  }

  vl_vector<T, Cap> (size_t count, T element) : _mem_state (STATIC),
  _size (0), _capacity (Cap), _static_capacity (Cap), _dynamic_arr (nullptr)
  {
    if (count > this->_capacity)
      {
        increase_capacity (count);
      }
    _size = count;
    std::fill (this->begin (), this->end (), element);
  }
  ~vl_vector<T, Cap> ()
  {
    delete[] _dynamic_arr;
  }

  /**
   * get vector's size
   * @return size of vector
   */
  size_t size () const
  { return _size; }
  /**
   * get vector's capacity
   * @return capacity of vector
   */
  size_t capacity () const
  { return _capacity; }
  /**
   * check if vector is empty
   * @return true if empty' otherwise false
   */
  bool empty () const
  { return _size == 0; }
  //write all other methods
  /**
   * insert an element to the end of the vector, if needed change capacity
   * and/or memory state
   * @param element element to insert
   */
  void push_back (T element)
  {

    if (_size + 1 > _capacity)
      {
        increase_capacity (1);
      }
    _size++;
    if (_mem_state == STATIC)
      {
        _static_arr[_size - 1] = element;
      }
    else
      {
        _dynamic_arr[_size - 1] = element;
      }

  }
  const T &at (size_t ind) const
  {
    if (ind >= _size)
      {
        throw std::out_of_range ("Index is out of range!");
      }
    if (_mem_state == STATIC)
      {
        return _static_arr[ind];
      }
    else
      {
        return _dynamic_arr[ind];
      }
  }
  /**
   * inserts an element to a vector at a given position
   * @param pos an iterator to the position to insert the element
   * @param element the element to insert
   * @return an iterator to the inserted element
   */
  iterator insert (const_iterator pos, T element)
  {
    size_t d = std::distance (this->cbegin (), pos);
    if (_size + 1 > _capacity)
      {
        increase_capacity (1);
      }
    make_space (this->begin () + d, 1);
    iterator j = this->begin () + d;
    _size++;
    *j = element;
    return j;

  }
  /**
   * inserts a sequence at a certain position in the vector
   * @param pos an iterator to a position in the vector to insert
   * @param first an iterator to the start of the sequence we want to insert
   * @param last an iterator to the end of the sequence we want to insert
   * @return a const_iterator to the beginning of the sequence in the vector
   */
  template<class ForwardIterator>
  iterator insert (const_iterator pos, ForwardIterator first,
                         ForwardIterator last)
  {
    size_t d = std::distance (this->cbegin (), pos);
    size_t count = std::distance (first, last);
    if (_size + count > _capacity)
      {
        increase_capacity (count);
      }
    make_space (this->begin () + d, count);
    std::copy (first, last, this->begin () + d);
    _size += count;
    return this->begin () + d;
  }
  /**
   * removes the last element in the vector, and decreases capacity and size
   * accordingly. if needed switches memory to static
   */
  void pop_back ()
  {
    if (_size == 0)
      {
        return;
      }
    _size--;
    if (_mem_state == DYNAMIC && _size <= _static_capacity)
      {
        decrease_capacity ();
      }
  }
  /**
   * erases an element at a certain position from the vector
   * @param pos and iterator to the element in the vector to erase
   * @return an iterator to the element to the right from pos
   */
  iterator erase (const_iterator pos)
  {
    size_t d = std::distance (this->cbegin (), pos);
    std::copy (this->begin () + d + 1, this->end (), this->begin () + d);
    _size--;
    if (_mem_state == DYNAMIC && _size <= _static_capacity)
      {
        decrease_capacity ();
      }
    return this->begin () + d;
  }
  /**
  * erases a sequence at a sequence from the vector
  * @param first an iterator to the start of the sequence we want to erase
  * @param last an iterator to the end of the sequence we want to erase
  * @return a const_iterator to the right of the sequence in the vector
  */
  iterator erase (const_iterator first, const_iterator last)
  {
    if (first >= last)
      {
        return first;
      }
    size_t count = std::distance (first, last);
    size_t first_pos = std::distance (this->cbegin (), first);
    size_t last_pos = std::distance (this->cbegin (), last);
    std::copy (
        this->begin () + last_pos, this->end (), this->begin () + first_pos);
    _size -= count;
    if (_mem_state == DYNAMIC && _size <= _static_capacity)
      {
        decrease_capacity ();
      }
    return this->begin () + first_pos;
  }
  /**
   * clears all elements in the vector
   */
  void clear ()
  {
    delete[]_dynamic_arr;
    _dynamic_arr= nullptr;
    _mem_state = STATIC;
    _capacity = _static_capacity;
    _size = 0;
  }
  /**
   * @return a pointer to where the elements in the vector are held(const ver).
   */
   const T *data () const
  {
    if (_mem_state == DYNAMIC)
      {
        return _dynamic_arr;
      }
    return _static_arr;
  }
  /**
   * @return a pointer to where the elements in the vector are held
   * (non const ver).
   */
   T *data ()
  {
    if (_mem_state == DYNAMIC)
      {
        return _dynamic_arr;
      }
    return _static_arr;
  }

  /**
   * checks if an element is in the vector
   * @return true if element is in the vector, else false
   */
  bool contains (const T &element) const
  {
    const T *arr = this->data ();
    for (size_t i = 0; i < _size; i++)
      {
        if (arr[i] == element)
          {
            return true;
          }
      }
    return false;

  }
  /**
   * assignment operator for vl_vector
   * @param other the vector who's values we want to assign
   * @return a reference to the vector we assigned to
   */
  vl_vector<T, Cap> &operator= (const vl_vector<T, Cap> &other)
  {
    if (&other != this)
      {
        delete[] this->_dynamic_arr;
        this->_dynamic_arr = nullptr;
        if (other._mem_state == STATIC)
          {
            for (size_t i = 0; i < other._size; i++)
              {
                this->_static_arr[i] = other._static_arr[i];
              }
          }
        else
          {
            this->_dynamic_arr = new T[other._capacity];
            for (size_t i = 0; i < other._size; i++)
              {
                this->_dynamic_arr[i] = other._dynamic_arr[i];
              }
          }
        this->_capacity = other._capacity;
        this->_size = other._size;
        this->_mem_state = other._mem_state;
      }
    return *this;

  }
  const T &operator[] (size_t index) const
  {
     const T *arr = this->data ();
    return arr[index];
  }
  T &operator[] (size_t index)
  {
    if (this->_mem_state == STATIC)
      {
        return this->_static_arr[index];
      }
    return this->_dynamic_arr[index];
  }
  bool operator== (const vl_vector<T, Cap> &other) const
  {
    if (this->_size != other._size)
      {
        return false;
      }
     const T *lhs_arr = this->data ();
     const T *rhs_arr = other.data ();
    for (size_t i = 0; i < other._size; i++)
      {
        if (lhs_arr[i] != rhs_arr[i])
          {
            return false;
          }
      }
    return true;
  }
  bool operator!= (const vl_vector<T, Cap> &other) const
  {
    return !(*this == other);
  }

 private:
  MemoryState _mem_state;
  size_t _size;
  size_t _capacity;
  size_t _static_capacity;
  T _static_arr[Cap];
  T *_dynamic_arr;
  void switch_to_dynamic ()
  {
    _dynamic_arr = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
      {
        _dynamic_arr[i] = _static_arr[i];
      }
    _mem_state = DYNAMIC;

  }
  void switch_to_static ()
  {
    for (size_t i = 0; i < _size; i++)
      {
        _static_arr[i] = _dynamic_arr[i];
      }
    _mem_state = STATIC;
    delete[] _dynamic_arr;
    _dynamic_arr = nullptr;

  }
  /**
   *increase vector capacity, and change memory to dynamic if necessary.
   * @param k the number of items to insert to the vector
   */
  void increase_capacity (size_t k)
  {
    _capacity = INCREASE_FACTOR * (_size + k);
    if (_mem_state == STATIC)
      {
        switch_to_dynamic ();
        return;
      }
    T *new_arr = new T[_capacity];
    for (size_t i = 0; i < _size; i++)
      {
        new_arr[i] = _dynamic_arr[i];
      }
    delete[]_dynamic_arr;
    _dynamic_arr = new_arr;

  }
  /**
   * decreases vector's capacity and switches memory state to static if needed
   */
  void decrease_capacity ()
  {
    switch_to_static ();
    _capacity = _static_capacity;
  }
  /**
   * moves all the elements from pos in vector a number of steps to the "right"
   * @param an iterator to the position to start moving elements from
   * @param s the number of steps each element should move
   */
  void make_space (const_iterator pos, size_t s)
  {
    iterator i = this->end () - 1;
    while (i >= pos)
      {
        *(i + s) = *i;
        i--;
      }
  }
};
#endif //_VL_VECTOR_H_
