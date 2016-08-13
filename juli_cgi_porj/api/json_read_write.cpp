#include "json_read_write.h"

JsonReadWrite::JsonReadWrite()
{
}

JsonReadWrite::~JsonReadWrite()
{}


bool JsonReadWrite::packObjectToJsonValue(const vector<string>& vecKeys
				, const vector<string>& vecValues
				, Json::Value& jvOutput)
{
		bool bRet = false;
		if (vecKeys.empty()
						|| vecValues.empty()
						|| !jvOutput.empty()
						|| vecKeys.size() != vecValues.size())
		{
				return bRet;
		}

		int nObjsCount = (int)vecKeys.size();
		Json::Value jvTemp;
		for (int i = 0; i < nObjsCount; ++i)
		{
				jvTemp[vecKeys[i].c_str()] = vecValues[i].c_str();
		}
		jvOutput = jvTemp;

		bRet = true;
		return bRet;
}	

bool JsonReadWrite::packStringListToJsonString(const vector< vector<string> > &vecStringList
				, const vector<string> &vecKeys
				, string &strOutputJsonString)
{
		bool bRet = false;

		if (vecStringList[0].size() != vecKeys.size()
						|| vecKeys.empty())
		{
				return bRet;
		}

		Json::Value jvRoot;
		//JsonReadWrite jrwObj;
		Json::FastWriter jfwObj;
		for (int i = 0; i < (int)vecStringList.size(); ++i)
		{
				vector<string> vecValues = vecStringList[i];
				Json::Value jvTemp;
				bool bPackRet = this->packObjectToJsonValue(vecKeys , vecValues , jvTemp);
				if (!bPackRet) break;

				jvRoot.append(jvTemp);
		}

		//转换为json字符串
		strOutputJsonString = jfwObj.write(jvRoot);
		bRet = true;
		return bRet;
}

bool  JsonReadWrite::parseJsonStringToStringList(const string& strInputJson
				, const vector<string> &vecKeys
				, vector< vector<string> > &vecOutputStringList)
{
		bool bRet = false;
		if (strInputJson.empty()
						|| vecKeys.empty())
		{
				return bRet;
		}
		//vecOutputStringList.clear();

		Json::Value jvParseRoot;
		Json::Reader jrObj;
		if (!jrObj.parse(strInputJson , jvParseRoot)) return bRet;

		int nJvalueSize = jvParseRoot.size();
		if (jvParseRoot.isArray())
		{
				for (int i = 0; i < nJvalueSize; ++i)
				{
						vector<string> vecTemp(vecKeys.size());
						for (int j = 0; j < (int)vecKeys.size(); ++j)
						{
								vecTemp[j] = jvParseRoot[i][vecKeys[j].c_str()].asString();	
						}
						vecOutputStringList.push_back(vecTemp);
				}
		}
		else if (jvParseRoot.isObject())
		{
			if (nJvalueSize != (int)vecKeys.size()) return bRet;
			vector<string> vecTemp(vecKeys.size());
			for (int i = 0; i < vecKeys.size(); ++i)
			{
				vecTemp[i] = jvParseRoot[vecKeys[i].c_str()].asString();
			}
			vecOutputStringList.push_back(vecTemp);
		}

		bRet = true;
		return bRet;

}
