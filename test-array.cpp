#include <iostream>
#include <cstdlib>
#include "string.h"
#include "array.h"

// authors: lee.seu@husky.neu.edu, aguilar.ca@husky.neu.edu

void t_true(bool p) { if (!p) exit(1); }
void t_false(bool p) { if (p) exit(1); }

void test_array_create() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(b);
	array->add(0, a);
	Array* array_2 = new Array();
	array_2->add(0, b);
	array_2->add(0, a);
	t_true(array->equals(array_2));
	delete array;
	delete array_2;
	delete a;
	delete b;
}

void test_push_back_all() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	array->push_back(b);
	Array* array_2 = new Array();
	array_2->push_back_all(array);
	t_true(array->equals(array_2));

	delete array;
	delete array_2;
	delete a;
	delete b;
}

void test_add_all() {
	String* a = new String("a");
	String* b = new String("b");
	String* c = new String("c");
	Array* array = new Array();
	array->add(0, b);
	array->add(0, a);
	Array* array_2 = new Array();
	array_2->add(0, c);
	array_2->add_all(0, array);
	Array* array_3 = new Array();
	array_3->push_back(a);
	array_3->push_back(b);
	array_3->push_back(c);
	t_true(array_2->equals(array_3));

	delete array;
	delete array_2;
	delete array_3;
	delete a;
	delete b;
	delete c;
}

void test_clear() {
	Object* o = new Object();
	Array* array = new Array();
	Array* array_2 = new Array();
	array_2->push_back(o);
	t_false(array->equals(array_2));
	array_2->clear();
	t_true(array->equals(array_2));

	delete array;
	delete array_2;
	delete o;
}

void test_contains() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->contains(a));
	t_false(array->contains(b));

	delete array;
	delete a;
	delete b;
}

void test_index_of() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->index_of(a) == 0);
	t_true(array->index_of(b) > array->size());

	delete array;
	delete a;
	delete b;
}

void test_get() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	array->push_back(b);
	t_true(a->equals(array->get(0)));
	t_true(b->equals(array->get(1)));

	delete array;
	delete a;
	delete b;
}

void test_is_empty() {
	String* a = new String("a");
	Array* array = new Array();
	t_true(array->is_empty());
	array->push_back(a);
	t_false(array->is_empty());
	delete array;
	delete a;
}

void test_size() {
	String* a = new String("a");
	Array* array = new Array();
	t_true(array->size() == 0);
	array->push_back(a);
	t_true(array->size() == 1);
	delete array;
	delete a;
}

void test_remove() {
	String* a = new String("a");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->size() == 1);
	Object* removed = array->remove(0);
	t_true(array->size() == 0);
	t_true(a->equals(removed));
	delete array;
	delete a;
}

void test_set() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->get(0)->equals(a));
	Object* replaced = array->set(0, b);
	t_true(array->get(0)->equals(b));
	t_true(a->equals(replaced));
	delete array;
	delete a;
	delete b;
}

void test_hash() {
	String* a = new String("a");
	Array* array = new Array();
	Array* array_2 = new Array();
	array->push_back(a);
	array_2->push_back(a);
	t_true(array->hash() == array_2->hash());
	delete array;
	delete array_2;
	delete a;
}

void test_clone() {
	String* a = new String("a");
	Array* array = new Array();
	array->push_back(a);
	Object* array_2 = array->clone();
	t_true(array->equals(array_2));
	array->remove(0);
	t_false(array->equals(array_2));
	delete array;
	delete array_2;
	delete a;
}

int main() {
	test_array_create();
	test_push_back_all();
	test_add_all();
	test_clear();
	test_contains();
	test_index_of();
	test_get();
	test_is_empty();
	test_size();
	test_remove();
	test_set();
	test_hash();
	test_clone();
	std::cout << "All tests passed!";
}
