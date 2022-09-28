#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

long load_truck[100]; // trọng tải của truck
long load_drone[100]; // trọng tải của drone
double time_truck[100]; // time đã đi của truck
double time_drone[100]; // time đã đi của drone
double time_drone_n[100][100]; // time đã đi của drone
long delivered[100]; // lượng hàng đã giao cho khách

long n, K=1, M=1;
int truck_speed=40, drone_speed=60;
int route; // hành trình thứ route của drone
int drone_duration=30, work_time=30;   // time giới hạn d - drone bay 1 vòng, D chung
int m_truck=1500, m_drone=40; // trọng tải giới hạn
int low[100]; // yêu cầu tối thiểu
int upper[100]; // yêu cầu tối đa
int weight[100]; // lợi nhuận

int x, y; // toạ độ
vector<pair<double, double>> index_customer;  // toạ độ khách hàng
vector<vector<double>> matrix_dist(n, vector<double>(n));     // time giữa các khách hàng

int truck[100][100]; // lượng hàng truck i giao cho khách j
int drone[100][100][100]; // lượng hàng drone i trong hành trình j giao cho khách k

vector<vector<string>> param;
typedef struct __fields{
    int K; // number_truck
    int M; // number_drone
    int truck_speed, drone_speed;
    int drone_duration, work_time; // time giới hạn d - drone bay 1 vòng, D chung
    int truck_capacity, drone_capacity;  
}__fields;
map<string, __fields> params;  

void read_test(string file_name){
    string fname = "./test/";
    fname += file_name;

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open()){
       while(getline(file, line)){
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
            row.push_back(word);
            content.push_back(row);
            }
        }
    else
        cout<<"Could not open the file\n";
    
    n = content.size();
    cout << content[1][1];
    for (int i = 1; i < n; i++)
    {
        string str = content[i][1];
        __fields fields;
        // fields.K = stoi(content[i][3]);
        // fields.M = stoi(content[i][4]);
        // fields.work_time = stoi(content[i][5]);
        // fields.truck_capacity = stoi(content[i][6]);
        // fields.drone_capacity = stoi(content[i][7]);
        // fields.drone_speed = stoi(content[i][8]);
        // fields.truck_speed = stoi(content[i][9]);
        // fields.drone_duration = stoi(content[i][10]);
        // params.insert(make_pair(str, fields));
        cout << content[i][3] << " " << content[i][4] <<" " << content[i][5] <<" " 
        << content[i][6] <<" "<<content[i][7]<<" "<<content[i][8]<<" "<<content[i][9]<< " " <<content[i][10] << " ";
        if (content[i][3].length() >  1) cout << content[i][3][1];
        cout <<endl;
    }
}

int main(){   
    read_test("param.csv");

    // matrix_dist.resize(n);
    // for (int i=0; i<n; ++i)    {
    //     vector<double> temp;
    //     for (int j=0; j<n; ++j){
    //         temp.push_back(calculate_distance(index_customer[i], index_customer[j]));
    //         // cout << "matrix_dist[i][j]" << " ";
    //     }
    //     matrix_dist.push_back(temp);
    //     cout << "\n";
    // }
    // for (int i = 0; i < n; i++){
    //     // for (int j = 0; j < n; j++){
    //     //     cout << matrix_dist[i][j] << " ";
    //     // }    
    //     cout << index_customer[i].first << " " << index_customer[i].second << " " << low[i] << " " << upper[i] << " " << weight[i] << endl;
    // }
    // for(auto it = params.cbegin(); it != params.cend(); ++it)    {
    //     std::cout << it->first << "\n";
    // }

    return 0;
}
