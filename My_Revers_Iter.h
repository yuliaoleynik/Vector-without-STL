#pragma once
#include <iterator>

namespace Vector
{
	template <class TypeIter>
	class My_Const_Rev_Iter
	{
	public:
		typedef TypeIter value_type;
		typedef const TypeIter* pointer;
		typedef const TypeIter& reference;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef std::random_access_iterator_tag iterator_category;

		My_Const_Rev_Iter()
		{
			Iter = 0;
		}

		My_Const_Rev_Iter(TypeIter *Other)
		{
			Iter = Other;
		}

		My_Const_Rev_Iter(const My_Const_Rev_Iter& Other)
		{
			Iter = Other.Iter;
		}

		~My_Const_Rev_Iter()
		{

		}

		My_Const_Rev_Iter& operator =(const My_Const_Rev_Iter& Other)
		{
			Iter = Other.Iter;
			return *this;
		}

		pointer operator ->() const
		{
			return &**this;
		}

		reference operator *() const 
		{
			My_Const_Rev_Iter Temp = *this;
			return *--Temp.Iter;
		}

		My_Const_Rev_Iter& operator ++()
		{
			--Iter;
			return *this;
		}

		My_Const_Rev_Iter operator ++(int i)
		{
			My_Const_Rev_Iter Temp(*this);
			--(*this);
			return Temp;
		}

		My_Const_Rev_Iter& operator --()
		{
			++Iter;
			return *this;
		}

		My_Const_Rev_Iter operator --(int i)
		{
			My_Const_Rev_Iter Temp(*this);
			++(*this);
			return Temp;
		}

		My_Const_Rev_Iter& operator +=(const difference_type& index)
		{
			Iter -= index;
			return *this;
		}

		My_Const_Rev_Iter& operator -=(const difference_type& index)
		{
			Iter += index;
			return *this;
		}

		My_Const_Rev_Iter operator +(const difference_type& index)
		{
			return Iter - index;
		}

		My_Const_Rev_Iter operator -(const difference_type& index)
		{
			return Iter + index;
		}

		reference operator [](size_type& index)
		{
			return *(Iter - index);
		}

		bool operator <(const My_Const_Rev_Iter& Other) const
		{
			return Iter < Other.Iter;
		}

		bool operator >(const My_Const_Rev_Iter& Other) const
		{
			return (!(*this < Other));
		}

		bool operator ==(const My_Const_Rev_Iter& Other) const
		{
			return Iter == Other.Iter;
		}

		bool operator !=(const My_Const_Rev_Iter& Other) const
		{
			return (!(*this == Other));
		}

		bool operator <=(const My_Const_Rev_Iter& Other) const
		{
			return Iter <= Other.Iter;
		}

		bool operator >=(const My_Const_Rev_Iter& Other) const
		{
			return (!(*this <= Other.Iter));
		}

		difference_type operator -(const My_Const_Rev_Iter& Other)const
		{
			return Iter - Other.Iter;
		}

	private:
		TypeIter* Iter;
	};

	template <class TypeIter>
	class My_Rev_Iter : public My_Const_Rev_Iter<TypeIter>
	{
	public:
		typedef TypeIter value_type;
		typedef const TypeIter* pointer;
		typedef const TypeIter& reference;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef std::random_access_iterator_tag iterator_category;

		My_Rev_Iter()
			:My_Const_Rev_Iter()
		{
			Iter = 0;
		}

		My_Rev_Iter(TypeIter* Other)
			:My_Const_Rev_Iter(Other)
		{
			Iter = Other;
		}

		My_Rev_Iter(const My_Rev_Iter& Other)
			:My_Const_Rev_Iter(Other)
		{
			Iter = Other.Iter;
		}

		~My_Rev_Iter()
		{

		}

		My_Rev_Iter& operator =(const My_Rev_Iter& Other)
		{
			Iter = Other.Iter;
			return *this;
		}

		pointer operator ->() const
		{
			return &**this;
		}

		reference operator *() const
		{
			My_Rev_Iter Temp = *this;
			return *--Temp.Iter;
		}

		My_Rev_Iter& operator ++()
		{
			--Iter;
			return *this;
		}

		My_Rev_Iter operator ++(int i)
		{
			My_Rev_Iter Temp(*this);
			--(*this);
			return Temp;
		}

		My_Rev_Iter& operator --()
		{
			++Iter;
			return *this;
		}

		My_Rev_Iter operator --(int i)
		{
			My_Rev_Iter Temp(*this);
			++(*this);
			return Temp;
		}

		My_Rev_Iter& operator +=(const difference_type& index)
		{
			Iter -= index;
			return *this;
		}

		My_Rev_Iter& operator -=(const difference_type& index)
		{
			Iter += index;
			return *this;
		}

		My_Rev_Iter operator +(const difference_type& index) const
		{
			return Iter - index;
		}

		My_Rev_Iter operator -(const difference_type& index) const
		{
			return Iter + index;
		}

		reference operator [](size_type& index)
		{
			return *(Iter - index);
		}

		bool operator <(const My_Rev_Iter& Other) const
		{
			return Iter < Other.Iter;
		}

		bool operator >(const My_Rev_Iter& Other) const
		{
			return (!(*this < Other));
		}

		bool operator ==(const My_Rev_Iter& Other) const
		{
			return Iter == Other.Iter;
		}

		bool operator !=(const My_Rev_Iter& Other) const
		{
			return (!(*this == Other));
		}

		bool operator <=(const My_Rev_Iter& Other) const
		{
			return Iter <= Other.Iter;
		}

		bool operator >=(const My_Rev_Iter& Other) const
		{
			return (!(*this <= Other));
		}

		difference_type operator -(const My_Rev_Iter& Other) const
		{
			return Iter - Other.Iter;
		}

	private:
		pointer Iter;
	};
}

