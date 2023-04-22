#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
int fromto[101],dist[101],dotarl[101];

/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */

int BFS(int v){
    queue<pair<int,int>> que;
    que.push({1,0});
    while (!que.empty()){
        
        pair<int,int> fr=que.front();
        que.pop();
        
        if(fr.first==100){
            return fr.second;
        }
        
        for (int i=fr.first+1; i<fr.first+7 && i<101; i++){
            if (!dotarl[i]){
                dotarl[i]=1;
                int k=i;
                if (fromto[k]!=-1){
                    k=fromto[k];
                    dotarl[k]=1;
                }
                que.push(make_pair(k,fr.second+1));
                
            }
        }
        
    }
    return -1;
}

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    memset(fromto, -1, sizeof(fromto));
    memset(dotarl, 0, sizeof(dotarl));
    int a,b;
    for (int i=0;i<ladders.size();i++){
        a=ladders[i][0];
        b=ladders[i][1];
        cerr<<a<<" "<<b<<endl;
        fromto[a]=b;
    }
    for (int i=0;i<snakes.size();i++){
        a=snakes[i][0];
        b=snakes[i][1];
        fromto[a]=b;
    }
    //memset(vis, 0, sizeof(vis));
    for(int i=0;i<101;i++){
        dist[i]=2147483647;
    }
    dist[1]=0;
    dotarl[1]=1;
    return BFS(1);
    /*if (dotarl==1)
        return dist[100];
    else
        return -1;
*/}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> ladders(n);

        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            string ladders_row_temp_temp;
            getline(cin, ladders_row_temp_temp);

            vector<string> ladders_row_temp = split(rtrim(ladders_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int ladders_row_item = stoi(ladders_row_temp[j]);

                ladders[i][j] = ladders_row_item;
            }
        }

        string m_temp;
        getline(cin, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        vector<vector<int>> snakes(m);

        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            string snakes_row_temp_temp;
            getline(cin, snakes_row_temp_temp);

            vector<string> snakes_row_temp = split(rtrim(snakes_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int snakes_row_item = stoi(snakes_row_temp[j]);

                snakes[i][j] = snakes_row_item;
            }
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

