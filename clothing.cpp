#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "clothing.h"


Clothing::Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand) 
: Product("clothing", name, price, qty), size_(size), brand_(brand) {}

std::set<std::string> Clothing::keywords() const {
  std::set<std::string> words;
  words.insert(name_);
  words.insert(brand_);
  words.insert(size_);
  return words;
}

std::string Clothing::displayString() const {
  std::string disp = name_ + 
  "\nSize: " + size_ + " Brand: " + brand_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
  return disp;
  //  std::ostringstream oss; 
  //   oss << name_ << "\nAuthor: " << brand_ << " ISBN: " << size_
  //       << "\nPrice: " << price_ << " Quantity: " << qty_ << " left";
    
  //   return oss.str();
}

void Clothing::dump(std::ostream& os) const {
  os<< "clothing\n" << name_ << "\n" << price_ << "\n" << qty_ 
       << "\n" << size_ << "\n" << brand_ << "\n";
}