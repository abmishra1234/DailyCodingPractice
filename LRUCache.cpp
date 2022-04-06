/*
	LRU Cache code 
	1. Cache have always limited space so it can't store infinite content
	2.a.  Until Cahe is not full adding content into cache is addition
	2.b. Once cache is full you have to make the space for new entry and do so that
	Repeat the same...

	This problem , multiple time asked in amazon interview
	Complexity : Medium
*/
// #define FORREF
#ifndef FORREF
using namespace std;

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

/*
	Just maintain some key value pair
	this is to showcase that if you have updated the some element of linkedlist that that is treated most recently used and 
	in eviction policy it won't cleared.
*/

struct LRUCache {
/*
	@Abinash Mishra : Please evaluate the Time& Space complexity of your solutionand do the justification if required
		or may be better share some insight to improve these incase
*/

	typedef pair<int, int> Pair;
	typedef list<Pair> LRUList;
	typedef LRUList::iterator ListIter;
	

	LRUList lrulist;


	// This is maintained for removing the element from list in const operation
	typedef unordered_map<int, ListIter> CacheMap; 
	CacheMap ccmap;

	static const int capacity = 5;
	int size;

	LRUCache() : size(0) {
	}

	/*
		in LRU, you have to maintain the element in the order it is geeting added or updated etc..
		It means any element which is added recently or updated recently could be considered as most recently used
		reverse of it could be considered as least recently used
		Eviction policy from the cache is LRU based
		you have to just write two method - 
		1. Get 
			if you read some element from cache than that would become most recently used and In eviction policy this element might be the last one
		2. Put
			a. Imagine this element is not present in cache and also cache is not full
			approach - add element at front
			
			b. Imagine this element is not present in cache and also cache is full
			approach - in this situation, we have to remove element from back and add element into the front
			
			c. imagine the element is already present in cache and you only need to update the value corresponding to this key
			approach - in this situation , you only need to update the element and put this element into the front

	*/

	int get(int key) {
		/*
			Some one ask me am i going to change my size or do i need to check the cache is full?
			My answer is , No, we don't have to do any such things here, even you check the Cache availability, won't make
			much difference but it might introduce extra call in your implementation which having no use.
		*/
		
		CacheMap::iterator it = ccmap.find(key);
		
		if (it == ccmap.end())
			return -1; // Assuming that there is no negative value in system
		
		// first it->second is to reach the perticular list element and next second call will give me pair second element
		int fkey = (it->second)->second; 
		int fvalue = (it->second)->first;

		/*
			Now what you have to do to make sure that this element would be most recently used element of cache after this api call.
			One of the Approach for making this element MRU that delete from current position and add again into the cache.
		*/

		// Deletion block
		{
			delNode(it->second);
			ccmap.erase(fkey);
			this->size -= 1;
		}

		// Addition block
		{ 
			addNode(fkey, fvalue);
			ccmap.insert(make_pair(fkey, lrulist.begin()));
			this->size += 1;
		}

		return fvalue;
	}

	void put(int key, int value) {
		/*
			So here you are suppose to add new pair into the Cache
			So here , first thing you have to check that does the key element already exist in Cache?
			Case 01 : If so than we have to do the following
			Approach :
			- Fetch the { key, value } pair from the  cache if already present
			- Delete the perticular Element from Cache
			- Update the value with new value corresponding the key
			- Add this pair element to the Cache

			Case 02 : Otherwise, if the key is not present into the Cache?
			Approach:
			- You have to think about the Cache capacity and current Cache Size
			- (i) Suppose Cache size < capacity, in this case you only need to add the new pair into the Cache
				do the size update as soon as you do the addition
			- (ii) What if the Capacity is same as current size, meaning Cache is Full?
				(a)You have to remove the elemnt from back and update the size
				(b)Add the element into front of list and update the size
		*/
		CacheMap::iterator it = ccmap.find(key);
		if (it != ccmap.end()) {
			// Key is already exist in cache
			auto lit = it->second;
			int lkey = lit->first;
			int lvalue = lit->second;
			lvalue = value;
			delNode(lit);
			--size;
			ccmap.erase(key);
			addNode(lkey, lvalue);
			++size;
			ccmap.insert(make_pair(lkey, lrulist.begin()));
		}
		else {
			// Key is not exist in cache
			if (size == capacity) {
				// Cache is full
				auto it = lrulist.rbegin();
				ccmap.erase(it->first);
				delNode();
				--size;
				addNode(key, value);
				++size;
				ccmap.insert(make_pair(key, lrulist.begin()));
			}
			else
			{
				// Cache is not full
				addNode(key, value);
				++size;
				ccmap.insert(make_pair(key, lrulist.begin()));
			}
		}
	}

	bool isCacheFull() {
		return (size == capacity);
	}

	void print() {
		for (auto p : lrulist) {
			cout << p.first << " : " << p.second << endl;
		}
	}

private:
	// Overloaded method deleting from anywhere
	void delNode(ListIter it) {
		lrulist.erase(it);
	}

	// overloaded method for deleting from back
	void delNode(void) {
		lrulist.pop_back();
	}

	// 
	void addNode(int key, int value) {
		lrulist.push_front(make_pair(key, value));
	}
};

// Driver Code
int main() {
	LRUCache inst;
	inst.put(10, 10);
	inst.put(20, 20);
	inst.put(30, 30);
	inst.put(40, 40);
	inst.put(50, 50);

	auto ans = inst.isCacheFull();
//	cout << "Is Cache is full ? :  " << ans << endl;

	auto ret = inst.get(10);
//	cout << "return value : " << ret << endl;
	inst.put(60, 60);
	inst.print();

	return 0;
}
#endif // !FORREF

