#ifndef StringList_hpp
#define StringList_hpp


#include "ListNode.hpp"
#include "StringListIterator.hpp"
#include <string>
#include <cstddef>
#include <iostream>
#include <stdexcept>


//
// Accelerated C++, Chapter 10, Problem 4
//
// StringList is a doubly linked list that holds strings.
//
class StringList{
public:
  typedef std::string value_type;
  typedef std::string& reference;
  typedef const std::string& const_reference;
  typedef StringListIterator<value_type> iterator;
  typedef StringListIterator<const value_type> const_iterator;
  //  typedef StringListIterator<value_type>::difference_type difference_type;
  typedef ptrdiff_t difference_type;
  typedef size_t size_type;

  StringList() : m_begin(nullptr), m_end(nullptr), m_size(0) {}
  ~StringList() {
    StringList::clear();
  }

  iterator begin(){
    return iterator(m_begin);
  }
  const_iterator begin() const{
    return const_iterator(m_begin);
  }

  iterator end(){
    return iterator(m_end);
  }
  const_iterator end() const{
    return const_iterator(m_end);
  }

  bool empty() const {
    if(m_size == 0){
      return true;
    }else{
      return false;
    }
  }

  size_type size() const {
    return m_size;
  }

  reference front() {
    if(!m_begin){
      throw std::out_of_range("front() was called on an empty StringList...");
    }
    return m_begin->get_data();
  }
  const reference front() const {
    if(!m_begin){
      throw std::out_of_range("front() was called on an empty StringList...");
    }
    return m_begin->get_data();
  }

  reference back() {
    if(!m_begin){
      throw std::out_of_range("back() was called on an empty StringList...");
    }
    return m_end->get_prev()->get_data();
  }
  const reference back() const {
    if(!m_begin){
      throw std::out_of_range("back() was called on an empty StringList...");
    }
    return m_end->get_prev()->get_data();
  }

  void push_front(const value_type& val){
    auto new_begin = new ListNode<value_type>(val, nullptr, m_begin);
    if(m_begin){
      m_begin->set_prev(new_begin);
    }else{
      // the list was empty so the back element is now also the front element.
      m_end = new ListNode<value_type>(value_type(), new_begin, nullptr);
      new_begin->set_next(m_end);
    }
    m_begin = new_begin;
    ++m_size;
  }
  void pop_front(){
    if(!m_begin){
      throw std::out_of_range("pop_front() was called on an empty StringList...");
    }
    auto new_begin = m_begin->get_next();
    new_begin->set_prev(nullptr);
    delete m_begin;
    m_begin = new_begin;
    --m_size;
    if(m_begin == m_end){
      // the list had one element, so the back element was also the front (and both should be nullptr now).
      delete m_end;
      m_begin = nullptr;
      m_end = nullptr;
      m_size = 0;
    }
  }

  void push_back(const value_type& val){
    if(!m_begin){
      // if the list is empty, first make a new node for m_end
      m_end = new ListNode<value_type>(value_type(), nullptr, nullptr);
      auto new_node = new ListNode<value_type>(val, nullptr, m_end);
      m_end->set_prev(new_node);
      m_begin = new_node;
    }else{
      auto new_node = new ListNode<value_type>(val, m_end->get_prev(), m_end);
      m_end->get_prev()->set_next(new_node);
      m_end->set_prev(new_node);
    }
    ++m_size;
  }
  void pop_back(){
    if(!m_begin){
      throw std::out_of_range("pop_back() was called on an empty StringList...");
    }
    auto pop_node = m_end->get_prev();
    m_end->set_prev(pop_node->get_prev());
    if(m_end->get_prev()){
      m_end->get_prev()->set_next(m_end);
      --m_size;
    }else{
      // the list had one element, so the back element was also the front (and both should be nullptr now).
      delete m_end;
      m_begin = nullptr;
      m_end = nullptr;
      m_size = 0;
    }
    delete pop_node;
  }

  //  insert()
  //  erase()
  void clear(){
    if(m_begin){
      while(m_end->get_prev() != m_begin){
	// std::cout << "deleting word: " << m_end->get_prev()->get_data() << std::endl;
	auto dead_node = m_end->get_prev();
	m_end->set_prev(dead_node->get_prev());
	delete dead_node;
      }
      // std::cout << "deleting word: " << m_begin->get_data() << std::endl;
      delete m_begin;
      m_begin = nullptr;
      m_end = nullptr;
      m_size = 0;
    }
  }


private:
  ListNode<value_type>* m_begin;
  ListNode<value_type>* m_end;
  size_type m_size;

};








#endif
