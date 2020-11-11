#include <string>
#include <iostream>
using namespace std;

//Function to convert Roman numerals to decimal numbers
int RomanDecimalValue(char c)
{
	if (c == 'I') { return 1; }
	if (c == 'V') { return 5; }
	if (c == 'X') { return 10; }
	if (c == 'L') { return 50; }
	if (c == 'C') { return 100; }
	if (c == 'D') { return 500; }
	if (c == 'M') { return 1000; }
	return -1;
}
//function to check if the rules are borken
bool checkForRomanNumeralValidity(string romanNumber){
	bool bBusy = true;
	for (int i = 0; i < romanNumber.length(); i++) {
		int ConvertedRoman1 = RomanDecimalValue(romanNumber[i]); // find the first roman numerals converted value

		if (i + 1 < romanNumber.length()) {
			int ConvertedRoman2 = RomanDecimalValue(romanNumber[i + 1]); // find the second roman numerals converted value

			//check for rule 6
			if (i + 3 < romanNumber.length()) { // make sure there arent four identical Roman numerals in a row
				if ((RomanDecimalValue(romanNumber[i]) == RomanDecimalValue(romanNumber[i + 1])) && (RomanDecimalValue(romanNumber[i]) == RomanDecimalValue(romanNumber[i + 2]))
					&& (RomanDecimalValue(romanNumber[i]) == RomanDecimalValue(romanNumber[i + 3]))) {
					bBusy = false;
					return bBusy;
				}
			}

			//check for rule 5
			if ((ConvertedRoman1 == 1 && ConvertedRoman2 != 5) && (ConvertedRoman1 == 1 && ConvertedRoman2 != 10)) {
				if (ConvertedRoman1 == ConvertedRoman2) {
					bBusy = true;
				}
				else {
					bBusy = false;
				}
			}
			if ((ConvertedRoman1 == 10 && ConvertedRoman2 != 50) && (ConvertedRoman1 == 10 && ConvertedRoman2 != 100)) {
				if (ConvertedRoman1 == ConvertedRoman2) {
					bBusy = true;
				}
				else {
					bBusy = false;
				}
			}
			if ((ConvertedRoman1 == 100 && ConvertedRoman2 != 500) && (ConvertedRoman1 == 1 && ConvertedRoman2 != 1000)) {
				if (ConvertedRoman1 == ConvertedRoman2) {
					bBusy = true;
				}
				else {
					bBusy = false;
				}
			}

			//check for rule 7
			if ((RomanDecimalValue(romanNumber[i]) == 5) || (RomanDecimalValue(romanNumber[i]) == 50) || (RomanDecimalValue(romanNumber[i]) == 500)) {
				if (RomanDecimalValue(romanNumber[i]) == RomanDecimalValue(romanNumber[i + 1])){
						bBusy = false;
				}
			}
		}
	}
	return bBusy;
}

int covertedvalue(string romanNumber) {
	int result = 0;

	//check if the Roman numeral rules are broken
	if (!checkForRomanNumeralValidity(romanNumber)) {
		return -1;
	}

	for (int i = 0; i < romanNumber.length(); i++) {
		int ConvertedRoman1 = RomanDecimalValue(romanNumber[i]); // find the first roman numerals converted value

		if (i + 1 < romanNumber.length()) {
			int ConvertedRoman2 = RomanDecimalValue(romanNumber[i + 1]); // find the second roman numerals converted value

			//compare values and chech for greater than or equal
			if (ConvertedRoman1 >= ConvertedRoman2) {
				result += ConvertedRoman1;
			}
			//if values are less than
			else {
				result += ConvertedRoman2 - ConvertedRoman1;
				i++;
			}
		}
		else {
			result += ConvertedRoman1;
		}	
	}
	return result;
}

int main() {
	//string x = "IX";
	string stringArray[9]{ "I", "II", "XL", "LL", "IV", "MMM", "CCCC" ,"MCX" ,"XM" };

	for (auto i : stringArray) {
		cout << covertedvalue(i) << endl;
	}

}