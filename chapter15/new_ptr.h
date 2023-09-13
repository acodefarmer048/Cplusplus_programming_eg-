#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <iostream>
#include <stdexcept>
#include <cstdef>

//---------------------------------------------split-line-----------------
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
//so make_unique usually show up in class T

	Ptr() : p(0), refptr(new std::size_t(1)) {}
	Ptr(T* t): p(t), refptr(new std::size_t(1)) {}
	Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr;}

	Ptr& operator=(const Ptr& );
	~Ptr();
	operator bool() const { return p;}
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
		return p;
	throw std::runtime_error("unbound Ptr");
}

//------------------------------------split-line--------------------------
template <class T> Ptr<T>::~Ptr()
{
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}
}
//------------------------------------split-line--------------------------
template <class T> T* clone(const T* tp)
{
	return tp->clone();
}



