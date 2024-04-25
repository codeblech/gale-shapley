#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <random>
#include <sstream>
using std::cout, std::cin, std::find;

class PrettyPrint
{

    void A(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if ((i <= 3 && i + j == 4) || (i >= 3 && j == 1) || (i >= 3 && j == 5) || (i <= 3 && j == i + 2) || i == 5)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void B(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || (j <= 3 && (i == 1 || i == 5 || i == 9)) || (j >= 3 && ((i <= 3 && j == i + 2) || (i >= 3 && i <= 5 && j + i == 8) || (i <= 7 && i >= 5 && j == i - 2) || (i >= 7 && i + j == 12))))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void C(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 9 || j == 1)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void D(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j <= 3 && (i == 1 || i == 9)) || j == 1 || (j >= 5 && ((i <= 5 && j == i + 4) || (i >= 5 && i + j == 14))))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void E(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 1 || (i == 5 && j <= 4) || i == 9)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void F(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 1 || (i == 5 && j <= 4))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void G(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j == 1 && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || (i == 5 && j >= 5))
                cout << "*";

            else
                cout << " ";
        }
    }

    void H(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 5 || j == 5)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void I(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 3 || i == 1 || i == 9)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void J(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if ((j == 5 && i <= 7) || (i >= 7 && ((j <= 3 && i == j + 6) || (j >= 3 && i + j == 12))))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void K(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || (i <= 5 && i + j == 6) || (i >= 5 && i == j + 4))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void L(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 9)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void M(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (j == 1 || j == 9 || (j <= 5 && i == j) || (j >= 5 && i + j == 10))
                cout << "*";

            else
                cout << " ";
        }
    }

    void N(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (j == 1 || j == 9 || i == j)
                cout << "*";

            else
                cout << " ";
        }
    }

    void O(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (((j == 1 || j == 9) && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || j == i + 5)
                cout << "*";

            else
                cout << " ";
        }
    }

    void P(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || j == 1 || (j == 5 && i <= 5))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void Q(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (((j == 1 || j == 9) && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || j == i + 5 || (i >= 6 && i == j))
                cout << "*";

            else
                cout << " ";
        }
    }

    void R(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || j == 1 || (j == 5 && i <= 5) || (i >= 5 && j == i - 4))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void S(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || i == 9 || (j == 1 && i <= 5) || (j == 5 && i >= 5))
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void T(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || j == 3)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void U(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || j == 5 || i == 9)
                cout << "* ";

            else
                cout << "  ";
        }
    }

    void V(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((i <= 5 && (j == 1 || j == 9)) || (i >= 5 && (i == j + 4 || i + j == 14)))
                cout << "*";

            else
                cout << " ";
        }
    }

    void W(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((i <= 7 && (j == 1 || j == 9)) || (i >= 7 && (i == j + 6 || i + j == 12 || i == j + 2 || i + j == 16)))
                cout << "*";

            else
                cout << " ";
        }
    }

    void X(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (i == j || i + j == 10)
                cout << "*";

            else
                cout << " ";
        }
    }

    void Y(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j == 5 && i >= 5) || (i <= 5 && (i == j || i + j == 10)))
                cout << "*";

            else
                cout << " ";
        }
    }

    void Z(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (i == 1 || i == 9 || j + i == 10)
                cout << "*";

            else
                cout << " ";
        }
    }

public:
    PrettyPrint() {}

    PrettyPrint(char s[])
    {
        int x;

        for (int a = 1; a <= 9; a++)
        {

            for (int i = 0; i < 10000; i++)
            {

                for (int j = 0; j < 10000; j++)
                {
                }
            }

            x = 0;
            while (s[x] != '\0')
            {

                switch (s[x])
                {

                case 'A':
                    A(a);
                    break;

                case 'B':
                    B(a);
                    break;

                case 'C':
                    C(a);
                    break;

                case 'D':
                    D(a);
                    break;

                case 'E':
                    E(a);
                    break;

                case 'F':
                    F(a);
                    break;

                case 'G':
                    G(a);
                    break;

                case 'H':
                    H(a);
                    break;

                case 'I':
                    I(a);
                    break;

                case 'J':
                    J(a);
                    break;

                case 'K':
                    K(a);
                    break;

                case 'L':
                    L(a);
                    break;

                case 'M':
                    M(a);
                    break;

                case 'N':
                    N(a);
                    break;

                case 'O':
                    O(a);
                    break;

                case 'P':
                    P(a);
                    break;

                case 'Q':
                    Q(a);
                    break;

                case 'R':
                    R(a);
                    break;

                case 'S':
                    S(a);
                    break;

                case 'T':
                    T(a);
                    break;

                case 'U':
                    U(a);
                    break;

                case 'V':
                    V(a);
                    break;

                case 'W':
                    W(a);
                    break;

                case 'X':
                    X(a);
                    break;

                case 'Y':
                    Y(a);
                    break;

                case 'Z':
                    Z(a);
                    break;

                case ' ':
                    cout << "     ";
                    break;

                default:
                    cout << "invalid input";
                }

                x++;
                cout << "  ";
            }

            cout << "\n";
        }
    }
};

void delay(int msecs)
{

    clock_t endTime;
    endTime = clock() + msecs * CLOCKS_PER_SEC / 1000;
    while (clock() < endTime)
    {
    }
}

int PrettyPrintColors()
{
    PrettyPrint p("ALGORITHMS");
    delay(300);
    system("color 0A");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }

    delay(300);
    system("color 0B");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }

    delay(300);
    system("color 0C");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }

    delay(300);
    system("color 0D");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }

    delay(300);
    system("color 0E");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }

    delay(300);
    system("color 0F");

    for (int i = 0; i < 10000; i++)
    {

        for (int j = 0; j < 10000; j++)
        {
        }
    }
    std::cout << std::endl;
    return 0;
}

// Person class representing either a man or a woman
class Person
{
public:
    int id;
    std::vector<int> preferences; // List of preferred partners in order
    int partner;                  // ID of the current partner (-1 if single)
    int proposalIndex;            // Index of the next person to propose to

    Person(int id) : id(id), partner(-1), proposalIndex(0) {}
};

// StableMarriage class to implement the Gale-Shapley algorithm
class StableMarriage
{
public:
    std::vector<Person> men;
    std::vector<Person> women;
    bool maleOptimal;

    // Constructor to initialize men and women with their preferences
    StableMarriage(int numMen, int numWomen, bool maleOptimal = true) : maleOptimal(maleOptimal)
    {
        // Create men and women objects
        for (int i = 0; i < numMen; ++i)
        {
            men.push_back(Person(i));
        }
        for (int i = 0; i < numWomen; ++i)
        {
            women.push_back(Person(i));
        }

        // Ask the user for preference input method
        char choice;
        cout << "Generate random preferences or enter manually? (r/m): ";
        cin >> choice;

        if (choice == 'r')
        {
            generateRandomPreferences();
        }
        else if (choice == 'm')
        {
            getManualPreferences();
        }
        else
        {
            cout << "Invalid choice. Using random preferences.\n";
            generateRandomPreferences();
        }
    }

    // Function to generate random preferences for men and women
    void generateRandomPreferences()
    {
        std::random_device rd;
        std::mt19937 g(rd());

        for (Person &man : men)
        {
            man.preferences.resize(women.size());
            std::iota(man.preferences.begin(), man.preferences.end(), 0);
            std::shuffle(man.preferences.begin(), man.preferences.end(), g);

            // Print the generated preference order in readable format
            std::ostringstream oss;
            oss << "Man " << man.id << " preferences: ";
            for (int womanId : man.preferences)
            {
                oss << "Woman " << womanId << " > ";
            }
            cout << oss.str() << "\n";
        }

        for (Person &woman : women)
        {
            woman.preferences.resize(men.size());
            std::iota(woman.preferences.begin(), woman.preferences.end(), 0);
            std::shuffle(woman.preferences.begin(), woman.preferences.end(), g);

            // Print the generated preference order in readable format
            std::ostringstream oss;
            oss << "Woman " << woman.id << " preferences: ";
            for (int manId : woman.preferences)
            {
                oss << "Man " << manId << " > ";
            }
            cout << oss.str() << "\n";
        }
    }

    // Function to get manual preferences from the user
    void getManualPreferences()
    {
        for (Person &man : men)
        {
            cout << "Enter preferences for Man " << man.id << " (space-separated IDs): ";
            man.preferences.resize(women.size());
            for (int &w : man.preferences)
            {
                cin >> w;
            }
        }

        for (Person &woman : women)
        {
            cout << "Enter preferences for Woman " << woman.id << " (space-separated IDs): ";
            woman.preferences.resize(men.size());
            for (int &m : woman.preferences)
            {
                cin >> m;
            }
        }
    }

    void findStableMatching()
    {
        if (maleOptimal)
        {
            findStableMatchingMaleOptimal();
        }
        else
        {
            findStableMatchingFemaleOptimal();
        }
    }
    void findStableMatchingMaleOptimal()
    {
        std::queue<int> freeMen; // Queue of men who are currently single
        for (int i = 0; i < men.size(); ++i)
        {
            freeMen.push(i);
        }

        while (!freeMen.empty())
        {
            int manId = freeMen.front();
            freeMen.pop();
            Person &man = men[manId];

            // Check if man has any remaining preferences
            if (man.proposalIndex >= man.preferences.size())
            {
                continue; // Man has proposed to everyone, remains single
            }

            int womanId = man.preferences[man.proposalIndex++];
            // Ensure womanId is within bounds
            if (womanId >= women.size())
            {
                continue; // Invalid preference, skip to next
            }
            Person &woman = women[womanId];

            // If woman is free, they become a couple
            if (woman.partner == -1)
            {
                man.partner = womanId;
                woman.partner = manId;
            }
            else
            {
                // Check if woman prefers the current man over her partner
                int currentPartnerId = woman.partner;
                int currentPartnerRank = std::find(woman.preferences.begin(), woman.preferences.end(), currentPartnerId) - woman.preferences.begin();
                int newManRank = std::find(woman.preferences.begin(), woman.preferences.end(), manId) - woman.preferences.begin();

                if (newManRank < currentPartnerRank)
                {
                    // Woman prefers the new man, so she breaks up with her current partner
                    men[currentPartnerId].partner = -1;
                    freeMen.push(currentPartnerId);
                    man.partner = womanId;
                    woman.partner = manId;
                }
                else
                {
                    // Woman prefers her current partner, so the man remains single
                    freeMen.push(manId);
                }
            }
        }
    }

    void findStableMatchingFemaleOptimal()
    {
        std::queue<int> freeWomen; // Queue of women who are currently single
        for (int i = 0; i < women.size(); ++i)
        {
            freeWomen.push(i);
        }

        while (!freeWomen.empty())
        {
            int womanId = freeWomen.front();
            freeWomen.pop();
            Person &woman = women[womanId];

            if (woman.proposalIndex >= woman.preferences.size())
            {
                continue; // Woman has proposed to everyone, remains single
            }

            int manId = woman.preferences[woman.proposalIndex++];
            if (manId >= men.size())
            {
                continue; // Invalid preference, skip to next
            }

            Person &man = men[manId];

            if (man.partner == -1)
            {
                man.partner = womanId;
                woman.partner = manId;
            }
            else
            {
                int currentPartnerId = man.partner;
                int currentPartnerRank = std::find(man.preferences.begin(), man.preferences.end(), currentPartnerId) - man.preferences.begin();
                int newWomanRank = std::find(man.preferences.begin(), man.preferences.end(), womanId) - man.preferences.begin();

                if (newWomanRank < currentPartnerRank)
                {
                    women[currentPartnerId].partner = -1;
                    freeWomen.push(currentPartnerId);
                    man.partner = womanId;
                    woman.partner = manId;
                }
                else
                {
                    freeWomen.push(womanId);
                }
            }
        }
    }
    // Print the stable matching (including single individuals)
    void printMatching()
    {
        std::cout << "Stable Matching:\n";
        for (const Person &man : men)
        {
            if (man.partner != -1)
            {
                std::cout << "Man " << man.id << " is paired with Woman " << man.partner << std::endl;
            }
            else
            {
                std::cout << "Man " << man.id << " is single.\n";
            }
        }
        for (const Person &woman : women)
        {
            if (woman.partner == -1)
            {
                std::cout << "Woman " << woman.id << " is single.\n";
            }
        }
    }
};

int main()
{
    PrettyPrintColors();
    // fflush(stdin);
    // fflush(stdout);
    // cout.flush();
    int numMen, numWomen;
    std::cout << "Enter the number of men: ";
    std::cin >> numMen;
    std::cout << "Enter the number of women: ";
    std::cin >> numWomen;

    // Male-optimal matching
    StableMarriage sm(numMen, numWomen, true);
    sm.findStableMatchingMaleOptimal();
    std::cout << "\nMale-Optimal Matching:\n";
    sm.printMatching();

    sm.findStableMatchingFemaleOptimal();
    std::cout << "\nFemale-Optimal Matching:\n";
    sm.printMatching();

    int quit;
    std::cout << "Do you want to quit? (Enter any value to quit):";
    std::cin >> quit;
    return 0;
}
