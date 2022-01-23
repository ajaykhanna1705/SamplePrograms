

#include<iostream>
#include "Scheduler.h"

using namespace std;
int Scheduler::GetNumMatchesPerDay(const int& numTeams)
{
    return numTeams / 2;
}

int Scheduler::GetNumDaysForTournament(const int& numTeams)
{
    return (numTeams - 1) * 2;
}

int Scheduler::GetTotalMatches(const int& numTeams)
{

    return GetNumMatchesPerDay(numTeams)* GetNumDaysForTournament(numTeams);
}

//schedule table for 4 teams
//    0 1 2 3
//---------------------
// 0- 0 2 3 1
// 1- 2 0 1 3
// 2- 3 1 0 2
// 3- 1 2 3 0
// the table store the day number of the match between two teams
//for example: here 0 index represents teams 1 similarly all others
// Above table can be interpreted as Team 1 and Team 2 will have there match on day 2
//Team 1 and Team 3 will have match on day 3
//Team 1 and Team 3 will have match on day 1 and similarly all others pair can be interpreted.
void Scheduler::GetSchedule(int numTeams)
{
    //schedule vector stores the day of match for two teams
    vector<vector<int>> schedule(numTeams, vector<int>(numTeams, 0));

    for (int i = 0; i < numTeams - 1; ++i)
    {
        for (int j = 0; j < numTeams - 1; ++j)
        {
            if (i == j)
            {
                schedule[i][numTeams - 1] = ((i + j + 1) + (i + j + 1) / numTeams) % numTeams;
                schedule[numTeams - 1][j] = ((i + j + 1) + (i + j + 1) / numTeams) % numTeams;
                schedule[i][j] = 0;
            }

            else
            {
                schedule[i][j] = ((i + j + 1) + (i + j + 1) / numTeams) % numTeams;
            }
        }
    }
    displayDayWiseMatches(schedule);
}

void Scheduler::displayDayWiseMatches(vector<vector<int>> & schedule)
{
    int touDays = GetNumDaysForTournament(schedule.size());

    vector<vector<pair<int, int>>> homematches(touDays / 2 + 1); 
    for (int i = 0; i < schedule.size(); ++i)
    {
        for (int j = i + 1; j < schedule[0].size(); ++j)
        {
            //storing team pair that will play on day stored in schedule[i][j]
            //Here i and j are team numbers
            homematches[schedule[i][j]].push_back(pair<int, int>(i + 1, j + 1));//Adding 1 because index starts from zero
        }
    }

    vector<vector<pair<int, int>>> awaymatches(touDays / 2 + 1);
    for (int i = 1; i < schedule.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            //storing team pair that will play on day stored in schedule[i][j]
            //Here i and j are team numbers
            awaymatches[schedule[i][j]].push_back(pair<int, int>(i + 1, j + 1));//Adding 1 because index starts from zero
        }
    }

    displaySchedule(homematches, awaymatches);
}
void Scheduler::displaySchedule(vector<vector<pair<int, int>>> & homematches, vector<vector<pair<int, int>>> & awaymatches)
{
    int size = homematches.size();
    int dayWiseMatches = homematches[1].size();
    int count = 1;

    for (int i = 1; i < size; ++i)
    {
        cout << "MatchDay" << count++ << ":";
        for (int j = 0; j < dayWiseMatches; ++j)
        {
            cout << "\t" << homematches[i][j].first << "," << homematches[i][j].second << ".";
        }
        cout << endl;
        cout << "MatchDay" << count++ << ":";
        for (int j = 0; j < dayWiseMatches; ++j)
        {
            cout << "\t" << awaymatches[i][j].first << "," << awaymatches[i][j].second << ".";
        }
        cout << endl;
    }
}