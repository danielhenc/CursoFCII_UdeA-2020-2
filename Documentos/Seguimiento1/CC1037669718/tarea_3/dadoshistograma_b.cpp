/*
  Tarea 3 b
  Santiago Bustamante
*/

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;

int main(){
  const unsigned int N = 36000; // number of throws
  unsigned int dice1, dice2, sum;
  vector<int> frequency(11,0); // sum frequency from 2 to 12

  srand(time(NULL));

  for(int i = 0; i < N; i++){
    dice1 = 1 + rand()%6;
    dice2 = 1 + rand()%6;
    sum = dice1 + dice2;

    frequency[sum - 2]++;
  }

  cout << "| SUM | FREQUENCY | PERCENTAGE |\n";
  for(int i = 0; i < 11; i++){
    cout << "|" << setw(5) << i + 2 << "|" << setw(11) << frequency[i] << "|" << setw(12) << setprecision(2) << fixed << float(frequency[i])/float(N)*100 << "|\n";
  }
  return 0;
}
  
