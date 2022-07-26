// 5 players ABCDE being scored by 5 different judges.
// The final score is the average of the non-extreme scores of the judges.
// The extreme scores are the scores of the minimum and maximum scores.

#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <algorithm>

class Player
{
public:
    string m_name;
    int m_score;
    deque<int> m_scoreList;

public:

    Player(){
        deque<int> m_scoreList;
    }

    Player(string name, int score)
    {
        m_name = name;
        m_score = score;
        deque<int> m_scoreList;
    }

    string getName()
    {
        return m_name;
    }

    int getScore()
    {
        return m_score;
    }
};

ostream& operator<<(ostream& os, const Player& player)
{
    // os << "name: " << player.getName() << " score: " << player.getScore(); // constant can't be changed
    os << "name: " << player.m_name << " score: " << player.m_score;
    return os;
}

template <class T>
void printVector(const T v)
{
    for (typename T::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;

        // alternative
        // cout << "name: " << *it.getName() << " score: " << *it.getScore() << endl; // error: no member named 'getName' in 'std::__wrap_iter<Player *>'
        // debug
        // cout << typeid(*it).name() << endl; // 6Player
        // cout << typeid(it).name() << endl; // NSt3__111__wrap_iterIP6PlayerEE
        // cout << "name: " << (*it).getName() << " score: " << (*it).getScore() << endl; // no error
    }
    cout << endl;
}

template <class T>
void printScoreList(const vector<T> &v)
{
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*it).getName() << endl;
        cout << "Score list: ";
        for (deque<int>::const_iterator itt = (*it).m_scoreList.begin(); itt != (*it).m_scoreList.end(); itt++)
        {
            cout << (*itt) << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
void printAllList(const vector<T> &v)
{
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
        cout << "Score list: ";
        for (deque<int>::const_iterator itt = (*it).m_scoreList.begin(); itt != (*it).m_scoreList.end(); itt++)
        {
            cout << (*itt) << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
void scoreVector(vector<T> &v)
{
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (int i=0;i<10;i++)
        {
            (*it).m_scoreList.push_back(rand()%41+60); // 60 to 100
        }
    }
}

template <class T>
void calculteScore(vector<T> &v)
{
    for (typename vector<T>::iterator it = v.begin(); it != v.end(); it++)
    {
        sort((*it).m_scoreList.begin(), (*it).m_scoreList.end());
        (*it).m_scoreList.pop_back();
        (*it).m_scoreList.pop_front();

        int sum = 0;
        for (deque<int>::iterator itt = (*it).m_scoreList.begin(); itt != (*it).m_scoreList.end(); itt++)
        {
            sum += (*itt);
        }
        // (*it).m_score = sum / ((*it).m_scoreList.end()-(*it).m_scoreList.begin()); // same
        (*it).m_score = sum / (*it).m_scoreList.size();
    }
}

int main()
{   
    // init players with name and score = 0
    vector<Player> playerList;
    string base_name = "player_";
    for (int i=0; i<5; i++)
    {
        playerList.push_back(Player(base_name+(char)(65+i), 0));
    }
    // printVector(playerList);

    // scoring players
    cout << "<<<<<  scoring players  >>>>>" << endl;
    scoreVector(playerList);
    // printScoreList(playerList);
    printAllList(playerList);

    // calculate score
    cout << "<<<<<  calculating score  >>>>" << endl;
    calculteScore(playerList);
    printAllList(playerList);
}
