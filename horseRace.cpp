#include <iostream>
#include <cstdlib>
#include <ctime>

int MAXHORSE = 5;
int BOARDSIZE = 15;
bool keepGoing = true;

void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

int main()
{
  int horses[MAXHORSE] = {0};
  srand(time(NULL));
  
  std::cout << "Welcome to Horser Racer! \n";

  while(keepGoing){
    std::cout << "Press Enter to Continue! \n";
    std::cin.get();
    system("clear"); // Clear the Screen
    std::cout << " BALLSTATE DERBY\n";
    for(int i=0; i<MAXHORSE; i++){
      advance(i, horses);
      printLane(i, horses);
      if(isWinner(i, horses)){
        std::cout << " Horse " << i << " has won! \n";
        keepGoing = false;
      } // end if
    } // end for
  } // end while
  return 0;
} // end main

void advance(int horseNum, int* horses){
  int coin = rand() % 2;
  if(coin == 1){
      horses[horseNum]++;
  }// end if
  
} // end advance

void printLane(int horseNum, int* horses){
  std::cout << "|";
  for(int j=0; j<BOARDSIZE; j++){
    if(j == horses[horseNum]){
      std::cout << horseNum;
    } // end if
    else{
      std::cout << ".";
    } // end else
  } // end for
  std::cout << "| \n";
} // end printLane

bool isWinner(int horseNum, int* horses){
  if(horses[horseNum] == (BOARDSIZE - 1)){
    return true;
  }// end if
  else{
    return false;
  } // end else
} // end isWinner 