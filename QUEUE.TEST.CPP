#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() 
{
    int testCase = 0;
    int t;

    while (cin >> t && t != 0) {
        unordered_map<int, int> teamMap; // Map to store team number of each element
        queue<int> teamOrder; // Queue to maintain the order of teams
        queue<int> teamQueue[1000001]; // Array of queues for each team (team number ranges from 0 to 999999)

        for (int i = 0; i < t; ++i) {
            int n; // Number of elements in the team
            cin >> n;

            for (int j = 0; j < n; ++j) {
                int element;
                cin >> element;
                teamMap[element] = i + 1; // Assign team number to each element
            }
        }

        string command;
        cout << "Scenario #" << ++testCase << endl;

        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                int element;
                cin >> element;
                int team = teamMap[element];

                if (teamQueue[team].empty()) {
                    teamOrder.push(team);
                }

                teamQueue[team].push(element);
            } else if (command == "DEQUEUE") {
                int team = teamOrder.front();
                int element = teamQueue[team].front();
                teamQueue[team].pop();

                cout << element << endl;

                if (teamQueue[team].empty()) {
                    teamOrder.pop();
                }
            }
        }

        cout << endl;
    }

    return 0;
}
