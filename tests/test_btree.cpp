/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_btree.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:34:07 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/17 23:38:16 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <cassert>

void test_btree()
{
	module_head("btree");
	ft::_rb_tree<int, std::less<int> > tree;

	for (int i = 0; i <= 10; i++)
	{
		std::cout << "insert " << i << std::endl;
		tree.insert(i);
		tree.print();
		std::cout << "----------------------" << std::endl; 
	}
	std::cout << "find:" << *tree.find(5) << std::endl;
	std::cout << "find:" << (*tree.find(42))->data << std::endl; 
	std::cout << "size:" << tree.size() << std::endl;
	ft::_rb_tree<int, std::less<int> > tree2(tree);
	std::cout << "size:" << tree2.size() << std::endl;
	tree2.print();
	for (int i = 0; i <= 10; i++)
	{
		std::cout << "erase " << i << std::endl;
		tree.erase(i);
		tree.print();
		std::cout << "----------------------" << std::endl;
	}
	std::cout << "size:" << tree.size() << std::endl;
	tree2 = tree;
	module_foot();
}
