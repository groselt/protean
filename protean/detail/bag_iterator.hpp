//  (C) Copyright Johan Ditmar, Paul O'Neill & Luke Stedman 2009.
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).

#ifndef PROTEAN_DETAIL_BAG_ITERATOR_HPP
#define PROTEAN_DETAIL_BAG_ITERATOR_HPP

#include <protean/config.hpp>
#include <protean/variant_error.hpp>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4251)
#endif

namespace protean { namespace detail {

    template<
        typename ITERATOR_TRAITS
      , typename BASE=variant_iterator_interface<ITERATOR_TRAITS>
    >
    class PROTEAN_DLLEXPORT bag_iterator_interface : public BASE
    {
        typedef typename ITERATOR_TRAITS::value_type& reference_type;
        typedef typename ITERATOR_TRAITS::bag_iterator_type iterator_type;
        typedef typename BASE::date_time_t date_time_t;

    public:
        bag_iterator_interface(const iterator_type &iterator) :
            m_iterator( iterator )
        {
        }
        const std::string& key() const
        {
            return m_iterator->first;
        }
        reference_type value() const
        {
            return m_iterator->second;
        }
        const date_time_t& time() const
        {
            boost::throw_exception(variant_error("Attempt to call time() on bag iterator"));
        }
        void increment()
        {
            ++m_iterator;
        }
        void decrement()
        {
            --m_iterator;
        }
        bool equal(const BASE *rhs) const
        {
            const bag_iterator_interface* cast_rhs = dynamic_cast<const bag_iterator_interface*>(rhs);
            if (cast_rhs==NULL)
            {
                boost::throw_exception(variant_error("Unable to convert iterator to bag iterator"));
            }
            return m_iterator==cast_rhs->iterator();
        }
        iterator_type iterator() const
        {
            return m_iterator;
        }
        BASE* clone()
        {
            return new bag_iterator_interface(m_iterator);
        }
        variant_const_iterator_base* to_const() const
        {
            return new bag_iterator_interface<const_iterator_traits>(m_iterator);
        }

    private:
        iterator_type m_iterator;
    };

    typedef bag_iterator_interface<iterator_traits> bag_iterator;
    typedef bag_iterator_interface<const_iterator_traits> bag_const_iterator;

}} // namespace protean::detail

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif // PROTEAN_DETAIL_BAG_ITERATOR_HPP