/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:59:37 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/14 18:01:19 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include <memory>

namespace ft
{
	template <typename T>
	struct _rbtree_node
	{
		_rbtree_node *left;
		_rbtree_node *right;
		_rbtree_node *parent;
		T data;
		bool color;

		_rbtree_node(T &data) : left(NULL), right(NULL), parent(NULL), data(data), color(RED) {}
		_rbtree_node(void) : left(NULL), right(NULL), parent(NULL), color(RED) {}
		~_rbtree_node(void) {}

		_rbtree_node *get_parent(void) const
		{
			return this->parent;
		}
		_rbtree_node *get_grandparent(void) const
		{
			if (this->parent == NULL)
				return NULL;
			return this->parent->parent;
		}
		_rbtree_node *get_sibling(void) const
		{
			if (this->parent == NULL)
				return NULL;
			if (this == this->parent->left)
				return this->parent->right;
			else
				return this->parent->left;
		}
		_rbtree_node *get_uncle(void) const
		{
			if (this->parent == NULL)
				return NULL;
			return (this->parent->get_sibling());
		}
		void rotate_left(void)
		{
			_rbtree_node *y = this->right;

			this->right = y->left;
			if (y->left != NULL)
				y->left->parent = this;
			y->parent = this->parent;
			if (this->parent == NULL)
				this->parent = y;
			else if (this == this->parent->left)
				this->parent->left = y;
			else
				this->parent->right = y;
			y->left = this;
			this->parent = y;
		}
		void rotate_right(void)
		{
			_rbtree_node *y = this->left;

			this->left = y->right;
			if (y->right != NULL)
				y->right->parent = this;
			y->parent = this->parent;
			if (this->parent == NULL)
				this->parent = y;
			else if (this == this->parent->left)
				this->parent->left = y;
			else
				this->parent->right = y;
			y->right = this;
			this->parent = y;
		}
	};
}
#endif
