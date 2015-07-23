
#include "stdafx.h"




namespace my_stl
{

	using std::input_iterator_tag;
	using std::output_iterator_tag;
	using std::forward_iterator_tag;
	using std::random_access_iterator_tag;
	using std::bidirectional_iterator_tag;
	//���ֵ��������� (���ֵ���������֮����ڼ̳й�ϵ)

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
		//��������������������
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distence difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};


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
	inline typename iterator_traits<Iterator>::iterator_category iterator_category(const Iterator&)
	{
		typedef typename iterator_traits<Iterator>::iterator_category category;
		return category();

	}

	//�˺������Է����ȡ�õ�������value_type
	template<typename Iterator>
	inline typename iterator_traits<Iterator>::value_type * value_type(const Iterator&)
	{
		//����һ��ָ�����͵Ŀ�ָ��
		return static_cast<typename iterator_traits<Iterator>::value_type *>(0);
	}

	//���ԭ��ָ����Ƶ�traitsƫ�ػ��汾
	template<typename T>
	struct  iterator_traits<T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t defference_type;
		typedef T* pointer;
		typedef T& reference;
	};

	//���ԭ��ָ��֮pointer-to-const��Ƶ�Ƭ�ػ��汾
	template<typename T>
	struct iterator_traits<const T*>
	{
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t defference_type;
		typedef const T* pointer;
		typedef const T& reference;
	};

	//����������advance����
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
