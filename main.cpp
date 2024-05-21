#include <iostream>
#include "QuineMcCluskey.h"
using namespace std;
int main() {
    int m[11] = {9,12,13,15};
    int d[7] = {1,4,5,7,8,11,14};
    int c[12] = {0,1,2,5,6,7};
    QuineMcCluskey test(m, 4, d, 7, false);
//    QuineMcCluskey test(c, 6, false);
    test.solve();

    cout << "Grouped Terms:" << endl;
    for (const auto& data : test.getGroupedTerms()) {
        cout << "MainTerms Included: [";
        for (const auto& minterm : data.termsIncluded) {
            cout << minterm << " ";
        }
        cout << "] Deleted Args: [";
        for (const auto& arg : data.deletedArgs) {
            cout << arg << " ";

        }
//        cout << "]" << endl;
        cout << "] stage: " << data.stage;
        cout << " isPI: " << data.isPI <<  endl;
    }

    cout << "Prime Implicants:" << endl;
    for (const auto& data : test.getPrimeImplicants()) {
        cout << "MainTerms Included: [";
        for (const auto& minterm : data.termsIncluded) {
            cout << minterm << " ";
        }
        cout << "] Deleted Args: [";
        for (const auto& arg : data.deletedArgs) {
            cout << arg << " ";

        }
//        cout << "]" << endl;
        cout << "] isEssential: " << data.isEssential;
        cout << " isRequired: " << data.isRequired <<  endl;
    }

    cout << "*****************************************" << endl << "MainTerms status:" << endl;
    for (const auto& data : test.getMainTerms()) {

        cout << "term : " << data.term;
        cout << " | is covered : " << data.isCovered <<  endl;
    }

    cout << "*****************************************" << endl << "here : " << test.getStringExpression() << endl;

    return 0;
}
