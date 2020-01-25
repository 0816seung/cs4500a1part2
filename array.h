//lang:CwC
#pragma once
#include "object.h"

// Representation of an array: expands as necessary
class Array: public Object {
public:
	// default constructor for array
	// inherits from object
	Array() : Object() {}

	// default destructor for array
	~Array() {}

	// adds (pushes) given object to back of the array
	virtual void push_back(Object* o) {}

	// adds (pushes) all objects in given array to back of the array
	virtual void push_back_all(Array* arr) {}

	// adds given element at the given index
	virtual void add(size_t i, Object* o) {}

	// adds all objects in given array at the given index
	virtual void add_all(size_t i, Array* arr) {}

	// removes all objects from this array
	// Note: this should not apply any changes to the objects themselves
	virtual void clear() {}

	// returns true if the given object exists in this array
	virtual bool contains(Object* o) {}

	// returns index of the first occurrence of the given object in the array
	// returns some unsigned int greater than the size of the array if not in the array
	virtual size_t index_of(Object* o) {}

	// returns the object at the given position in the array
	virtual Object* get(size_t i) {}

	// returns true if the array has no elements
	virtual bool is_empty() {}

	// returns the number of elements in the array
	virtual size_t size() {}

	// removes the element at the given index of the array and returns it
	virtual Object* remove(size_t i) {}

	// replaces the element at the given index of the array with the given object
	// and returns the original object
	// Note: this should not apply any changes to either object
	virtual Object* set(size_t i, Object* e) {}

	// returns true if given object is equal to this array
	virtual bool equals(Object * other) {}

	// returns hash code for this array
	virtual size_t hash() {}

	// returns string representation of this array
	virtual char* to_string() {}

	// returns copy of this array
	virtual Object* clone() {}
};