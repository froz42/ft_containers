/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorConstReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:15:11 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 16:24:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONST_REVERSE_ITERATOR_HPP
# define VECTOR_CONST_REVERSE_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <typename T>
	class VectorConstReverseIterator
	{
		
		public:
			typedef T value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef std::ptrdiff_t difference_type;

			VectorConstReverseIterator(void) : _ptr(NULL) {};
			VectorConstReverseIterator(pointer ptr) : _ptr(ptr) {};
			VectorConstReverseIterator(const VectorConstReverseIterator& other) : _ptr(other._ptr) {};
			virtual ~VectorConstReverseIterator(void) {};

			VectorConstReverseIterator& operator=(const VectorConstReverseIterator& other)
			{
				this->_ptr = other._ptr;
				return (*this);
			}

			bool operator==(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool operator!=(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr != other._ptr);
			}
			bool operator<(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr < other._ptr);
			}
			bool operator>(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr > other._ptr);
			}
			bool operator<=(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr <= other._ptr);
			}
			bool operator>=(VectorConstReverseIterator const &other) const
			{
				return (this->_ptr >= other._ptr);
			}

			VectorConstReverseIterator operator+(difference_type n) const
			{
				return (VectorConstReverseIterator(this->_ptr - n));
			}
			VectorConstReverseIterator operator-(difference_type n) const
			{
				return (VectorConstReverseIterator(this->_ptr + n));
			}

			VectorConstReverseIterator& operator+=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}
			VectorConstReverseIterator& operator-=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}

			VectorConstReverseIterator& operator++(void)
			{
				--this->_ptr;
				return (*this);
			}
			VectorConstReverseIterator& operator--(void)
			{
				++this->_ptr;
				return (*this);
			}
			
			VectorConstReverseIterator operator++(int)
			{
				VectorConstReverseIterator tmp(*this);
				--this->_ptr;
				return (tmp);
			}
			VectorConstReverseIterator operator--(int)
			{
				VectorConstReverseIterator tmp(*this);
				++this->_ptr;
				return (tmp);
			}

			const_reference operator*(void) const
			{
				return (*this->_ptr);
			}

			const_reference operator[](difference_type n) const
			{
				return (*(this->_ptr - n));
			}
			
			const_pointer operator->(void) const
			{
				return (this->_ptr);
			}

		private:
			pointer _ptr;
	};
}
#endif
