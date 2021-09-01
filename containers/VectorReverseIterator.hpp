/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:15:11 by tmatis            #+#    #+#             */
/*   Updated: 2021/09/01 16:24:11 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <typename T>
	class VectorReverseIterator
	{
		
		public:
			typedef T value_type;
			typedef value_type& reference;
			typedef value_type* pointer;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef std::ptrdiff_t difference_type;

			VectorReverseIterator(void) : _ptr(NULL) {};
			VectorReverseIterator(pointer ptr) : _ptr(ptr) {};
			VectorReverseIterator(const VectorReverseIterator& other) : _ptr(other._ptr) {};
			virtual ~VectorReverseIterator(void) {};

			VectorReverseIterator& operator=(const VectorReverseIterator& other)
			{
				this->_ptr = other._ptr;
				return (*this);
			}

			bool operator==(VectorReverseIterator const &other) const
			{
				return (this->_ptr == other._ptr);
			}
			bool operator!=(VectorReverseIterator const &other) const
			{
				return (this->_ptr != other._ptr);
			}
			bool operator<(VectorReverseIterator const &other) const
			{
				return (this->_ptr < other._ptr);
			}
			bool operator>(VectorReverseIterator const &other) const
			{
				return (this->_ptr > other._ptr);
			}
			bool operator<=(VectorReverseIterator const &other) const
			{
				return (this->_ptr <= other._ptr);
			}
			bool operator>=(VectorReverseIterator const &other) const
			{
				return (this->_ptr >= other._ptr);
			}

			VectorReverseIterator operator+(difference_type n) const
			{
				return (VectorReverseIterator(this->_ptr - n));
			}
			VectorReverseIterator operator-(difference_type n) const
			{
				return (VectorReverseIterator(this->_ptr + n));
			}

			VectorReverseIterator& operator+=(difference_type n)
			{
				this->_ptr -= n;
				return (*this);
			}
			VectorReverseIterator& operator-=(difference_type n)
			{
				this->_ptr += n;
				return (*this);
			}

			VectorReverseIterator& operator++(void)
			{
				--this->_ptr;
				return (*this);
			}
			VectorReverseIterator& operator--(void)
			{
				++this->_ptr;
				return (*this);
			}
			
			VectorReverseIterator operator++(int)
			{
				VectorReverseIterator tmp(*this);
				--this->_ptr;
				return (tmp);
			}
			VectorReverseIterator operator--(int)
			{
				VectorReverseIterator tmp(*this);
				++this->_ptr;
				return (tmp);
			}

			reference operator*(void)
			{
				return (*this->_ptr);
			}
			const_reference operator*(void) const
			{
				return (*this->_ptr);
			}

			reference operator[](difference_type n)
			{
				return (*(this->_ptr - n));
			}
			const_reference operator[](difference_type n) const
			{
				return (*(this->_ptr - n));
			}

			pointer operator->(void)
			{
				return (this->_ptr);
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
