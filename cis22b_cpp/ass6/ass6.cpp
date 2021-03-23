// Assignment #6
// Trang Van
// Code::Blocks on Windows

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int numOfRecords =300;

class MutualFund
{
    private:
        string ticker;
        int date[numOfRecords];           // convert string to int to use
        float close[numOfRecords];       // current close

        //Data members for processing close[]
        float minClose;
        float maxClose;
        double avg50;        // average for 50 days
        double avg200;       // average for 200 days
        float pctGain;
        string recommend;

        //Functions to process close[]
        void processFunds(int*,float*);
        size_t searchForYearIndex (const int*, int, size_t) const;
        float findMin(int*,float*, int) const;
        float findMax(int*, float*, int) const;
        double findAvg(float*, int) const;
        float findPct(float);
        string giveRecommendation(float) const;

    public:
        void assignTicker(string t)
        {
            ticker = t;
        }
        void readHistoryFile(string);
        void report() const;
};

int main()
{
    MutualFund vbmfx;
    vbmfx.assignTicker("VBMFX");
    vbmfx.readHistoryFile("vbmfx.csv");
    vbmfx.report();

    MutualFund vtsmx;
    vtsmx.assignTicker("VTSMX");
    vtsmx.readHistoryFile("vtsmx.csv");
    vtsmx.report();
}

void MutualFund::readHistoryFile (string filename)
{
    ifstream fin(filename);
    string buffer, dummy;
    size_t pos, pos2, pos3, pos4, pos5, pos6;

    //Check for successful file opening
    if (!fin)
    {
        cout << "Error. Unable to open:" << filename << endl;
        exit (1);
    }

    // Ignore heading
    getline (fin, buffer);

    int count =0, i =0;

    while (i < numOfRecords && getline(fin, buffer))
    {
        if (!fin)
        {
            break;
        }
        if (buffer.size() < 1)
        {
            continue;
        }

        pos = buffer.find(',');                    // Stores away first comma
        string ds = buffer.substr(0,pos);

        //Convert date to int
        string mm,dd,yy;
        yy = ds.substr(2,2);
        mm = ds.substr(5,2);
        dd = ds.substr(8,2);

        date[i] = 10000 * stoi(yy) + 100 * stoi(mm) + stoi(dd);

        pos2 = buffer.find (',', pos + 1);
        dummy = buffer.substr(pos, pos2-pos);
        pos = pos2;

        pos3 = buffer.find(',',pos+1);
        dummy += buffer.substr(pos+1, pos3-(pos+1));
        pos = pos3;

        pos4 = buffer.find(',', pos+1);
        dummy += buffer.substr(pos+1, pos4-(pos+1));
        pos = pos4;

        pos5 = buffer.find(',', pos+1);

        close[i] = stof(buffer. substr (pos+1, pos5-(pos+1)));
        pos = pos5;

        // Store rest into dummy
        pos6 = buffer.find("\n", pos+1);
        dummy += buffer.substr(pos+1, pos6-(pos+1));

        i++;
        count++;                //NUMBER OF RECORDS READ
    }

    processFunds(date, close);

    fin.close();
    buffer.clear();
}

void MutualFund::processFunds(int* date, float*close)
{
    int yearAgo = date[numOfRecords-1]-10000;

    //Find index of yearAgo in date[]
    int index = searchForYearIndex(date, yearAgo, numOfRecords);

    minClose = findMin(date, close, index);
    maxClose = findMax(date, close, index);
    avg50 = findAvg(close, 50);
    avg200 = findAvg(close, 200);
    pctGain= findPct(avg200)*100;
    recommend= giveRecommendation(pctGain);

}

size_t MutualFund::searchForYearIndex (const int* date, int yearAgo, size_t size) const
{
    size_t index = 0;

    while (index < size && date[index] != yearAgo)
    {
        ++index;
    }

    if (index == size)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

float MutualFund::findMin(int* date, float* close, int i) const
{
    float minClose = close[i];

    for (int j=0; j < numOfRecords; j++)
    {
        if (date[j] > date[i] && date[j] < date[numOfRecords-1])
        {
            if (minClose > close[j])
            {
                minClose = close[j];
            }
        }
    }

    return minClose;
}

float MutualFund::findMax(int* date, float* close, int i) const
{
    float maxClose = close[i];

    for (int j=0; j < numOfRecords; j++)
    {
        if (date[j] > date[i] && date[j] < date[numOfRecords-1])
        {
            if (maxClose < close[j])
            {
                maxClose = close[j];
            }
        }
    }

    return maxClose;
}

double MutualFund::findAvg(float* close, int d) const
{
    double total=0;

    for(int i = numOfRecords-d; i < numOfRecords; i++)
    {
        total += close[i];
    }

    return total/d;
}

float MutualFund:: findPct(float avg)
{
    return (close[numOfRecords-1]-avg)/avg;
}

string MutualFund::giveRecommendation(float pct) const
{
    if (pct < -5)
    {
        return "Buy";
    } else if (pct > 5)
    {
        return "Sell";
    } else
    {
        return "Hold";
    }
}

void MutualFund::report()const
{
    cout << "Fund: " << ticker << endl;
    cout << "Analysis Date: " << ((date[numOfRecords-1]%1000)-(date[numOfRecords-1]%100))/100 << '/'<< (date[numOfRecords-1]%100)<< '/' << date[numOfRecords-1]/10000<< endl;
    cout << "Latest Close: $" << fixed << setprecision(2) << close[numOfRecords-1]<< endl;
    cout << "Minimum for the last year = $" << fixed << setprecision(2)<< minClose << endl;
    cout << "Maximum for the last year = $" << fixed<< setprecision(2) << maxClose << endl;
    cout << "50 day moving average = $"  << fixed << setprecision(2) <<avg50 << endl;
    cout << "200 day moving average = $" << fixed << setprecision(2) << avg200 << endl;
    cout << "% gain over 200 Day Moving Avg: " << fixed << setprecision(1) << pctGain << '%' << endl;
    cout << "Recommendation: " << recommend << endl << "\n";
}

