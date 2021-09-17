/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:24:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/18 00:06:43 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "tree.hpp"

namespace ft
{
	template <class Node>
	class tree_iterator
	{
	public:
		typedef typename Node::value_type value_type;
		typedef Node *node_ptr;
		typedef value_type *pointer;
		typedef value_type &reference;
		typedef value_type const *const_pointer;
		typedef value_type const &const_reference;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef typename std::ptrdiff_t difference_type;

		node_ptr node;

		tree_iterator(node_ptr node, node_ptr root, node_ptr NIL)
			: node(node), root(root), NIL(NIL) {}
		tree_iterator(void) : node(NULL), root(NULL), NIL(NULL) {}
		tree_iterator(const tree_iterator &other)
			: node(other.node), root(other.root), NIL(other.NIL) {}

		~tree_iterator(void) {}

		//overload for const iterator
		operator tree_iterator<node_ptr const>(void) const
		{
			return tree_iterator<node_ptr const>(node, root, NIL);
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
			node_ptr node = node;
			node_ptr previous = NIL;

			//       3 <--- start
			//     /   \
			//    1     5
			//   / \
			//  0   2 <-- target
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
			node_ptr node = node;
			node_ptr next = NIL;

			if (node->right != NIL)
				return min(node->right);
			
			next = node->parent;
			while (next != NIL && node == next->right)
			{
				node = next;
				next = next->parent;
			}
			return next;
		}
	};
}

#endif
