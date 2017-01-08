#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
template<typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size=101);
    bool insert(const HashedObj& x);
    bool contain(const HashedObj& x) const;
    bool remove(const HashedObj& x);
    void makeEmpty();
private:
    vector<list<HashedObj>> theLists;
    int currentSize;
    void rehash()
    {
        vector<list<HashedObj>> oldLists=theLists;
        theLists.resize(nextPrime(2*theLists.size() ) );
        for(int i=0;i<currentSize;i++)
            theLists[i].clear();
        currentSize=0;
        for(int i=0;i<currentSize;i++)
        {
            list<HashedObj>::iterator itr=oldLists[i].begin();
            while (itr!=oldLists[i].end() )
                insert(*itr++);
        }
    }
    int myhash(const HashedObj& x) const;
    
};
int hash(const string& x);
int hash(int key);
                   
template<typename HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj& x) const
{
    int hashVal=hash(x);
    hashVal%=theLists.size();
    if(hashVal<0)
        hashVal+=theLists.size();
    return hashVal;
}

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for(int i=0;i<theLists.size();++i)
    {
        theLists[i].clear();
    }
}
template<typename HashedObj>
inline bool HashTable<HashedObj>::contain(const HashedObj &x) const
{
    const list<HashedObj> &whichList =theLists[myhash(x)];
    return find(whichList.begin(),whichList.end(),x)!=whichList.end();
}
template<typename HashedObj>
inline bool HashTable<HashedObj>::remove(const HashedObj &x)
{
    
    list<HashedObj> &whichList=theLists[myhash(x)];
    list<HashedObj>::iterator ite=find(whichList.begin(),whichList.end(),x);
    if(ite==whichList.end() )
        return false;
    whichList.erase();
    --currentSize;
    return true;
    
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& x)
{
    list<HashedObj> &whichList=theLists[myhash(x)];
    if (whichList.end()!=find(whichList.begin(),whichList.end(),x) )
        return false;
    whichList.push_back(x);
    if (++currentSize>theLists.size() )
        rehash();
    return true;
}
