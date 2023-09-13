#ifndef GUARD_picture_h
#define GUARD_picture_h

#include "Ptr.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

//private classes for use in the implementation only
class Picture;//forward declaration to avoid errors.
//------------------------------------split-line--------------------------
class Pic_base {
	friend std::ostream& operator<<(std::ostream& , const Picture& );
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	//no public interface(except for the destruction)
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	//pure virtual functions for an abstract base class
	virtual wd_sz width() const=0;
	virtual ht_sz height() const=0;
	virtual void display(std::ostream& , ht_sz, bool) const=0;
public:
	//public virtual destructor to be inherited
	virtual ~Pic_base() {}
protected:
	//static member
	static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
		while (beg!=end) {
			os << " ";
			++beg;
		}
	}
};

//------------------------------------------------------split-line--------
class String_Pic: public Pic_base {
	friend class Picture;
	std::vector<std::string> data;
	String_Pic(const std::vector<std::string>& v): data(v) {}


	wd_sz width() const {
		wd_sz n=0;
		for (ht_sz i=0; i!=data.size(); ++i)
			n=std::max(n, data[i].size());
		return n;
	}
	ht_sz height() const { return data.size(); }
	void display(std::ostream& , ht_sz. bool) const;
};
//-----------------------------------------------split-line------------
class Frame_Pic: public Pic_base {
	friend Picture frame(const Picture& );
	//no public interface
	Ptr<Pic_base> p;
	Frame_Pic(const Ptr<Pic_base>& pic) : p(pic) {}

	wd_sz width() const { return p->width() +4; }
	ht_sz height() const { return p->height()+4; }
	void display(std::ostream& , ht_sz, bool) const;
};
//--------------------------------------------split-line---------------
class VCat_Pic: public Pic_base {
	friend Picture vcat(const Picture& , const Picture& );
	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b):
		top(t), bottom(b) {}


	wd_sz width() const
		{return std::max(top->width(), bottom->width()); }

	ht_sz height() const
		{return top->height()+ bottom->height(); }
	void display(std::ostream& , ht_sz, bool) const;
};
//-----------------------------------------split-line------------------
class HCat_Pic: public Pic_base {
	friend Picture hcat(const Picture& , const Picture& )
