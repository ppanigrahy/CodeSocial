#include<iostream>
using namespace std;
pair<int,int> getFinalPos(pair<int, int> grid_size, pair<int,int> init_pos, string sequence)
{
char prev_dir = 'E';
pair<int, int> curr_pos = init_pos;
for(int i=0; i<sequence.length(); i++)
{
char dir;
if(sequence[i] == 'M') 
dir = prev_dir;
else
dir = sequence[i];
if(dir == 'N') curr_pos.first++;
else if(dir  == 'S') curr_pos.first--;
else if(dir  == 'E') curr_pos.second++;
else if(dir  == 'W') curr_pos.second--;

prev_dir = dir;

if((curr_pos.first < 0 || curr_pos.first > grid_size.first) || (curr_pos.second < 0 || curr_pos.second > grid_size.second))
{
throw exception();
}
}
return curr_pos;
}

int main()
{
pair<int,int> initial_pos(5,3);
pair<int,int> size(50,25);
pair<int,int> final_pos;
try{
final_pos = getFinalPos(size, initial_pos, "NEWMMSSS");
cout<<final_pos.first<<"  "<<final_pos.second;
}
catch(...){
cerr<<"Crossing Boundry Exception";
}
return 0;
}
