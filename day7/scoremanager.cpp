#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
template <typename t>
class scoremanager{
    private:
    vector<t> scores;
    public:
    void addscore(t score){
        scores.push_back(score);
    }   
    t getaverage() const{
        if (scores.empty()) return t();
        t sum = 0;
        for(t s : scores)sum += s;
        return sum / scores.size();
    }
    t gethigest(){
        return *max_element(scores.begin(),scores.end());
    }
    t getlowest(){
        return *min_element(scores.begin(),scores.end());
    }
    void displayall(){
        cout<<"scores:";
        for(t s : scores)cout<<s<<" ";
        cout<<endl;
    }
    int getcount(){return scores.size();
    }
};
    int main(){
        scoremanager<int> mathscores;
        mathscores.addscore(85);
        mathscores.addscore(92);
        mathscores.addscore(78);
        mathscores.addscore(95);
        mathscores.addscore(88);
        cout<<"===math scores(int)==="<<endl;
        mathscores.displayall();
        cout<<"count:"<<mathscores.getcount()<<endl;
        cout<<"average:"<<mathscores.getaverage()<<endl;
        cout<<"highest:"<<mathscores.gethigest()<<endl;
        cout<<"lowest:"<<mathscores.getlowest()<<endl;
        scoremanager<double>sciencescores;
        sciencescores.addscore(88.5);
        sciencescores.addscore(91.2);
        sciencescores.addscore(76.8);
        cout<<"===science scores(double)==="<<endl;
        sciencescores.displayall();
        cout<<"average:"<<sciencescores.getaverage()<<endl;
        return 0;
    }
    