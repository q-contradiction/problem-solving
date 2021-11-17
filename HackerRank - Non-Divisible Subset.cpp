/*
 * Problem: www.hackerrank.com/challenges/non-divisible-subset/problem
 */


int nonDivisibleSubset(int k, vector<int> s) {

    vector<int> mods_frequency(k,0);
    int elements=0;

    for (int i=0; i<s.size(); ++i){
        s[i]=s[i]%k;
        mods_frequency[s[i]]++;
    }

    for (int i=1; i <  k/2.0; ++i){
        elements+= (mods_frequency[i]>= mods_frequency[k-i]) ? mods_frequency[i] : mods_frequency[k-i];
    }

    if (mods_frequency[0]>0) ++elements; /*We can take only a single element, in case it not empty */
    if (k%2==0 and mods_frequency[k/2]>0) ++elements;

    return elements;
}
