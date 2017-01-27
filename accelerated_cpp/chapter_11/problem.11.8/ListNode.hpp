#ifndef ListNode_hpp
#define ListNode_hpp

//
// ListNode<T> represents a node in a doubly linked list of type 'T'.
//

template <class T>
class ListNode{
public:
  ListNode() : m_data(T()), m_prev(nullptr), m_next(nullptr) {}
  ListNode(T data) : m_data(data), m_prev(nullptr), m_next(nullptr) {}
  ListNode(T data, ListNode<T>* prev, ListNode<T>* next) : m_data(data), m_prev(prev), m_next(next) {}

  T& get_data() { return m_data; }
  const T& get_data() const { return m_data; }

  ListNode<T>* get_next() { return m_next; }
  const ListNode<T>* get_next() const { return m_next; }

  ListNode<T>* get_prev() { return m_prev; }
  const ListNode<T>* get_prev() const { return m_prev; }

  void set_data(T data) { m_data = data; }
  void set_next(ListNode<T>* next) { m_next = next; }
  void set_prev(ListNode<T>* prev) { m_prev = prev; }


private:
  T m_data;
  ListNode<T>* m_prev;
  ListNode<T>* m_next;

};


#endif
