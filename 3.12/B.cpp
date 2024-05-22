#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i = 1;i <= t;i++)
    {
        int num;
        char letter;


        cin >> letter >> num;
        if(letter == 'I'){

            int *p = new int[num];
            int sum = 0;
            for(int j = 0;j < num;j++)
            {
                cin >> *(p + j);
            }
            for(int j = 0;j < num;j++)
            {
                sum += *(p + j);
            }
            cout << sum / num << endl;
        }
        if(letter == 'C'){
            char *p = new char[num];
            int tem = 0;
            for(int j = 0;j < num;j++)
            {
                cin >> *(p + j);
            }
            for(int j = 0;j < num;j++)
            {
                if (*(p + tem) < *(p + j))
                {
                    tem = j;
                }
                
            }
            cout << *(p + tem) << endl;
        }
        if(letter == 'F'){
            float *p = new float[num];
            int tem = 0;
            for(int j = 0;j < num;j++)
            {
                cin >> *(p + j);
            }
            for(int j = 0;j < num;j++)
            {
                if (*(p + tem) > *(p + j))
                {
                    tem = j;
                }
                
            }
            cout << *(p + tem) << endl;
        }
        
    }
}