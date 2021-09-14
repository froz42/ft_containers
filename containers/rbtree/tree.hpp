/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 21:33:23 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/14 18:51:23 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#define BLACK 0
#define RED 1

#include <iostream>
#include <iomanip>
#include "node.hpp"

namespace ft
{
	template <typename T, typename Compare>
	class rbtree
	{
	public:
		typedef _rbtree_node<T> node;
		typedef _rbtree_node<T> *node_ptr;
		typedef _rbtree_node<T> &node_ref;
		typedef T data_type;
		typedef Compare compare;
		typedef std::allocator<_rbtree_node<T> > allocator;
		typedef size_t size_type;

		rbtree(const allocator &alloc = allocator()) : _root(NULL), _comp(compare())
		{
			this->_alloc = alloc;
		}
		rbtree(const rbtree &other) : _root(NULL), _comp(compare()), _alloc(other._alloc)
		{
			_recursive_copy(*this, other._root);
		}

		~rbtree(void)
		{
			this->clear();
		}

		rbtree &operator=(const rbtree &other)
		{
			if (this != &other)
			{
				this->clear();
				_alloc = other._alloc;
				_comp = other._comp;
				_recursive_copy(*this, other._root);
			}
			return (*this);
		}

		rbtree copy(void) const
		{
			return (rbtree(*this));
		}

		size_type size(void) const
		{
			return (_recursive_size(this->_root));
		}

		bool empty(void) const
		{
			return (this->_root == NULL);
		}

		void clear(void)
		{
			_recursive_clear(this->_root);
			this->_root = NULL;
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
		
		// pretty print
		void print(node *p = NULL, int indent = 0) const
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
		void _recursive_clear(node_ptr n)
		{
			if (n != NULL)
			{
				_recursive_clear(n->left);
				_recursive_clear(n->right);
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
			}
		}
		void _recursive_copy(rbtree &dest, node_ptr src = NULL)
		{
			if (src == NULL)
				src = this->_root;
			dest.insert(src->data);
			if (src->left != NULL)
				_recursive_copy(dest, src->left);
			if (src->right != NULL)
				_recursive_copy(dest, src->right);
		}
		static size_type _recursive_size(const node_ptr root)
		{
			if (root == NULL)
				return 0;
			return (1
			+ _recursive_size(root->left)
			+ _recursive_size(root->right));
		}
	};
}

#endif
