#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"



class MyDataStore : public DataStore {
public:
    ~MyDataStore();

    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;
    void addToCart(Product* p, std::string username);
    std::vector<Product*>& getCart(std::string username);
    std::map<std::string, User*> getUsers() const;
    // void saveDatabase();
    
private:
    std::set<Product*> products;
    // std::set<User*> users;
    std::map<std::string, User*> users;
    std::map<std::string, std::vector<Product*>> cart;
};

#endif
