#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "mydatastore.h"
#include "util.h"

MyDataStore::~MyDataStore() {
    for (std::set<Product*>::iterator p = products.begin(); p != products.end(); ++p) {
        delete (*p);
    }
    products.clear();

    for (std::map<std::string, User*>::iterator u = users.begin(); u != users.end(); ++u) {
        delete (u->second);
    }
    users.clear();
}

void MyDataStore::addProduct(Product* p) {
  products.insert(p);
}

std::set<std::string> vectorToSet(const std::vector<std::string>& vec) {
    return std::set<std::string>(vec.begin(), vec.end());
}

void MyDataStore::addUser(User* u) {
  users.insert(make_pair(u->getName(), u));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
  std::vector<Product*> results;
  std::set<std::string> foundTerms, setTerms, currentKW;
  std::string stringTerms, stringKW;

  // setTerms = vectorToSet(terms);
  for (int v = 0; v<terms.size(); v++) {
    stringTerms += terms[v];
    stringTerms += " ";
}
  setTerms = parseStringToWords(stringTerms);

  for (std::set<Product*>::iterator p = products.begin(); p != products.end(); ++p) {
    stringKW.clear();
    currentKW = (*p)->keywords();
    // setTerms = parseStringToWords(stringTerms);
    for (std::set<std::string>::iterator it = currentKW.begin(); it != currentKW.end(); ++it) {
      stringKW += *it;
      stringKW += " ";
    }

    currentKW = parseStringToWords(stringKW);
    foundTerms = setIntersection(currentKW, setTerms);

        if ((type == 0 && foundTerms.size() == setTerms.size()) || (type == 1 && !foundTerms.empty())) {                  
            // results.insert(results.begin(), *p);
            results.push_back(*p);
        }

    // if (type == 0) {
    //   foundTerms = setIntersection(currentKW, setTerms);

    //   if (foundTerms.size()== terms.size())
    //     results.push_back(*p);
    // }
    // else if (type ==1) {
    //     foundTerms = setIntersection(currentKW, setTerms);

    //     if (!foundTerms.empty())
    //       results.push_back(*p);
    // } 
  }
    return results;
}

void MyDataStore::dump(std::ostream& ofile) {
    ofile << "<products>\n";
    for (std::set<Product*>::iterator p = products.begin(); p != products.end(); ++p) {
      (*p)->dump(ofile);
      // delete (*p);
  }
    ofile << "</products>\n";

    ofile << "<users>\n";
    for (std::map<std::string, User*>::iterator u = users.begin(); u != users.end(); ++u) {
      ((*u).second)->dump(ofile);
      // delete (*u).second;
  }
    ofile << "</users>\n";
}

void MyDataStore::addToCart(Product* p, std::string username){
  cart[username].push_back(p);
}

std::vector<Product*>& MyDataStore::getCart(std::string username){
      static std::vector<Product*> empty;

  if (cart.find(username)!= cart.end())
    return cart[username];
  else {
    return empty;
  }
}

std::map<std::string, User*> MyDataStore::getUsers() const {
  return users;
}


// void MyDataStore::saveDatabase() {
//   // inFile = "database.txt";
// }
