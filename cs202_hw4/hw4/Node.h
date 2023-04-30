/*
* Title: Node
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A Node Class which holds word and indices
*/
#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
class Node {
public:
    Node();
    Node(string name,int index);
    int hashCalculator();
    int getHashNo();
    int getLine();
    string getWord();
    void setLine(int no);
    void setWord(string newWord);
    Node *next;

private:
    string word;
    int hashNo;
    int line;
    Node *neighbors;


};
