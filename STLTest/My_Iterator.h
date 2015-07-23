
#include "stdafx.h"


namespace my_stl
{


//五种迭代器类型 (五种迭代器类型之间存在继承关系)

struct input_iterator_tag
{

};

struct output_iterator_tag
{

};

struct forward_iterator_tag: public input_iterator_tag
{

};

struct bidirection_iterator_tag : public forward_iterator_tag
{

};

struct random_access_iterator_tag : public bidirection_iterator_tag
{

};

//template<typename Category,typename T, typename Distence=ptrdiff_t,typename Pointer=T*, typename Reference=T&>
//struct iterator
//{
//	//迭代器的五种内置类型
//	typedef Category iterator_category;
//	typedef T value_type;
//	typedef Distence difference_type;
//	typedef Pointer pointer;
//	typedef Reference reference;
//};


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
inline typename iterator_traits<Iterator>::iterator_category iterator_catergory(const Iterator&)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return catergory();
	
}

//此函数可以方便的取得迭代器的value_type
template<typename Iterator>
inline typename iterator_traits<Iterator>::value_type * value_type(const Iterator&)
{
	//返回一个指定类型的空指针

	return static_cast<typename iterator_traits<Iterator>::value_type *>(0);
}

}