//lang:CwC
#pragma once
#include <stdlib.h>

// Representation of an object
// authors: lee.seu@husky.neu.edu, aguilar.ca@husky.neu.edu
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

	/** Returns the object's hash value. Two objects that are equal should         
   	* have the same hash; object's that are not, may have the same hash.          
   	* Subclasses should implement hash_me_(). */ 
	size_t hash() {}

	// unimplemented hash code function
	virtual size_t hash_me_() {
		return 1;
	}

	// return string representation of this object
	virtual char* to_string() {}

	/** Print to stdout. */                                                        
  	virtual void print() {} 

	// returns a copy of this object
	virtual Object* clone() {}
};