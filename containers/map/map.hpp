/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:34:25 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/19 16:11:43 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "../rbtree/tree.hpp"
#include "../pair/make_pair.hpp"
#include "../iterators/lexicographical_compare.hpp"
#include "../iterators/equal.hpp"

namespace ft
{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<Key, T> > >
	class map
	{
	public:
		// typedef
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<key_type, mapped_type> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;

		// help compare key
		class value_compare
		{
		public:
			bool operator()(const value_type &a, const value_type &b) const
			{
				return (key_compare()(a.first, b.first));
			}
			value_compare &operator=(const value_compare &) { return *this; }
		};

		typedef
			typename _rb_tree<value_type, value_compare>::iterator
				iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::const_iterator
				const_iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::reverse_iterator
				reverse_iterator;
		typedef
			typename _rb_tree<value_type, value_compare>::const_reverse_iterator
				const_reverse_iterator;

		// constructors
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
			: _tree()
		{
			_alloc = alloc;
			_key_comp = comp;
			_value_comp = value_compare();
		}

		template <class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare(),
			const Allocator &alloc = Allocator()) : _tree()
		{
			_alloc = alloc;
			_key_comp = comp;
			_value_comp = value_compare();
			insert(first, last);
		}

		map(const map &other)
		{
			_alloc = other._alloc;
			_key_comp = other._key_comp;
			_value_comp = other._value_comp;
			_tree = other._tree;
		}

		~map(void) {}

		map &operator=(const map &other)
		{
			_alloc = other._alloc;
			_key_comp = other._key_comp;
			_value_comp = other._value_comp;
			_tree = other._tree;
			return *this;
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		// element access //

		mapped_type &at(const key_type &key)
		{
			iterator v =
				_tree.find(ft::make_pair(key, mapped_type()));
			if (v != _tree.end())
				return (v.node->data.second);
			throw std::out_of_range("map::at");
		}

		const mapped_type &at(const key_type &key) const
		{
			const_iterator v =
				_tree.find(ft::make_pair(key, mapped_type()));
			if (v != _tree.end())
				return (v.node->data.second);
			throw std::out_of_range("map::at");
		}

		mapped_type &operator[](const key_type &key)
		{
			iterator res = _tree.find(ft::make_pair(key, mapped_type()));

			if (res != _tree.end())
				return (res.node->data.second);
			else
			{
				ft::pair<iterator, bool> res2 = _tree.insert(
					ft::make_pair(key, mapped_type()));
				return (res2.first.node->data.second);
			}
		}

		// iterator //

		iterator begin(void)
		{
			return (_tree.begin());
		}

		const_iterator begin(void) const
		{
			return (_tree.begin());
		}

		iterator end(void)
		{
			return (_tree.end());
		}

		const_iterator end(void) const
		{
			return (_tree.end());
		}

		reverse_iterator rbegin(void)
		{
			return (_tree.rbegin());
		}

		const_reverse_iterator rbegin(void) const
		{
			return (_tree.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (_tree.rend());
		}

		const_reverse_iterator rend(void) const
		{
			return (_tree.rend());
		}

		// capacity //

		bool empty(void) const
		{
			return (_tree.size() == 0);
		}

		size_type size(void) const
		{
			return (_tree.size());
		}

		size_type max_size(void) const
		{
			return (_tree.max_size());
		}

		// modifiers //

		void clear(void)
		{
			_tree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type &value)
		{
			return (_tree.insert(value));
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			for (; first != last; ++first)
				_tree.insert(*first);
		}

		iterator insert(iterator hint, const value_type &value)
		{
			return (_tree.insert(hint, value));
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
			return (_tree.erase(ft::make_pair(key, mapped_type())));
		}

		void swap(map &other)
		{
			std::swap(_alloc, other._alloc);
			std::swap(_key_comp, other._key_comp);
			std::swap(_value_comp, other._value_comp);
			_tree.swap(other._tree);
		}

		// lookups //

		size_type count(const key_type &key) const
		{
			iterator res = _tree.find(ft::make_pair(key, mapped_type()));

			return (res == _tree.end()) ? 0 : 1;
		}

		iterator find(const key_type &key)
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		const_iterator find(const key_type &key) const
		{
			return (_tree.find(ft::make_pair(key, mapped_type())));
		}

		iterator lower_bound(const Key &key)
		{
			return (_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator lower_bound(const Key &key) const
		{
			return (_tree.lower_bound(ft::make_pair(key, mapped_type())));
		}

		iterator upper_bound(const Key &key)
		{
			return (_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		const_iterator upper_bound(const Key &key) const
		{
			return (_tree.upper_bound(ft::make_pair(key, mapped_type())));
		}

		ft::pair<iterator, iterator> equal_range(const Key &key)
		{
			iterator lower = lower_bound(key);
			iterator upper = upper_bound(key);
			return (ft::make_pair(lower, upper));
		}

		ft::pair<const_iterator, const_iterator>
			equal_range(const Key &key) const
		{
			const_iterator lower = lower_bound(key);
			const_iterator upper = upper_bound(key);
			return (ft::make_pair(lower, upper));
		}

		// observers //

		key_compare key_comp(void) const
		{
			return (_key_comp);
		}

		value_compare value_comp(void) const
		{
			return (_value_comp);
		}

	private:
		_rb_tree<value_type, value_compare> _tree;
		allocator_type _alloc;
		key_compare _key_comp;
		value_compare _value_comp;
	};

	// non-member functions //

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
											rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs,
				   const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs,
					const ft::map<Key, T, Compare, Alloc> &rhs)
	{
		return (rhs == lhs || rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key, T, Compare, Alloc> &lhs,
			  ft::map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif
