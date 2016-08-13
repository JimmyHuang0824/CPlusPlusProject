#ifndef _JSON_READ_WRITE_H
#define _JSON_READ_WRITE_H

#include <json/json.h>
#include <string>
#include <vector>

using namespace std;

class JsonReadWrite
{
	public://constructor
		JsonReadWrite();
		~JsonReadWrite();

	public://interface
		bool packObjectToJsonValue(const vector<string>& vecKeys
									, const vector<string>& vecValues
									, Json::Value& jvOutput);	
		bool packStringListToJsonString(const vector< vector<string> > &vecStringList
									, const vector<string> &vecKeys
									, string &strOutputJsonString);
		bool parseJsonStringToStringList(const string& strInputJson
									, const vector<string> &vecKeys
									, vector< vector<string> > &vecOutputStringList);
};
#endif
