#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

using namespace std;

const int NUM_MEN = 1000;
const int NUM_WOMEN = 1000;

// Function to generate a random double value between min and max
double randDouble(double min, double max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> dis(min, max);
    return dis(gen);
}

int main() {
    // Initialize the CWP matrix with random values between lower and upper bounds
    double lowerBound, upperBound;
    std::cout << "Enter the lower and upper bounds for the CWP matrix(space separated) [ex: 5 90]: ";
    std::cin >> lowerBound >> upperBound;
    vector<vector<double>> CWP(NUM_MEN, vector<double>(NUM_WOMEN));
    for (int i = 0; i < NUM_MEN; i++) {
        for (int j = 0; j < NUM_WOMEN; j++) {
            CWP[i][j] = randDouble(lowerBound, upperBound);
        }
    }

    // Write CWP matrix to a CSV file
    ofstream outfile("cwp_data.csv");   // NUM_MEN x NUM_WOMEN matrix
    for (int i = 0; i < NUM_MEN; i++) {
        for (int j = 0; j < NUM_WOMEN; j++) {
            outfile << CWP[i][j];
            if (j < NUM_WOMEN - 1) {
                outfile << ",";
            }
        }
        outfile << endl;
    }
    outfile.close();

    // Vector to store the matched pairs
    vector<pair<int, int>> matches;

    // Vector to keep track of engaged women
    vector<bool> engagedWomen(NUM_WOMEN, false);

    // Sorted lists of men's preferences
    vector<vector<int>> sortedLists(NUM_MEN);
    for (int i = 0; i < NUM_MEN; i++) {
        sortedLists[i].resize(NUM_WOMEN);
        for (int j = 0; j < NUM_WOMEN; j++) {
            sortedLists[i][j] = j;
        }
        sort(sortedLists[i].begin(), sortedLists[i].end(), [&](int a, int b) {
            return CWP[i][a] > CWP[i][b];
        });
    }

    // Greedy matching
    for (int i = 0; i < NUM_MEN; i++) {
        for (int j = 0; j < NUM_WOMEN; j++) {
            int womanIndex = sortedLists[i][j];
            if (!engagedWomen[womanIndex]) {
                matches.push_back(make_pair(i, womanIndex));
                engagedWomen[womanIndex] = true;
                break;
            }
        }
    }

    // Calculate the AWM
    double awm = 0.0;
    for (const auto& match : matches) {
        int manIndex = match.first;
        int womanIndex = match.second;
        awm += CWP[manIndex][womanIndex];
    }
    awm /= NUM_MEN;

    // Print the matched pairs
    cout << "Matched Pairs:" << endl;
    for (const auto& match : matches) {
        int manIndex = match.first;
        int womanIndex = match.second;
        cout << "Man " << manIndex << " - Woman " << womanIndex << endl;
    }
    cout << "Average Weighted Matching (AWM): " << awm << endl;

    return 0;
}