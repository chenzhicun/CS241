#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>
#include <cmath>

using namespace std;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

const int num_gene = 1000;
const int epoch_limit = 5001;
const double prob_mutution=0.1;
const double prob_crossover=0.5;
const double terminate_condition=0.001;
const double pi=3.14159;

class Populatoin{
private:
    vector<vector<bool>> chrom;
    vector<double> de_chrom;
    vector<double> prob;
    double func(double x)
    {
        double tmp=x*sin(x);
        /*tmp=-tmp;
        if(tmp<0)
            tmp=0;
        return tmp;*/
        tmp=1/((tmp+15)*(tmp+15));
        return tmp;
    }
    bool terminate(int max_p){
        double average=0;
        for(int i=0;i<num_gene;i++)
            average+=prob[i];
        average=average/num_gene;
        if((prob[max_p]-average)<terminate_condition)
            return true;
        else
            return false;
    }
public:
    Populatoin(){};
    void deCode(){
        for(int i=0;i<num_gene;i++){
            double tmp=0;
            int factor=1;
            for(int j=0;j<16;j++){
                tmp+=factor*chrom[i][j];
                factor*=2;
            }
            de_chrom[i]=((16*tmp)/pow(2,16))-1;
        }
    }
    void crossOver(){
        shuffle(chrom.begin(),chrom.end(),generator);
        for(int i=0;i<(num_gene-1)*prob_crossover;i+=2)
        {
            int start=generator() % chrom[i].size();
            int end=generator()%chrom[i].size();
            if(start>end)
                swap(start,end);
            for(int j=start;j<end;j++)
                swap(chrom[i][j],chrom[i+1][j]);
        }
    }
    void mutution(){
        for(int i=0;i<num_gene;i++){
            uniform_real_distribution<double> u(0,1);
            if(u(generator)<prob_mutution)
                chrom[i][generator()%chrom[i].size()]=generator()%2;
        }
    }
    void seletion(int num){
        double max=-1;
        int max_p=0;
        double total=0;
        for(int i=0;i<num_gene;i++){
            double value=func(de_chrom[i]);
            if (value>max)
            {
                max=value;
                max_p=i;
            }
            prob[i]=value;
            total+=value;
        }
        cout<<"Generation: "<<num<<" max_x: "<<de_chrom[max_p]<<endl;
        if(terminate(max_p))
            exit(0);
        for(int i=0;i<num_gene;i++)
            prob[i]=prob[i]/(double)total;
        uniform_real_distribution<double> u(0,1);
        //有可能存在一点问题，因为这个函数导致极值点的取值没有被很强化？轮盘赌的概率可能不一定集中在极值点附近？
        vector<vector<bool>> res;
        for(int i=0;i<num_gene;i++){
            double tmp=u(generator);
            double prob_total=0;
            for(int j=0;j<num_gene;j++){
                prob_total+=prob[j];
                if(prob_total>=tmp){
                    res.push_back(chrom[j]);
                    break;
                }
            }
        }
        chrom=res;
    }
    void generate(){
        uniform_int_distribution<int> u(0,1);
        for(int i=0;i<num_gene;i++)
        {
            vector<bool> tmp;
            tmp.clear();
            for(int j=0;j<16;j++)
            {
                tmp.push_back(u(generator));
            }
            chrom.push_back(tmp);
            de_chrom.push_back(0);
            prob.push_back(0);
        }
    }
};


int main()
{
    Populatoin populatoin;
    populatoin.generate();
    for(int i=0;i<epoch_limit;i++){
        populatoin.deCode();
        populatoin.seletion(i);
        populatoin.crossOver();
        populatoin.mutution();
    }
    return 0;
}