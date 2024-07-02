#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <conio.h>
using namespace std;
bool compareStrings(string str1, string str2)
{

   return str1 == str2;
}
int randomnumber_generator(int length)
{

   std::random_device rd;
   std::mt19937 gen(rd());
   int random_number;
   // Define the range for random numbers
   int min = 0;
   int max = length;

   // Create a distribution in the specified range
   std::uniform_int_distribution<> distr(min, max);

   // Generate and print 10 random numbers
   for (int i = 0; i < 1; i++)
   {
      random_number = distr(gen);
   }
   return random_number;
}

int main()
{
A:
   string word, guessed_word;

   int i = 0, j, k = 0, wrong_tries = 0, counter = 0, counter_outer = 0;
   char letter_inpt;

   cout <<endl<< "Enter a word : (Dont show to the word guesser !! ) : ";
   cin >> word;
   system("cls");
   int length_of_word = word.length();

   int index_generated = randomnumber_generator(length_of_word);

   guessed_word = string(length_of_word, '_');

   guessed_word[index_generated] = word[index_generated];

   cout << guessed_word;
   cout << endl
        << "The game starts !!! ";
   cout << "10 wrong tries is game over";

   for (int i = 0; wrong_tries < 10; i++)
   { // loop for continuous letters input
      cout << endl
           << "Guess the letters : ";
      cin >> letter_inpt;

      for (int j = 0; j < length_of_word; j++)
      { // loop to check the letter inputted with every letters at string "word"
         if (word[j] == letter_inpt)
         {
            guessed_word[j] = letter_inpt;
         }
         else if (word[j] != letter_inpt)
         {
            counter++;
         }
      }
      if (counter == length_of_word)
      {
         cout << "Invalid character entered : " << endl;
         wrong_tries++;
         counter = 0;
      }
      if (word.compare(guessed_word) == 0)
      {
         cout << "Congratulations ! You guessed the word " << guessed_word;
         break;
      }

      cout << guessed_word;
      if (wrong_tries == 10)
      {
         cout << endl
              << "Your limit of 10 is over ! Game Over !";
         cout << endl
              << "Thanks for playing" << endl;
         cout << "The word was " << word;
         wrong_tries = 100;
      }

      counter = 0;
   }
   cout << endl
        << "Press Y/y to replay ! ";
   char replay = getch();
   if (replay == 'y' || replay == 'Y')
   {
      goto A;
   }
   else
   {
      return 0;
   }
   return 0;
}