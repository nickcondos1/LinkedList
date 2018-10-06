// Nick Condos
// Compiles with both g++ version 6.3.0 and visual studios/microsoft compiler 19.13.26129

#include "LinkedList.h"
#include "biginteger.h"

using namespace std;

int main()
{
	LinkedList<int> one;
	one.addFirst(1);
	one.addFirst(3);
	one.addFirst(9);
	one.addFirst(6);
	one.addFirst(4);

	LinkedList<BigInteger> bigI;
	BigInteger first("125130957135897135");
	BigInteger second("913745189034");
	BigInteger third("27598124751351");
	bigI.addFirst(first);
	bigI.addFirst(second);
	bigI.addFirst(third);

	int choice = 0;

	while (choice != 23)
	{
		cout << "\n\nCurrent list contains: \n" << one << endl;

		cout << "1) Test the copy constructor" << endl;
		cout << "2) Test the move constructor" << endl;
		cout << "3) Test the '=' operator overload" << endl;
		cout << "4) Test the move '=' operator overload" << endl;
		cout << "5) Test the '==' operator overload" << endl;
		cout << "6) Test the '[]' overload for GETTING a value from list " << endl;
		cout << "7) Test the '[]' overload for SETTING a value in list " << endl;
		cout << "8) Test the '+' concatenating two lists" << endl;
		cout << "9) Test the '<<' operator overload" << endl;
		cout << "10) Add an item to end of list " << endl;
		cout << "11) Add an item to specified index " << endl;
		cout << "12) Add an item to beginning of list" << endl;
		cout << "13) Remove first instance of specified data " << endl;
		cout << "14) Remove an item based on index specified " << endl;
		cout << "15) Remove ALL occurrences of a specified item " << endl;
		cout << "16) Sort a list " << endl;
		cout << "17) Test iterator " << endl;
		cout << "18) Print out BIGINTEGER linkedlist" << endl;
		cout << "19) AddLast for BIGINTEGER linkedlist" << endl;
		cout << "20) AddIndex for BIGINTEGER linkedlist" << endl;
		cout << "21) Remove at index of BIGINTEGER linkedlist" << endl;
		cout << "22) Sort BIGINTEGER linkedlist" << endl;
		cout << "23) Quit the program" << endl;

		cout << "Please enter a menu option: " << endl;
		cin >> choice;
		cout << endl;

		if (choice < 1 || choice > 23)
			cout << "Invalid menu option, try again" << endl;

		switch(choice)
		{
			case 1:
			{
				LinkedList<int> three = one; //Calls copy constructor
				three.print(cout);
				cout << endl;
			}
				break;

			case 2:
			{
				LinkedList<int> temp;
				temp = one;
				cout << "List one contains: " << temp << endl;
				LinkedList<int> four(move(temp)); //Calls move constructor
				cout << "After calling move constructor, list one now contains: \n" << temp << endl;
				cout << "And list two now contains: " << endl;
				four.print(cout);
				cout << endl;
			}
				break;

			case 3:
			{
				LinkedList<int> two;
				cout << "List one contains: \n" << one;
				cout << "List two contains: \n" << two;
				two = one; // Assignment operator overload
				cout << "After assignment, list two now contains: " << endl;
				cout << two << endl; //Output operator overload
			}
				break;

			case 4:
			{
				LinkedList<int> temp;
				LinkedList<int> five;
				temp = one;
				cout << "List one contains: " << temp << endl;
				five = move(temp); //Calls move assignment operator
				cout << "After calling move assignment operator, list one now contains: \n" << temp << endl;
				cout << "And list two now contains: " << endl;
				five.print(cout);
				cout << endl;
			}
				break;

			case 5:
			{
				LinkedList<int> temp;
				temp = one;
				cout << "List one contains: \n" << one;
				cout << "List two contains: \n" << temp;
				cout << "Are they equal? \n" << (temp == one) << endl;
				temp.addFirst(234);
				cout << "List one contains: \n" << one;
				cout << "List two contains: \n" << temp;
				cout << "Are they equal? \n" << (temp == one) << endl;

			}
				break;

			case 6:
			{
				cout << "List contains: " << one << endl;
				cout << "Get item at index 2" << endl;
				cout << "Item is: " << one[2] << endl;
			}
				break;

			case 7:
			{
				int num;
				cout << "List contains: " << one << endl;
				cout << "Enter an item to be set at index 3: " << endl;
				cin >> num;
				one[3] = num;
				cout << "List now contains: " << one << endl;
			}
				break;

			case 8:
			{
				LinkedList<int> six;
				LinkedList<int> two;
				two = one;
				two.addFirst(100);
				cout << "List one contains: " << one << endl;
				cout << "List two contains: " << two << endl;
				cout << "Combined lists create: ";
				six = one + two;
				cout << six << endl;
				cout << "Adding completed" << endl;
			}
				break;

			case 9:
			{
				cout << one << endl;
			}
				break;

			case 10:
			{
				int num;
				cout << "List one contains: " << one << endl;
				cout << "Please enter a number to be added to end of list: " << endl;
				cin >> num;
				one.addLast(num);
				cout << "List one now contains: " << one << endl;
			}
				break;

			case 11:
			{
				try {
					int index;
					int num;
					cout << "List one contains: " << one << endl;
					cout << "Please enter a valid index to add new data at: " << endl;
					cin >> index;
					cout << "Please enter a number to be added at that index: " << endl;
					cin >> num;
					one.add(index, num);
					cout << "List one now contains: " << one << endl;
				}
				catch (const out_of_range& e)
				{
					cout << "Index out of range" << endl;
				}
			}
				break;

			case 12:
			{
				int num;
				cout << "Enter an item to be added to beginning of list: " << endl;
				cin >> num;
				one.addFirst(num);
			}
				break;

			case 13:
			{
				int num;
				cout << "List one contains: " << one << endl;
				cout << "Please enter an item to be removed from list: " << endl;
				cin >> num;
				bool yesNo = one.remove(num);
				cout << "Was the item removed? " << endl;
				if (yesNo == true)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
				break;

			case 14:
			{
				try {
					int index;
					cout << "List one contains: " << one << endl;
					cout << "Please enter an index to remove item: " << endl;
					cin >> index;
					int item = one.removeIndex(index);
					cout << "Item removed was: " << item << endl;
				}
				catch (const out_of_range& e)
				{
					cout << "Index out of range" << endl;
				}
			}
				break;

			case 15:
			{
				int num;
				cout << "List one contains: " << one << endl;
				cout << "Please enter an item to remove all occurrences of it: " << endl;
				cin >> num;
				bool yesNo = one.removeAll(num);
				cout << "Were the items removed? " << endl;
					if (yesNo == true)
						cout << "Yes" << endl;
					else
						cout << "No" << endl;
			}
				break;

			case 16:
			{
				cout << "List before sorting is: " << one << endl;
				one.sort();
				cout << "List after sorting is: " << one << endl;
			}
				break;

			case 17:
			{
				one.itTesting(one);
			}
				break;

			case 18:
			{
				cout << bigI << endl;
			}
				break;

			case 19:
			{
				cout << "Value to be added is: '1241930549135'" << endl;
				cout << "BigInt list before adding to end: \n" << endl;
				cout << bigI << endl;
				bigI.addLast((BigInteger)("1241930549135"));
				cout << "BigInt list after adding to end: \n" << endl;
				cout << bigI << endl;
			}
				break;

			case 20:
			{
				try {
					int index;
					string num;
					cout << "List contains: \n" << bigI << endl;
					cout << "Please enter a valid index to add new data at: " << endl;
					cin >> index;
					cout << "Please enter a new Big Integer to be added: " << endl;
					cin >> num;
					BigInteger val(num);
					bigI.add(index, val);
					cout << "List now contains: \n" << bigI << endl;
				}
				catch (const out_of_range& e)
				{
					cout << "Index out of range" << endl;
				}
			}
				break;

			case 21:
			{
				try {
					int index;
					cout << "List contains: \n" << bigI << endl;
					cout << "Please enter an index to remove item: " << endl;
					cin >> index;
					BigInteger item = bigI.removeIndex(index);
					cout << "Item removed was: " << item << endl;
					cout << "List now contains: \n" << endl;
					cout << bigI << endl;
				}
				catch (const out_of_range& e)
				{
					cout << "Index out of range" << endl;
				}
			}
				break;

			case 22:
			{
				cout << "Before sorting, list is: \n" << bigI << endl;
				bigI.sort();
				cout << "After sorting, list is: \n" << bigI << endl;
			}
				break;

			case 23:
				cout << "You've chosen to quit the program" << endl;
				break;


		}


	}

	return 0;
}




