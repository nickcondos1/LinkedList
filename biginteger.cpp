// Nick Condos


#include "biginteger.h"

using namespace std;

BigInteger::BigInteger()
{
	sign = true;
	digits = 0;
	number = "";
	bigInt = {};
}
//=======================================================================================================================
BigInteger::BigInteger(string value)
{
	number = value;
	string val = deleteZero(value);

	if (val[0] == '-')
	{
		sign = false;
		val.erase(0,1); //Will add the sign back in output
		setNumber(val);
		digits = val.size();

		for (int i = 0; i < val.size(); i++) { //Convert string to int's and puts them in vector
			bigInt.push_back(val[i] - '0');
		}

	}

	else if (val[0] == '+')
	{
		sign = true;
		val.erase(0,1);
		setNumber(val);
		digits = val.size();

		for (int i = 0; i < val.size(); i++) {
			bigInt.push_back(val[i] - '0');
		}

	}

	else
	{
		sign = true;
		setNumber(val);
		digits = val.size();

		for (int i = 0; i < val.size(); i++) {
			bigInt.push_back(val[i] - '0');
		}

	}

}
//=======================================================================================================================
BigInteger::BigInteger(const BigInteger& original) //Copy Constructor
{
	setSign(original.getSign1());
	setDigits(original.getDigits());
	setBigInt(original.getBigInt());
}
//=======================================================================================================================
string BigInteger::getSign() const
{
	if (sign == true)
		return "+";
	else
		return "-";
}
//=======================================================================================================================
string BigInteger::getNumber1() const
{
	string temp = number;
	for (int i = 0; i < temp.size(); i++)
		{
			if (temp[0] == '0' || temp[0] == '+' || temp[0] == '-') {
				temp.erase(0,1);
			}
			else {
				return temp;
			}
		}
		return temp;
}
//=======================================================================================================================
void BigInteger::setSign(bool s)
{
	sign = s;
}
//=======================================================================================================================
void BigInteger::setDigits(int d)
{
	digits = d;
}
//=======================================================================================================================
void BigInteger::setBigInt(vector<int> bigI)
{
	bigInt = bigI;
}
//=======================================================================================================================
void BigInteger::setNumber(string n)
{
	number = n;
}
//=======================================================================================================================
const BigInteger& BigInteger::operator = (const BigInteger& original)
{
	if (this != &original)
	{
		sign = original.sign;
		digits = original.digits;
		bigInt = original.bigInt;
	}
	return *this;
}
//=======================================================================================================================
istream& operator >> (istream& in, BigInteger &bigI)
{
	in >> bigI.number;

		string val = bigI.number;

		for (int i = 0; i < val.size(); i++)
			{
				if (val[0] == '0') {
					val.erase(0,1);
				}
			}

		if (val[0] == '-')
		{
			bigI.sign = false;
			val.erase(0,1); //Will add the sign back in output
			bigI.setNumber(val);
			bigI.digits = val.size();

			for (int i = 0; i < val.size(); i++) { //Convert string to int's and puts them in vector
				bigI.bigInt.push_back(val[i] - '0');
			}

		}

		else if (val[0] == '+')
		{
			bigI.sign = true;
			val.erase(0,1);
			bigI.setNumber(val);
			bigI.digits = val.size();

			for (int i = 0; i < val.size(); i++) {
				bigI.bigInt.push_back(val[i] - '0');
			}

		}

		else
		{
			bigI.sign = true;
			bigI.setNumber(val);
			bigI.digits = val.size();

			for (int i = 0; i < val.size(); i++) {
				bigI.bigInt.push_back(val[i] - '0');
			}

		}

	return in;
}
//=======================================================================================================================
ostream& operator << (ostream& out, const BigInteger &bigI)
{
	out << bigI.getSign();

	for (int i: bigI.getBigInt()) {
		out << i;
	}
	out << endl;
	return out;
}
//=======================================================================================================================
bool BigInteger::operator == (const BigInteger& that)
{
	bool yesNoSign = sign == that.sign;
	bool yesNoDigit = digits == that.digits;
	if (yesNoSign == false) {
		return false;
	}
	else if (yesNoDigit == false) {
		return false;
	}
	else {
		for (int i = 0; i < bigInt.size(); i++)
		{
			if (bigInt[i] != that.bigInt[i])
				return false;
		}
		return true;
	}
	return false;
}
//=======================================================================================================================
bool BigInteger::operator > (const BigInteger& that) const
{
	if (this == &that)
		return false;
	else if (sign == true && that.sign == false)
		return true;
	else if (sign == false && that.sign == true)
		return false;
	else if (digits > that.digits)
		return true;
	else if (digits < that.digits)
		return false;
	else {
		for (int i = 0; i < digits; i++) {
			if (bigInt[i] > that.bigInt[i])
				return true;
			else if (bigInt[i] < that.bigInt[i])
				return false;
		}
	}
	return false;
}
//=======================================================================================================================
bool BigInteger::operator < (const BigInteger& that) const //Was getting errors when i negated the > operator
{														   //So i just rewrote it
	if (this == &that)
			return false;
		else if (sign == true && that.sign == false)
			return false;
		else if (sign == false && that.sign == true)
			return true;
		else if (digits < that.digits)
			return true;
		else if (digits > that.digits)
			return false;
		else {
			for (int i = 0; i < digits; i++) {
				if (bigInt[i] < that.bigInt[i])
					return true;
				else if (bigInt[i] > that.bigInt[i])
					return false;
			}
		}
		return false;

}
//=======================================================================================================================
bool BigInteger::operator <= (const BigInteger& that) const
{
	return !(*this > that);
}
//=======================================================================================================================
bool BigInteger::operator >= (const BigInteger& that) const
{
	if (this == &that)
		return true;
	else if (sign == true && that.sign == false)
		return true;
	else if (sign == false && that.sign == true)
		return false;
	else if (digits > that.digits)
		return true;
	else if (digits < that.digits)
		return false;
	else {
		for (int i = 0; i < digits; i++) {
			if (bigInt[i] > that.bigInt[i])
				return true;
			else if (bigInt[i] < that.bigInt[i])
				return false;
		}
	}
	return true;
}
//=======================================================================================================================
BigInteger BigInteger::operator + (const BigInteger& that) const //ADDITION
{
	vector<int> one = bigInt;
	vector<int> two = that.bigInt;
	vector<int> sum(one.size());

//=======================================================
//Playing around with the signs for correct output     //
	if (sign == false && that.sign == true)
	{												   //
		BigInteger temp;
		BigInteger big = *this;						   //
		big.setSign(true);
													   //
		if (big > that) {
			temp = big - that;						   //
			temp.setSign(false);
			return temp;							   //
		}
		else {										   //
			temp = big - that;
			temp.setSign(true);						   //
			return temp;
		}											   //

	}												   //

	if (sign == true && that.sign == false)			   //
	{
		BigInteger big = that;						   //
		big.setSign(true);
		BigInteger temp = *this - big;				   //
		return temp;
	}												   //
//=======================================================

	if (one.size() > two.size())
			swap(one, two);

	int carry = 0;

	reverse(one.begin(), one.end()); //Reverse so we don't have to add
	reverse(two.begin(), two.end()); //right to left

	for (int i = 0; i < one.size(); i++) // Takes care of result up to the shortest digit length
	{
		int add = ((one[i]) + (two[i])) + carry;
		int toBeAdded = add % 10; //the remainder
		carry = add / 10; // Either 0 or 1 for carry

		sum.push_back(toBeAdded);

	}

	//If BigIntegers are equal in length this doesn't apply
	for (int i = one.size(); i < two.size(); i++) // Adds the rest of the digits from larger string
	{
		int add = (two[i]) + carry;
		int toBeAdded = add % 10;
		carry = add / 10;

		sum.push_back(toBeAdded);

	}

	if (carry > 0) {
		sum.push_back(carry);
	}

	string str;
	for (int i = 0; i < sum.size(); i++)
		{
				str = str.append(to_string(sum[i]));
		}

	reverse(str.begin(), str.end()); //Result would be backwards because we reversed its components
	for (int i = 0; i < digits; i++)
	{
		str.pop_back();
	}

	BigInteger three = BigInteger(str);

	if (sign == false && that.sign == false) //If both bigInts were negative, add the negative sign back
		three.setSign(false);

	return three;

}
//=======================================================================================================================
BigInteger BigInteger::operator - (const BigInteger& that) const //SUBTRACTION
{
	vector<int> one;
	vector<int> fixed;

//================================================================
//A Bunch of ugly code to produce the correct sign and results  //
	if (sign == false && that.sign == true)						//
	{
		BigInteger temp;										//
		BigInteger big = *this;
		big.setSign(true);										//
		if (big > that)
		{														//
			temp = big + that;
			temp.setSign(false);								//
			return temp;
		}														//
		else {
			temp = big + that;									//
			temp.setSign(false);
			return temp;										//
		}
	}															//

	if (sign == true && that.sign == false)						//
	{
			BigInteger big = that;								//
			big.setSign(true);
			BigInteger temp = *this + big;						//
			return temp;
	}															//

	if (*this > that) {											//
		one = bigInt;
		fixed = addZero(that.getBigInt(), one);					//
	}
	else if (*this < that) {									//
		 one = that.bigInt;
		 fixed = addZero(getBigInt(), one);						//
	}
	else {														//
		string s = "00";
		BigInteger zero(s);										//
		zero.setSign(true);
		return zero;											//
	}															//
//================================================================
	vector<int> difference (one.size()); //Where i will store the results

	int s1 = one.size();
	int s2 = fixed.size();

	for (int i = s1 - 1; i >= 0; i--) //Computing the results, just like you would on paper
	{
		int diff;
		if ((one[i] - fixed[i]) > 0) {
			diff = one[i] - fixed[i];
		}
		else if (one[i] == fixed[i]) {
			diff = 0;
		}

		else {
			one[i-1] = one[i-1] - 1;
			one[i] = one[i] + 10;
			diff = one[i] - fixed[i];
		}
		difference[i] = diff;
	}

	string str;
	for (int i = 0; i < difference.size(); i++) //Convert vector to string
	{
			str = str.append(to_string(difference[i]));
	}

	BigInteger subtracted(str);


//Some more fun sign changing
	if (*this > that) {
		subtracted.sign = true;

		if (sign == false && that.sign == false)
				subtracted.sign = false;
	}
	else {
		subtracted.sign = false;

		if (sign == false && that.sign == false)
				subtracted.sign = true;
	}

	return subtracted;
}
//=======================================================================================================================
BigInteger BigInteger::operator * (const BigInteger& that) const //MULTIPLICATION
{
	//https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
	//for help with storing and shifting the results after adding, i.e. pos1, pos2
	//Grade accordingly i guess?

	vector<int> one = bigInt;
	vector<int> two = that.bigInt;
	vector<int> product(one.size() + two.size(), 0); //Load product with 0's with a large enough size

	if (digits < that.digits)
		swap(one, two); //Want the 'bigger' number on 'top'

	int carry = 0;
	int pos1 = 0;
	int pos2 = 0;

//    BiggerNumber
//  x SmallerNumber
//  ^^^^^^^^^^^^^^^^       <-- This is the format i'm going for, although it
//   ResultingNumber           really doesn't matter which is on 'top'

	for (int i = two.size() - 1; i >= 0; i--) //Bottom number
	{
		int num1 = two[i];

		pos2 = 0;

		for (int j = one.size() - 1; j >= 0; j--) //Top number
		{
			int num2 = one[j];
			int total = (num1 * num2) + product[pos1 + pos2] + carry; //Adds result to the current product in vector along with the carried over number

			carry = total / 10;
			product[pos1 + pos2] = total % 10;
			pos2++;
		}

		if (carry > 0)
			product[pos1 + pos2] = product[pos1 + pos2] + carry;

		pos1++;
	}

	string str;
	for (int i = 0; i < product.size(); i++) //Convert vector to string
	{
			str = str.append(to_string(product[i]));
	}


	reverse(str.begin(), str.end());
	BigInteger result = BigInteger(str);

	if (sign == true && that.sign == false) //Adding the correct sign based on input
		result.sign = false;
	else if (sign == false && that.sign == true)
		result.sign = false;
	else
		return result;

	return result;


}
//=======================================================================================================================
string BigInteger::deleteZero(const string& bigString) //Chops off zeros at the front of string
{
	string temp = bigString;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[0] == '0') {
			temp.erase(0,1);
		}
		else {
			return temp;
		}
	}
	return temp;
}
//=======================================================================================================================
vector<int> BigInteger::addZero(vector<int> one, vector<int> two) const //Adds zeros for easy subtraction
{

	for (int i = 0; one.size() != two.size(); i++)
	{
		one.insert(one.begin(), 0);
	}

	return one;
}
//=======================================================================================================================







