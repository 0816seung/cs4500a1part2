//lang:CwC
#pragma once
#include "object.h"

// Representation of a string
// Passed in values should be copied and deleted
// authors: lee.seu@husky.neu.edu, aguilar.ca@husky.neu.edu
class String: public Object {
public:
	// default constructor that inherits from Object
	String() : Object() {}

	// constructor to create String copying c
	String(char* c): Object() {}

	// constructor to create String copying c
	String(const char* c): Object() {}

	// destructor
	~String() {}

	// returns length of the string
	size_t size() {}

	// returns result of concatenating this string and s
	String* concat(String* s) {}

	// returns the index of the first occurrence of the given character
	// returns a number greater than length of this string if no occurrence found
	size_t index_of(char c) {}

	// returns a number < 0 if this string comes lexicographically before the given string
	// returns 0 if this string is lexicographically equal to the given string
	// returns a number > 0 if this string comes lexicographically after the given string
	int compare(String* s) {}

	// checks if the given object is equal to this String
	bool equals(Object * other) {}

	// unimplemented hash code function
	size_t hash() {}

	// return string representation of this object
	// should not return a reference to any internal objects
	char* to_string() {}

	// returns a copy of this object
	Object* clone() {}

	// prints this string to stdout
	void print() {}
};