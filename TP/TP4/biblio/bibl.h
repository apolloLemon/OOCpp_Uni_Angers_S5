#pragma once
#include <string>
#include <ostream>
#include <vector>

class Document {
	std::string title;
	std::string author;

public:
	Document(std::string, std::string);
	virtual ~Document()=default;

	virtual int Price() const=0;
	virtual bool Rentable() const=0;
	virtual void OutStream(std::ostream &) const;

	virtual std::string typedoc() const=0;
	virtual void OutStream(std::ostream &);

	virtual Document * clone() const =0;
};

class WrittenDocument : public Document{
	int pages;

public:
	WrittenDocument(std::string, std::string, int);
	int Price() const override final;
	void OutStream(std::ostream &) override;

	int Pages() const {return pages;}
};

class Video : public Document {
	std::string mediaType; //replace with ENUM
public:
	Video(std::string, std::string, std::string);
	int Price() const override;
	bool Rentable() const override;

	void OutStream(std::ostream &) override;
	std::string typedoc () const;
	Document * clone() const override;
};

class Periodical : public WrittenDocument {
	int num;
public:
	Periodical(std::string, std::string, int, int);
	bool Rentable() const override;
	void OutStream(std::ostream &) override;
	std::string typedoc () const;
	Document * clone() const override;
};

class Book : public WrittenDocument {
	bool rentable;
public:
	Book(std::string, std::string, int, bool);
	bool Rentable() const override;
	std::string typedoc () const;
	Document * clone() const override;
};


class Library {
	std::vector<Document *> documents;
public:
	Library()=default;
	//Library(Library const &);
	//operateur=(Library const &);
	~Library();

	/*
	Because we're adding to a list of pointers
	we can't risk using the Doc passed as arg
	It could be deleted elsewhere, so let's copy
	cf. clone()
	*/
	void Add(Document const &);

	//DONT show pointers outside
	//std::vector<Document *> const & Documents() {return Documents;}
	std::size_t mysize() const {return documents.size();}
	Document const & access(std::size_t i) const {return *(documents.at(i));}

};