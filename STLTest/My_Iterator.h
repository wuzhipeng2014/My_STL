
#include "stdafx.h"


namespace my_stl
{


//���ֵ��������� (���ֵ���������֮����ڼ̳й�ϵ)

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
//	//��������������������
//	typedef Category iterator_category;
//	typedef T value_type;
//	typedef Distence difference_type;
//	typedef Pointer pointer;
//	typedef Reference reference;
//};


template<typename Iterator>
struct iterator_traits
{
	//����������������������ת��Ϊͳһ������
	typedef typename Iterator::iterator_category iterator_category;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
};

//�˺������Է����ȡ�õ�����������
template<typename Iterator>
inline typename iterator_traits<Iterator>::iterator_category iterator_catergory(const Iterator&)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return catergory();
	
}

//�˺������Է����ȡ�õ�������value_type
template<typename Iterator>
inline typename iterator_traits<Iterator>::value_type * value_type(const Iterator&)
{
	//����һ��ָ�����͵Ŀ�ָ��

	return static_cast<typename iterator_traits<Iterator>::value_type *>(0);
}

}