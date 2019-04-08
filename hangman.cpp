
#include <iostream>
#include <cstdlib> //for srand()
#include <ctime>   //for time()
#include <string>

using namespace std;

//Postcondition: Description of program is written on the screen.
void print_message();

//Precondition: User is ready to enter there guessed letter choice 
//Postcondition: Prints out "Guess a letter" to the screen and returns the guessed letter (a type char)
//Params:
//	guessedLetter: a letter of type char that the user wishes to enter as the guessed letter
char getUserLetter(char &guessedLetter);


//Precondition: Subtracts the  number of chances with the incorrect attempts
//Params:
//	numberOfchances: a number of type int 
//	incorrect: a number of type int that counts the incorrect letters entered
//Returns the number of chances the user has left (a type int)
int triesLeft(int numberOfChances, int incorrect);

//Postcondition: Updates the secret word by filling in the correct letter guessed. If guessed letter is not correct, then the function return the number of incorrect guesses which increments as more incorrect guesses occur. 
//Params:
//	word:a word of type string that is randomly chosen for the game
//	guessedLetter:a letter of type char that the user wishes to enter as the guessed letter
//	secret: a word of type string that initializes the secret word with a '_'
//	incorrect:a number of type int that counts the incorrect letters entered
int updateWord(string word, char& guessedLetter, string &secret, int& incorrect);

//Precondition: missed letter only outputs when user enters an incorrect letter
//Params:
//      word: a word of type string that is randomly chosen for the game
//      guessedLetter:a letter of type char that the user wishes to enter as the guessed letter
//Returns the incorrect letter entered
string missedLetter(string word, char guessedLetter);

//Postcondition: If the word is guessed, the user wins and returns a type char of 'W', but if the word is not guessed, user loses and returns a type char of 'L'.
//Precondition: The number of chances and incorrect tries will determine whether user has won or lost
//Params:
//	numberOfChances: a number of type int
//	incorrect: a number of type int that counts the incorrect letters entered
char winOrLose(int numberOfChances, int incorrect);

//Params:
// 	word: a word of type string that is randomly chosen for the game
// Returns the secret word, whether you lose or win 
void displayWord(string word);


int main()
{
        
        //Print the welcoming message to the user
        print_message();
	
	//The number of chances user has to guess the word
	int numberOfChances=8;
	
	//Number of incorrect attemps
        int incorrect=0;

	//Secret words for the hangman game
        string actualWord[]= {"HAPPY", "SAD", "MAD", "EXCITED"};

        //Randomly choose the words from the list
        srand(time(0));
        int n= rand() % 4;
        string word= actualWord[n];
	
        //Initialize secret word with _ character
	string secret;
	int length=word.length();	
	for(int i=0; i<length;i++)
	{
		secret+='_';
	}
	//Letter user enters
	string entered;
	
	//Wrong letters entered
	string missed;
	
	// Guessed Letter user enters
	char guessedLetter;
	do
        {
		cout<<"\nAnswer: "<<secret<<endl;
		cout<<"You've used the following letters: "<<entered<<endl;
		cout<<"You have "<<triesLeft(numberOfChances, incorrect)<<" chances left."<<endl;
		cout<<"Missed: "<<missedLetter(word, guessedLetter)<<endl;		
		
		//Receive the letter guessed by the user
		guessedLetter= getUserLetter(guessedLetter);
		guessedLetter= toupper(guessedLetter);
		
			
		while(entered.find(guessedLetter) != string::npos)
		{
			cout<<"\nYou have already guessed "<<guessedLetter<<". Don't be sad, we did not remove a chance from you.Try again!"<<endl;
			cout<<"\nAnswer: "<<secret<<endl;
			guessedLetter= getUserLetter(guessedLetter);
                	guessedLetter= toupper(guessedLetter);
		}
		
		entered+=guessedLetter; //this stores in all the letters entered from the users guess (wrong and correct)
	        missed+=guessedLetter; //this puts in all the wrong letters entered

		updateWord(word, guessedLetter, secret, incorrect); 


	}while((incorrect < numberOfChances) && (secret!= word));

	//End of Game, User wins or loses
	char gameStatus;
	gameStatus= winOrLose(numberOfChances, incorrect);
	
	if(gameStatus=='L')
		
		cout<<"\nYou lost,looks like you will be hanged!\n";
        else
		cout<< "\nYou Won, looks like you wont be hanged!\n";
	
	displayWord(word);	//Displays the secret word
	
	return 0;
}

void print_message()
{
        cout<< "***********************************************************"<<endl;
        cout<< "\t"<<"Welcome to the game of Hangman!"<<endl;
        cout<< "You have 8 chances to guess the word. Goodluck!!!!"<<endl;
	cout<< "To help you I will list all your guessed letters in"<<endl;
        cout<< "one line (wrong and correct letters)"<<endl;
	cout<< "\nHowever, while I will list your misses, they won't"<<endl;
	cout<< "all apear together, so as soon as you enter a new"<<endl;
	cout<< "guess the previous missed will be removed, and only"<<endl;
	cout<< "be filled again if you enter a wrong guess."<<endl;
	cout<< "\nPS. I will let you know if you repeat any guessed letters"<<endl; 
        cout<< "***********************************************************"<<endl;
}

char getUserLetter(char &guessedLetter)
{
        cout<< "\nGuess a letter: ";
        cin >> guessedLetter;
        return guessedLetter;
}

int triesLeft(int numberOfChances, int incorrect)
{
	return (numberOfChances - incorrect);
}

int updateWord(string word, char& guessedLetter, string &secret, int& incorrect)
{
	int length= word.length();
	if (word.find(guessedLetter) != string::npos)
	{
        	cout<<"\nYes! Great guess, "<<guessedLetter<<" is in the word.\n";
		
		for (int i=0; i<length; i++)
		{
			if (word[i] == guessedLetter)
			{
				secret[i] = guessedLetter;	//Updates the secret word by filling in the correct letter guessed
			}
		}
	}
    	
    	else
    	{
        	cout<<"\nSorry! "<<guessedLetter<< " is not in the word.\n";
		incorrect++;
    	}
        return incorrect;
}
string missedLetter(string word, char guessedLetter)
{
        string missed;
        bool found=false;
        int length=word.length();
	for (int i=0; i<length;i++)
        {
                if (word[i] == guessedLetter)
                {
                        found=true;
                }
        }
        if (!found)
	{
                missed+=guessedLetter;
                
	}
		return missed;
}
char winOrLose(int numberOfChances, int incorrect)
{
	if (incorrect== numberOfChances)
		return 'L';
      
        else
		return 'W';
}

void displayWord(string word)
{
	cout<< "\n<<< The secret word was "<<word<< "."<<endl;
}
