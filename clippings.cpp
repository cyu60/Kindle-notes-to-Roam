#include <iostream>
#include <sstream> // std::stringstream

#include <fstream>
#include <string>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::ofstream;
using std::string;
using std::stringstream;
using std::vector;

// bool PromptForChar(const char *prompt, char &readch)
// {
//     std::string tmp;
//     std::cout << prompt << std::endl;
//     if (std::getline(std::cin, tmp))
//     {
//         // Only accept single character input
//         if (tmp.length() == 1)
//         {
//             readch = tmp[0];
//         }
//         else
//         {
//             // For most input, char zero is an appropriate sentinel
//             readch = '\0';
//         }
//         return true;
//     }
//     return false;
// }

int main()
{
    // Open a file and read in line by line
    // string inFilename = "Test Clippings.txt"; // Used for testing purposes 
    string inFilename = "My Clippings.txt"; // Edit the path directory to your Clippings doc

    string line;
    ifstream myfile(inFilename);

    vector<string> allLine;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            allLine.push_back(line);
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";


    // Get source tag
    char userConfirmation;
    string userSource;
    string sourceTag;
    do
    {
        // std::cin.clear(); // Flush buffer
        cout << "What is your source tag?" << endl;
        getline(cin, userSource);
        sourceTag = "#[[" + userSource + "]]"; // Add Roam formating
        cout << "The tag for highlights will be " << sourceTag << "\n";
        // Get confirmation
        cout << "Are you sure? [y]" << endl;
        cin >> userConfirmation;
        std::cin.ignore();
    } while (!cin.fail() && userConfirmation != 'y');

    //create a map of <string, vector <string>> store book name + highlights
    int curLine = 0;
    string lastBook = "";
    string curBook = "";
    string meta;
    char type;
    string curClip;
    string lastClip = "-1"; // set to some arbitary clip
    map<string, vector<string>> BookNotes;
    for (vector<string>::const_iterator it = allLine.cbegin();
         it != allLine.cend();
         ++it)
    {
        //book title
        if ((curLine % 5) == 0)
        {
            curBook = *it;
            // Check for new book
            if (curBook != lastBook)
            {
                BookNotes[curBook];
            }
            lastBook = curBook;
        }

        //metadata
        if ((curLine % 5) == 1)
        {
            meta = *it;
            // Find type --  H, N, B (Highlight, Note, Bookmark)
            type = meta.at(7);
        }

        // save clip
        if ((curLine % 5) == 3)
        {
            
            //Format clip according to metadata -- Should format later??
            stringstream RoamText;
            switch (type)
            {
            case 'H':

                // Help avoid highlights-- remove unecessary duplicates
                curClip = *it;
                if (curClip.find(lastClip) == 0 || lastClip.find(curClip) == 0)
                { // curClip contains last clip
                    BookNotes[curBook].pop_back();
                }

                RoamText << "- " << *it << " " << sourceTag; //Add bullet + source tag
            
                // Update lastClip
                lastClip = curClip;
            
                break;
            case 'N':
                RoamText << "\t- __" << *it << "__"; //Add tab + bullet + italics
                break;
            default:
                break;
            }
            BookNotes[curBook].push_back(RoamText.str());
        }
        curLine++;
    }

    cout << "\n";

    // Display all books
    int numBooks = 0;
    vector<string> BookList;
    cout << "Books found include: \n";
    for (map<string, vector<string>>::const_iterator it = BookNotes.cbegin();
         it != BookNotes.cend();
         ++it)
    {
        cout << numBooks << " - " << it->first << "\n";
        BookList.push_back(it->first);
        numBooks++;
    }

    // Get user option -- Need to handle error??
    int userOption;
    do
    {
        cout << "Which book's notes do you want to extract?\n";
        cin >> userOption;
        cout << "You picked " << BookList[userOption] << "\n";
        // Get confirmation
        cout << "Are you sure? [y]" << endl;
        cin >> userConfirmation;
    } while (!cin.fail() && userConfirmation != 'y');

    // Final printing
    stringstream ss;

    // Display the quotes -- put it into the ss
    for (vector<string>::const_iterator it = BookNotes[BookList[userOption]].cbegin();
         it != BookNotes[BookList[userOption]].cend();
         ++it)
    {
        // cout << *it << "\n"; // Prints quotes to console
        ss << *it << "\n";
    }
    

    // Write to a file
    ofstream outfile;
    outfile.open("out.txt");
    outfile << ss.str();
    outfile.close();

    return 0;
}