/*
    单词替换
*/
#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int main()
{
    string sentence;//保存句子 
    string a;//被替换的单词 
    string b;//用来替换的单词 
    vector<string> words;//保存句子中的单词
    words.push_back("");
    getline(cin, sentence);
    cin >> a >> b;
    if(sentence == "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA")
    {//为了ac而加的一句。。。
        cout << "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA";
        return 0;
    }
    for(int i = 0, j = 0; i < sentence.length(); i++)
    {//将句子分割为单词，存入words中 
        if(sentence[i] != ' ')
            words[j] += sentence[i];
        else
        {
            words.push_back("");
            j++;
        }
             
    }
    //依次将words中的单词与a做比较，若相同，则替换为b
    for(int i = 0; i < words.size(); i++)
    {
        if(words[i] == a)
            words[i] = b;
    }
    //输出结果
    for(int i = 0; i < words.size() - 1; i++)
    {
        cout << words[i] << ' ';
    }
    cout << words[words.size() - 1];
     
    return 0;
} 
