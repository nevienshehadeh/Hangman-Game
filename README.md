# Hangman-Game
The Game of Hangman:  The user of the game has 8 chances to guess a word. The secret word is represented to the player with a '_' in each missing letter. The game allows the user to enter a letter of their chose, if the letter is in the secret word, the game tells the player this  and reveals all instances of that letter in the secret word. If the letter is not in the word, the game tells the player this and subtract 1 from the players 8 chances. However, if the user tries to guess the same letter previously entered, the game will not remove a chance from their number of chances; rather, it will give them another chance (and continue to do this until a new letter is entered).


>>Programs operations: 
	As soon as you compile my program, a welcoming and description of the program will print to the screen, then the secret word will appear but be initialized with the '_' character (this will be labeled as the "Answer", then the "Misses" will appear (this places all the wrong letters entered), then all the letters entered (wrong and right) will appear, and then finally the program will output to the user how many chances they have left. 
	
	Besides the welcoming and description of the program, the rest continues to output to the screen so long as the word is not guessed and the number of chances does not exceed to 8. However, when the user enters a letter already guessed, the only thing that will output is the message telling the user that they have already guessed this letter and to try again, and the "Answer" with initialized '_' and any guessed Letter filled into that. This will continue to appear until the user enters a new letter and once the new letter is entered the "Answer", "Misses", "Wrong and Right letters entered, and "Number of chances left" will reappear. 

The user is free to enter the letter in lower case or upper case, either one used, the program will understand it. 

>>>Programs Design:
	In designing my program, I felt it was best to split most of the task into different functions. The first important decision was to figure out how to hide the secret word and initialize it to ‘_’. After figuring out how to do this I was able to output it to the screen as the “Answer”, and then give the user the ability to guess the word. Next I needed to figure out a way to update that secret word and fill in the correct letters to the secret word. That was the most complicated part for me, so I decided to use (.find) member function of the standard class string , this checked whether the guessed letter was in the secret word; however it was important that this part was done in a while loop and not in a if statement. The if-statement will bring you to some errors. Then this updated the secret word by filling in the correct letter guessed. If not found, this incremented the incorrect int. In my main, I had the do while loop set so that when the incorrect int reached to numberOfChances(which was 8) it would end the game; which is why I needed to keep track of the incorrect letters.  So as long as the secret word was not guessed yet and the number of chances did not exceed, the game would continue. 

>>>Testing and Debugging:
	I decided to test my program by testing each individual function separately to be able to debug easily. I felt that helped and was way more efficient then just compiling the entire function as a whole. In the beginning when I tried to do that, I felt I was getting  no where because I was getting continues errors. However, as soon as I decided to split up the tasks (while I still got errors) I realized it was much easier to debug.
	
	The second difficult task I encountered was to be able to list the letters that the player chose, but that we're not in the secret word. I was only able to list the misses individually, so I decided to output all letters (wrong and right) in one section, and just the wrong letters in another section (but these wrong letters only output individually). I would say that was the hardest part to figure out.

	I also found it extremely helpful to create two separate programs. I kept one for testing, and I left the other one to add the functions that worked properly  so I didn’t confuse the ones that worked and the ones that didn’t. This was so useful for me because it kept everything organized for me, and by doing this I wasn’t getting as much errors as I usually was.  
