/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:12:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/18 16:19:50 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>

static void test_constructor(void)
{
	TESTED_NAMESPACE::map<std::string, int> m1;
	module_head("map::constructor(void)");
	std::cout << "m1::size: " << m1.size() << std::endl;
	std::cout << "m1::empty: " << m1.empty() << std::endl;
	std::cout << "m1::clear: ";
	m1.clear();
	std::cout << m1.size() << std::endl;
	module_foot();
	TESTED_NAMESPACE::map<std::string, int> m2(m1);
	module_head("map::constructor(map<std::string, int>) (empty)");
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	module_head("map::constructor(map<std::string, int>) (not empty)");
	std::cout << "m2::size: " << m2.size() << std::endl;
	std::cout << "m2::empty: " << m2.empty() << std::endl;
	std::cout << "m2::clear: ";
	m2.clear();
	std::cout << m2.size() << std::endl;
	module_foot();

	module_head("map::constructor(iterator, iterator) (empty)");
	TESTED_NAMESPACE::map<std::string, int> m3(m2.begin(), m2.end());
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	std::cout << "m3::clear: ";
	m3.clear();
	std::cout << m3.size() << std::endl;
	module_foot();
	module_head("map::constructor(iterator, iterator) (not empty)");
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m3.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "m3::size: " << m3.size() << std::endl;
	std::cout << "m3::empty: " << m3.empty() << std::endl;
	TESTED_NAMESPACE::map<std::string, int> m4(m3.begin(), m3.end());
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
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	module_head("map::insert(value) duplicate");
	r = m1.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 2));
	std::cout << "r.first.first: " << r.first->first << std::endl;
	std::cout << "r.first.second: " << r.first->second << std::endl;
	std::cout << "r.second: " << r.second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int>::iterator it;

	module_head("map::insert(iterator, value)");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	module_head("map::insert(iterator, value) duplicate");
	it = m1.insert(m1.begin(), TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 7));
	std::cout << "it.first.first: " << it->first << std::endl;
	std::cout << "it.first.second: " << it->second << std::endl;
	module_foot();

	TESTED_NAMESPACE::map<std::string, int> m2;

	module_head("map::insert(iterator, iterator)");
	m2.insert(m1.begin(), m1.end());
	std::cout << "m2.size: " << m2.size() << std::endl;
	std::cout << "m2.empty: " << m2.empty() << std::endl;
	module_foot();

	module_head("map::insert(iterator, iterator) duplicate");
	m2.insert(m1.begin(), m1.end());
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

void test_map(void)
{
	test_constructor();
	test_insert();
}
