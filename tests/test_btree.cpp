/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_btree.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:34:07 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/14 18:51:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <cassert>

void test_btree()
{
	ft::rbtree<int, std::less<int> > tree;

	for (int i = 0; i < 5; i++)
	{
		tree.insert(i);
		tree.print();
		std::cout << "----------------------" << std::endl; 
	}
	ft::rbtree<int, std::less<int> > tree2(tree);
	std::cout << "tree2:size" << tree2.size() << std::endl;
	std::cout << "tree::size: " << tree.size() << std::endl;
	std::cout << "tree::empty: " << tree.empty() << std::endl;
	tree.clear();
	std::cout << "tree::size after clear: " << tree.size() << std::endl;
	tree.insert(42);
	tree = tree2;
	std::cout << "tree::size after =: " << tree.size() << std::endl;
}
