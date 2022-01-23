#include<vector>

class Scheduler
{
    int GetNumMatchesPerDay(const int& numTeams);
    int GetNumDaysForTournament(const int& numTeams);
    void displayDayWiseMatches(std::vector<std::vector<int>>& schedule);
    void displaySchedule(std::vector<std::vector<std::pair<int, int>>>& homematches, 
        std::vector<std::vector<std::pair<int, int>>>& awaymatches);
public:
    int GetTotalMatches(const int& numTeams);
    void GetSchedule(int numTeams);
    
};