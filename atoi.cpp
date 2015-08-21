/*
Implement atoi to convert a string to an integer.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include "header.h"

//int myAtoi(string str){
//    int sz = str.length();
//    if(sz == 0) return 0;
//    int res = 0, curr = 0, flag_count = 0;
//    bool flag = true;
//    for(;curr<sz && (str[curr]==' ' || str[curr] == '+' || str[curr] == '-');curr++){
//        if(str[curr] == ' ' && flag_count>0) return 0;
//        if(str[curr] == '+') flag_count++;
//        if(str[curr] == '-'){
//            flag = false;
//            flag_count++;
//        }
//    }
//    if(curr == sz || str[curr]<'0' || str[curr]>'9' || flag_count>1) return 0;
//    while(curr<sz && (str[curr]<='9' && str[curr]>='0' || str[curr] == ',')){
//        if(str[curr] == ','){curr++;continue;}
//        int d = str[curr]-'0';
//        if(res!=0 && 10*res/res!=10) return flag?INT_MAX:INT_MIN;
//        if(res*10-1>(INT_MAX-d)) return flag?INT_MAX:INT_MIN;
//        if(res*10-1 == INT_MAX-d) return flag?INT_MAX:INT_MIN;
//        res = res*10+d;
//        curr++;
//    }
//    if(flag) return res;
//    return -1*res;
//}

int myAtoi(string str){
    int sz = str.length();
    if(sz == 0) return 0;
    int res = 0;
    bool flag = true, met = false;
    for(int curr = 0; curr<sz; curr++){
        if(str[curr] == ' ' && !met) continue;
        if(str[curr]<'0' || str[curr]>'9'){
            if(met) break;
            if(str[curr] == '+' || str[curr] == '-'){
                flag = str[curr]=='-'?false:true;
                met = true;
            }
            else break;
        }
        if(res>INT_MAX/10) return flag?INT_MAX:INT_MIN;
        res = res*10;
        int d = str[curr]-'0';
        if(res>INT_MAX-d) return flag?INT_MAX:INT_MIN;
        res += d;
        met = true;
    }
    return res;
}

int main(){
//    cout<<myAtoi("          +        25554343ABC")<<endl;
//    cout<<myAtoi("2147483648")<<endl;
//    cout<<myAtoi("             -        2147483648")<<endl;
//    cout<<myAtoi("2147483647")<<endl;
//    cout<<myAtoi("+-2")<<endl;
    cout<<myAtoi("    10522545459")<<endl;
    return 0; 
}