/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:04:30 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 22:52:33 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../containers/vector.hpp"
#include <vector>

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE std
#endif

void module_head(std::string module_name)
{
	std::cout << ">>> " << module_name << std::endl;
}

void module_foot(void)
{
	std::cout << "<<<" << std::endl;
}

template <typename T>
void module_test(std::string name, T result)
{
	module_head(name);
	std::cout << result << std::endl;
	module_foot();
}

void test_empty_vector(void)
{
	TESTED_NAMESPACE::vector<int> v;

	module_test("vector::max_size", v.max_size());
	module_test("vector::size", v.size());
	module_test("vector::empty", v.empty());
}

void test_vector(void)
{
	test_empty_vector();
}

int main(void)
{
	module_test("witness test", 42);
	test_vector();
}
