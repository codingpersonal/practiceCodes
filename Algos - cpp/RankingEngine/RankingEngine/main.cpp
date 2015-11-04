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
	const int numOfDocs = 5;
	string docName[numOfDocs] = {"Wikipedia.txt","BallWiki.txt","LiveStrong.txt","TennisExpress.txt","TennisNews.txt"};
	string fileName;
	string word;

	map<string,float>outMap;
	docInfo outURLInfo;

	vector<mapsi>wordToFreq;

	map<int,docInfo>IdToDocInfo;

	tfidf t_obj(numOfDocs);

	for(int index = 0; index < 5; index++){
		fileName = "E:\\Learning\\C++\\RankingEngine\\InputFiles\\" + docName[index];
		URLProcessor p_obj(fileName);

		p_obj.generateNormalizedWordFrequency(outMap,outURLInfo);
		t_obj.addURLInfo(outMap,outURLInfo, index);
	}

	//pre-processing done

	//hardcoded to search for tennis ball
	const int count = 2;
	string search[count] = {"tennis","ball"};

	vector<string> searchQuery;
	vector<string>rankedURLs;

	for(int index = 0; index < count; index++){
		searchQuery.push_back(search[index]);
	}

	RankingEngine r_obj(numOfDocs,t_obj);
	r_obj.rankDocURLS(searchQuery,rankedURLs);

	//printing the output vector here
	for(int index = 0; index < rankedURLs.size(); index++){
		//cout<<rankedURLs[index]<<"\n";
	}

	return 0;
}