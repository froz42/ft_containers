/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:33:23 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/13 14:35:09 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#define BLACK 0
#define RED 1

#include <memory>
#include <iostream>
#include <iomanip>

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
	template <typename T, typename Compare>
	class rbtree
	{
	public:
		/* typedef */
		typedef _rbtree_node<T> node;
		typedef _rbtree_node<T> *node_ptr;
		typedef _rbtree_node<T> &node_ref;
		typedef T data_type;
		typedef Compare compare;
		typedef std::allocator<_rbtree_node<T> > allocator;
		/* constructor */
		//default
		rbtree(void) : _root(NULL), _comp(compare()) {}

		~rbtree(void)
		{
			this->clear();
		}
		/* member function */
		void insert(T data)
		{
			node_ptr n = _alloc.allocate(1);
			_alloc.construct(n, _rbtree_node<T>(data));

			_recursive_insert(this->_root, n);

			_insert_fixup(n);

			// search for new root
			while (n->parent != NULL)
				n = n->parent;
			this->_root = n;
		}
		void clear(void)
		{
			_recursive_clear(this->_root);
		}
		// pretty print
		void print(node *p = NULL, int indent = 0)
		{
			if (p == NULL)
				p = this->_root;
			if (p != NULL)
			{
				if (p->right)
				{
					print(p->right, indent + 4);
				}
				if (indent)
				{
					std::cout << std::setw(indent) << ' ';
				}
				if (p->right)
					std::cout << " /\n"
							  << std::setw(indent) << ' ';
				if (p->color == RED)
					std::cout << "\033[0;31m";
				std::cout << p->data << "\n ";
				std::cout << "\033[0m";
				if (p->left)
				{
					std::cout << std::setw(indent) << ' ' << " \\\n";
					print(p->left, indent + 4);
				}
			}
		}

	private:
		node_ptr _root;
		compare _comp;
		allocator _alloc;

		void _recursive_insert(node_ptr &root, node_ptr &n)
		{
			if (root != NULL && _comp(n->data, root->data))
			{
				if (root->left != NULL)
				{
					_recursive_insert(root->left, n);
					return;
				}
				else
					root->left = n;
			}
			else if (root != NULL)
			{
				if (root->right != NULL)
				{
					_recursive_insert(root->right, n);
					return;
				}
				else
					root->right = n;
			}

			n->parent = root;
		}
		static void _insert_fixup(node_ptr &n)
		{
			if (n->get_parent() == NULL) // case 1
				n->color = BLACK;
			else if (n->get_parent()->color == BLACK) // case 2
				return;
			else if (n->get_uncle() != NULL && n->get_uncle()->color == RED) // case 3
			{
				node_ptr g = n->get_grandparent();
				n->get_parent()->color = BLACK;
				n->get_uncle()->color = BLACK;
				g->color = RED;
				_insert_fixup(g);
			}
			else // case 4
			{
				node_ptr p = n->get_parent();
				node_ptr g = n->get_grandparent();
				if (g->left && n == g->left->right)
				{
					p->rotate_left();
					n = n->left;
				}
				else if (n == g->right->left)
				{
					p->rotate_right();
					n = n->right;
				}
				p = n->get_parent();
				g = n->get_grandparent();
				if (n == p->left)
					g->rotate_right();
				else
					g->rotate_left();
				p->color = BLACK;
				g->color = RED;
			}
		}
		void _recursive_clear(node_ptr &n)
		{
			if (n->left != NULL)
				_recursive_clear(n->left);
			if (n->right != NULL)
				_recursive_clear(n->right);
			_alloc.destroy(n);
			_alloc.deallocate(n, 1);
		}
	};
}

#endif
