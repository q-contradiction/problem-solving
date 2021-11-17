/*
 * Problem : https://www.hackerrank.com/challenges/two-characters/problem
 *
 * The problem is classified as easy, but it is more difficult. 
 * First we create an STL map to store the indexes of all characters in the string in sets. 
 *
 * Combining 2 sets we first determine if they can form an alternate string by comparing their sizes
 * If it is possible, we extract the elements of the 2 sets sequentially into a vector
 * And in every iteration we check if the elements continue to be sorted. 
 */
 
 
 int size_alternate(set<int> A, set<int> B) {

    vector<int> indexes;

    int minA = *A.begin(), minB = *B.begin();
    int x = (minA < minB) ? 0 : 1;
    
    if (x == 0 && (A.size() < B.size() || A.size() > B.size() + 1))
        return 0;
    else if (x == 1 && (B.size() < A.size() || B.size() > A.size() + 1))
        return 0;
        
    int pos = -1;
    while (!A.empty() || !B.empty()) {
        if (x == 0) {
            indexes.push_back(*A.begin());
            A.erase(A.begin());

        }
        else {
            indexes.push_back(*B.begin());
            B.erase(B.begin());
        }
        ++pos;
        if (pos >= 1 && indexes[pos] < indexes[pos - 1])
            return 0;
        x = (x + 1) % 2;
    }

    return indexes.size();
} 


int alternate(string s) {

    map<char, set<int>> chars_indexes;
    int max_size = 0, string_size;
    
    for (size_t i = 0; i < s.length(); ++i)
        chars_indexes[s[i]].insert(i);

    for (auto it1 = chars_indexes.begin(); it1 != prev(chars_indexes.end()); ++it1) {
        for (auto it2 = next(it1); it2 != chars_indexes.end(); ++it2) {
            string_size = size_alternate(it1->second, it2->second);
            if (string_size > max_size)
                max_size = string_size;
        }
    }

    return (max_size);
}
