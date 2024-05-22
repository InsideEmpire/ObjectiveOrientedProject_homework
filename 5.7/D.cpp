#include <iostream>
using namespace std;
class Process
{
private:
    int PID;
    string username;
    char RW;
    int time;
    static int totalReaderTime;
    static int totalWriterTime;
    static int longestWriterTime;
    static int mustInQueueReader;
public:

    Process(){}
    Process(int P, string U, char R, int T):PID(P),username(U),RW(R),time(T){}
    void display()
    {
        cout << "PID-" << PID << " User-" << username << " as a " << (RW == 'R' ? "reader used time-" : "writer used time-") << time << endl;
    }
    static void countTotalReaderTime(Process p[], int n)
    {
        
        for (int i = 0; i < n; i++)
        {
            if (p[i].RW == 'R')
            {
                totalReaderTime += p[i].time;
            }
            
        }
    }
    static void countTotalWriterTime(Process p[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].RW == 'W')
            {
                totalWriterTime += p[i].time;
            }
            
        }
    }
    static void countlongestWriterTime(Process p[], int n)
    {
        
        for (int i = 0; i < n; i++)
        {
            if (longestWriterTime < p[i].time)
        {
            longestWriterTime = p[i].time;
        }
            
        }
    }
    static void countmustInQueueReader(Process p[], int n)
    {
        int queue[n];
        if (p[0].RW == 'R')
        {
            queue[0] = 1;
        }
        
        for (int i = 1; i < n; i++)
        {
            queue[i] = 0;
            if (p[i].RW == 'R')
            {
                queue[i] = queue[i - 1] + 1;
            }
            
        }
        
        for (int i = 0; i < n; i++)
        {
            if (mustInQueueReader < queue[i])
            {
                mustInQueueReader = queue[i];
            }
            
        }
        
    }
    static int gettotalReaderTime(){return totalReaderTime;}
    static int getmustInQueueReader(){return mustInQueueReader;}
    static int gettotalWriterTime(){return totalWriterTime;}
    static int getlongestWriterTime(){return longestWriterTime;}
};
int Process::totalReaderTime = 0;
int Process::totalWriterTime = 0;
int Process::longestWriterTime = 0;
int Process::mustInQueueReader = 0;
int main()
{
    Process *p = new Process[10001];
    int PID;
    string username;
    char RW;
    int time;
    cin >> PID;
    int num = 0;
    while (PID != 0)
    {
        cin >> username >> RW >> time;
        p[num++] = Process(PID, username, RW, time);
        p[num - 1].display();
        //
        cin >> PID;
    }
    cout << endl;
    Process::countTotalReaderTime(p, num);
    Process::countTotalWriterTime(p, num);
    Process::countlongestWriterTime(p, num);
    Process::countmustInQueueReader(p, num);
    cout << "Total readers' time-" << Process::gettotalReaderTime() << " with maximum " << Process::getmustInQueueReader() << " readers at the same time\n";
    cout << "Total writers' time-" << Process::gettotalWriterTime() << " with maximum writing time " << Process::getlongestWriterTime() << "\n";
}