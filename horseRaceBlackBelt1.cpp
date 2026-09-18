#include <iostream>
#include <cstdlib>
#include <ctime>

int MAXHORSE = 5;
int BOARDSIZE = 15;
int turn = 1;
bool keepGoing = true;

void advance(int horseNum, int* horses);
void steadyAdvance(int horseNum, int* horses);
void leapAdvance(int horseNum, int* horses);
void burstAdvance(int horseNum, int* horses);
void shinyAdvance(int horseNum, int* horses);

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
      // This could probably be a long if/else statement, but this seemed to work better.
      switch (i) {
        case 0: advance(i, horses);
        break;
        case 1: steadyAdvance(i, horses);
        break;
        case 2: leapAdvance(i, horses);
        break;
        case 3: burstAdvance(i, horses);
        break;
        case 4: shinyAdvance(i, horses);
        break;
        default: return 0;
      }
      printLane(i, horses);
      if(isWinner(i, horses)){
        std::cout << " Horse " << i << " has won! \n";
        keepGoing = false;
      } // end if
    } // end for
    turn++;
  } // end while
  return 0;
} // end main

void advance(int horseNum, int* horses){
  int coin = rand() % 2;
  if(coin == 1){
      horses[horseNum]++;
  }// end if
} // end advance

void steadyAdvance(int horseNum, int* horses){
  int steadyMove = turn % 2;
  horses[horseNum] += steadyMove;
} // end steadyAdvance

void leapAdvance(int horseNum, int* horses){
  int coin = rand() % 3;
  if(coin == 2){
    horses[horseNum] += 2;
  } // end if
} // end leapAdvance

void burstAdvance(int horseNum, int* horses){
  if(turn < 8){
    int coin = rand() % 5;
    if(!(coin == 0)){
      horses[horseNum]++;
    } // end if
  } // end if
  else{
    int coin = rand() % 3;
    if(coin == 2){
      horses[horseNum]++;
    } // end if
  } // end else
} // end burstAdvance

void shinyAdvance(int horseNum, int* horses){
  int shinyCheck = rand() % 8192;
  if(shinyCheck == 0){
    horses[horseNum] = BOARDSIZE;
    std::cout << "You should buy a lottery ticket! \n";
  } // end if
} // end shinAdvance

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
  if(horses[horseNum] >= (BOARDSIZE - 1)){
    return true;
  }// end if
  else{
    return false;
  } // end else
} // end isWinner 