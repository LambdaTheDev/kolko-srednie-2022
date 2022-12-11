#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    set<int> barIdsByTownId[n];
    map<int, int> townIdsByBarCount;

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++)
        {
            int t;
            cin >> t;

            // Bar ID to town ID
            barIdsByTownId[i].insert(t);
        }

        map<int, int>::value_type entry { m, i };
        townIdsByBarCount.insert(entry);
    }

    map<int, int>::reverse_iterator it;
    set<int> outputBarIds;

    int i = 0;
    for(it = townIdsByBarCount.rbegin(); it != townIdsByBarCount.rend(); it++)
    {
        if(i++ >= k) break;

        int townId = it->second;
        for(auto barId : barIdsByTownId[townId])
        {
            outputBarIds.insert(barId);
        }
    }

    cout << outputBarIds.size() << endl;
    for(auto barId : outputBarIds)
    {
        cout << barId << " ";
    }
}
