#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <algorithm>
#include "Picture.hpp"


//
// non-member functions implementation
//
Picture frame(const Picture& pic, const char corner_char, const char tb_char, const char left_char, const char right_char){
  return new Frame_Pic(pic.p, corner_char, tb_char, left_char, right_char);
}

Picture hcat(const Picture& l, const Picture& r){
  return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b){
  return new VCat_Pic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture){
  const Pic_base::ht_sz ht = picture.p->height();

  for(Pic_base::ht_sz i = 0; i != ht; ++i){
    picture.p->display(os, i, false);
    os << std::endl;
  }
  return os;
}


//
// Pic_base implementation
//
void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end){
  while(beg < end){
    os << " ";
    ++beg;
  }
}


//
// Picture implementation
//
Picture::Picture(const std::vector<std::string>& v) : p(new String_Pic(v)) {}


//
// String_Pic implementation
//
Pic_base::wd_sz String_Pic::width() const{
  Pic_base::wd_sz n = 0;
  for(Pic_base::ht_sz i = 0; i != data.size(); ++i){
    n = std::max(n, data[i].size());
  }
  return n;
}


void String_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const{
  wd_sz start = 0;

  if(row < height()){
    os << data[row];
    start = data[row].size();
  }

  if(do_pad){
    pad(os, start, width());
  }
}


//
// Frame_Pic implementation
//
void Frame_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const{
  if(row >= height()){
    if(do_pad){
      pad(os, 0, width());
    }
  }else{
    if(row == 0 || row == height() - 1){
      os << m_corner_char;
      if(width() >= 2){ // for size of string(n, char), n must be >= 0
	os << std::string(width() - 2, m_tb_char);
      }
      os << m_corner_char;
    }else if(row == 1 || row == height() - 2){
      os << m_l_char;
      pad(os, 1, width() - 1);
      os << m_r_char;
    }else{
      os << m_l_char << " ";
      p->display(os, row - 2, true);
      os << " " << m_r_char;
    }
  }
}


//
// HCat_Pic implementation
//
void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const{
  left->display(os, row, do_pad || row < right->height());
  right->display(os, row, do_pad);
}


//
// VCat_Pic implementation
//
void VCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const{
  wd_sz w = 0;
  if(row < top->height()){
    top->display(os, row, do_pad);
    w = top->width();
  }else if(row < height()){
    bottom->display(os, row - top->height(), do_pad);
    w = bottom->width();
  }
  if(do_pad){
    pad(os, w, width());
  }
}

