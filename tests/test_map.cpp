/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:12:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/18 15:29:00 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

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

	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test"), 1));
	m2.insert(TESTED_NAMESPACE::make_pair(static_cast<std::string>("test2"), 6));


	TESTED_NAMESPACE::map<std::string, int>::iterator it = m2.begin();
	TESTED_NAMESPACE::map<std::string, int>::iterator it2 = m2.end();

	std::cout << "m2::begin: " << it->first << std::endl;

	TESTED_NAMESPACE::map<std::string, int> m3;
	m3.insert(it, it2);
	module_head("map::constructor(map<std::string, int>) (not empty)");
	std::cout << "m3::size: " << m3.size() << std::endl;
	module_foot();

}

void test_map(void)
{
	test_constructor();
}
