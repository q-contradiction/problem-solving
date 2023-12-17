// Problem: https://www.hackerrank.com/challenges/queens-attack-2/problem

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    
    // clockwise boundaries in the 8 directions, starting from top & ending to top left, initialized with chessboard limits 
    // Every set contains the obstacles in a specific direction (sorted by distance from Queen). first element of set : closest obstacle
    std::array<std::set<int>, 8> boundaries = {{
        {n + 1 - r_q},                           // top 
        {std::min(n + 1 - r_q, n + 1 - c_q)},    // top right 
        {n + 1 - c_q},                           // right   
        {std::min(r_q, n + 1 - c_q)},            // bottom right 
        {r_q},                                   // bottom 
        {std::min(r_q, c_q)},                    // bottom left 
        {c_q},                                   // left 
        {std::min(n + 1 - r_q, c_q)}             // top left 
    }};
    
    for (size_t i = 0; i < obstacles.size(); ++i) {
        int r = obstacles[i][0] - r_q;
        int c = obstacles[i][1] - c_q;
      
        // determine direction of the obstacle & add distance to the corresponding set
        if (c == 0 && r > 0)
            boundaries[0].insert(r);
        else if (c == 0 && r < 0)
            boundaries[4].insert(abs(r));
        else if (r == 0 && c > 0)
            boundaries[2].insert(c);
        else if (r == 0 && c < 0)
            boundaries[6].insert(abs(c));
        else if (r == c && r > 0 )
            boundaries[1].insert(r);   
        else if (r == c && r < 0 )
            boundaries[5].insert(abs(r));
        else if (r == -c && r > 0 )
            boundaries[7].insert(r);
        else if (r == -c && r < 0 )
            boundaries[3].insert(abs(r));
        else 
            continue;
    }
    
    int attackPositions = 0;

    for (size_t i = 0; i < 8; ++i) {
        attackPositions += (*boundaries[i].begin() - 1);
    }
    
    return (attackPositions);
}
