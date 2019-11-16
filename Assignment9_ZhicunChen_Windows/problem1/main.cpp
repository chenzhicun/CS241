#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);
const string GENES = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890,.-;:_!\\\"#%&/()=?@${[]}";
const string TARGET = "Hello, World! 19/11/09";
const int num_gene = 150;
const int epoch_limit = 5001;
const double prob_mutution=0.1;
const double prob_crossover=0.5;

void generate(vector<string> &generation) {
    for (int i = 0; i < num_gene; i++) {
        string tmp = GENES;
        shuffle(tmp.begin(), tmp.end(), default_random_engine(generator()));
        tmp = tmp.substr(0, TARGET.length());
        generation.push_back(tmp);
    }
}

void selection(vector<string> &generation,int num) {
    int max = -1;
    int max_p = 0;
    vector<double> prob;
    int total = 0;
    for (int i = 0; i < num_gene; i++) {
        int value = 0;
        for (int j = 0; j < generation[i].length(); j++) {
            if (generation[i][j] == TARGET[j])
                ++value;
        }
        if (value > max) {
            max = value;
            max_p = i;
        }
        prob.push_back(value);
        total += value;
    }
    cout << "Generation: "<<num<<" String: "<<generation[max_p]<<endl;
    if(generation[max_p]==TARGET) exit(0);
    for (int i = 0; i < num_gene; i++) {
        prob[i] = prob[i] / (double) total;
    }
    uniform_real_distribution<double> u(0, 1);
    vector<string> res;
    for (int i = 0; i < num_gene; i++) {
        double tmp = u(generator);
        double prob_total = 0;
        for (int j = 0; j < num_gene; j++) {
            prob_total += prob[j];
            if (prob_total >= tmp) {
                res.push_back(generation[j]);
                break;
            }
        }
    }
    generation = res;
}

void mutution(vector<string> &generation) {
    for(int i=0;i<num_gene;i++)
    {
        uniform_real_distribution<double> u(0,1);
        if(u(generator)<prob_mutution)
        {
            generation[i][generator()%generation[i].length()]=GENES[generator()%GENES.length()];
        }
    }
}

void crossover(vector<string> &generation) {
    shuffle(generation.begin(),generation.end(),generator);
    for(int i=0;i<num_gene-1;i+=2)
    {
        int start = generator() % generation[i].length();
        int end = generator() % generation[i].length();
        if(start>end)
            swap(start,end);
        for (int j = start; j < end; j++) {
            swap(generation[i][j], generation[i + 1][j]);
        }
    }
}

int main() {
    vector<string> generation;
    generate(generation);
    for (int i = 0; i < 5000; i++) {
        selection(generation,i);
        crossover(generation);
        mutution(generation);
    }
}