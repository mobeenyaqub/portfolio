#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//Creating a structure and declaring variables
struct record {
	int bookID{};
	double price{};
	string bookTitle{};
	string bookAuthor{};
};


int main()
{
	record students[5]{};
	string holder{};

	//Looping over to get data from the user 5 times
	for (int i = 0; i < 5; i++) {

		cout << "Enter the book ID : ";
		cin >> students[i].bookID;

		cout << "\nEnter the name of books author : ";
		cin.ignore();
		getline(cin, students[i].bookAuthor);

		cout << "\nEnter book title : ";
		getline(cin, students[i].bookTitle);

		cout << "\nEnter price of the book : ";
		cin >> students[i].price;

		cout << "\n------------------------------\n\n";
	}

	cout << "Books with same authors are : \n";

	//Looping over to find the books with same authors and displaying the titles of those books, with same authors
	for (int i = 0; i < 5; i++) {

		string str1, str2;
		int comma_count = 0;

		str1 = students[i].bookAuthor;

		for (int j = 0; j < 5; j++) {
			str2 = students[j].bookAuthor;

			//Comparing authors throughout the array
			if (str1 == str2) {
				holder += students[j].bookTitle + ",";
				students[j].bookTitle.clear();
				comma_count++;
			}

		}

		//Comma count is being compared 
		if (holder.length() > comma_count && comma_count > 1) {
			int a = holder.length() - 1;
			holder[a] = ' ';
			cout << "\nAuthor : " << str1 << "\tTitle : " << holder << "\b" << endl;
		}

		holder.clear();

		comma_count = 0;
	}

	return 0;
}
