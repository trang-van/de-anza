// Assignment #5
// Trang Van
// Code::Blocks on Windows 10

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct NBA_Team
{
    string name;
    string conference;
    string division;
    unsigned short wins;
    unsigned short losses;
    float pct;
};

const int ARRAY_SIZE = 30;

// Function Prototypes
void getTeamFile(string, NBA_Team []);
void parseScores(string, NBA_Team*);
void processScores (string, string, int, int, NBA_Team*);
int getTeamIndex(string, NBA_Team* );
float sortKey (NBA_Team*);
void swap(NBA_Team*[],int,int);
void sort(NBA_Team*, int);
void printOutput(NBA_Team*);


int main()
{
    const string teamFile = "NBA_Teams.txt";
    const string scoreFile = "NBA_Scores.txt";

    NBA_Team teams[ARRAY_SIZE];

    getTeamFile(teamFile,teams);
    parseScores(scoreFile, teams);
    sort(teams, ARRAY_SIZE);
    printOutput(teams);

    return 0;
}

void getTeamFile (string filename, NBA_Team teams[])
{
    ifstream finTeam (filename);

    //Check file for successful opening
    if (finTeam.fail())
    {
        cout << "Error! Cannot open: " << filename << endl;
        exit (1);
    }

    string conf, div, nam;                      //Temp to read into these
    string dummy;

    int count = 0;                                 // index into array

    for (int c =0; c < 2; c++)
    {
        finTeam >> conf;
        finTeam >> dummy;                                 //stores blank line

        for (int d = 0; d < 3; d++)                               //Process 3 divisions
        {
            finTeam >> div;
            getline(finTeam, dummy);
            for (int t=0; t < 5; t++)
            {
                getline(finTeam, nam);

                teams[count].name = nam;
                teams[count].conference = conf;
                teams[count].division = div;
                teams[count].wins = 0;
                teams[count].losses = 0;
                teams[count].pct = 0;

                count++;
            }
        }
    }
}

void printOutput (NBA_Team* teams)
{

    int count=0;

    for (int c =0; c < 2 ; c++)
    {
        cout << teams[count].conference << " Conference\n" << endl;

        for (int d =0; d < 3; d++)
        {
            cout << left << setw(10) << teams[count].division << " Division" <<setw(6);

            cout << right << "W" << setw(5) << "L" << setw(8) << "Pct" << endl;
            for (int t=0; t <5;t++)
            {
                 cout <<setw(23) << left << teams[count].name << right << setw(2) << teams[count].wins << setw(5) << teams[count].losses << setw(8);
                 cout << fixed << right << setprecision(3) << teams[count].pct<<endl;
                 count++;
            }
            cout << "\n";
        }

    }
}

void parseScores(string filename, NBA_Team* teams)
{
    ifstream finScores(filename);

    // Check file for successful opening
    if (finScores.fail())
    {
        cout << "Error! Cannot open: " << filename << endl;
        exit(1);
    }

    //Parse scores file
    string buf, t1, t2;
    string dummy;                                    //Content to ignore
    int t1Score=0, t2Score=0;
    size_t pos, pos2, pos3, pos4, pos5;

    while (!finScores.eof())
    {
        getline(finScores, buf);                    // Reads in first line to ignore
        while (getline (finScores, buf))
        {
            pos = buf.find(',');                    // Stores away first comma
            dummy = buf.substr(0,pos);

            pos2 = buf.find(',', pos+1);            // Stores away up to the next comma
            dummy += buf.substr(pos, pos2-pos);
            pos = pos2;

            //Get T1 Information
            pos3 = buf.find(',',pos+1);
            t1 = buf.substr(pos+1, pos3-(pos+1));

            pos4 = buf.find(',', pos3+1);
            t1Score = stoi(buf.substr(pos3+1, pos4-(pos3+1)));

            pos3 = pos4;

            //Get T2 Information
            pos4 = buf.find(',', pos3 + 1);
            t2 = buf.substr(pos3 + 1, pos4-(pos3+1));

            pos5 = buf.find(',', pos4+1);
            t2Score = stoi(buf.substr(pos4+1, pos5-(pos4+1)));

            pos4=pos5;

          // Store rest into dummy
            pos5 = buf.find("\n", pos4+1);
            dummy += buf.substr(pos4+1, pos5-(pos4+1));

            processScores(t1, t2, t1Score, t2Score, teams);
        }
    }
}

void processScores (string t1, string t2, int t1Score, int t2Score, NBA_Team* teams)
{
    int team1Pos = getTeamIndex(t1, teams);
    int team2Pos = getTeamIndex(t2, teams);


    if (t1Score > t2Score)
    {
        teams[team1Pos].wins++;
        teams[team2Pos].losses++;

    } else
    {
        teams[team2Pos].wins++;
        teams[team1Pos].losses++;
    }

    //Calculate Percents
    for (int i =0; i <ARRAY_SIZE; i++)
    {
        teams[i].pct = static_cast<float>(teams[i].wins)/(teams[i].wins + teams[i].losses);
    }
}

int getTeamIndex(string team, NBA_Team* teams)
{
    int index =0;

    while(index < ARRAY_SIZE)
    {
        if (strcmp(teams[index].name.c_str(), team.c_str())== 0)
        {
            return index;
        }

        index++;
    }

    return index;
}

//Sort by percentage by each division
void swap(NBA_Team* arr[],int minIndex,int i)
{
    NBA_Team* temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}

void sort(NBA_Team* teams, int size)
{
	int minIndex;

	for (int i = 0; i < size-1; i++)
	{
		minIndex =i;

		for (int j = i+1; j < size; j++)
		{
			if (sortKey(&teams[minIndex]) < sortKey(&teams[j]))
			{
				minIndex=j;
			}
			if (minIndex !=i)
			{
			    swap(teams[minIndex], teams[i]);
			}
		}
	}
}

float sortKey (NBA_Team* teams)
{
	int c = teams->conference[0];
	int d = teams->division[0];
	float p = teams->pct;
	return c * 100 + d + p;
}

