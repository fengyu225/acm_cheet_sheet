#include "header.h"

//int strStr(string haystack, string needle){
//    //naive way
//    int h_sz = haystack.size(), n_sz = needle.size();
//    if(h_sz<n_sz) return -1;
//    if(n_sz == 0) return 0;
//    int h_curr = 0, n_curr = 0;
//    while(h_curr<=h_sz-n_sz){
//        if(haystack[h_curr+n_curr] == needle[n_curr]){
//            n_curr++;
//            if(n_curr == n_sz) return h_curr;
//        }
//        else{
//            h_curr++;
//            n_curr = 0;
//        }
//    }
//    return -1;
//}

void build_next(string& needle, vector<int>& next){
    int n_sz = needle.length();
    int k = -1;
    for(int i=0; i<n_sz-1;){
        if(k == -1 || needle[i] == needle[k]){
            k++;
            next[++i] = k;
        }
        else k=next[k];
    }
}

int strStr(string haystack, string needle){
    //KMP
    int h_sz = haystack.length(), n_sz = needle.length();
    if(n_sz>h_sz) return -1;
    if(n_sz == 0) return 0;
    vector<int> next(n_sz, -1);
    build_next(needle, next);
    int h_curr = 0, n_curr = 0;
    while(h_curr<h_sz){
        if(haystack[h_curr] == needle[n_curr]){
            h_curr++;
            n_curr++;
            if(n_curr == n_sz) return h_curr-n_curr;
        }
        else if(next[n_curr] == -1){
            h_curr++;
            n_curr = 0;
        }
        else n_curr = next[n_curr];
    }
    return -1;
}

int main(){
    cout<<strStr("mississippi", "issipi")<<endl;
    return 0;
}