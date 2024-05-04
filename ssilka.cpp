#include <iostream>
#include <string>

using namespace std;


class MyString {
private:
	char* str;

public:
	MyString() {
		this->str = new char[] {"\0"};
	}
	MyString(const char* str) {
		this->str = strCopy(str);
	}

	MyString(const MyString& other) {
		this->str = strCopy(other.str);
	}


	MyString& operator =(const MyString& other) {
		if (this == &other) return *this;
		if (this->str != nullptr) {
			delete[] this->str;
		}
		this->str = strCopy(other.str);
		return *this;

	}
	void operator +=(const MyString& other) {
		int length1 = strlen(this->str);
		int length2 = strlen(other.str);

		char* newStr = new char[length1 + length2 + 1];
		for (int i = 0; i < length1; i++)
		{
			newStr[i] = this->str[i];
		}
		for (int i = 0; i < length2; i++)
		{
			newStr[length1 + i] = other.str[i];
		}
		newStr[length1 + length2] = '\0';
		delete[] this->str;
		this->str = newStr;
	}

	MyString operator +(const MyString& other) {
		MyString newStr;
		newStr += *this;
		newStr += other;
		return newStr;
	}



	void print() {
		cout << this->str << endl;
	}
	~MyString() {
		delete[] this->str;
	}
	int length() {
		return strlen(this->str);
	}
	friend ostream& operator << (ostream& out, MyString& myStr) {
		out << myStr.str;
		return out;
	}

	char& operator [](int index) {
		if (index >= this->length()|| index<0) throw;
		return this->str[index];
	}
	bool operator ==(MyString& myStr) {
		if (this->length() != myStr.length()) {
			return false;
		}
		for (int i = 0; i < myStr.length(); i++)
		{
			if (this->str[i] != myStr.str[i])return false;
		}
		return true;
	}
	bool operator !=(MyString& myStr) {
		if (this->length() != myStr.length()) {
			return true;
		}
		for (int i = 0; i < myStr.length(); i++)
		{
			if (this->str[i] != myStr.str[i])return true;
		}
		return false;
	}
	bool operator >(MyString& myStr) {
		char str12 = NULL;
		char str22 = NULL;
		for (int i = 0; i < this->length(); i++)
		{

		}
	}
	bool operator <(MyString& myStr) {

	}
	bool operator <=(MyString& myStr) {

	}
	bool operator >=(MyString& myStr) {

	}
private:
	char* strCopy(const char* str) {
		char* newStr;
		int length = strlen(str);
		newStr = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			newStr[i] = str[i];
		}
		newStr[length] = '\0';
		return newStr;
	}



};

int main()
{
	MyString str1 = "Test";
	MyString str2 = "Test2";

	cout << str1[0];

	MyString str3 = str1;
	MyString str4 = "ghsdfhgsd";

}