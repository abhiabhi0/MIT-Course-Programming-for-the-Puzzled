#include <iostream>
#include <vector>

struct range
{
    std::size_t start = 0;
    std::size_t size = 0;
};

struct ranges
{
    std::vector<range> ranges;
    std::size_t total_sets = 0; //it will tell us minimum number of commands
};

void find_ranges(std::vector<char> const& caps, ranges& forward, ranges& backward)
{
    forward = ranges();
    backward = ranges();

    if (caps.empty())
    {
        std::cout << "Empty list!!!\n";
        return;
    }

    for (std::size_t i = 0; i < caps.size(); )
    {
        char style = caps[i];
        std::size_t start = i;
        std::size_t end = (std::find(caps.begin() + i + 1, caps.end(), !style) - caps.begin());
        std::size_t size = (end - i);

        ranges& rs = (style == 'F' ? forward : backward);
        rs.ranges.push_back({start, size});
        rs.total_sets += 1;

        i += size;
    }
}

void speak_commands(std::vector<range> const& ranges)
{
    for (auto const& r : ranges)
    {
        if (r.size == 1)
        {
            std::cout << "Person in position " << r.start << " please flip your cap!\n";
        }
        else
        {
            std::cout << "People in positions " << r.start << " through " << (r.start + r.size - 1) << " please flip your caps!\n";
        }
    }
}

int main()
{
    std::vector<char> caps = {'F', 'F', 'B', 'B', 'B', 'F', 'B', 'B',
                                                  'B', 'F', 'F', 'B', 'F'};

    ranges forward, backward;
    find_ranges(caps, forward, backward);

    ranges const& to_flip = (backward.total <= forward.total) ? backward : forward);
    speak_commands(to_flip.ranges);

}
