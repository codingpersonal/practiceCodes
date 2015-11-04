using namespace std;
#include"URLProcessor.h"
#include<vector>

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

	vector<mapsi>wordToFreq;

	map<int,docInfo>IdToDocInfo;

private:

	int numOfDocs;

	//computes the inverse document frequency 
	//idf = log(total num of docs / number of docs with search term t in it)
	double computeIdf(int docWithSearchTerm);

	//returns the count of the document which have string k in them
	int docsWithSearchQuery(string word);

	//stores the idf of the input search query in the vector here
	void storeIdfInVectorForSearchQuery(string word,double idf,  map<string,double>&outMap);
};