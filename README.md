# CS121_project_4
Procedural Horse Race in C


array of horsePosition[5] where the horseNum refers to the slot in the array and the position is 0-15 where 15 is the winning square.

```
     ...............|
     ...............|
     ...............|
     ...............|
     ...............|
```

how to replace these without it being an array and filling every field with a . and replacing it with the position of a horse after that initializes each turn.
take the array of horses, have two for loops. First loop goes through each horse, second loop goes through each space. If the space matches the number held within the horse array (checked by comparing with the second loops sentinel), replace that space with the horse's number.

```
int MAXHORSE = 5;
int BOARDSIZE = 15;

flips a coin each iteration to see if the horse's spot increases by one
 void advance(int horseNum, int* horses);
     int coin = rand() % 2;
     if (coin = 1)
          horses[horseNum]++

prints the lanes onto the screen, checking where the horse is and replacing the grass there with the horse
 void printLane(int horseNum, int* horses);
     for(int i = 0; i > maxHorse; i++)
          for(int j = 0; j > boardSize; j++)
               if(j == horseNum[i])
                    print i
               else
                    print '.'
          print "| \n"

checks if the horse has reached the last spot of the board, that being 14 by default due to 0 indexing
 bool isWinner(int horseNum, int* horses);
     if(horse[horseNum] == (boardsize-1))
     return true
     else false

int main()
     initialize horse array
     seed the rand
     get first input to begin
     for each horse in the horse array
          check if each horse advances
          print the lanes
          check if a horse has won
          if horse hasn't won, continue the loop on next enter
          if horse has won, set keepgoing to false and print win message
```

### Blackbelt Options
Add an 'Experimental' option select which allows you to activate some of these

Each horse will have a random 30-70% chance of moving
This will be told to the player before the race begins in terms of "Moods", where 30% will be "Abysmal", 31-49% will be "Poor", 50% will be "Average", 51-69% will be "Good", and 70% will be "Incredible"
The player will be able to bet off of this

Alternatively, each horse could use a different die to determine their movement. 0 uses a d2, 1 uses a d4, 2 uses a d6, 3 uses a d12, and 4 uses a d20. Not sure if this would effect the odds.

Each horse could have a unique movement pattern. For example, one horse could move at a constant pace (1 tile every 2 turns), one could leap forward (2 tiles on a % of 3), one could start fast and get slower (start with an 80% chance to move, but slowly decrease down to 40% as the turns continue), shiny horse (1/8192 to just win), invisible horse (Coin flip, but you can't see where it is on the field).