// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: Baconian Cipher.cpp
// Program Description: ………
// Last Modification Date: 22/03/2022
// Author1 and ID and Group: Abdelrahman Nasr Aqll 20210122
// Teaching Assistant: Dr.mohammad elramly
// Purpose:To Cipher and Discipher the massedges
#include <iostream>
#include <algorithm>
#include<string>
#include<cmath>
using namespace std;
void baconian_cipher();
void baconian_discipher();

int main()
{
	int userChoice;
	bool isEndprogram = true;
	//program loop that take the user choice
	while (isEndprogram)
	{
		cout << "enter 1 if you want to cipher\n" << "enter 2 if you want to discipher\n" << "enter 0 if you want to exit\n";
		cin >> userChoice;
		if (userChoice == 1)
		{
			baconian_cipher();
		}
		else if (userChoice == 2)
		{
			baconian_discipher();
		}
		else if (userChoice == 0)
		{
			isEndprogram = false;
		}
		else
		{
			cout << "NOT EXSIST INPUT PLEASE TRY AGAIN...";
		}
	}
}

void baconian_cipher()
{
	string plainText , temper="";
	cout << "Enter the plain text you want to cipher: \n";
	cin >> plainText;
	//reversing the text 
	reverse(plainText.begin(), plainText.end());
	for (int i = 0; i < plainText.length(); i++)
	{
		//numbering alpha from zero to 25
	    plainText[i] -= 65;
		for (int j = 0; j < 5; j++)
		{
			//convert alpha digit to binary
			if (plainText[i] & 1 == 1)
			{
				// b = 1
				temper += "b";
			}
			else
			{ 
				// a = 0
				temper += "a";
			}
			//shifting the text to do the anding
			plainText[i] = plainText[i] >> 1;
		}
	}
	reverse(temper.begin(), temper.end());
	cout << temper << endl;
}

void baconian_discipher()
{
	string encripted , converted="";
	char disciphered;
	int converter = 0;
	cout << "Enter the word you want to discipher: \n";
	cin >> encripted;
	//reversing the text
	reverse(encripted.begin(), encripted.end());
	for (int i = 0; i < encripted.length(); i+=5)
	{
		for (int j = 0; j < 5; j++)
		{
			//moving by five because the string digit take five binart digits
			if (encripted[i+j] == 'a')
			{
				converter += 0 * (pow(2, j));
			}
			else if (encripted[i+j] == 'b')
			{
				converter += pow(2, j);
			}
		}
		//adding 65 to return to axact ascii value
		disciphered = converter + 65;
		converted.push_back(disciphered);
		converter = 0;
	}
	reverse(converted.begin(), converted.end());
	cout << converted << "\n";
}


