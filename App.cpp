
#include "Scheduler.h"
#include <iostream>

int main()
{
    int numteams = 0;
    std::cout << "Enter number of teams: ";
    std::cin >> numteams;

    if (numteams % 2 != 0)
    {
        std::cout << "Invalid number of teams";
        return 1;
    }
    Scheduler s;
    s.GetSchedule(numteams);
    return 0;
}