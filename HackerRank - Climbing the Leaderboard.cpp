/*
 * Problem: www.hackerrank.com/challenges/climbing-the-leaderboard/problem
 */

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    vector<int>::reverse_iterator al;
    vector<int>::iterator sc=scores.begin();
    vector<int> position;
    int index = 0;

    for (al = alice.rbegin(); al != alice.rend(); ++al){
        while (*al < *sc && sc != scores.end()){
            if (*sc == *(sc+1)) {
                sc++;
                continue;
            } else{
                index++;
                sc++;
            }
        }

        if (*al > *sc){
            position.push_back(index+1);
            continue;
        } else {
            position.push_back(index+1);
            while (*sc == *(sc+1)){
                sc++;
            }   
        }
    }

    return position;    
}
