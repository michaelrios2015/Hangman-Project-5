# Hangman-Project-5

This is the assignment the project was created for 

**COSC 501 at Towson University**
 
Write a program that plays the game of HANGMAN(guessing a mystery word).  Read a word to be guessed from a file into successive elements of the array WORD. The player must guess the letters belonging to WORD. A single guessing session should be terminated when either all letters have been guessed correctly (player wins) or a specified number of incorrect guesses have been made (computer wins). A run must consist of at least two sessions: one player wins and one computer wins. The player decides whether or not to start a new session.  
 
 
Hints:   Use an array  SOLUTION to keep track of the solution generated  so far. Initialize SOLUTION to a string of symbols "*". Each time a letter of WORD is guessed, replace the corresponding "*" in SOLUTION with that letter. For example, cin >> Guess; if (Guess == WORD[index]) {SOLUTION[index] = Guess} 
 
 You may consider using the following functions:
 
* Initialize: initialize SOLUTION to *'s and other global variables to 0. 
* Guess: process guesses of the mystery word. Read in guesses until the limit is reached or the word is guessed. If the guessed letter is not in the word, inform the player. Otherwise, tell the player the number of times the letter occurs in the word and display the partial solution to the user.     
* ReadString: Before running your program, you should prepare a file containing 20 words, each on a separate line. At the beginning of each session, read a word from the file into the string named WORD.      
* PrintSolution: print the guessed word and the number of times the player has tried.     
* GuessedWord: It is a function. It returns TRUE if every element of SOLUTION is not a *. 
* and other functions if needed. 
 
Main program: control when to stop the loop, call functions, and print out the player's scores in terms of wins. 
 
Pay attention to the differences between value and variable parameters. 
 
Run your program three times and print the execution step by stem     
To make the output interesting and to earn extra points, you may want to draw a figure on the screen step by step.    
 
Good Luck and Have Fun!


