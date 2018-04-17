#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
//Author Xinrui Li
using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;
void printScoreBoard(vector< vector<int> >grid)
{
  int teams = grid.size();
  int periods = grid[0].size();
  cout<<"SCOREBOARD"<<endl;
  for(int i = 0; i < teams; i++)
  {
    cout<<"Player "<<i + 1<<": ";
    for(int j = 0; j < periods; j++)
    {
    cout<< grid[i][j] << "|";
    }
    cout<<endl;
  }
}
int randomBetween(int first,int second)
{
  return first + rand() % (second - first + 1);
}  
int main()
{
  int periods;
  int teams;
  vector<vector<int> > record;
  cout<<"How many competitors? ";
  cin>>teams;
  cout<<"How many scoring periods? ";
  cin>>periods;

  if( teams < MIN_TEAMS || periods < MIN_PERIODS || 
      teams > MAX_TEAMS || periods > MAX_PERIODS )
  {
    cout<<"Must have between "<<MIN_TEAMS<<" and "<<MAX_TEAMS<<" competitors.\n";
    cout<<"and between "<<MIN_PERIODS<<" and "<<MAX_PERIODS<<" periods.\n";
    return 0;
  }
  else
  {
   //make scoreboard and fill it with zeros
    for(int row = 0; row < teams; row++)
    {
      vector<int> arr;
      for(int column =0; column < periods; column++)
      {
        arr.push_back(0);
      }
      record.push_back(arr);
    }  
    printScoreBoard(record);
    srand((int)time(0));
   for(int row = 0; row <teams; row++)
   {
      for(int column = 0; column < periods; column++)
      {
       record[row][column] = randomBetween(5,5);
      } 
   }
   printScoreBoard(record);
  }
  return 0;
}
