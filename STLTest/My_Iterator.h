
#include "stdafx.h"




namespace my_stl
{

	using std::input_iterator_tag;
	using std::output_iterator_tag;
	using std::forward_iterator_tag;
	using std::random_access_iterator_tag;
	using std::bidirectional_iterator_tag;
	//五种迭代器类型 (五种迭代器类型之间存在继承关系)

	//struct input_iterator_tag
	//{

	//};

	//struct output_iterator_tag
	//{

	//};

	//struct forward_iterator_tag : public input_iterator_tag
	//{

	//};

	//struct bidirection_iterator_tag : public forward_iterator_tag
	//{

	//};

	//struct random_access_iterator_tag : public bidirection_iterator_tag
	//{

	//};

	template<typename Category, typename T, typename Distence = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		//迭代器的五种内置类型
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distence difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};


	template<typename Iterator>
	struct iterator_traits
	{
		//将迭代器的五种内置类型转换为统一的名称
		typedef typename Iterator::iterator_category iterator_category;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
	};

	//此函数可以方便的取得迭代器的类型
	template<typename Iterator>
	inline typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator&)
	{
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();

	}

	//此函数可以方便的取得迭代器的value_type
	template<typename Iterator>
	inline typename iterator_traits<Iterator>::value_type * value_type(const Iterator&)
	{
		//返回一个指定类型的空指针
		return static_cast<typename iterator_traits<Iterator>::value_type *>(0);
	}

	//针对原生指针设计的traits偏特化版本
	template<typename T>
	struct  iterator_traits<T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t defference_type;
		typedef T* pointer;
		typedef T& reference;
	};

	//针对原声指针之pointer-to-const设计的片特化版本
	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t defference_type;
		typedef const T* pointer;
		typedef const T& reference;
	};

	//以下是整组advance函数
	template<typename InputIterator, typename Distance>
	inline void __advance(InputIterator &i, Distance n, input_iterator_tag)
	{
		while (--n)
		{
			++i;
		}
	}

	template<typename InputIterator, typename Distance>
	inline void __advance(InputIterator & i, typename Distance, bidirectional_iterator_tag)
	{
		if (n >= 0)
		{
			while (n--) ++i;
		}
		else
		{
			while (n++)
			{
				--i;
			}
		}
	}

	template<typename InputIterator, typename Distance>
	inline void __advance(InputIterator & i, Distance n, random_access_iterator_tag)
	{
		i += n;
	}

	template<typename InputIterator, typename Distance>
	inline void advance(InputIterator & i, Distance n)
	{
		__advance(i,n,iterator_category(i));
	}

}
