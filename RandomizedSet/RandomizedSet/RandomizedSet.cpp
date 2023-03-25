#include"RandomizedSet.h"
#include <cstdlib>

RandomizedSet::RandomizedSet() {

}

RandomizedSet::~RandomizedSet() {
	this->key_index_map.clear();
	this->values.clear();
}


/*
 Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
*/
bool RandomizedSet::insert(int val) {
	if (this->key_index_map.find(val) != this->key_index_map.end())
	{  
		// element already exists in the list
		return false;
	}
	else {
		// store the new element in the map with the index of the element in the list
		this->key_index_map[val] = this->values.size();
		// insert the new element in the values list
		this->values.push_back(val);
		return true;
	}
}
/*
 Removes an item val from the set if present. Returns true if the item was present, false otherwise.
*/
bool RandomizedSet::remove(int val) {

	if (this->key_index_map.find(val) != this->key_index_map.end())
	{
		// get the index of the value to be removed
		size_t index = this->key_index_map[val];
		// get the last element in the list of values
		int key_to_swap = this->values[this->values.size()-1];
		// update the index of the last element to the index of the removed element in the map
		this->key_index_map[key_to_swap] = index;
		// erase the val to index mapping the map
		this->key_index_map.erase(val);
		// swap the values
		this->values[index] = key_to_swap;
		this->values[this->values.size() - 1] = val;
		// remove the last element = val from the list of val
		this->values.pop_back();
		return true;
	}
	else {
		return false;
	}

}
int RandomizedSet::getRandom() {
	int index = rand() % this->values.size();
	return this->values[index];
}