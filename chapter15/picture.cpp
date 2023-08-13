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

