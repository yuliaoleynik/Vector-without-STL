#pragma once
#include <cassert>
#include "MyIterator.h"
#include "My_Revers_Iter.h"

 

//{ push_back(),  All methods that MyVector have
//  pop_back(),
//  size(),
//  capasity(),
//  empty(),
//  resize(),
//  swap(),
//  at(),
//  assign(),
//  erase(),
//  insert(),
//  end,begin,rend,rbegin,front,back,
//  clear() }


namespace Vector
{
	template <class Type >
	class MyVector
	{
	public:
		typedef size_t size_type;
		typedef Type value_type;
		typedef ptrdiff_t difference_type;
		typedef My_Const_Iter<Type> const_iterator;
		typedef My_Iter<Type> iterator;
		typedef My_Const_Rev_Iter<Type> const_reverse_iter;
		typedef My_Rev_Iter<Type> reverse_iter;

		MyVector()
			:m_size(0),m_capasity(0)
		{
			m_vector = nullptr;
		}

		MyVector(const size_type size,const value_type* elem = value_type())
		{
			m_size = size;
			m_capasity = size;
			m_vector = new value_type[m_size];
			for (size_t i = 0; i < m_size; ++i)
			{
				m_vector[i] = elem;
			}			
		}

		MyVector(const MyVector& Other)
		{
			m_size = Other.m_size;
			m_capasity = Other.m_capasity;
			m_vector = new value_type[Other.m_size];

			for (size_t i = 0; i < m_size; ++i)
			{
				m_vector[i] = Other.m_vector[i];
			}
		}

		~MyVector()
		{
			delete[] m_vector;
		}

		inline const size_type size() const{return m_size;}
		inline const size_type capacity() const{return m_capasity;}
		inline const bool empty() const { return m_size == 0;}

		void resize(const size_type size, const value_type& val = value_type())
		{
			reserve(size);

			for (size_type i = m_size; i < size; ++i)
				m_vector[i] = val;
			end() += m_size - size;
			m_size = size;
		}

		void reserve(const size_type size)
		{
			value_type* data = new value_type[size];

			for (size_type i = 0; i < size; ++i)
				data[i] = m_vector[i];

			delete[] m_vector;
			m_vector = data;
			
			if (size > m_capasity)
				m_capasity = size;
		}

		inline value_type& operator[](const size_type index)
		{
			assert(index >= 0 && index <= m_size);
			return m_vector[index];
		}

		inline const value_type& operator[](const size_type index) const
		{
			assert(index >= 0 && index <= m_size);
			return m_vector[index];
		}

		void push_back(const value_type& elem)
		{
			m_size += 1;
			if (m_size > m_capasity)
				reserve(2 * m_size - 1);
			m_vector[m_size - 1] = elem;
		}

		inline void clear()
		{
			resize(0);
		}

		const MyVector& operator =(const MyVector& Other)
		{
			if (this == &Other)
				return *this;

			delete[] m_vector;
			m_size = Other.m_size;

			if (m_capasity < Other.m_capasity)
				m_capasity = Other.m_capasity;

			m_vector = new value_type[m_size];
			for (size_t i = 0; i < m_size; ++i)
				m_vector[i] =  Other.m_vector[i];

			return *this;
		}

		void swap(MyVector& Other)
		{
			MyVector<value_type> Temp(*this);
			*this = Other;
			Other = Temp;
		}

		inline iterator begin()
		{
			return iterator(m_vector);
		}

		inline const_iterator begin() const
		{
			return const_iterator(m_vector);
		}

		inline iterator end()
		{
			return iterator(m_vector + m_size);
		}

		inline const_iterator end() const
		{
			return const_iterator(m_vector + m_size);
		}

		inline reverse_iter rbegin()
		{
			return reverse_iter(m_vector + m_size);
		}

		inline const_reverse_iter rbegin() const
		{
			return const_reverse_iter(m_vector + m_size);
		}

		inline reverse_iter rend()
		{
			return reverse_iter(m_vector);
		}

		inline const_reverse_iter rend() const
		{
			return const_reverse_iter(m_vector);
		}

		inline value_type& front()
		{
			return *m_vector;
		}

		inline value_type& back()
		{
			return *(m_vector + m_size - 1);
		}

		inline const value_type& front() const
		{
			return *m_vector;
		}

		inline const value_type& back() const
		{
			return *(m_vector + m_size - 1);
		}

		void pop_back()
		{
			m_size -= 1;
			resize(m_size);
		}

		inline value_type& at(const size_type index)
		{
			assert(index >= 0 && index <= m_size);
			return m_vector[index];
		}

		inline const value_type& at(const size_type index) const
		{
			assert(index >= 0 && index <= m_size);
			return m_vector[index];
		}

		void assign(const size_type size, const value_type& elem)
		{
			resize(size, elem);
		}

		void erase(iterator pos)
		{
			/*assert(pos >= 0 && pos <= m_size);*/

			if (m_size == 1)
			{
				clear();
				return;
			}
			
			size_type index = 0;
			value_type* data = new value_type[m_size - 1];

			for (size_type before = 0; before < m_size; ++before)
			{
				if (&m_vector[before] == pos.Iter) 
				{
					index = before; 
					break;
				}
				data[before] = m_vector[before];
			}
			for ( size_type after = index + 1; after < m_size; ++after)
				data[after - 1] = m_vector[after];

			delete[] m_vector;
			m_vector = data;
			--m_size;
		}


		/*iterator insert(iterator pos, const value_type& elem)
		{
			assert(!(end() < pos));
			assert(!(begin() > pos));
			size_type offs = pos - begin();
			copy(1, offs, elem);
			return (begin() + offs);
		}*/

	private:
		size_type m_size;
		size_type m_capasity;
		Type* m_vector;

		/*void copy(const size_type& sz, const difference_type& offs,
			const value_type& elem = 0, iterator first = 0, iterator last = 0)
		{
			pointer Buf;
			Buf = Al.allocate(m_size + sz);
			for (size_type i = 0; i < m_size + sz; ++i)
			{
				Al.construct(&Buf[i], m_vector[i]);
			}
			for (pointer t = Buf + m_size + sz - 1; t >= Buf + offs; --t)
			{
				if (sz > 1)
					*(t + 1) = *(t - sz + 1);
				else
					*(t + 1) = *t;
			}
			for (pointer t = Buf + offs; t != Buf + offs + sz; ++t)
			{
				if (first == 0 && last == 0)
					Al.construct(t, elem);
				else
					Al.construct(t, *first++);
			}
			resize(m_size + sz);
			m_vector = Buf;
		}*/
	};

	template<class Type>
	inline bool operator ==(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return (First.size() == Second.size() &&
			std::equal(First.begin(), First.end(), Second.begin()));
	}

	template<class Type>
	inline bool operator !=(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return (!(First == Second));
	}

	template<class Type>
	inline bool operator <(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return std::lexicographical_compare(First.begin(), First.end(), Second.begin(), Second.end());
	}

	template<class Type>
	inline bool operator >(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return Second < First;
	}

	template<class Type>
	inline bool operator <=(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return (!(Second < First));
	}

	template<class Type>
	inline bool operator >=(const MyVector<Type>& First,
		const MyVector<Type>& Second)
	{
		return (!(First < Second));
	}

};
