Firstly, we made all of the methods in Array virtual, so it can be easily inheritd from by future requirements, such as SortedArray or the like.

For indexof(), when it doesn't find the given Object, we chose to return a number > size(), instead of -1.

remove() and set() returns the object removed or replaced.

For to_string, it should return some string representation of an array, but we did not bind it to a specific representation (consider how Python represents arrays: [a,b,d] )

Our tests do not include to_string for this reason.

All other relevant methods are tested in test-array.cpp. This assignment does not require a makefile, but with a working implementation of this API, running "g++ -Wall test-array.cpp", then "./a.out" would run all the tests, with a success message if they all pass.
