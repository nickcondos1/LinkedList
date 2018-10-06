// Nick Condos
// Compiled with G++ and Visual Studios
// BigInteger class, for infinite precision values

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class BigInteger
{
	friend istream& operator >> (istream& in, BigInteger &bigI); // Input operator overload

	private:
		string number;
		bool sign; // (+ = true), (- = false);
		int digits; // Technically the size of vector
		vector<int> bigInt;

	public:
		BigInteger();
		BigInteger(string val);
		BigInteger(const BigInteger& original); // Copy Constructor

		string getNumber() const { return number; }
		string getNumber1() const;
		string getSign() const;
		bool getSign1() const { return sign; }
		int getDigits() const { return digits; }
		vector<int> getBigInt() const { return bigInt; }

		void setNumber(string n);
		void setSign(bool sign);
		void setDigits(int digits);
		void setBigInt(vector<int> bigInt);

		//Some member functions
		const BigInteger& operator = (const BigInteger& original);

		bool operator == (const BigInteger&);
		bool operator != (const BigInteger& rhs) { return !(*this == rhs); }
		bool operator > (const BigInteger&) const;
		bool operator < (const BigInteger&) const; 
		bool operator <= (const BigInteger&) const;
		bool operator >= (const BigInteger&) const;

		BigInteger operator+(const BigInteger&) const;
		BigInteger operator-(const BigInteger&) const;
		BigInteger operator*(const BigInteger&) const;

		string deleteZero(const string& bigString);
		vector<int> addZero(vector<int> one, vector<int> two) const;




};

ostream& operator << (ostream& out, const BigInteger &bigI);


#endif /* BIGINTEGER_H_ */
