//*********************************************** 
// COSC 501                                Project 5
// Michael Rios                             11/30/13 
// PROGRAM-NAME: project 5	 
//  
//Hangman the game!!
//*********************************************** 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Intitializes major variable
void Initialize(char word[50], char solution[50], int& wrong_guess, int& index, int& word_length);

//reads in word at random from file
void ReadString(char word[50]);

//gets length of word
void WordLength(char word[50], int& word_length);

//test letter guessed verus all letters in word
void Guess();

//prints the solution array so user can see their guess
void PrintSolution();

//tests to see if the word is guessed
int GuessedWord(char solution[50]);

//draws the traditional hangman 
void draw_person(int wrong_guess);

char guess;
char word[50], solution[50];
int wrong_guess, index, word_length;
ifstream Infile;

void main()
{
	
	char cont = 'y';
	int games_won = 0;


	//allows user to contine untill they choose not to
	while (cont != 'n')
	{
		
		Initialize(word, solution, wrong_guess, index, word_length);
		
		ReadString(word);

		//keeps game going till the word is guessed or the player makes 6 wrong guesses
		while ((!GuessedWord(solution) && wrong_guess < 6))
		{	
			Guess();
			PrintSolution();
		}
		//if player has won
		if (wrong_guess < 6)
		{	cout << "CONGRATULATIONS YOU WON!!! CONGRATULATIONS YOU WON!!! CONGRATULATIONS YOU WON!!!\n";
			games_won++;}
		//player has lost
		else
			cout << "sorry, charlie the word was " << word << endl;
	
		cout << "press any button but n to continue\n";
		cin >> cont;
	}

	//gives final score in terms of games won
	cout << "thanks for playing you won " << games_won << " game. Till next time\n";
	
}
void Initialize(char word[50], char solution[50], int& wrong_guess, int& index, int& word_length)
{
	index = 0;
	wrong_guess = 0;
	word_length = 0;

	//gives us two arrays of 50 *
	for (int i = 0; i < 50; i++)
	{
		word[i] = '*';
		solution[i] = '*';
	}

}
void ReadString(char word[50])
{
	Infile.open("words.txt");
	int random;
		
	random = (rand() % 26);
	
	if (Infile.fail())
	{
		cout << "failed\n";
		exit(1);
	}
	
	//picks one of the words at random
	for (int i = 0; i < random + 1 ; i++)
	{
	Infile >> word;
	}

	Infile.close();
}

void Guess()
{
	cout << "Please guess a letter\n"; 
	cin >> guess;
	int correct = 0;
	
	//goes through the entire word and compares each letter to the guess
	for(int i = 0; i < word_length; i++)
	{
		//if the guess matches the letter sets the solution array to that letter
		if (guess == word[i])
		{ 
			solution[i] = guess;
			correct++;
		}
	}	
	
	//lets player know no matches were found
	if (correct == 0)
	{
		cout << "sorry " << guess << " is not in the word\n"; 
		wrong_guess ++; 
		draw_person(wrong_guess);
	}

	//PrintSolution();
	
}

//finds word length this is needed as it is not a uniform value
void WordLength(char word[50], int& word_length)
{
	while (word[word_length] != '\0')
		word_length ++;
}

//prints the solution array also lets player know how many more guesses they have
void PrintSolution()
{
	cout << "Your gues so far ";
	for (int i = 0; i < word_length; i++)
		cout << solution[i];
	cout << endl;

	if (wrong_guess < 5)
		cout << "you have " << 6-wrong_guess << " more guesses\n";
	else if (wrong_guess == 5)
		cout << "you have 1 more guess\n"; 
	else 
		cout << "you have no more guesses\n";
}


//checks to see if the word has been correctly guessed
int GuessedWord(char solution[50])
{
	int i = 0;
	
	WordLength(word, word_length);
	
	//as soon as there are no more * in the solution array,
	//at least up to word length, then the solution has been guessed
	while (word_length > i)
	{
		if(solution[i] == '*')
			return 0;
		else 
			i++;
	}

	return 1;
}


//fun drawing
void draw_person(int wrong_guess)
{

	if (wrong_guess == 1)
	{
		cout << setw(20) <<" |-------| \n";
		cout << setw(20) <<" o       | \n";
		cout << setw(20) <<"         | \n";
		cout << setw(20) <<"         | \n";
		cout << setw(20) <<"         | \n";
		cout << setw(23) <<"_________|___ \n";
	}
	else if (wrong_guess == 2)
	{
		cout << setw(20) <<"  |-------| \n";
		cout << setw(20) <<"  o       | \n";
		cout << setw(20) <<"  |       | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(23) <<" _________|___ \n";
	}
	else if (wrong_guess == 3)
	{
		cout << setw(20) <<"  |-------| \n";
		cout << setw(20) <<"  o       | \n";
		cout << setw(20) <<" /|       | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(23) <<" _________|___ \n";
	}
	else if (wrong_guess == 4)
	{
		cout << setw(20) <<"  |-------| \n";
		cout << setw(20) <<"  o       | \n";
		cout << setw(20) <<" /|\\      | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(23) <<" _________|___ \n";
	}
	else if (wrong_guess == 5)
	{
		cout << setw(20) <<"  |-------| \n";
		cout << setw(20) <<"  o       | \n";
		cout << setw(20) <<" /|\\      | \n";
		cout << setw(20) <<" /        | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(23) <<" _________|___ \n";
	}
	else 
	{
		cout << setw(20) <<"  |-------| \n";
		cout << setw(20) <<"  o       | \n";
		cout << setw(20) <<" /|\\      | \n";
		cout << setw(20) <<" / \\      | \n";
		cout << setw(20) <<"          | \n";
		cout << setw(23) <<" _________|___ \n";
	}

}