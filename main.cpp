#include <fstream>
#include <vector>
#include "Graph.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        return 1;
    }
    ifstream input;
    input.open(argv[1]);
    ios_base::sync_with_stdio(false);
    string line;
    getline(input, line);
    istringstream iss(line);

    int rows, columns;
    iss >> rows >> columns;
    int* arr=new int[rows*columns+1];
    for(int i = 1; i <= rows; i++) {
        getline(input, line);
        istringstream iss2(line);
        int height;
        int j=(i-1)*columns+1;
        while (iss2 >> height) {
            arr[j] = height;
            j++;
        }
    }

    Graph graph(rows, columns);
    int size=graph.size;
    for(int i=1; i<size; i++) {

        if (i<=size-columns) {
            if (i % graph.columns != 0) {
                graph.edge(i, i + 1, abs(arr[i] - arr[i + 1]));
                graph.edge(i, i + columns, abs(arr[i] - arr[i + columns]));
            }
            else {
                graph.edge(i, i + columns, abs(arr[i] - arr[i + columns]));
            }
        }
        else {
            graph.edge(i, i + 1, abs(arr[i] - arr[i + 1]));
        }

    }

    delete[] arr;

    vector<int> result;
    getline(input, line);
    istringstream iss2(line);
    int numOfQueries;
    iss2 >> numOfQueries;
    for (int i=0; i<numOfQueries; i++) {
        int y1, y2, x1, x2, sourceIndex, destinationIndex;
        getline(input, line);
        istringstream iss3(line);
        iss3 >> y1 >> x1 >> y2 >> x2;
        sourceIndex=(y1-1)*columns+x1;
        destinationIndex=(y2-1)*columns+x2;
        result.push_back(graph.optimalCost(sourceIndex, destinationIndex));
    }
    input.close();

    ofstream output;
    output.open(argv[2]);

    for(auto i:result) {
        output << i << endl;
    }
    output.close();

}
