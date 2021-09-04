/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:45:06 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/04 15:12:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <sstream>
#include <iostream>
#include <string>

void test_iterator(void)
{
	std::string str = "Hello World";

	TESTED_NAMESPACE::reverse_iterator<std::string::iterator> rbegin(str.end());
	TESTED_NAMESPACE::reverse_iterator<std::string::iterator> rend(str.begin());

	module_head("reverse_iterator");
	std::cout << "str: " << str << std::endl;
	std::cout << "rbegin: " << &(*rbegin) << std::endl;
	std::cout << "rend: " << &(*rend) << std::endl;
	for (; rbegin != rend; ++rbegin)
		std::cout << *rbegin << "; ";
	std::cout << std::endl;
	module_foot();
}
