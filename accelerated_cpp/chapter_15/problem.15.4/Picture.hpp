#ifndef guard_picture_hpp
#define guard_picture_hpp


#include <vector>
#include <queue>
#include <string>
#include <ostream>
#include "Ptr.hpp"


// Pic_base definition
class Picture;
//
// Trying to forward declare a Ptr<Pic_base> so it 
// can be declared a friend class in Pic_base but this
// is a circular reference?
//
// class Pic_base;
// template<>
// class Ptr<Pic_base>;
//

class Pic_base{
  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend void reframe(Picture&, std::queue<char>&);
  friend class Frame_Pic;
  friend class HCat_Pic;
  friend class VCat_Pic;
  friend class String_Pic;
  //  friend class Ptr<Pic_base>;

  typedef std::vector<std::string>::size_type ht_sz;
  typedef std::string::size_type wd_sz;

  virtual wd_sz width() const = 0;
  virtual ht_sz height() const = 0;
  virtual void display(std::ostream&, ht_sz, bool) const = 0;
  virtual void reframe(std::queue<char>&) = 0;


public:
  virtual ~Pic_base() {}
  //
  // clone() being public doesn't seem ideal to me,
  // but I don't know how to grant access to Ptr<Pic_base> otherwise.
  // I don't think it's valid to do so within Pic_base because
  // that creates a circular reference / incomplete type.
  //
  virtual Pic_base* clone() const = 0;


protected:
  static void pad(std::ostream& os, wd_sz beg, wd_sz end);

};


// Picture definition
class Picture{
  friend std::ostream& operator<<(std::ostream&, const Picture&);
  friend Picture frame(const Picture&, const char, const char, const char, const char);
  friend Picture hcat(const Picture&, const Picture&);
  friend Picture vcat(const Picture&, const Picture&);
  friend void reframe(Picture&, std::queue<char>&);

public:
  Picture(const std::vector<std::string>& = std::vector<std::string>());


private:
  Picture(Pic_base* ptr) : p(ptr) {}
  Ptr<Pic_base> p;
};


// non-member function definitions
Picture frame(const Picture&, const char = '*', const char = '*', const char = '*', const char = '*');
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);
void reframe(Picture&, std::queue<char>&);


// String_Pic definition
class String_Pic : public Pic_base{
  friend class Picture;
  std::vector<std::string> data;
  String_Pic(const std::vector<std::string>& v) : data(v) {}

  wd_sz width() const;
  ht_sz height() const { return data.size(); }
  void display(std::ostream&, ht_sz, bool) const;
  void reframe(std::queue<char>&) {}
  String_Pic* clone() const { return new String_Pic(*this); }
};


// Frame_Pic definition
class Frame_Pic : public Pic_base{
  friend Picture frame(const Picture&, const char, const char, const char, const char);
  Ptr<Pic_base> p;
  // framing characters to use for different frame sections
  char m_corner_char; // corner character
  char m_tb_char; // top and bottom character
  char m_l_char; // left character
  char m_r_char; // right character
  Frame_Pic(const Ptr<Pic_base>& pic, 
	    const char corner_char,
	    const char tb_char,
	    const char l_char, 
	    const char r_char) : p(pic), 
				       m_corner_char(corner_char),
				       m_tb_char(tb_char),
				       m_l_char(l_char),
				       m_r_char(r_char) {}

  wd_sz width() const { return p->width() + 4; }
  ht_sz height() const { return p->height() + 4; }
  void display(std::ostream&, ht_sz, bool) const;
  void reframe(std::queue<char>&);
  Frame_Pic* clone() const { return new Frame_Pic(*this); }
};


// HCat_Pic definition
class HCat_Pic : public Pic_base{
  friend Picture hcat(const Picture&, const Picture&);
  Ptr<Pic_base> left, right;
  HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) {}

  wd_sz width() const { return left->width() + right->width(); }
  ht_sz height() const { return std::max(left->height(), right->height()); }
  void display(std::ostream&, ht_sz, bool) const;
  void reframe(std::queue<char>&);
  HCat_Pic* clone() const { return new HCat_Pic(*this); }
};


// VCat_Pic definition
class VCat_Pic : public Pic_base{
  friend Picture vcat(const Picture&, const Picture&);

  Ptr<Pic_base> top, bottom;
  VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) {}

  wd_sz width() const { return std::max(top->width(), bottom->width()); }
  ht_sz height() const { return top->height() + bottom->height(); }
  void display(std::ostream&, ht_sz, bool) const;
  void reframe(std::queue<char>&);
  VCat_Pic* clone() const { return new VCat_Pic(*this); }
};




#endif
