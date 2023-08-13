#ifndef GUARD_picture_h
#define GUARD_picture_h

#include "Ptr.h"//memory control
#include <vector>
#include <string>
#include <iostream>

//private classes for use in the implementation only
//----------------------------------split-line-----------------------------------
class Pic_base {
	friend std::ostream& operator<<(std::ostream& , const Picture& );
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	//no public interface(except for the destructor)
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	//pure virtual functions for an abstract base class
	virtual wd_sz width() const=0;
	virtual ht_sz height() const=0;
	virtual void display(std::ostream& , ht_sz, bool) const=0;
public:
	//public virtual destructor to be inherited
	virtual ~Pic_base() {}
};

//----------------------------------split-line-----------------------------------
class String_Pic: public Pic_base {

};
//----------------------------------split-line-----------------------------------
class Frame_Pic: public Pic_base {
	//no public interface
	Ptr<Pic_base> p;
	Frame_Pic(const Ptr<Pic_base>& pic):p(pic) {}

	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream& , ht_sz, bool) const;
};
//----------------------------------split-line-----------------------------------
class VCat_Pic: public Pic_base {

};
//----------------------------------split-line-----------------------------------
class HCat_Pic: public Pic_base {

};
//----------------------------------split-line-----------------------------------
class Picture {
public:
	Picture(const std::vector<std::string>& =
		std::vector<std::string>());
private:
	Ptr<Pic_base> p;
};
//functions for interface
Picture frame(const Picture& );
Picture hcat(const Picture& , const Picture& );
Picture vcat(const Picture& , const Picture& );
std::ostream& operator<<(std::ostream& , const Picture& );

