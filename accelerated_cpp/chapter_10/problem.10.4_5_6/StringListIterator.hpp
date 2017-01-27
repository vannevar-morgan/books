#ifndef StringListIterator_hpp
#define StringListIterator_hpp


#include <iterator>
#include <type_traits>
#include <cstddef>
#include "ListNode.hpp"



//
// Accelerated C++, Chapter 10, Problem 5
//
// Iterator for a StringList.
// StringList is a doubly linked list that holds strings.
//
template <class Type, class UnqualifiedType = typename std::remove_cv<Type>::type>
class StringListIterator : public std::iterator<std::bidirectional_iterator_tag, 
					        UnqualifiedType,
					        std::ptrdiff_t,
					        Type*,
					        Type& >{
public:
  StringListIterator() : m_node(nullptr) {}
  explicit StringListIterator(ListNode<UnqualifiedType>* node) : m_node(node) {}

  StringListIterator& operator++ () {
    // need to check if the node is nullptr
    m_node = m_node->get_next();
    return *this;
  }

  StringListIterator operator++ (int) {
    // need to check if the node is nullptr
    StringListIterator tmp(*this);
    m_node = m_node->get_next();
    return tmp;
  }

  StringListIterator& operator-- () {
    // need to check if the node is nullptr
    m_node = m_node->get_prev();
    return *this;
  }

  StringListIterator operator-- (int) {
    // need to check if the node is nullptr
    StringListIterator tmp(*this);
    m_node = m_node->get_prev();
    return tmp;
  }

  bool operator== (const StringListIterator& rhs) const { return m_node == rhs.m_node; }

  bool operator!= (const StringListIterator& rhs) const { return m_node != rhs.m_node; }

  Type& operator* () const {
    // need to check if the node is nullptr
    return m_node->get_data();
  }

  Type& operator-> () const {
    // need to check if the node is nullptr
    return m_node->get_data();
  }

  operator StringListIterator<const Type>() const {
    return StringListIterator<const Type>(m_node);
  }



private:
  ListNode<UnqualifiedType>* m_node;


};





#endif
