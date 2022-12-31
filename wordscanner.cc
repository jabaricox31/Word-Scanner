/* 	Jabari Cox
	z1867741
	CSCI 340 Section 2
	
	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/
#include <map>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>


 /**
 * @param_s A reference to a const string that represents the word that needs 
 * to be processed
 * @param_s A reference to a string that represents the word without punctuation
 * @note Two lambda functions find the first alphanumeric character and the first punctuation
 * character if their is any and parses the word to get the word without 
 * punctuation.
 ************************************************************************/
void clean_entry(const std::string& old_word, std::string& cleaned_word)
{

   auto first_char = std::find_if(old_word.begin(), old_word.end(), [](char i){return isalnum(i); });

   auto second_char = std::find_if(first_char, old_word.end(), [](char j){return (!isalnum(j)); });

   std::string clean_word(first_char,second_char); // Initializing the string to the range of the two iterators passed from the find_if lambda expressions

   std::for_each(clean_word.begin(), clean_word.end(), [&] (char &k){ k = tolower(k); }); //Turngs all the characters in the string to lower case

   cleaned_word = clean_word; //Setting clean word to the passed in reference string


}

 /**
 * @param_s A reference to an map container that reresents the map container the words need
 * to go in.
 * @note This function processes all the words from the input file and calls the
 * clean_entry() function to get rid of the punctuation if their is any. Then, it
 * stores that word in the map.
 ************************************************************************/
void get_words(std::map<std::string, int>& temp_map)
{

   std::string input;
   while(std::cin >> input) //Loop that processes all the words
   {


      std::string new_word;
      clean_entry(input,new_word); //Calling the clean_entry function to clean the words

      if( new_word.length() != 0) //Storing words if they are returned
      {

         temp_map[new_word]++;

      }

   }


}

 /**
 * @param_s A reference to a const map container that has the values that need to be printed out
 * @note This loop uses a lambda expression to print the info in the map
 ************************************************************************/
void print_words(const std::map<std::string, int>& print_map)
{

   int NO_ITEMS = 4;
   int ITEM_WORD_WIDTH = 14;
   int ITEM_COUNT_WIDTH = 3;
   int j = 0;
   int sum = 0;
   std::for_each(print_map.begin(),print_map.end(),[&](const std::pair<std::string, int> &p) 
   {
      std::cout <<std::setw(ITEM_WORD_WIDTH)<<std::left << p.first << ":" << std::setw(ITEM_COUNT_WIDTH)<< p.second;
      sum += p.second;
      j++;
      if ( j % NO_ITEMS == 0)
      {
         std::cout<<std::endl;

      }

   });

     std::cout<<std::endl;
     std::cout<<std::left<<std::setw(ITEM_WORD_WIDTH)<<"number of words in input stream "<<std::setw(ITEM_COUNT_WIDTH)<<std::right<<":"<< sum << std::endl;
     std::cout<<std::left<<std::setw(ITEM_WORD_WIDTH)<<"number of words in output stream"<<std::setw(ITEM_COUNT_WIDTH)<<std::right<<":"<< j << std::endl;


}


int main()
{

   std::map<std::string, int> map1; //Declaring the map object that will hold and print values

   get_words(map1);// Calling the get_words method to get all of the values cleaned and put in the map

   print_words(map1); //Calling the print_words method to print out the value in the map.

   return 0;

}

