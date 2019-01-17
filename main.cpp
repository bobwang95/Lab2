#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {

// random numbers
    srand(time(NULL));
    int rang;
    rang = (rand()%(1024-512+1))+512;

    const int loops{rang};
    const int lowerbound{50};
    const int upperbound{90};
    default_random_engine generator(time(0));
    uniform_real_distribution<double>
            distribution(lowerbound, upperbound);

// store to file

    ofstream f{"Readings.txt"};
    f<< fixed <<setprecision(3);

    for (int i = 0; i <= loops; ++i) {
        double my_random = distribution(generator);
        f << i << " ";
        f << my_random << '\n';

    }
    f.close();

    ifstream fs("Readings.txt");
    string str{""};
    int total{0};
    int index{0};
    double sum {0};
    double number{0.0};
    double arr[loops+1];
    while(getline(fs,str)){
        total++;
        stringstream ss(str);
        if (ss>>index>>number){
            arr[index] = number;
            sum += number;
        }
    }
    fs.close();
    sort(arr, arr+total);
    cout << "There are " << total <<" readings in the file."<< endl;
    cout << "The average reading is " << fixed << setprecision(3) << sum/total << endl;
    cout << "The lowest reading is " << arr[0] << endl;
    cout << "The highest reading " << arr[total-1] << endl;
    if(total % 2 != 0) {
        cout << "The median reading is " << arr[total/2 + 1] << endl;
    } else {
        double middle1 {arr[total/2]};
        double middle2 {arr[total/2+1]};
        double median = (middle1 + middle2)/2;
        cout << "The median reading is " << median << endl;
    }

    return 0;

}