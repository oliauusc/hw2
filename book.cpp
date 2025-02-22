#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "book.h"


Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author) 
: Product("book", name, price, qty), isbn_(isbn), author_(author) {}

std::set<std::string> Book::keywords() const {
  std::set<std::string> words;
  words.insert(name_);
  words.insert(author_);
  words.insert(isbn_);
  return words;
}

std::string Book::displayString() const {
  std::string disp = name_ + 
  "\nAuthor: " + author_ + " ISBN: " + isbn_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
  return disp;
  //  std::ostringstream oss; 
  //   oss << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_
  //       << "\nPrice: " << price_ << " Quantity: " << qty_ << " left";
    
  //   return oss.str();
}

void Book::dump(std::ostream& os) const {
  os<< "book\n" << name_ << "\n" << price_ << "\n" << qty_ 
       << "\n" << isbn_ << "\n" << author_ << "\n";
}