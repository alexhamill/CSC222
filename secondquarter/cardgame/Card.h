#include <string>
#include <vector>
using namespace std;

struct Card
{
    int suit, rank;

    Card();
    Card(int s, int r);
    string to_string() const;
    bool operator==(const Card&) const;
};