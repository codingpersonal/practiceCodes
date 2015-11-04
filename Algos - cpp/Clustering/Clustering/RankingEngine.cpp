#include"RankingEngine.h"

RankingEngine::RankingEngine(int docCount, tfidf obj):numOfDocs(docCount),t_obj(obj) {
}

RankingEngine::~RankingEngine(){
}

void RankingEngine::rankDocURLS(vector<string>searchQuery, vector<string>&rankedURLs){
	populateSearchQueryToIDFMap(searchQuery);
	multimap<double,string> docToTFIDF = populateDocURLToIDFMap(searchQuery);

	multimap<double,string>::const_iterator it = docToTFIDF.begin();
	while(it != docToTFIDF.end()){
		cout<<it->second << " : " << it->first<<"\n";
		rankedURLs.push_back(it->second);
		it++;
	}
}

void RankingEngine::populateSearchQueryToIDFMap(vector<string>searchQuery){
	vector<string>::const_iterator it = searchQuery.begin();
	while(it != searchQuery.end()){
		t_obj.generateIdf(*it,searchQueryToIDF);
		it++;
	}
}

multimap<double,string> RankingEngine::populateDocURLToIDFMap(vector<string>searchQuery){
	//iterate all over the documents
	multimap<double,string> docToTFIDF;

	for(int index = 0; index < numOfDocs; index++){
		mapsi tempMap = t_obj.wordToFreq[index];	//using public member of other class here
		docInfo obj = t_obj.IdToDocInfo[index];								//using struct here of other class
		double weight = 0;
		bool flag = false;
		//iterate over every search query
		for(int id = 0; id < searchQuery.size(); id++){
			string word = searchQuery[id];
			double idf = searchQueryToIDF[word];
			double tf = tempMap[word];

			//a flag is placed to check if all the search queries are missing from the current document
			if(tf)
				flag = true;

			weight = weight + (idf * tf);
		}

		//check if flag is still false then we need to remove this document from the rankedURLs
		if(flag){
			//fill up the map for each document
			docToTFIDF.insert ( std::pair<double,string>(weight, obj.docURL));
		}
	}

	return docToTFIDF;
}

