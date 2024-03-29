/*
 * Problem: www.hackerrank.com/challenges/encryption/copy-from/116329247
 */

vector<int> rowsandcolumns(int len){

    double x = sqrt(len);
    int up = ceil(x), down=floor(x);
    vector<int> arr;

    
    if (down*down >= len) {
        arr.push_back(down);
        arr.push_back(down);
    }
    else if (down*up >= len){
        arr.push_back(down);
        arr.push_back(up);
    }

    else {
        arr.push_back(up);
        arr.push_back(up);
    }

    return arr;
}

string encryption(string s) {

    vector<int> v=rowsandcolumns(s.length());
    int rows = v[0], columns = v[1];
    string l="";

     for (int i = 0; i < columns; ++i){
        for (int j = i; j < s.size(); j = j + columns){
                l += s[j];
        }
        l += " ";
    }

    return l;

}
