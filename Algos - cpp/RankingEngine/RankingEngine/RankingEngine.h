#include<vector>
#include<string>
#include"tfidf.h"
using namespace std;
#include <map>

class RankingEngine{
private:
	int numOfDocs;

	tfidf t_obj;

	//map of idf for the search query
	map<string,double>searchQueryToIDF;

	//populates the map containing all the search queries to their idf
	void populateSearchQueryToIDFMap(vector<string>searchQuery);

	//populates the map containing TF-IDF for all the search queries
	std::multimap<double,string> populateDocURLToIDFMap(vector<string> searchQuery);

	//map containing TF-IDF for all the search queries for all documents.
	//maps tfidf to urlPath

public:

	//constructor of the class
	RankingEngine(int docCount, tfidf t_obj);

	//destructor of the class
	~RankingEngine();

	//ranks all the documents with the search query
	void rankDocURLS(vector<string>searchQuery, vector<string>&rankedURLs);
};