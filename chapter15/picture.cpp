#include "Ptr.h"//memory control
#include "picture.h"
#include <vector>
#include <string>
#include <iostream>

using std::istream; using std::ostream;
using std::cin;     using std::cout;
using std::vector;  using std::string;
using std::endl;

//interface define for functions
Picture frame(const Picture& pic)
{
	//call Frame_Pic constructor
	return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_Pic(t.p, b.p);
}

ostream& operator<<(ostream& os, const Picture& picture)
{
	const Pic_base::ht_sz ht=picture.p->height();
	for(Pic_base::ht_sz i=0; i!=ht;++i) {
		picture.p->display(os, i, false);
		os<<endl;
	}
	return os;
}

//Picture public constructor
Picture::Picture(const vector<string>& v):p(new String_Pic(v)) {}
//-----------------------------------splite-line-----------------------------------
//display functions for each derived classes. and pad function called when the row >= height() can be convenient for recursion.
void String_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz start=0;

	// write the row if we're still in range
	if ( row < height() ) {
		os << data[row];
		start = data[row].size();
	}

	// pad the output if necessary
	if (do_pad)
		pad(os, start, width());
}

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	if (row>=height()) {
		if (do_pad)
			pad(os, 0, width());
	} else {
		if (row==0 || row==height()-1) {
			os<<string(width(),'*');
		} else if (row==1 || row==height()-2) {
			os << "*";
			pad(os, 1, width()-1);
			os << "*";
		} else {
			os << "* ";
			p->display(os, row-2, true);
			os << " *";
		}
	}
}

void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	wd_sz w=0;
	if (row < top->height()) {
		top->display(os, row, do_pad);
		w=top->width();
	} else if (row < height()) {
		bottom->display(os, row-top->height(), do_pad);
		w=bottom->width();
	}
	if (do_pad)
		pad(os, w, width());
}

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}
