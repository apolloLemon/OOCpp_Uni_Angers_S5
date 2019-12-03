#include <string>
#include <memory>
#include <vector>

std::ostream & operator<<(std::ostream & os, Owner const & o);

class Owner {
//Couple removed the factorisation of Address and Name

public:
	enum class ownertype {
		person, couple, firm
	};
	Owner()=default;
	//here we want to ban copies of Owners
	Owner(Owner const & o)=delete; //since copy constructors of subclasses call the superclass, this blocks
	Onwe & operator=(Owner const & o)=delete; //same

	virtual ~Owner()=default;

//don't return ref on local method vars //quicktips
	virtual std::string Name() const =0;
	virtual ownertype OwnerType() const =0;
//but we can return a reference to address
	virtual const & std::string Address() const =0;

	virtual void OutSteam(std::ostream & os) const;
//since this uses previously definied virtual methods,
//we can code it here
	std::string MaillingSticker() const;


};

class Person : public Owner {
private:
	std::string name;
	std::string birthDate;
	std::string address;

public:
	std::string Name() const override;
	ownertype OwnerType() const override;
	std::string const & Address() const override;
	void OutSteam(std::ostream & os) const override;
};

class Firm : public Owner {
private:
	std::string name;
	std::string address;
	std::shared_ptr<Person> manager;
public:
	std::string Name() const override;
	ownertype OwnerType() const override;
	std::string const & Address() const override;
	void OutSteam(std::ostream & os) const override;
};

class Couple : public Owner {
private:
	std::shared_ptr<Person> p1;
	std::shared_ptr<Person> p2;
	
	//This Constructor is private so that you have to use a Factory
	Couple(std::shared_ptr<Person> _p1,std::shared_ptr<Person> _p2)
	:Owner(), p1(_p1), p2(_p2) {}
public:
	std::string Name() const override;
	ownertype OwnerType() const override;
	std::string const & Address() const override;
	void OutSteam(std::ostream & os) const override;

//Factorize in Owner?	
	static std::shared_ptr<Couple> Factory(std::shared_ptr<Person> _p1, std::shared_ptr<Person> _p2) {
		if(p1->Address()==p2->Address())
			//return std::make_shared<Couple>(_p1,_p2);
			//because Couple's constructor is private
			//we can't use make_shared on the Constructor
			return std::shared_ptr<Couple>(new Couple(_p1,_p2));
		else
			return nullptr;
	}
};


class Account {
	std::shared_ptr<Owner> owner;

};