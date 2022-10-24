#include <list>
#include <vector>
#include <functional>
#include <iostream>

template <typename Key, typename Value>
class HashTable{
public:
    HashTable();
    void add(Key key, Value value);
    void print();
private:
    struct Element{
        Key key;
        Value value;
    };

    using ChainList=std::list<Element>;
    std::vector<ChainList> mTable;

    const double duplicationRatio = 0.7;
    int mDivitionRatio = 8;
    double porcentageUsage();
};

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable():mTable(8){}

template <typename Key, typename Value>
void HashTable<Key, Value>::add(Key key, Value value) {
    auto hash = std::hash<Key>{}(key);

    if(porcentageUsage() > duplicationRatio) {
        // duplicate table size
        mTable.reserve(mTable.capacity()*2);
        mDivitionRatio *= 2;
    }

    std::size_t tableIndex = hash / (mDivitionRatio - 1);
    mTable.at(tableIndex).push_back(Element{key, value});
}

template <typename Key, typename Value>
void HashTable<Key, Value>::print() {
    std::cout << "{ ";

    for(const auto& chainList : mTable) {
        for(const auto& elem : chainList) {
            std::cout << elem.key << " : " << elem.value << ", ";
        }
    }

    std::cout << "}" << std::endl;
}


template <typename Key, typename Value>
double HashTable<Key, Value>::porcentageUsage() {
    return (double)mTable.size()/(double)mTable.capacity();
}