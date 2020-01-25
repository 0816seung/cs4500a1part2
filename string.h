//lang:CwC
#pragma once
#include "object.h"

// Representation of a string
class String: public Object {
public:
	// default constructor that inherits from Object
	String() : Object() {}

	// constructor to create String from a String literal
	String(const char* c): Object() {}

	// destructor
	~String() {}

	// returns length of the string
	size_t length() {}

	// returns result of concatenating this string and s
	String* concat(String* s) {}

	// returns the index of the first occurrence of the given character
	// returns a number greater than length of this string if no occurrence found
	size_t index_of(char c) {}

	// returns a number < 0 if this string comes lexicographically before the given string
	// returns 0 if this string is lexicographically equal to the given string
	// returns a number > 0 if this string comes lexicographically after the given string
	int compare_to(String* s) {}

	// checks if the given object is equal to this String
	bool equals(Object * other) {
		return this == other;
	}

	// unimplemented hash code function
	size_t hash() {}

	// return string representation of this object
	char* to_string() {}

	// returns a copy of this object
	Object* clone() {
		// STUB
	}
};