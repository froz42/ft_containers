/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:22 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/02 14:47:17 by tmatis           ###   ########.fr       */
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

void test_empty_vector(void)
{
	TESTED_NAMESPACE::vector<int> v;
	TESTED_NAMESPACE::vector<int> v2(v);
	TESTED_NAMESPACE::vector<int> v3;
	v3 = v;
	module_test("[empty] vector::operator=", v3.size() == v.size());
	module_test("[empty] vector::operator=", v3.empty() == v.empty());
	module_test("[empty] vector::begin", &*v.begin());
	module_test("[empty] vector::end", &*v.end());
	module_test("[empty] vector::rbegin", &*v.rbegin());
	module_test("[empty] vector::rend", &*v.rend());
	module_test("[empty] vector::size", v.size());
	module_test("[empty] vector::max_size", v.max_size());
	module_test("[empty] vector::empty", v.empty());
	module_test("[empty] vector::capacity", v.capacity());
	module_test("[empty] vector::content", string_vector(v));
	v.resize(10);
	module_test("[empty] vector::resize", v.size());
	module_test("[empty] vector::capacity", v.capacity());
	module_test("[empty] vector::content", string_vector(v));
	v.resize(1);
	module_test("[empty] vector::resize", v.size());
	module_test("[empty] vector::capacity", v.capacity());
	module_test("[empty] vector::content", string_vector(v));
	v.resize(10, 42);
	module_test("[empty] vector::resize", v.size());
	module_test("[empty] vector::capacity", v.capacity());
	module_test("[empty] vector::content", string_vector(v));
	v2 = v;
	module_test("[empty] vector::resize after copy", v2.size());
	module_test("[empty] vector::capacity after copy", v2.capacity());
	module_test("[empty] vector::content after copy", string_vector(v2));
	v.clear();
	module_test("[empty] vector::clear", v.size());
	module_test("[empty] vector::capacity after clear", v.capacity());
	module_test("[empty] vector::content after clear", string_vector(v));
}

void test_vector(void)
{
	test_empty_vector();
}
