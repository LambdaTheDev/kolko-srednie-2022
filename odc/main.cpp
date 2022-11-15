#include <iostream>

using namespace std;

typedef pair<int, int> point;
typedef pair<int, int> vec;

int vectorProduct(vec first, vec second)
{
    return (first.first * second.second) - (second.first * first.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        point p0, p1, p2, p3;
        vec v0, v1;

        cin >> p0.first >> p0.second >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;

        v0.first = p1.first - p0.second;
        v0.second = p1.second - p0.second;

        v1.first = p3.first - p2.first;
        v1.second = p3.second - p3.second;

        
    }
}
