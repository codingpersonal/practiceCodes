using namespace std;
#include"URLProcessor.h"
#include<vector>
#include<map>
#include<iostream>
#include<string>

class tfidf
{
public:
	//constructor
	tfidf(int docCount);

	//destructor
	~tfidf();

	//update the vector of maps(all docs) and the map for id and strcut of docInfo
	void addURLInfo(mapsi wordsFreq, docInfo documentDetail,int docId); 

	//generates the vector of idfs for the search query
	void generateIdf(string word, map<string,double>&outMap);

	//vector containing the map of each document [word-normalised freq]
	vector<mapsi>wordToFreq;

	//vector containing the idf of all docs [word-idf]
	vector<map<string,double>>idfVec;

	//map for document number to stcture having all doc info
	map<int,docInfo>IdToDocInfo;

	//computes the vector of multimap for each document[tfidf-word]
	void computeTfidfForAllWords(mapsi &wordToAllDocumentFreqMap);

	void printNorFreqMap();

	void printIdfMap();

	void printTfidfMap();

private:

	int numOfDocs;

	//multimap to store the tfidf to word mapping
	vector<multimap<double,string>>tfidfVec;

	//computes the inverse document frequency 
	//idf = log(total num of docs / number of docs with search term t in it)
	double computeIdf(int docWithSearchTerm);

	//returns the count of the document which have string k in them
	int docsWithSearchQuery(string word);

	//stores the idf of the input search query in the vector here
	void storeIdfInVectorForSearchQuery(string word,double idf,  map<string,double>&outMap);

	//using normalised freq map, it generates the idf map
	void populateIdfMapForCurrDoc(map<string,double>norFreqMap,map<string,double>&idfMap);

	//using nor freq map and idf map, it generates the tfidf map
	void populateTfIdfMapForCurrDoc(map<string,double>norFreqMap,map<string,double>idfMap, multimap<double,string>&tfidfMap);
};