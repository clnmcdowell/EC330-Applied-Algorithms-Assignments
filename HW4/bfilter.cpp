// hash functions from http://www.partow.net/programming/hashfunctions/index.html#AvailableHashFunctions

#include <vector>
#include "bfilter.h"


class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        return 0;
    }
};

class GoodHashFun_0 : public HashFun 
{
    unsigned int operator()(const std::string& key) //RS hash function, modified to work with strings
    {
        unsigned int b = 378551;
        unsigned int a = 63689;
        unsigned int hash = 0;
        unsigned int i = 0;
        unsigned int str = 0;

        for (i = 0; i < key.size(); ++str, ++i)
        {
            hash = hash * a + (key[str]);
            a = a * b;
        }

        return hash;
    }
};

class GoodHashFun_1 : public HashFun
{
    unsigned int operator()(const std::string &key) //JS hash function, modified to work with strings
    {
        unsigned int hash = 1315423911;
        unsigned int i = 0;
        unsigned int str = 0;

        for (i = 0; i < key.size(); ++str, ++i)
        {
            hash ^= ((hash << 5) + (key[str]) + (hash >> 2));
        }

        return hash;
    }
};

void BloomFilter::add_hash_funs() {
    GoodHashFun_0 *h1 = new GoodHashFun_0();
    GoodHashFun_1 *h2 = new GoodHashFun_1();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) { 
    unsigned int hash_result;

    for(int i = 0; i < (this->hash_funs.size()); i++)
    {
        hash_result = this->call_hash(i, key);
        (this->filter)[hash_result % 330] = 1;
    }
}

bool BloomFilter::member(const std::string& key) {
    unsigned int hash_result;

    for (int i = 0; i < (this->hash_funs.size()); i++)
    {
        hash_result = this->call_hash(i, key);
        if((this->filter)[hash_result % 330] == 0)
        {
            return false;
        }
    }

    return true;
}
