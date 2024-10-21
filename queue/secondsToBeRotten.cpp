int secondsToBeRotten(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    int freshCount = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j));
            }
            else if (grid[i][j] == 1)
            {
                freshCount++;
            }
        }
    }
    if (freshCount == 0)
        return 0;

    int seconds = 0;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty())
    {
        int qSize = q.size();
        bool rottenSomething = false;

        for (int i = 0; i < qSize; ++i)
        {
            pair<int, int> current = q.front();
            int x = current.first;
            int y = current.second;
            q.pop();
            for (int d = 0; d < int(directions.size()); ++d)
            {
                int newX = x + directions[d].first;
                int newY = y + directions[d].second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;          // Rot the fresh apple
                    q.push(make_pair(newX, newY)); // Enqueue the new rotten apple
                    freshCount--;                  // Reduce the fresh apple count
                    rottenSomething = true;
                }
            }
        }

        // Only increment seconds if we rotted something in this round
        if (rottenSomething)
        {
            seconds++;
        }
    }

    // If there are still fresh apples left, return -1
    return freshCount == 0 ? seconds : -1;
}