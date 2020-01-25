//lang:CwC
#pragma once
#include <stdlib.h>

// Representation of an object
class Object {
public:

	// default constructor
	Object() {}

	// destructor
	virtual ~Object() { }

	// checks if the given object is equal to this object
	virtual bool equals(Object * other) {
		return this == other;
	}

	// unimplemented hash code function
	virtual size_t hash() {
		return 1;
	}

	// return string representation of this object
	virtual char* to_string() {}

	// returns a copy of this object
	virtual Object* clone() {}
};