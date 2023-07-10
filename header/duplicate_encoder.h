//https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/train/cpp
#pragma once

#include <map>
#include <string>
using namespace std;

std::string duplicate_encoder(const std::string& word);

std::string duplicate_encoder(const std::string& word){
    std::map<std::string, int> m{};
    for (auto i = 0; i < word.size() ; i ++ )
    {
        string s;
        if (word[i] < 97)
            s = (1, word[i]+32);
        else
            s = (1, word[i]);


        if (auto target = m.find(s); target != m.end()){
            m[s] ++;
        } else {
            m[s] = 0;
        }
    }
    string res = "";
    for (auto i = 0; i < word.size(); i ++ )
    {
        string s;
        if (word[i] < 97)
            s = (1, word[i]+32);
        else
            s = (1, word[i]);
        if (m[s] > 0)
            res = res + ")";
        else
            res = res + "(";
    }
    return res;
}



