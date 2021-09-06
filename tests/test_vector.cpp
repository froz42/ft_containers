/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/06 21:22:14 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>
#include <iostream>
#include <string>

template <typename T>
std::string string_vector(TESTED_NAMESPACE::vector<T> &v)
{
	std::ostringstream ss;

	ss << "{";
	for (typename TESTED_NAMESPACE::vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		ss << *it;
		if (it != v.end() - 1)
			ss << ", ";
	}
	ss << "}";
	return ss.str();
}

void test_constructor()
{
	module_head("vector::constructor");
	TESTED_NAMESPACE::vector<int> v1; // default constructor
	TESTED_NAMESPACE::vector<int> v2(5); // size constructor
	TESTED_NAMESPACE::vector<int> v3(5, 42); // size and value constructor
	TESTED_NAMESPACE::vector<int> v4(v3); // copy constructor
	TESTED_NAMESPACE::vector<int> v5(v3.begin(), v3.end()); // iterator constructor
	module_foot();

	module_test("vector::constructor (default)", string_vector(v1));
	module_test("vector::constructor (size)", string_vector(v2));
	module_test("vector::constructor (size and value)", string_vector(v3));
	module_test("vector::constructor (copy)", string_vector(v4));
	module_test("vector::constructor (iterator)", string_vector(v5));

	module_test("vector::constructor (default) (size)", v1.size());
	module_test("vector::constructor (size) (size)", v2.size());
	module_test("vector::constructor (size and value) (size)", v3.size());
	module_test("vector::constructor (copy) (size)", v4.size());
	module_test("vector::constructor (iterator) (size)", v5.size());

	module_test("vector::constructor (default) (capacity)", v1.capacity());
	module_test("vector::constructor (size) (capacity)", v2.capacity());
	module_test("vector::constructor (size and value) (capacity)", v3.capacity());
	module_test("vector::constructor (copy) (capacity)", v4.capacity());
	module_test("vector::constructor (iterator) (capacity)", v5.capacity());

	module_test("vector::constructor (default) (empty)", v1.empty());
	module_test("vector::constructor (size) (empty)", v2.empty());
	module_test("vector::constructor (size and value) (empty)", v3.empty());
	module_test("vector::constructor (copy) (empty)", v4.empty());
	module_test("vector::constructor (iterator) (empty)", v5.empty());

	module_test("vector::constructor (default) (front)", v1.front());
	module_test("vector::constructor (size) (front)", v2.front());
	module_test("vector::constructor (size and value) (front)", v3.front());
	module_test("vector::constructor (copy) (front)", v4.front());
	module_test("vector::constructor (iterator) (front)", v5.front());

	module_test("vector::constructor (default) (back)", v1.back());
	module_test("vector::constructor (size) (back)", v2.back());
	module_test("vector::constructor (size and value) (back)", v3.back());
	module_test("vector::constructor (copy) (back)", v4.back());
	module_test("vector::constructor (iterator) (back)", v5.back());

	module_test("vector::constructor (default) (at)", v1.at(0));
	module_test("vector::constructor (size) (at)", v2.at(0));
	module_test("vector::constructor (size and value) (at)", v3.at(0));
	module_test("vector::constructor (copy) (at)", v4.at(0));
	module_test("vector::constructor (iterator) (at)", v5.at(0));

	module_test("vector::constructor (default) (operator[]", &v1[0]);
	module_test("vector::constructor (size) (operator[]", &v2[0]);
	module_test("vector::constructor (size and value) (operator[]", &v3[0]);
	module_test("vector::constructor (copy) (operator[]", v4[0]);
	module_test("vector::constructor (iterator) (operator[]", v5[0]);

	module_test("vector::constructor (default) (begin)", &*(v1.begin()));
	module_test("vector::constructor (size) (begin)", &*(v2.begin()));
	module_test("vector::constructor (size and value) (begin)", &*(v3.begin()));
	module_test("vector::constructor (copy) (begin)", &*(v4.begin()));
	module_test("vector::constructor (iterator) (begin)", &*(v5.begin()));
	

}

void test_vector(void)
{
	test_constructor();
}
