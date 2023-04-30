/*
* Title: WordNetwork
* Author: Tarýk Buðra Karali
* ID: 21703937
* Section: 1
* Assignment: 4
* Description : A class that creates graph according to datas from edge and vertex txt
*/


#include "WordNetwork.h"
#include <iostream>
#include <sstream>


WordNetwork ::WordNetwork( const string vertexFile , const string edgeFile )
{
    vertices = new Node[VERTEX_SIZE];

    // reading vertexFile and store them in Node Array
    //*******************************************************************
    string line = "";
    ifstream read(vertexFile.c_str());
    int i = 0;

    if ( read.is_open() ){

        while ( getline(read, line) ){
               // cout << line << endl;
            vertices[i].setWord(line);
            vertices[i].setLine(i);
            i++;
        }
        read.close();
    }

    //*********************************************************************************************************************************************

    //*********************************************************************************************************************************************

    //Filling HashTable
    hashTable = new List[TABLE_SIZE];

    for(int vertexNo = 0; vertexNo < VERTEX_SIZE; vertexNo ++)
    {
        int value = hashFunction(vertices[vertexNo]);
        hashTable[value].add(vertices[vertexNo].getWord(),vertices[vertexNo].getLine());
    }

    //*********************************************************************************************************************************************
    //*********************************************************************************************************************************************

    //Creating adjacency matrix
    adjMatrix = new int*[VERTEX_SIZE];

    for (int i = 0; i < VERTEX_SIZE; i++) {
      adjMatrix[i] = new int[VERTEX_SIZE];

      for (int j = 0; j < VERTEX_SIZE; j++)
        adjMatrix[i][j] = 0;
    }

   //*********************************************************************************************************************************************
   //*********************************************************************************************************************************************

   //reading edges and filling adjacency matrix
    ifstream reading(edgeFile.c_str());
    string line1 = "";
    int edgeCounter = 0;

    if ( reading.is_open() ){

        while ( getline(reading, line1) ){
            stringstream check1(line1);
            string intermediate;
            string s1;
            string s2;

            int k = 0;

            while(getline(check1, intermediate, ','))
            {
                if(k==0)
                   s1 = intermediate;
                else
                   s2 = intermediate;

                 k ++;
            }

            edgeCounter ++;

            addEdge(s1,s2);
        }
        reading.close();
    }
}

WordNetwork :: ~ WordNetwork () {
   for(int i = 0; i < VERTEX_SIZE; i++)
     delete adjMatrix[i];

   delete adjMatrix;
   delete vertices;
   delete hashTable;
}


//This function calculate the hash value of given Node
int WordNetwork :: hashFunction(Node &key){

   int hashVal = key.getHashNo();

   hashVal %=TABLE_SIZE;

   if (hashVal < 0)   /* in case overflows occurs */
	 hashVal += TABLE_SIZE;

   return hashVal;

}

//This function calculate the hash no of given string
int WordNetwork :: hashFinder(string word){
   int hashVal = 0;

   for (int i = 0; i < word.length(); i++){
     hashVal = 37 * hashVal + word[i];
   }

   return hashVal;
}

//This function add edge to graph by changing appropriate value in the adjacency matrix
void WordNetwork :: addEdge(const string word1,const string word2)
{
    int hash1 = hashFinder(word1);
    int hash2 = hashFinder(word2);

    hash1 %=TABLE_SIZE;
    hash2 %=TABLE_SIZE;

    int index1 = hashTable[hash1].searchList(word1)->getLine();
    int index2 = hashTable[hash2].searchList(word2)->getLine();

    adjMatrix[index1][index2] = 1;
    adjMatrix[index2][index1] = 1;

}

//This function lists all words that are immediate neighbors of the input word.
void WordNetwork :: listNeighbors ( const string word )
{
   //Finding word's index(line number) by reaching hash table.
   int hash1 = hashFinder(word);
   hash1 %=TABLE_SIZE;
   int index1 = hashTable[hash1].searchList(word)->getLine();


   cout << "Neighbors of " << word << " :" << endl;

   //reading neighbors by looking adjacency matrix
   for (int i = 0; i < VERTEX_SIZE; i++)
   {
       if(adjMatrix[index1][i] == 1)
          cout<< vertices[i].getWord() << endl;
   }
}

//This function is an implementation of Recursive Depth-First Traversal Algorithm in the slides
void WordNetwork ::  dft(int* &visited, string word, List &path)
{
   //Finding word's index(line number) by reaching hash table.
   int hash1 = hashFinder(word);
   hash1 %=TABLE_SIZE;
   int index1 = hashTable[hash1].searchList(word)->getLine();

   visited[index1] = 1; //making visited

   path.add(word,index1); //add the path List

   //counter determine the current word has any unvisited neighbor
   int counter = 0;

   for (int t = 0; t < VERTEX_SIZE; t++)
   {
       if((adjMatrix[index1][t] == 1) && (visited[vertices[t].getLine()] == 0))
          counter++;
   }

   // if current word has any unvisited neighbor , then go to next word
   if(counter > 0)
   {

      for (int i = 0; i < VERTEX_SIZE; i++)
      {
        // if((adjMatrix[index1][i] == 1 )&& (visited[vertices[i].getLine()] == 0)&&(justOne < 1))
        if((adjMatrix[index1][i] == 1 )&& (visited[vertices[i].getLine()] == 0))
         {
             dft(visited,vertices[i].getWord(),path);
         }

      }
   }

   else{
   }

}

void WordNetwork :: listConnectedComponents ()
{
    int componentNo = 1;
    int* visited = new int[VERTEX_SIZE];

    for(int ind = 0; ind < VERTEX_SIZE; ind++)
        visited[ind] = 0;

    for (int i = 0; i < VERTEX_SIZE; i++)
      {
          List path;

          dft(visited,vertices[i].getWord(),path);

          if(path.getLength() > 1){
             cout<<"Connected component " << componentNo <<endl;
             path.printList();
             componentNo ++;
          }
      }
}


// This function is an implementation of Recursive Depth-First Traversal Algorithm in the slides with some additional part in order to detect depth
void WordNetwork :: distanceHelper(int* &visited, string word, int remain)
{

    // remain is a determiner for the distance if remain = 0 then we got the desired distance
    if(remain == 0)
    {
        int hash1 = hashFinder(word);
        hash1 %=TABLE_SIZE;
        int index1 = hashTable[hash1].searchList(word)->getLine();
        visited[index1] = 1;

        for (int i = 0; i < VERTEX_SIZE; i++)
        {
            if((adjMatrix[index1][i] == 1 )&& (visited[vertices[i].getLine()] == 0))
                cout << vertices[i].getWord() << endl;
        }

    }

    // if remain != 0 then continue with (remain -1)
    else
    {
        int hash1 = hashFinder(word);
        hash1 %=TABLE_SIZE;
        int index1 = hashTable[hash1].searchList(word)->getLine();
        visited[index1] = 1;

        for (int i = 0; i < VERTEX_SIZE; i++)
        {
            if((adjMatrix[index1][i] == 1 )&& (visited[vertices[i].getLine()] == 0))
                distanceHelper(visited,vertices[i].getWord(),remain-1);
        }

    }
}

void WordNetwork:: listNeighbors ( const string word , const int distance )
{
    int* visited = new int[VERTEX_SIZE];

    for(int ind = 0; ind < VERTEX_SIZE; ind++)
             visited[ind] = 0;

    cout<< "Neighbors of " << word << " with distance " << distance << " :" << endl;
    distanceHelper(visited,word,distance - 1);
}

//This function is an implementation of Recursive Breadth-First Traversal  Algorithm in the slides
bool WordNetwork:: bfs(string source, string destination, int pre[] , int distance[])
{
    List anQueue;
    int visited[VERTEX_SIZE];

    for(int ind = 0; ind < VERTEX_SIZE; ind++)
    {
        visited[ind] = 0;
        distance[ind] = INT_MAX;
        pre[ind] = -1;
    }

    //finding source's line no
    int hash1 = hashFinder(source);
    hash1 %=TABLE_SIZE;
    int index1 = hashTable[hash1].searchList(source)->getLine();

    int hash2 = hashFinder(destination);
    hash2 %=TABLE_SIZE;
    int finalPosition = hashTable[hash2].searchList(destination)->getLine();

    visited[index1] = 1;
    distance[index1] = 0;

    anQueue.add(source,index1);

    while(!anQueue.isEmpty())
    {
        Node* u = anQueue.find(1);
        anQueue.remove(1);

        int line = u->getLine();

        for(int i = 0; i < VERTEX_SIZE; i++)
        {
            if((adjMatrix[line][i] == 1 )&& (visited[i] == 0))
            {
                visited[i] = 1;
                distance[i] = distance[line] + 1;
                pre[i] = line;
                anQueue.add(vertices[i].getWord(),vertices[i].getLine());

                if( i == finalPosition)
                    return true;

            }
        }
    }

    return false;

}

// This function finds the shotest path between given two words by using bft algorithm
void WordNetwork:: findShortestPath ( const string word1 , const string word2 )
{
    int pre[VERTEX_SIZE], distance[VERTEX_SIZE];

    if (bfs(word1,word2,pre,distance) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    int hash1 = hashFinder(word2);
    hash1 %=TABLE_SIZE;
    int index1 = hashTable[hash1].searchList(word2)->getLine();


    List path;
    int crawl = index1;
    path.add(word2,index1);

    while (pre[crawl] != -1) {
        path.add(vertices[pre[crawl]].getWord(),vertices[pre[crawl]].getLine());
        crawl = pre[crawl];
    }

    cout << "SHORTEST lENGTH : " << distance[index1] << endl;

    cout <<"Shortest path from " << word1 << " to "<< word2 << " : " << endl;

    path.printBack();
}

