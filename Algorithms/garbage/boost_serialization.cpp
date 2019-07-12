// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
/*
	GLOBAL INCLUDES
*/
#include <string>
#include <iostream>
#include <fstream>
//	TEXT/BIN FORM FLAG
//  comment next line to set the text mode 
	#define BOOST_LIB_SER_MODE
/*
	& BOOST_LIB INCLUDE
*/

#include <boost/serialization/vector.hpp>
#ifndef BOOST_LIB_SER_MODE
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#else
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#endif

class A
{
private:
	std::string _std_string;
	//serialization block
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, unsigned const ver)
	{
		ar& this->_std_string;
		std::cout << "\n\tserizalzation Class A done...";
	}
public:
	A() {};
	~A() {};
	std::string getString()
	{
		return this->_std_string;
	}
	void setString()
	{
		std::getline(std::cin, this->_std_string);
	}
};
class B
{
private:
	std::vector<A> _vector_A;
	//serialization block
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& this->_vector_A;
		std::cout << "\n\tserizalzation Class B done...";
	}
public:
	B() {};
	~B() {};

	std::vector<A> getA()
	{
		return this->_vector_A;
	}
	void setA()
	{
		A _A;
		_A.setString();
		_vector_A.push_back(_A);
	}
};

int main()
{
	//pre_info
	#ifndef BOOST_LIB_SER_MODE
		std::cout << "Current serialization mode: text\n";
	#else
		std::cout << "Current serialization mode: binary\n";
	#endif
	B _B, _Deser;
	std::string path = "Serialized.dat";
	std::cout << "Current filename: " << path;
	std::cout << "\nINIT DATA: ";
	_B.setA();
	std::cout << "\nFirst stage...";
	{	
		std::ofstream ofs(path);
		#ifndef BOOST_LIB_SER_MODE
				boost::archive::text_oarchive oa(ofs);
		#else
				boost::archive::binary_oarchive oa(ofs);
		#endif
		oa << _B;
	}
	std::cout << "\nFirst stage done...";
	std::cout << "\nSecond stage...";
	{
		std::ifstream ifs(path);
		#ifndef BOOST_LIB_SER_MODE
				boost::archive::text_iarchive ia(ifs);
		#else
				boost::archive::binary_iarchive ia(ifs);
		#endif
		ia >> _Deser;
	}
	std::cout << "\nSecond stage done...";
	std::cout << "\nPress any key to continue: ";
	std::cin.get();
	std::cout << "\n\tVerification stage...";
	std::cout << "\n\tInit data string: " << _B.getA().at(0).getString();
	std::cout << "\n\tDeSerialize data string: " << _Deser.getA().at(0).getString();
	std::cout << "\n\tResult: " << std::boolalpha << (_B.getA().at(0).getString() == _Deser.getA().at(0).getString()) ? true : false;
	std::cout << "\n\tVerification stage done...\n";
	std::cout << "\nPress any key to exit: ";
	std::cin.get();
	return 0;
}