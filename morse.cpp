#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

/*****************************************/
void header(){

    //cout << "\033[1;" << 40 << "m" << "\033[1;" << 31 << "m";
    cout << "\033[1;" << 40 << "m" << "\033[1;" << 40 << "m";

cout << "                                                                                                           " << endl;
cout << "             ███╗   ███╗ ██████╗ ██████╗ ███████╗███████╗    ███╗   ██╗███████╗██████╗ ██████╗             " << endl;
cout << "             ████╗ ████║██╔═══██╗██╔══██╗██╔════╝██╔════╝    ████╗  ██║██╔════╝██╔══██╗██╔══██╗            " << endl;
cout << "             ██╔████╔██║██║   ██║██████╔╝███████╗█████╗      ██╔██╗ ██║█████╗  ██████╔╝██║  ██║            " << endl;
cout << "             ██║╚██╔╝██║██║   ██║██╔══██╗╚════██║██╔══╝      ██║╚██╗██║██╔══╝  ██╔══██╗██║  ██║            " << endl;
cout << "             ██║ ╚═╝ ██║╚██████╔╝██║  ██║███████║███████╗    ██║ ╚████║███████╗██║  ██║██████╔╝            " << endl;
cout << "             ╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝    ╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝╚═════╝             " << endl;
cout << "                                                                                                           " << endl;
cout << "\033[0m";}
/*****************************************/
void disclaimer(string txt){
    int length;
    length = txt.length();

    int leftW = 53;
    int rightW = 53;

    leftW += length/2;
    rightW -= length/2;

    cout << "\033[1;" << 40     << "m" << "\033[1;" << 31 << "m" << "\033[1;" << 53 << "m";
    cout << "|" << setw(leftW) << right << txt << setw(rightW)  << "|" << "\033[0m" << endl;}
/*****************************************/
void disclaimer(){
    
        cout << "\033[1;" << 40 << "m" << "\033[1;" << 31 << "m" << "\033[1;" << 53 << "m" << "|" << setw(106) << right  << "|" << "\033[0m" << endl;}
/*****************************************/
string inputString(string text){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m";
    cout << "| " << text;
    string temp;
    cin >> temp;
    cout << "\033[0m";
    return temp;}
/*****************************************/
string getlineString(string text){
    cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m";
    cout <<"| " <<text;
    string temp;
    getline(cin , temp);
    cout  << "\033[0m";
    return temp;}
/*****************************************/
void toLower(string & text){

	int size = text.length();

	for (int i = 0; i < size; ++i)
	{
		if (text[i] >= 65 && text[i] <= 90)
		{
			text[i] += 32;
		}	
	}	}	
/*****************************************/
void morse(string option){

	string morseAlpha[26] = {".-" , "-..." , "-.-." , "-.." , "." , "..-." , "--." , "...." , ".." , ".---" , "-.-" , ".-.." , "--" , "-." , "---" , ".--." , "--.-" , ".-." , "..." , "-" , "..-" , "...-" , ".--" , "-..-" , "-.--" , "--.."};
	string morseDigit[10] = {".----" , "..---" , "...--" , "....-" , "....." , "-...." , "--..." , "---.." , "----." , "-----"};
	

	
	/**************************************************************************/
	if(option == "list"){

		for (int i = 0, j = 65; i < 26; ++i, ++j)
		{
   			cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(2) << left;

			cout << static_cast<char>(j) << setw(8) << right << morseAlpha[i] << "  |" << "\33[0m" << endl;
		}
		for(int i = 0, j = 48; i < 10; i++, j++)
		{
   			cout << "\033[1;" << 46 << "m" << "\033[1;" << 30 << "m" << "\033[1;" << 53 << "m" << setw(2) << "| " << setw(2) << left;
			cout << static_cast<char>(j) << setw(8) << right << morseDigit[i] << "  |" << "\33[0m";
			if (i != 9)
			{
				cout << endl;
			}
		}
		}
	/**************************************************************************/
	if (option == "encode"){
		disclaimer();
		string plainText;    	
    	cin.ignore();
		plainText = getlineString("Enter Your Text : ");	
		toLower(plainText);
		disclaimer();

		cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << "| ";
		for (int i = 0; i < plainText.length(); ++i)
		{
			if (plainText[i] >= 97 && plainText[i] <= 122)
			{
				int index = static_cast<int>(plainText[i]);
				cout << morseAlpha[index-97] ;
			}
			else if(plainText[i] >= 48 && plainText[i] <= 57)
			{
				int index = static_cast<int>(plainText[i]);
				cout << morseDigit[index-48] ;
			}
			cout << " ";
		}
		cout << " |"<<"\033[0m";}
	/**************************************************************************/
	if (option == "decode"){
		disclaimer();
		string plainText;    	
    	cin.ignore();
		plainText = getlineString("Enter Your Text : ");	
		disclaimer();


	    // Create a stringstream from the input string
		istringstream iss(plainText);
	    // Create a vector to store the separated words
	    vector<string> words;

	    string word;
	    while (iss >> word) {
	        words.push_back(word);
	    }

	    // Display the separated words
		cout << "\033[1;" << 103 << "m" << "\033[1;" << 90 << "m" << "\033[1;" << 53 << "m" << "| ";
	    for (const string& code : words) {
	       for (int i = 0; i < 26 ; ++i)
	       {
	       	 if (morseAlpha[i] == code)
	       	 {
	       	 	cout << static_cast<char>(i + 65);
	       	 }
	       }
	       for (int i = 0; i < 10; ++i)
	       {
	       	 if(morseDigit[i] == code)
	       	 {
	       	 	cout << static_cast<char>(i + 48); 
	       	 }
	       }
	    }
		cout << " |"<<"\033[0m";}}
/*****************************************/

int main()
{
	system("clear");
	header();
	disclaimer("Welcome.");

	string choice = inputString("Enter 'encode' for encoding, 'decode' for decoding or 'list' to list morse codes : ");
	
	morse(choice);

	cout << endl;


	disclaimer("Copyright © https://github.com/mrblackhearts");


	return 0;
}