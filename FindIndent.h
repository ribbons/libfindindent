/*
 * Copyright © 2014-2015 Matt Robinson
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <string>
#include <vector>

class FindIndent
{
private:
	int minIndent, maxIndent, maxAnalyseLines;
	int lines, thresholdLines, tabLines, spaceLines;
	int prevLineInd;
	std::vector<int> diffCounts;

public:
	typedef enum { tsUnknown, tsTabs, tsSpaces } TabStyle;

	static const int indUnknown;

	FindIndent();

	bool ProcessLine(const char* buffer, int length);

	bool ProcessLine(const std::string text)
	{
		return ProcessLine(text.c_str(), text.length());
	}

	int getMinIndent();

	void setMinIndent(int min);

	int getMaxIndent();

	void setMaxIndent(int max);

	int getMaxAnalyseLines();

	void setMaxAnalyseLines(int max);

	TabStyle getTabStyle();

	int getIndentSize();
};
