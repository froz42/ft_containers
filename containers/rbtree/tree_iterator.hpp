/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:24:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/18 15:47:13 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include <iterator> // std::bidirectional_iterator_tag
#include <cstddef>	// std::ptrdiff_t, NULL

namespace ft
{
	template <class Node>
	class tree_iterator
	{
	public:
		typedef Node value_type;
		typedef value_type *node_ptr;
		typedef typename Node::value_type const data_type;
		typedef data_type &reference;
		typedef data_type const &const_reference;
		typedef data_type *pointer;
		typedef data_type const *const_pointer;
		typedef typename std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;

		node_ptr node;

		tree_iterator(node_ptr node, node_ptr root, node_ptr NIL)
			: node(node), root(root), NIL(NIL) {}

		tree_iterator(void) : node(NULL), root(NULL), NIL(NULL) {}

		tree_iterator(const tree_iterator &other)
			: node(other.node), root(other.root), NIL(other.NIL) {}

		~tree_iterator(void) {}

		//overload for const iterator
		operator tree_iterator<value_type const>(void) const
		{
			return tree_iterator<value_type const>(node, root, NIL);
		}

		tree_iterator &operator=(const tree_iterator &other)
		{
			node = other.node;
			root = other.root;
			NIL = other.NIL;
			return *this;
		}

		bool operator==(const tree_iterator &other) const
		{
			return node == other.node;
		}

		bool operator!=(const tree_iterator &other) const
		{
			return node != other.node;
		}

		reference operator*(void)
		{
			return node->data;
		}

		const_reference operator*(void) const
		{
			return *(node->data);
		}

		pointer operator->(void)
		{
			return &(operator*());
		}

		const_pointer operator->(void) const
		{
			return &(operator*());
		}

		tree_iterator &operator++(void)
		{
			if (node != NIL)
				node = _next();
			return *this;
		}

		tree_iterator operator++(int)
		{
			tree_iterator tmp(*this);
			++(*this);
			return tmp;
		}

		tree_iterator &operator--(void)
		{
			if (node != NIL)
				node = _prev();
			else
				node = max(root);
			return *this;
		}

		tree_iterator operator--(int)
		{
			tree_iterator tmp(*this);
			--(*this);
			return tmp;
		}

	private:
		node_ptr root;
		node_ptr NIL;

		node_ptr max(node_ptr node)
		{
			while (node->right != NIL)
				node = node->right;
			return node;
		}

		node_ptr min(node_ptr node)
		{
			while (node->left != NIL)
				node = node->left;
			return node;
		}

		//find the previous node in the tree
		node_ptr _prev(void)
		{
			node_ptr n = node;
			node_ptr previous = NIL;

			if (node->left != NIL)
				return max(node->left);
			previous = node->parent;
			while (previous != NIL && node == previous->left)
			{
				node = previous;
				previous = previous->parent;
			}
			return previous;
		}

		//find the next node in the tree
		node_ptr _next(void)
		{
			node_ptr n = node;
			node_ptr next = NIL;

			if (n->right != NIL)
				return min(n->right);

			next = n->parent;
			while (next != NIL && node == next->right)
			{
				n = next;
				next = next->parent;
			}
			return next;
		}
	};
}

#endif
