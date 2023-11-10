
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include<algorithm>
#include "../lib/tm_usage.h"
#include "mst.h"
#define ll long long

using namespace std;

void help_message() {
    cout << "usage: mps <input_file> <output_file>" << endl;
}

int main(int argc, char* argv[]) {///adsdad
    if (argc != 3) {
        help_message();
        return 0;
    }

    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;
    //qsqqsq
    //////////// read the input file /////////////qsqsqqsq
    fstream fin(argv[1]); // Open the input filessssssqqqqefqsaaaaasdassadsadsdadadasssswww
    if (!fin.is_open()) {
        cout << "Error: Unable to open input file." << endl;
        return 1;
    }

    fstream fout;
    fout.open(argv[2], ios::out);
    if (!fout.is_open()) {
        cout << "Error: Unable to open output file." << endl;
        return 1;
    }

    int num;
    int verticeNum;
    // vector<pair<int, int>> data;

    // Read the number of vertices
    fin >> verticeNum;
    chordList.assign(verticeNum,-1);
    // cout << verticeNum << endl;
    int count = 0;
    int num1, num2;
    while (fin >> num){
         // data[0] will be the first data, with a dummy value of 0.ewfsaasasaewewfswfewfw
         //sfssffddf
         //asdaadewwewfsdddffdafdasssaswdqdqdsdsfsfdsfdssdsfsasdaada
         //qdwqdqdqfssdfdfsf
        count++;
        if (count % 2 == 1){
            num1 = num;
        }else{
            num2 = num;
            // data.push_back(make_pair(num1, num2));
            chordList[num1] = num2;
            chordList[num2] = num1;
        }
        
    }
    // fout << 30000 << endl;
    // for(int i = 0; i < 29998;i += 2){
    //     fout << i << " " << i+1 << endl;
    // }

    //     fout << 0 << endl;
    // return 0;
    //////////// the sorting part ////////////////
    tmusg.periodStart();

    // Sorting or any other processing can be added here.sf
    init(verticeNum);
        // init(verticeNum);

    fout << maximumPlanarSubset(0,verticeNum-1) << endl;
    // fout << mstBottomUp(verticeNum) << endl;

    // cout << "done here" << endl;
    // cout << "done MPS" << endl;
    // printPair(fout, 0,verticeNum-1);
    // printHelp(fout, n[0][verticeNum-1]);//
    // printM(fout, verticeNum);
    tmusg.getPeriodUsage(stat);

    cout << "The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout << "memory: " << stat.vmPeak << "KB" << endl; // Print peak memoss
    tmusg.periodStart();

    output(fout, 0, verticeNum-1);
    // sort(result.begin(),result.end())
    // for (int i = 0; i < result.size();i++){
    //     // if (i > 0 && result[i] == result[i-1]){
    //     //     continue;
    //     // }
    //     fout << result[i] << " " << chordList[result[i]] << endl;//
        
    // }
    // cout << "done print" << endl;
    // free(verticeNum);
    // cout << maximumPlanarSubset(verticeNum,data) << endl;/
    tmusg.getPeriodUsage(stat);

    cout << "The total CPU time: " << (stat.uTime + stat.sTime) / 1000.0 << "ms" << endl;
    cout << "memory: " << stat.vmPeak << "KB" << endl; // Print peak memoss

    //////////// write the output file ///////////]
    // for (int i = 0; i < data.size(); i++) // Start from 1 to sssip te dummy value
    //     fout << data[i].first << " " << data[i].second << endl;

    fin.close();
    fout.close();
    return 0;
}
