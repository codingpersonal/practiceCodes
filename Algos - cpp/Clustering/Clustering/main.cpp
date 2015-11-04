/*This program reads from user a search query, say Tennis Ball
It then searches those two words from 5 documents and give their ranking based on the concept of tfidf.

http://www.tfidf.com/

Limitations: While searching the search query, it will treat plurals as separate words.
If say a document has "balls" rather than "ball", it will treat these two words differently.
*/
using namespace std;

#include<iostream>
#include"RankingEngine.h"
#include<string>

int main()
{
	//cout<<(unsigned char)"–";
	const int numOfDocs = 7;
	string docName[numOfDocs] = {"Wikipedia.txt","HealthAndFitness.txt","HealthyEating.txt","LiveStrong.txt","HealthyLiving.txt","leadership.txt","LeaderWiki.txt"};
	string fileName;
	string word;

	map<string,double>outMap;
	docInfo outURLInfo;

	vector<mapsi>wordToFreq;
	mapsi wordToAllDocumentFreqMap;
	map<int,docInfo>IdToDocInfo;

	tfidf t_obj(numOfDocs);

	for(int index = 0; index < 7; index++){
		fileName = "E:\\Learning\\C++\\Clustering\\InputFiles\\" + docName[index];
		URLProcessor p_obj(fileName);

		p_obj.generateNormalizedWordFrequency(outMap,outURLInfo,wordToAllDocumentFreqMap);
		t_obj.addURLInfo(outMap,outURLInfo, index);
	}

	//pre-processing done till finding the normalised frequency

	t_obj.computeTfidfForAllWords(wordToAllDocumentFreqMap);
	t_obj.printIdfMap();
	t_obj.printTfidfMap();

	return 0;
}