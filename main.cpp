#include <iostream>
#include <fstream>
#include "Driver.h"

string writeData(string basic_string, bool p, bool local, bool global, bool prediction, string basicString);

using namespace std;
string writeData(int lineNum, string index, bool p, bool local, bool global, bool prediction, string selector) {
    string correct = p? "t" : "n";
    string local_p = local? "t" : "n";
    string global_p = global? "t" : "n";
    string final_p = prediction? "t" : "n";

    string output =  to_string(lineNum) + " - br#" + index + " - correct_p " + correct + +
            " - Actual " + final_p + " - Selector "+ selector + " (local " + local_p +
               " - global " + global_p + ")";

    return output;
}

int main() {
    Driver *tournment = new Driver();
    string input = "";
    ifstream in ("input.txt");
    ofstream outfile ("output.txt");
    int lineNum = 0;

    if (in.is_open())
    {

        while (getline(in, input))
        {
            lineNum++;
            bool correct_P = input.substr(1) == "n"? false : true;
            string index = input.substr(0,1);
            bool local = tournment->getLocalPrediction(index, correct_P);
            bool global = tournment->getGlobalPrediction(correct_P);
            string selector = tournment->getSelectorPrediction(index, correct_P, local, global);
            bool prediction = tournment->getCorrectPrediction(local, global, selector);
            tournment->updateCorrectness(local, global, prediction, correct_P);
            outfile << (writeData(lineNum, index, correct_P,local, global, prediction, selector ));
            outfile << endl;
        }

        outfile << "Statistics :" << endl;
        outfile << "#of calls = " << to_string(lineNum) << endl;
        outfile << "#of branches = " << "9" << endl;
        outfile << "#of correct global = " << tournment->getCorrectGlobal()<<endl;
        outfile << "#of correct local = " << tournment->getcorrectLocal()<<endl;
        outfile << "#of correct Tournament prediction = " << tournment->getCorrectTournment();

        outfile.close();
        in.close();
    }

    return 0;
}

