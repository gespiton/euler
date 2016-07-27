#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream out("ha");
    int sunday = 0;
    int ite = 1;
    int year = 1900;
    int totalday = 0;
    bool isleap = false;
    for (; year <= 2000; ++year)
    {
        isleap = (year % 4 == 0&&(year%100!=0||year%400==0));
        if (isleap);
        for (int month = 1; month <= 12; ++month)
        {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                totalday = 31;
                break;
            case 2:
                if (isleap)
                {
                    totalday = 29;
                    break;
                }
                else
                {
                    totalday = 28;
                    break;
                }
            default:
                totalday = 30;
                break;
            }
            for (int i = 1; i <= totalday; ++i)
            {
				out <<year<<"  "<< month<<"  "<<i << "  " << ite << endl;
                if (i == 1 && ite == 7&&year!=1900)
                    ++sunday;
                if (ite == 7)
                    ite = 1;
                else
                    ++ite;
            }

        }
    }
    cout << sunday;
    system("pause");
}
