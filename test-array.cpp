#include <iostream>
#include <cstdlib>
#include "string.h"
#include "array.h"

void t_true(bool p) { if (!p) exit(1); }
void t_false(bool p) { if (p) exit(1); }

void test_array_create() {
	Array* array = new Array();
	array->push_back(new String("b"));
	array->add(0, new String("a"));
	Array* array_2 = new Array();
	array_2->add(0, new String("b"));
	array_2->add(0, new String ("a"));
	t_true(array->equals(array_2));
}

void test_push_back_all() {
	Array* array = new Array();
	array->push_back(new String("a"));
	array->push_back(new String ("b"));
	Array* array_2 = new Array();
	array_2->push_back_all(array);
	t_true(array->equals(array_2));
}

void test_add_all() {
	Array* array = new Array();
	array->add(0, new String("b"));
	array->add(0, new String("a"));
	Array* array_2 = new Array();
	array_2->add(0, new String("c"));
	array_2->add_all(0, array);
	Array* array_3 = new Array();
	array_3->push_back(new String("a"));
	array_3->push_back(new String("b"));
	array_3->push_back(new String("c"));
	t_true(array_2->equals(array_3));
}

void test_clear() {
	Array* array = new Array();
	Array* array_2 = new Array();
	array_2->push_back(new Object());
	t_false(array->equals(array_2));
	array_2->clear();
	t_true(array->equals(array_2));
}

void test_contains() {
	Array* array = new Array();
	array->push_back(new String("a"));
	t_true(array->contains(new String("a")));
	t_false(array->contains(new String("b")));
}

void test_index_of() {
	Array* array = new Array();
	array->push_back(new String("a"));
	t_true(array->index_of(new String("a")) == 0);
	t_true(array->index_of(new String("b")) > array->size());
}

void test_get() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	array->push_back(b);
	t_true(a->equals(array->get(0)));
	t_true(b->equals(array->get(1)));
}

void test_is_empty() {
	String* a = new String("a");
	Array* array = new Array();
	t_true(array->is_empty());
	array->push_back(a);
	t_false(array->is_empty());
}

void test_size() {
	String* a = new String("a");
	Array* array = new Array();
	t_true(array->size() == 0);
	array->push_back(a);
	t_true(array->size() == 1);
}

void test_remove() {
	String* a = new String("a");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->size() == 1);
	Object* removed = array->remove(0);
	t_true(array->size() == 0);
	t_true(a->equals(removed));
}

void test_set() {
	String* a = new String("a");
	String* b = new String("b");
	Array* array = new Array();
	array->push_back(a);
	t_true(array->get(0)->equals(a));
	Object* replaced = array->set(0, b);
	t_true(array->get(0)->equals(b));
	t_true(b->equals(replaced));
}

void test_hash() {
	Array* array = new Array();
	Array* array_2 = new Array();
	String* a = new String("a");
	array->push_back(a);
	array_2->push_back(a);
	t_true(array->hash() == array_2->hash());
}

void test_clone() {
	Array* array = new Array();
	String* a = new String("a");
	array->push_back(a);
	Object* array_2 = array->clone();
	t_true(array->equals(array_2));
	array->remove(0);
	t_false(array->equals(array_2));
}

void test_object_methods() {
	Object* object = new Object();
	t_true(object->equals(object));
	t_true(object->hash() == object->hash());
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
	test_object_methods();
	std::cout << "All tests passed!";
}