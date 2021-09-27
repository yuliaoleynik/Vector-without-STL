#pragma once
#include <iterator>

namespace Vector
{
    template <class TypeIter>
    class My_Const_Iter
    {
    public:
        typedef TypeIter value_type;
        typedef size_t size_type;
        typedef std :: random_access_iterator_tag iterator_category;
        typedef const TypeIter* pointer;
        typedef const TypeIter& reference;
        typedef ptrdiff_t difference_type;

        My_Const_Iter()
        {
            Iter = 0;
        }

        My_Const_Iter(TypeIter* Other)
        {
            Iter = Other;
        }

        My_Const_Iter(const My_Const_Iter& Other)
        {
            Iter = Other.Iter;
        }

        ~My_Const_Iter()
        {

        }

        My_Const_Iter& operator =(const My_Const_Iter& Other)
        {
            Iter = Other.Iter;
            return *this;
        }

        pointer operator -> () const
        {
            return &**Iter;
        }

        reference operator*() const
        {
            return *Iter;
        }

        My_Const_Iter& operator ++()
        {
            ++Iter;
            return *this;
        }

        My_Const_Iter operator ++(int i)
        {
            My_Const_Iter Temp(*this);
                ++(*this);
            return Temp;
        }

        My_Const_Iter& operator --()
        {
            --Iter;
            return *this;
        }

        My_Const_Iter operator --(int i)
        {
            My_Const_Iter Temp(*this);
                --(*this);
            return Temp;
        }

        My_Const_Iter& operator +=(const difference_type& number)
        {
            Iter += number;
            return *this;
        }

        My_Const_Iter& operator -=(const difference_type& number)
        {
            Iter -= number;
            return *this;
        }

        My_Const_Iter operator +(const size_type& number) const
        {
            My_Const_Iter Temp(*this);
            return Temp += number;
        }

        My_Const_Iter operator -(const size_type& number) const
        {
            My_Const_Iter Temp(*this);
            return Temp -= number;
        }

        reference operator [](const size_type& index)
        {
            return *(Iter + index);
        }

        bool operator <(My_Const_Iter& Other)
        {
            return Iter < Other.Iter;
        }

        bool operator >(My_Const_Iter& Other)
        {
            return (!(*this < Other));
        }

        bool operator ==(My_Const_Iter& Other)
        {
            return Iter == Other.Iter;
        }

        bool operator !=(My_Const_Iter& Other)
        {
            return (!(*this == Other));
        }

        bool operator <=(My_Const_Iter& Other)
        {
            return Iter <= Other.Iter;
        }

        bool operator >=(My_Const_Iter& Other)
        {
            return (!(*this <= Other));
        }

        difference_type operator -(const My_Const_Iter& Other)
        {
            return Iter - Other.Iter;
        }


        TypeIter* Iter;
    };


    template <class TypeIter>
    class My_Iter : public My_Const_Iter<TypeIter>
    {
    public:
        typedef TypeIter value_type;
        typedef size_t size_type;
        typedef std::random_access_iterator_tag iterator_category;
        typedef TypeIter* pointer;
        typedef TypeIter& reference;
        typedef ptrdiff_t difference_type;
        
        My_Iter()
            :My_Const_Iter()
        {
            Iter = 0;
        }

        My_Iter(pointer Other)
        {
            Iter = Other;
        }

        My_Iter(const My_Iter& Other)
        {
            Iter = Other.Iter;
        }

        ~My_Iter()
        {

        }

        My_Iter& operator =(const My_Iter& Other)
        {
            Iter = Other.Iter;
            return *this;
        }

        pointer operator -> () const
        {
            return &**this;
        }

        reference operator*() const
        {
            return*Iter;
        }

        My_Iter& operator ++()
        {
            ++Iter;
            return *this;
        }

        My_Iter operator ++(int i)
        {
            My_Iter Temp(*this);
                ++(*this);
            return Temp;
        }

        My_Iter& operator --()
        {
            --Iter;
            return *this;
        }

        My_Iter operator --(int i)
        {
            My_Iter Temp(*this);
                --(*this);
            return Temp;
        }

        My_Iter& operator +=(const difference_type& number)
        {
            Iter += number;
            return *this;
        }

        My_Iter& operator -=(const difference_type& number)
        {
            Iter -= number;
            return *this;
        }

        My_Iter operator +(const difference_type& index) const
        {
            My_Iter Temp(*this);
            return Temp += index;
        }

        My_Iter operator -(const difference_type& index) const
        {
            My_Iter Temp(*this);
            return Temp -= index;
        }

        reference operator [](const size_type& index)
        {
            return *(Iter + index);
        }

        bool operator <(const My_Iter& Other)
        {
            return Iter < Other.Iter;
        }

        bool operator >(const My_Iter& Other)
        {
            return (!(*this < Other));
        }

        bool operator ==(const My_Iter& Other)
        {
            return Iter == Other.Iter;
        }

        bool operator ==(const value_type& elem)
        {
            return *Iter == *elem;
        }

        bool operator !=(const My_Iter& Other)
        {
            return (!(*this == Other));
        }

        bool operator <=(const My_Iter& Other)
        {
            return Iter <= Other.Iter;
        }

        bool operator >=(const My_Iter& Other)
        {
            return (!(*this <= Other));
        }

        difference_type operator -(const My_Iter& Other)
        {
            return Iter - Other.Iter;
        }

        pointer Iter;
    };
}
