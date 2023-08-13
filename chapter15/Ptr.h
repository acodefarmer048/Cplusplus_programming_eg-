#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <iostream>
#include <stdexcept>
#include <cstddef>


//--------------------------------split line---------------------------------
template <class T> class Ptr {
public:
	void make_unique() {				
		if (*refptr != 1) {
			--*refptr;
			refptr = new std::size_t(1);
			p = p ? clone(p) : 0;
		}
	}
//only used when a shared object is gonna changed, we created a new
//one to avoid damaging other pointer(s)
//Ptr class has not provided functions qualified
//so mske_unique usually show up in class T

	Ptr(): p(0), refptr(new std::size_t(1)) {}
	Ptr(T* t): p(t), refptr(new std::size_t(1)) {}
	Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr;}

	Ptr& operator=(const Ptr& );
	~Ptr();
	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;
private:
	T* p;
	std::size_t* refptr;
};


template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++*rhs.refptr;//pointing to the same object as rhs does, which is different from Handle class
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
	refptr=rhs.refptr;
	p = rhs.p;
	return *this;
}

template <class T>
T& Ptr<T>::operator*() const
{
	if (p)
		return *p;
	throw std::runtime_error("unbound Ptr");
}

template <class T>
T* Ptr<T>::operator->() const
{
	if (p)
		return p;// x->y equals to (x.operator->())->y;
	throw std::runtime_error("unbound Ptr");
}

template <class T> Ptr<T>::~Ptr()
{
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
}

//--------------------------------split line---------------------------------
template <class T> T* clone(const T* tp)
{
	return tp->clone();
}//global function 

//--------------------------------split line---------------------------------
//template<>
//Vec<char>* clone(const Vec<char>* vp)
//{
//	return new Vec<char>(*vp);
//}
//an example of template spacialization 
//which is created in casa of shortage of clone function in a target class
//if a Vec<char>* argument is provided, the compiler would choose this spacialized version
//instead of the template one

//--------------------------------split line---------------------------------

//template <class T>
//bool compare(const Ptr<T>& left, const Ptr<T>& right)
//{
//	return left->value_to_compare() < right->value_to_compare();
//}
//
//template<>
//bool compare(const Ptr<Core>& left, const Ptr<Core>& right)
//{
//	return left->name() < right->name();
//}


#endif
