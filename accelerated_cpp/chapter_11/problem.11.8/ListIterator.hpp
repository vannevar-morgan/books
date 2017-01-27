#ifndef ListIterator_hpp
#define ListIterator_hpp


#include <iterator>
#include <type_traits>
#include <cstddef>
#include "ListNode.hpp"



//
// Accelerated C++, Chapter 11, Problem 8
//
// (Builds on StringListIterator from Chapter 10, Problem 5)
// Iterator for a List.
// List is a doubly linked list that holds values of type UnqualifiedType
//
template <class Type, class UnqualifiedType = typename std::remove_cv<Type>::type>
class ListIterator : public std::iterator<std::bidirectional_iterator_tag, 
                                          UnqualifiedType,
				          std::ptrdiff_t,
  				          Type*,
				          Type& >{
public:
  ListIterator() : m_node(nullptr) {}
  explicit ListIterator(ListNode<UnqualifiedType>* node) : m_node(node) {}

  ListIterator& operator++ () {
    // need to check if the node is nullptr
    m_node = m_node->get_next();
    return *this;
  }

  ListIterator operator++ (int) {
    // need to check if the node is nullptr
    ListIterator tmp(*this);
    m_node = m_node->get_next();
    return tmp;
  }

  ListIterator& operator-- () {
    // need to check if the node is nullptr
    m_node = m_node->get_prev();
    return *this;
  }

  ListIterator operator-- (int) {
    // need to check if the node is nullptr
    ListIterator tmp(*this);
    m_node = m_node->get_prev();
    return tmp;
  }

  bool operator== (const ListIterator& rhs) const { return m_node == rhs.m_node; }

  bool operator!= (const ListIterator& rhs) const { return m_node != rhs.m_node; }

  Type& operator* () const {
    // need to check if the node is nullptr
    return m_node->get_data();
  }

  Type& operator-> () const {
    // need to check if the node is nullptr
    return m_node->get_data();
  }

  operator ListIterator<const Type>() const {
    return ListIterator<const Type>(m_node);
  }



private:
  ListNode<UnqualifiedType>* m_node;


};





#endif
