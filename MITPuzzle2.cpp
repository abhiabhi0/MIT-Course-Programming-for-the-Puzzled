#include <iostream>
#include <vector>
#include <algorithm>

struct range
{
    int start = 0;
    int end = 0;

    range() = default;
    range(int start_time, int end_time):
        start(start_time),
        end(end_time)
        {}
};

int celeb_density(std::vector<range>& schedule)
{
    std::vector<int> hours(24, 0);

    int best_time = schedule[0].start;
    int max_celebs = 1;
    for (auto celeb : schedule)
    {
        for (int hour = celeb.start; hour < celeb.end; ++hour)
        {
            if (++hours[hour] > max_celebs)
            {
                ++max_celebs;
                best_time = hour;
            }
        }
    }
    return best_time;
}

int main()
{
    std::vector<range> schedule;

    int number_of_celebs;
    std::cout << "Enter number of celebrities attending party: ";
    std::cin >> number_of_celebs;

    if (number_of_celebs == 0)
    {
        return 0;
    }

    std::cout << "Enter entry time and exit time for a celebrity\n";
    for (int i = 0; i < number_of_celebs; ++i)
    {
        int s, e;
        std::cin >> s >> e;
        schedule.push_back(range(s, e));
    }

    int best_time = celeb_density(schedule);
    std::cout << "Best time to attend party is from " << best_time << " to " << best_time + 1 << "\n";
}
