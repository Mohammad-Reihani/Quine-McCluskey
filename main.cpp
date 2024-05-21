//#include <iostream>
//
//
//using namespace std;
//
////This is a demo to how to use QuineMcCluskey Class
//int main() {
//    int m[11] = {9,12,13,15};
//    int d[7] = {1,4,5,7,8,11,14};
//    int c[12] = {0,1,2,5,6,7};
////    QuineMcCluskey test(m, 4, d, 7, true);
//    QuineMcCluskey test(c, 6, false);
//    test.solve();
//
//    cout << "Grouped Terms:" << endl;
//    for (const auto& data : test.getGroupedTerms()) {
//        cout << "MainTerms Included: [";
//        for (const auto& minterm : data.termsIncluded) {
//            cout << minterm << " ";
//        }
//        cout << "] Deleted Args: [";
//        for (const auto& arg : data.deletedArgs) {
//            cout << arg << " ";
//
//        }
////        cout << "]" << endl;
//        cout << "] stage: " << data.stage;
//        cout << " isPI: " << data.isPI <<  endl;
//    }
//
//    cout << "Prime Implicants:" << endl;
//    for (const auto& data : test.getPrimeImplicants()) {
//        cout << "MainTerms Included: [";
//        for (const auto& minterm : data.termsIncluded) {
//            cout << minterm << " ";
//        }
//        cout << "] Deleted Args: [";
//        for (const auto& arg : data.deletedArgs) {
//            cout << arg << " ";
//
//        }
////        cout << "]" << endl;
//        cout << "] isEssential: " << data.isEssential;
//        cout << " isRequired: " << data.isRequired <<  endl;
//    }
//
//    cout << "*****************************************" << endl << "MainTerms status:" << endl;
//    for (const auto& data : test.getMainTerms()) {
//
//        cout << "term : " << data.term;
//        cout << " | is covered : " << data.isCovered <<  endl;
//    }
//
//    cout << "*****************************************" << endl << "here : " << test.getStringExpression() << endl;
//
//    return 0;
//}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "QuineMcCluskey.h"

using namespace std;

int main() {
    string input1, input2, choice;
    vector<int> mainTerms, dontCares;
    bool maxTermsAreInput;

    // Get input for the first line
    cout << "Enter the mainTerms in a line separated by spaces: " << endl;
    getline(std::cin, input1);

    // Check if input1 is empty
    while (input1.empty()) {
        std::cout << "Error: The mainTerms line cannot be empty. try again" << endl;
        getline(std::cin, input1);
    }

    // Parse input1 into mainTerms
    std::istringstream iss1(input1);
    int num;
    while (iss1 >> num) {
        mainTerms.push_back(num);
    }

    // Get input for the second line
    cout << "Enter don't cares of the function if any separated by spaces (press Enter to skip): " << endl;
    getline(std::cin, input2);

    // Parse input2 into dontCares if it's not empty
    if (!input2.empty()) {
        std::istringstream iss2(input2);
        while (iss2 >> num) {
            dontCares.push_back(num);
        }
    }

    cout << "Did you enter MaxTerms? (yes/y or any): " << endl;
    getline(std::cin, choice);

    // Process user choice
    if (choice == "yes" || choice == "y") {
        maxTermsAreInput = true;
    } else {
        maxTermsAreInput = false;
    }
    std::cout << "Proceeding..." << endl;

    QuineMcCluskey qmc(mainTerms.data(), int(mainTerms.size()), dontCares.data(), int(dontCares.size()), maxTermsAreInput);

    qmc.solve();//of course, it needs to be solved before anything


    //Going for display shit:
    cout << "-------------------------------------------------------------------" << endl;
    cout << "The function is now simplified, getting ready to display results : " << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Grouped Terms:" << endl;//Showing the whole simplification table, can you print it vertically?
    for (const auto& data : qmc.getGroupedTerms()) {
        cout << "MainTerms Included: [";
        for (const auto& minterm : data.termsIncluded) {
            cout << minterm << " ";
        }
        cout << "] Deleted Args: [";
        for (const auto& arg : data.deletedArgs) {
            cout << arg << " ";

        }
        cout << "] stage: " << data.stage;
        cout << " isPI: " << data.isPI <<  endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Prime Implicants:" << endl;//Show prime implicants with details
    for (const auto& data : qmc.getPrimeImplicants()) {
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
    cout << "-------------------------------------------------------------------" << endl;

    cout << "MainTerms status:" << endl;//Showing the status of mainTerms if they're covered or not.
    for (const auto& data : qmc.getMainTerms()) {

        cout << "term : " << data.term;
        cout << " | is covered : " << data.isCovered <<  endl;
    }
    cout << "-------------------------------------------------------------------" << endl;
    cout << "Simplified Expression : " << qmc.getStringExpression() << endl;//finally showing the simplified expression

    return 0;

    return 0;
}

