#include <iostream>
#include <string>
#include <vector>
#include <random>

// array of sample words
std::vector<std::string> words{
  "elephant",
  "guitar",
  "pineapple",
  "computer",
  "mountain",
  "library",
  "bicycle",
  "umbrella",
  "kangaroo",
  "airplane"
};

std::string randomizeWord()
{
  //create a randomize device to seed the random num generator
  std::random_device rd;
  std::mt19937 gen(rd());                                        // saves the seed differently every single time ( if same seed then always same num)

  int wordsArrayLength = words.size() - 1;                      // use size of array to get indexes
  std::uniform_int_distribution<> dis_int(0,wordsArrayLength);  // use integer distribution to get integer 
  int wordIndex{dis_int(gen)};
  std::string wordChosen{words[wordIndex]};                     // choose word in array with randomized index num
  return wordChosen;
}

std::vector<char> wordIntoBlankArray(std::vector<char> wordArray)
{
  std::vector<char> blankArray;
  for (char c : wordArray)
  {
    blankArray.push_back('_');        // creates an array with underscores as placeholders
  }

  return blankArray;
}

std::vector<char> matchWordToArray(std::vector<char> wordArray,std::vector<char> blankArray, char userInput)
{
  for (int i=0;i<wordArray.size();i++)      // loops through word array to find a match
  {
    if (wordArray[i] == userInput)
    {
      blankArray[i] = userInput;
    }
  }
  return blankArray;
}

std::string blankArrayToString(std::vector<char> blankArray)
{
  std::string currentGuess;
  for (char c :blankArray)
  {
    currentGuess.push_back(c);      // adds current character to the end of string
  }
  return currentGuess;
}

void runGame(std::string word, std::vector<char> wordArray, std::vector<char> blankArray)
{
  while (true)
  {
    std::cout << word << std::endl;

    // get user input
    std::cout << "Guess a letter!: ";
    char userInput;
    std::cin >> userInput;
    
    // go through wordArray to match userInput, returns blankArray with replaced letters
    blankArray = matchWordToArray(wordArray,blankArray,userInput);

    // create a string for the current guesses, using blankArray
    std::string currentGuess{blankArrayToString(blankArray)};
    std::cout << currentGuess << std::endl;
    }
}

int main()
{
  std::string word{randomizeWord()};                         // choose the random word
  std::vector<char> wordArray(word.begin(), word.end());     // turn words into an array of characters
  std::vector<char> blankArray{wordIntoBlankArray(wordArray)};

  runGame(word,wordArray,blankArray);                       // main game loop

  return 0;
}