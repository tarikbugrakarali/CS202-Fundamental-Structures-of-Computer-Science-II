/*
* Title: WordNetwork
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A class that creates graph according to datas from edge and vertex txt
*/


#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include "List.h"

#define VERTEX_SIZE 5757
#define EDGE_SIZE 14135
#define TABLE_SIZE 512

using namespace std;
class WordNetwork
{
public :
WordNetwork ( const string vertexFile , const string edgeFile );
~ WordNetwork () ;
void listNeighbors ( const string word ) ;
void listNeighbors ( const string word , const int distance );
void listConnectedComponents () ;
void findShortestPath ( const string word1 , const string word2 ) ;

void  dft(int* &visited, string word, List &path);
bool bfs(string source, string destination, int pre[] , int distance[]);
void distanceHelper(int* &visited, string word, int remain);
private :
// define your data members here
// define private member functions here , if any
// you MUST use the adjacency matrix representation
 // const int VERTEX_SIZE = 5757;
//  const int EDGE_SIZE = 14135;
//  const int TABLE_SIZE = 512;
  Node* vertices;
  List* hashTable;
  int** adjMatrix;

  int hashFunction(Node &key);
  void addEdge(const string word1,const string word2);
  int  hashFinder(string word);
};

