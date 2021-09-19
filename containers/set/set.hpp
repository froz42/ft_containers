/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:04:49 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 17:11:49 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../iterators/lexicographical_compare.hpp"
#include "../iterators/equal.hpp"

namespace ft
{
	template <
		class Key,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<Key> >
	class set
	{
	public:
		typedef Key key_type;
		typedef Key value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare value_compare;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef typename _rb_tree<value_type, value_compare>::iterator iterator;
		typedef typename _rb_tree<value_type, value_compare>::const_iterator const_iterator;
		typedef typename _rb_tree<value_type, value_compare>::reverse_iterator reverse_iterator;
		typedef typename _rb_tree<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

		// Constructors & destructor //
		explicit set(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : _tree()
		{
			_comp = comp;
			_alloc = alloc;
		}

		template <class InputIterator>
		set(InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type()) : _tree()
		{
			_alloc = alloc;
			_comp = comp;
			insert(first, last);
		}

		set(const set &other)
		{
			_alloc = other._alloc;
			_comp = other._comp;
		}

		~set(void){};

		set &operator=(const set &other)
		{
			_alloc = other._alloc;
			_comp = other._comp;
			_tree = other._tree;
			return *this;
		}

		allocator_type get_allocator(void) const
		{
			return _alloc;
		}

		// iterators //

		iterator begin(void)
		{
			return _tree.begin();
		}

		const_iterator begin(void) const
		{
			return _tree.begin();
		}

		iterator end(void)
		{
			return _tree.end();
		}

		const_iterator end(void) const
		{
			return _tree.end();
		}

		reverse_iterator rbegin(void)
		{
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin(void) const
		{
			return _tree.rbegin();
		}

		reverse_iterator rend(void)
		{
			return _tree.rend();
		}

		const_reverse_iterator rend(void) const
		{
			return _tree.rend();
		}

		// capacity //

		size_type size(void) const
		{
			return _tree.size();
		}

		size_type max_size(void) const
		{
			return _tree.max_size();
		}

		bool empty(void) const
		{
			return (_tree.size() == 0);
		}

		// modifiers //

		void clear(void)
		{
			_tree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return _tree.insert(value);
		}

		iterator insert(iterator hint, const value_type &value)
		{
			return _tree.insert(hint, value);
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				_tree.insert(*first);
		}

		void erase(iterator pos)
		{
			_tree.erase(pos);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
				_tree.erase(first++);
		}

		size_type erase(const key_type &key)
		{
			return _tree.erase(key);
		}

		void swap(set &other)
		{
			std::swap(_alloc, other._alloc);
			std::swap(_comp, other._comp);
			_tree.swap(other._tree);
		}

		// lookup //

		size_type count(const key_type &key) const
		{
			iterator res = _tree.find(key);

			return (res == _tree.end()) ? 0 : 1;
		}

		iterator find(const Key &key)
		{
			return _tree.find(key);
		}

		const_iterator find(const Key &key) const
		{
			return _tree.find(key);
		}

		iterator lower_bound(const Key &key)
		{
			return _tree.lower_bound(key);
		}

		const_iterator lower_bound(const Key &key) const
		{
			return _tree.lower_bound(key);
		}

		iterator upper_bound(const Key &key)
		{
			return _tree.upper_bound(key);
		}

		const_iterator upper_bound(const Key &key) const
		{
			return _tree.upper_bound(key);
		}

		ft::pair<iterator, iterator> equal_range(const Key &key)
		{
			iterator lower = _tree.lower_bound(key);
			iterator upper = _tree.upper_bound(key);

			return ft::make_pair(lower, upper);
		}

		ft::pair<const_iterator, const_iterator>
		equal_range(const Key &key) const
		{
			const_iterator lower = _tree.lower_bound(key);
			const_iterator upper = _tree.upper_bound(key);

			return ft::make_pair(lower, upper);
		}

		// Observers //

		key_compare key_comp(void) const
		{
			return _comp;
		}

		value_compare value_comp(void) const
		{
			return _comp;
		}

	private:
		_rb_tree<value_type, value_compare> _tree;
		allocator_type _alloc;
		key_compare _comp;
	};

	template <class Key, class Compare, class Alloc>
	bool operator==(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator!=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator<(const ft::set<Key, Compare, Alloc> &lhs,
				   const ft::set<Key, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end()));
	}

	template <class Key, class Compare, class Alloc>
	bool operator<=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>(const ft::set<Key, Compare, Alloc> &lhs,
				   const ft::set<Key, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>
	bool operator>=(const ft::set<Key, Compare, Alloc> &lhs,
					const ft::set<Key, Compare, Alloc> &rhs)
	{
		return (rhs == lhs || rhs < lhs);
	}

	template <class Key, class Compare, class Alloc>

	void swap(ft::set<Key, Compare, Alloc> &lhs,
			  ft::set<Key, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
