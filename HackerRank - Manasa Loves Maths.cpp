/*
 * Problem: www.hackerrank.com/challenges/manasa-loves-maths/problem
 *
 * Brute force search has complexity O(n!), the number of permutations of n-digit number
 *
 * From wiki, a number is divisible by 8 if The last three digits are divisible by 8  
 * The algorithm checks if the number has 1-2-(n>3) digits
 * For the latter case, we check if the digits of the 3-digit numbers divisiable by 8 are included in the number
 *
 */

string solve(string n) {
    
    int number;
    
    if (n.size() == 1) {
        number = n[0] - '0';
        if (number % 8 == 0)
            return "YES";
    }
    
    if (n.size() == 2) {
        number = 10 * (n[0] - '0') + (n[1] - '0');
        if (number % 8 == 0)
            return "YES";
        number = 10 * (n[1] - '0') + (n[0] - '0');
        if (number % 8 == 0)
            return "YES";
    }
    
    vector<int> string_numbers;    
    for (size_t i = 0; i < n.length(); ++i)
        string_numbers.push_back(n[i] - '0');
        

    for (number = 0; number <= 999; ++number) {
    
        if ( number % 8 == 0) {
            int x3 = number / 100; 
            int x2 = (number / 10) % 10;
            int x1 = number % 10;
            
            //Check if all 3 numbers exist in the vector of numbers.
            vector<int > copy_container (string_numbers);
            vector<int>::iterator it = find(copy_container.begin(), copy_container.end(), x1);
            
            if (it != copy_container.end()) {
                copy_container.erase(it);
                it = find(copy_container.begin(), copy_container.end(), x2);
                
                if (it != copy_container.end()) {
                    copy_container.erase(it);
                    it = find(copy_container.begin(), copy_container.end(), x3);
                    
                    if (it != copy_container.end()) {
                        //All elements were found in the string so there is a permutation that is divisible by 8.
                        return "YES";
                    }
                }
            }
        }else {
            continue;
        }
    }
    
    return "NO";
     
}
