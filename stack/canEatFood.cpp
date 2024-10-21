

// Utility function to check if a move is valid
bool isValidMove(int x, int y, int maze[5][5], vector<vector<bool>> &visited)
{
    return (x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] == 1 && !visited[x][y]);
}

// Function to check if the rat can eat the food
bool canEatFood(int maze[5][5], int fx, int fy)
{
    // If the start or the destination is a dead end
    if (maze[0][0] == 0 || maze[fx][fy] == 0)
    {
        return false;
    }

    // Direction vectors for up, left, down, right
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, -1, 0, 1};

    // Stack for DFS
    stack<Node> st;
    st.push(Node(0, 0));

    // Visited array to track visited cells
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    visited[0][0] = true;

    // Perform DFS
    while (!st.empty())
    {
        Node curr = st.top();
        st.pop();

        // If we have reached the food's location
        if (curr.x == fx && curr.y == fy)
        {
            return true;
        }

        // Try all four directions in anti-clockwise order
        while (curr.dir < 4)
        {
            int nextX = curr.x + row[curr.dir];
            int nextY = curr.y + col[curr.dir];

            curr.dir++;
            if (isValidMove(nextX, nextY, maze, visited))
            {
                visited[nextX][nextY] = true;
                st.push(curr);               // Push current state with updated direction
                st.push(Node(nextX, nextY)); // Push new node for the next move
                break;
            }
        }
    }

    // If we exhausted all paths and didn't find the food
    return false;
}
