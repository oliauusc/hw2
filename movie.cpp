#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "movie.h"


Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating) 
: Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

std::set<std::string> Movie::keywords() const {
  std::set<std::string> words;
  words.insert(name_);
  words.insert(genre_);
  words.insert(rating_);
  return words;
}

std::string Movie::displayString() const {
  std::string disp = name_ + 
  "\nGenre: " + genre_ + " Rating: " + rating_ +
  "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left";
  return disp;
  //  std::ostringstream oss; 
  //   oss << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_
  //       << "\nPrice: " << price_ << " Quantity: " << qty_ << " left";
    
  //   return oss.str();
}

void Movie::dump(std::ostream& os) const {
  os<< "movie\n" << name_ << "\n" << price_ << "\n" << qty_ 
       << "\n" << genre_ << "\n" << rating_ << "\n";
}