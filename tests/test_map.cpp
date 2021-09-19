/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:12:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 11:57:35 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>

template <typename T1, typename T2>
std::string string_map(TESTED_NAMESPACE::map<T1, T2> &v)
{
	std::ostringstream ss;

	ss << "{";
	for (typename TESTED_NAMESPACE::map<T1, T2>::iterator it = v.begin(); it != v.end(); ++it)
	{
		ss << it->first << ": " << it->second;
		if (it != v.end())
			ss << ", ";
	}
	ss << "}";
	return ss.str();
}

static void test_constructor(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	module_head("map::constructor(void)");
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "m1::size: " << m1.size() << std::endl;
	std::cout << "m1::empty: " << m1.empty() << std::endl;
	std::cout << "m1::clear: ";
	m1.clear();
	std::cout << m1.size() << std::endl;
	module_foot();
	TESTED_NAMESPACE::map<std::string, int> m2(m1);
	module_head("map::constructor(map<std::string, int>) (empty)");
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	module_head("map::constructor(map<std::string, int>) (not empty)");
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();

	module_head("map::constructor(iterator, iterator) (empty)");
	TESTED_NAMESPACE::map<std::string, int> m3(m2.begin(), m2.end());
	std::cout << "m3 content: " << string_map(m3) << std::endl;
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	std::cout << "m3::clear: ";
	m3.clear();
	std::cout << m3.size() << std::endl;
	module_foot();
	module_head("map::constructor(iterator, iterator) (not empty)");
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "m3 content: " << string_map(m3) << std::endl;
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	TESTED_NAMESPACE::map<std::string, int> m4(m3.begin(), m3.end());
	std::cout << "m4 content: " << string_map(m4) << std::endl;
	std::cout << "m4::size: " << m4.size() << std::endl;
	std::cout << "m4::empty: " << m4.empty() << std::endl;
	module_foot();

	module_head("map::constructor(const map<std::string, int>)");
	TESTED_NAMESPACE::map<std::string, int> m5(m4);
	std::cout << "m5::size: " << m5.size() << std::endl;
	std::cout << "m5::empty: " << m5.empty() << std::endl;
	std::cout << "m5::clear: ";
	m5.clear();
	std::cout << m5.size() << std::endl;
	module_foot();
}

static void test_insert(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<std::string, int>::iterator, bool> r;
	module_head("map::insert(value)");
	r = m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	module_head("map::insert(value) duplicate");
	r = m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 2));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int>::iterator it;

	module_head("map::insert(iterator, value)");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	module_head("map::insert(iterator, value) duplicate");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 7));
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int> m2;

	module_head("map::insert(iterator, iterator)");
	m2.insert(m1.begin(), m1.end());
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();

	module_head("map::insert(iterator, iterator) duplicate");
	m2.insert(m1.begin(), m1.end());
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();

	module_head("map::insert(value) time");
	TESTED_NAMESPACE::map<std::string, int> m3;
	for (int i = 0; i < 10000; ++i)
	{
		std::ostringstream ss;
		ss << "test" << i;
		m3.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
	}
	module_foot();

	module_head("map::size after time");
	std::cout << "m3.size: " << m3.size() << std::endl;
	module_foot();
}

static void test_assign_operator(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::map<std::string, int> m2;

	module_head("map::= empty");
	m1 = m2;
	std::cout << "m1 content: " << string_map(m1) << std::endl;
	std::cout << "m1.size: " << m1.size() << std::endl;
	std::cout << "m1.empty: " << m1.empty() << std::endl;
	module_foot();

	module_head("map::=");
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 1));
	m2 = m1;
	std::cout << "m2 content: " << string_map(m2) << std::endl;
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();
}

static void test_iterators(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	TESTED_NAMESPACE::map<std::string, int>::iterator it;
	TESTED_NAMESPACE::map<std::string, int>::iterator it2;
	it = m1.begin();
	it2 = m1.end();
	module_test("map::begin() == map::end()", it == it2);
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test1"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test3"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test4"), 1));
	m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test5"), 1));

	module_head("map::begin()");
	it = m1.begin();
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	module_head("map::end()");
	it2 = m1.end();
	for (it = m1.begin(); it != it2; ++it)
	{
		std::cout << "it.first.first: " << it->first << std::endl;
		std::cout << "it.first.second: " << it->second << std::endl;
	}
	module_foot();

	TESTED_NAMESPACE::map<std::string, int>::reverse_iterator rit;
	module_head("map::rbegin() && rend");
	for (rit = m1.rbegin(); rit != m1.rend(); ++rit)
	{
		std::cout << "rit.first.first: " << rit->first << std::endl;
		std::cout << "rit.first.second: " << rit->second << std::endl;	
	}
	module_foot();
}

void test_map(void)
{
	test_constructor();
	test_insert();
	test_assign_operator();
	test_iterators();
}
