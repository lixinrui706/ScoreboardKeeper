#include <iostream>
#include <vector>
//Author Xinrui Li
using namespace std;

const int MAX_PERIODS = 10;
const int MAX_TEAMS = 4;
const int MIN_PERIODS = 1;
const int MIN_TEAMS = 1;

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
    for(int i = 0; i < teams; i++)
    {
      vector<int> arr;
      for(int j =0; j < periods; j++)
      {
        arr.push_back(0);
      }
      record.push_back(arr);
    }  
   //once created, display the scoreboard
   cout<<"SCOREBOARD"<<endl;
   for(int i = 0; i < teams; i++)
   {
     cout<<"Player "<<i + 1<<": ";
     for(int j = 0; j < periods;j++)
     {
       cout<<record[i][j]<<"|";
     }
     cout<<endl;
   }  
  }
  return 0;
}
