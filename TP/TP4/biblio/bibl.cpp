#include "bibl.h"
#include <ostream>

std::ostream & operator<<(std::ostream & os, Document const & d) {
	d.OutStream(os);
	return os;
}

void Document::OutStream(std::ostream & os) {
	os 	<< typedoc()
		<< title << " " << author
		<< (Rentable()? "Rent " : "notRent ")
		<< "Cost " << Price();
}

void Video::OutStream(std::ostream & os) {
	Document::OutStream(os);
	os 	<< mediaType;
}

void WrittenDocument::OutStream(std::ostream & os) {
	Document::OutStream(os);
	os 	<< pages;
}

void Periodical::OutStream(std::ostream & os) {
	WrittenDocument::OutStream(os);
	os 	<< Pages();
}

Document::Document(std::string t, std::string a) :
	title(t), author(a) {}

WrittenDocument::WrittenDocument(std::string t, std::string a, int p) :
	Document(t,a), pages(p) {}

Video::Video(std::string t, std::string a, std::string m) :
	Document(t,a), mediaType(m) {}

Periodical::Periodical(std::string t, std::string a, int p, int n) :
	WrittenDocument(t,a,p), num(n) {}

Book::Book(std::string t, std::string a, int p, bool r) :
	WrittenDocument(t,a,p), rentable(r) {}


bool Video::Rentable () const {return true;}
bool Periodical::Rentable () const {return false;}
bool Book::Rentable () const {return rentable;}

std::string Video::typedoc () const {return "video";}
std::string Periodical::typedoc () const {return "periodical";}
std::string Book::typedoc () const {return "book";}

int Video::Price() const {return 7000;}
int WrittenDocument::Price() const {return pages*50;}


/*Library::~Library() {
	for(auto i : documents)
		delete i;
}*/


Document * Video::clone() const {return new Video(*this);}
Document * Book::clone() const {return new Book(*this);}
Document * Periodical::clone() const {return new Periodical(*this);}

void Library::Add(Document const & d){
	documents.push_back(d.clone());
}

int main(){
	Periodical p("bob","bobby",100,1);
	return 0;
}