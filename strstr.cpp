#include "header.h"

int strStr(string haystack, string needle){
    //naive way
    int h_sz = haystack.size(), n_sz = needle.size();
    if(h_sz<n_sz) return -1;
    if(n_sz == 0) return 0;
    int h_curr = 0, n_curr = 0;
    while(h_curr<=h_sz-n_sz){
        if(haystack[h_curr+n_curr] == needle[n_curr]){
            n_curr++;
            if(n_curr == n_sz) return h_curr;
        }
        else{
            h_curr++;
            n_curr = 0;
        }
    }
    return -1;
}

int main(){
    cout<<strStr("mississippi", "issipi")<<endl;
    return 0;
}