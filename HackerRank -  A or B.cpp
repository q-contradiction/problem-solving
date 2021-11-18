/*
 * Problem: https://www.hackerrank.com/challenges/aorb/problem
 *
 * Manually converting hexademical string representantions to binary and vice versa
 * If C[i] is '0', then both A and B must be both '0' (flip both if not)
 * If C[i] is '1', either A or B must be '1'. (Flip one of these 2, in this case b, since A must be as small as possible)
 * If there are remaining flips after the mandatory operations, make A string as small as possible by setting values to '0'
 */


map<char, string> hextobin = {    {'0', "0000"}, {'1', "0001"}, {'2', "0010"},
    {'3', "0011"}, {'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"}, 
    {'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"}, {'C', "1100"},
    {'D', "1101"}, {'E', "1110"}, {'F', "1111"}  };
    
map<string, string> bintohex = {  {"0000", "0"}, {"0001", "1"}, {"0010", "2"},
    {"0011", "3"}, {"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"}, 
    {"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"}, {"1100", "C"},
    {"1101", "D"}, {"1110", "E"}, {"1111", "F"} };
    
     
string convert_hex_to_bin(string h, int len) {
    
    string b = "";
    for (size_t i = 0; i < h.size(); ++i)
        b += hextobin[h[i]];
    return (string(len - 4*h.size(), '0') + b);
}

string convert_bin_to_hex(string b) {
    
    string h = "";
    for (size_t i = 0; i < b.size(); i = i + 4) 
        h += bintohex[string(b, i, 4)];
        
    h.erase(0, h.find_first_not_of('0'));

    return (h.empty()) ?  "0" : h;
}

void aOrB(int k, string a, string b, string c) {
    
    int len = a.size() > b.size()? 
    (a.size() > c.size()? a.size(): c.size()): (b.size() > c.size()? b.size(): c.size());
    
    string a_bin = convert_hex_to_bin(a, 4*len);
    string b_bin = convert_hex_to_bin(b, 4*len);
    string c_bin = convert_hex_to_bin(c, 4*len);
    
    int bit_flips = 0;
    
    for (size_t i = 0; i <= c_bin.size(); ++i) {
        if (c_bin[i] == '0') {
            bit_flips += (a_bin[i] - '0') + (b_bin[i] - '0');
            a_bin[i] = '0';
            b_bin[i] = '0';
        } else if (c_bin[i] == '1' && (a_bin[i] == '0' && b_bin[i] == '0')) {
            bit_flips += 1;
            b_bin[i] = '1';    
        }    
        if (bit_flips > k ) {
            cout << "-1\n";
            return ;
        }
    }
    
    int rem_flips = k - bit_flips;
    int i = 0;
    
    while (rem_flips >= 1 && i < a_bin.size()) {
        if (c_bin[i] == '1' && b_bin[i] == '1' && a_bin[i] == '1') {
            a_bin[i] = '0';   
            rem_flips--;     
        } 
        else if(c_bin[i] == '1' && b_bin[i] == '0' && a_bin[i] == '1' && rem_flips >= 2) {
            rem_flips -= 2;
            a_bin[i] = '0';
            b_bin[i] = '1';
        }
        i += 1;
    }
        
    string a_hex = convert_bin_to_hex(a_bin);
    string b_hex = convert_bin_to_hex(b_bin);
    
    cout << a_hex << endl << b_hex << endl;
    return; 
}
