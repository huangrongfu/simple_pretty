#include <iostream>
//#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
//#include <utility>
//#include <unistd.h>
using namespace std;

void fixTab(string& str, int tabs) {
	for (int i=1; i<=tabs; ++i) {
		str += "\t";
	}
}

std::vector<int> leftT;
int jsonPretty(const string& oriStr, string& outStr) {

	for (int i=0; i<oriStr.length(); ++i) {

		outStr += oriStr[i];

		if (oriStr[i] == '\0') {
			break;
		}

		if (oriStr[i] == '{') {

			leftT.push_back(i);
			if (oriStr[i+1] != '}') {
				outStr += "\n";
				fixTab(outStr, leftT.size());
			}
		}else if (oriStr[i] == '}') {

			if (!leftT.empty()) {
				leftT.pop_back();
			}

			if ( i-1 >= 0 && oriStr[i-1] != '{') {
				outStr.pop_back();
				outStr += "\n";
				fixTab(outStr, leftT.size());
				outStr += "}";
			}
		}else if (oriStr[i] == ',') {
			outStr += '\n';
			fixTab(outStr, leftT.size());
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	if (argc <= 1) {
		return 0;
	}

	if (argv[1] != NULL) {

		string oriStr(argv[1]);
		string outStr;

		jsonPretty(oriStr, outStr);

		cout << "there are outStr:\n" << outStr << endl;
	}else {
		cout << "usage:[oriStr]" << endl;
	}

	cout << "\nFinish." << endl;
	return 0;
}
