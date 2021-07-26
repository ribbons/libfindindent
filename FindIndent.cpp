/*
 * Copyright © 2014-2015 Matt Robinson
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <stdlib.h>
#include "FindIndent.h"

const int FindIndent::indUnknown = 0;

FindIndent::FindIndent() :
    minIndent(2),
    maxIndent(8),
    maxAnalyseLines(500),
    lines(0),
    thresholdLines(0),
    tabLines(0),
    spaceLines(0),
    prevLineInd(0),
    diffCounts(maxIndent - minIndent + 1)
{}

bool FindIndent::ProcessLine(const char* buffer, int length)
{
    bool tabs = false;
    int spaces = 0;
    bool skip = false;

    while(length > 0)
    {
        switch(buffer[length - 1])
        {
            case '\r':
            case '\n':
                length--;
                break;

            default:
                goto ENDTRIM;
        }
    }

ENDTRIM:

    for(int pos = 0; pos < length; pos++)
    {
        switch(buffer[pos])
        {
            case '\t':
                tabs = true;

                if(spaces > 0)
                {
                    skip = true;
                    goto EOL;
                }

                break;
            case ' ':
                spaces++;

                if(tabs)
                {
                    skip = true;
                    goto EOL;
                }

                break;
            case '*':
                skip = true;
                goto EOL;

            default:
                goto EOL;
        }
    }

EOL:

    if(!skip)
    {
        if(tabs)
        {
            tabLines++;
            thresholdLines++;
        }
        else
        {
            if(spaces > 0)
            {
                spaceLines++;
            }

            if(length > 0)
            {
                int difference = abs(spaces - prevLineInd);
                prevLineInd = spaces;

                if(difference >= minIndent && difference <= maxIndent)
                {
                    diffCounts[difference - minIndent]++;
                    thresholdLines++;
                }
            }
        }
    }

    return ++lines < maxAnalyseLines;
}

int FindIndent::getMinIndent()
{
    return minIndent;
}

void FindIndent::setMinIndent(int min)
{
    minIndent = min;
    diffCounts.resize(maxIndent - min + 1);
}

int FindIndent::getMaxIndent()
{
    return maxIndent;
}

void FindIndent::setMaxIndent(int max)
{
    maxIndent = max;
    diffCounts.resize(max - minIndent + 1);
}

int FindIndent::getMaxAnalyseLines()
{
    return maxAnalyseLines;
}

void FindIndent::setMaxAnalyseLines(int max)
{
    maxAnalyseLines = max;
}

FindIndent::TabStyle FindIndent::getTabStyle()
{
    if(tabLines > spaceLines)
    {
        return tsTabs;
    }
    else if(spaceLines > tabLines)
    {
        return tsSpaces;
    }

    return tsUnknown;
}

int FindIndent::getIndentSize()
{
    int maxPos = indUnknown;
    int maxVal = 0;

    for(unsigned int i = 0; i < diffCounts.size(); i++)
    {
        if(diffCounts[i] > maxVal && diffCounts[i] > thresholdLines / 10)
        {
            maxPos = i + minIndent;
            maxVal = diffCounts[i];
        }
    }

    return maxPos;
}
