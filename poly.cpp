#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <random>
#include <unordered_set>

class PrettyPrint
{

    void A(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if ((i <= 3 && i + j == 4) || (i >= 3 && j == 1) || (i >= 3 && j == 5) || (i <= 3 && j == i + 2) || i == 5)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void B(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || (j <= 3 && (i == 1 || i == 5 || i == 9)) || (j >= 3 && ((i <= 3 && j == i + 2) || (i >= 3 && i <= 5 && j + i == 8) || (i <= 7 && i >= 5 && j == i - 2) || (i >= 7 && i + j == 12))))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void C(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 9 || j == 1)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void D(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j <= 3 && (i == 1 || i == 9)) || j == 1 || (j >= 5 && ((i <= 5 && j == i + 4) || (i >= 5 && i + j == 14))))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void E(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 1 || (i == 5 && j <= 4) || i == 9)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void F(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 1 || (i == 5 && j <= 4))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void G(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j == 1 && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || (i == 5 && j >= 5))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void H(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 5 || j == 5)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void I(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 3 || i == 1 || i == 9)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void J(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if ((j == 5 && i <= 7) || (i >= 7 && ((j <= 3 && i == j + 6) || (j >= 3 && i + j == 12))))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void K(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || (i <= 5 && i + j == 6) || (i >= 5 && i == j + 4))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void L(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || i == 9)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void M(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (j == 1 || j == 9 || (j <= 5 && i == j) || (j >= 5 && i + j == 10))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void N(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (j == 1 || j == 9 || i == j)
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void O(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (((j == 1 || j == 9) && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || j == i + 5)
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void P(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || j == 1 || (j == 5 && i <= 5))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void Q(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (((j == 1 || j == 9) && i >= 4 && i <= 6) || ((i == 1 || i == 9) && j >= 4 && j <= 6) || i + j == 5 || i + j == 15 || i == j + 5 || j == i + 5 || (i >= 6 && i == j))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void R(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || j == 1 || (j == 5 && i <= 5) || (i >= 5 && j == i - 4))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void S(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || i == 5 || i == 9 || (j == 1 && i <= 5) || (j == 5 && i >= 5))
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void T(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (i == 1 || j == 3)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void U(int i)
    {
        int j;
        for (j = 1; j <= 5; j++)
        {

            if (j == 1 || j == 5 || i == 9)
                std::cout << "* ";

            else
                std::cout << "  ";
        }
    }

    void V(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((i <= 5 && (j == 1 || j == 9)) || (i >= 5 && (i == j + 4 || i + j == 14)))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void W(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((i <= 7 && (j == 1 || j == 9)) || (i >= 7 && (i == j + 6 || i + j == 12 || i == j + 2 || i + j == 16)))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void X(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (i == j || i + j == 10)
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void Y(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if ((j == 5 && i >= 5) || (i <= 5 && (i == j || i + j == 10)))
                std::cout << "*";

            else
                std::cout << " ";
        }
    }

    void Z(int i)
    {
        int j;
        for (j = 1; j <= 9; j++)
        {

            if (i == 1 || i == 9 || j + i == 10)
                std::cout << "*";

            else
                std::cout << " ";
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
                    std::cout << "     ";
                    break;

                default:
                    std::cout << "invalid input";
                }

                x++;
                std::cout << "  ";
            }

            std::cout << "\n";
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
    // char s[] = "ALGORITHMS";
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

class Person
{
public:
    int id;
    std::map<int, double> preferences; // Map of preferred partners to weights
    std::vector<int> partners;         // List of current partners
    int partnerCapacity;               // Maximum number of partners allowed
    int partnerCounts;                 // Current number of partners

    Person(int id, int capacity) : id(id), partnerCapacity(capacity), partnerCounts(0) {}
};

class PolygamousStableMarriage
{
public:
    std::vector<Person> men;
    std::vector<Person> women;
    int maxPartners; // Maximum number of partners allowed

    PolygamousStableMarriage(int numMen, int numWomen, int maxPartners)
    {
        // Create men and women objects with partner capacity
        for (int i = 0; i < numMen; ++i)
        {
            men.push_back(Person(i, maxPartners));
        }
        for (int i = 0; i < numWomen; ++i)
        {
            women.push_back(Person(i, maxPartners));
        }

        // Ask the user for preference input method
        std::cout << "Enter preferences manually (m) or generate randomly (r)? ";
        char choice;
        std::cin >> choice;

        if (choice == 'm')
        {
            // Manually enter preferences
            enterPreferencesManually();
        }
        else
        {
            // Generate random preferences
            generateRandomPreferences();
        }
    }

    void enterPreferencesManually()
    {
        for (Person &person : men)
        {
            std::cout << "Enter preferences for Man " << person.id << ":\n";
            for (Person &other : women)
            {
                std::cout << "Preference weight for Woman " << other.id << ": ";
                double weight;
                std::cin >> weight;
                person.preferences[other.id] = weight;
            }
        }

        for (Person &person : women)
        {
            std::cout << "Enter preferences for Woman " << person.id << ":\n";
            for (Person &other : men)
            {
                std::cout << "Preference weight for Man " << other.id << ": ";
                double weight;
                std::cin >> weight;
                person.preferences[other.id] = weight;
            }
        }
    }

    // Function to generate random preferences for men and women
    void generateRandomPreferences()
    {
        std::random_device rd;
        std::mt19937 g(rd());

        for (Person &man : men)
        {
            // Fill preferences with random weights
            for (const Person &woman : women)
            {
                double weight = std::uniform_real_distribution<>(0.0, 1.0)(g);
                man.preferences[woman.id] = weight;
            }
        }

        // Similarly for women
        for (Person &woman : women)
        {
            // Fill preferences with random weights
            for (const Person &man : men)
            {
                double weight = std::uniform_real_distribution<>(0.0, 1.0)(g);
                woman.preferences[man.id] = weight;
            }
        }
    }

    // Function to find a stable matching (adapted for polygamy and weights)
    void findMaleOptimalStableMatching()
    {
        std::queue<int> freeMen;
        std::unordered_set<int> proposalsMade;

        for (int i = 0; i < men.size(); ++i)
        {
            freeMen.push(i);
        }

        while (!freeMen.empty())
        {
            int manId = freeMen.front();
            freeMen.pop();
            Person &man = men[manId];

            if (man.partnerCounts >= man.partnerCapacity)
            {
                continue; // Man is full, skip
            }

            bool proposalMade = false;

            // Sort preferences based on weights in descending order
            std::vector<std::pair<int, double>> sortedPreferences(man.preferences.begin(), man.preferences.end());
            std::sort(sortedPreferences.begin(), sortedPreferences.end(),
                      [](const auto &a, const auto &b)
                      {
                          return a.second > b.second; // Sort by weight (descending)
                      });

            // Propose to women in sorted order
            for (const auto &pref : sortedPreferences)
            {
                int womanId = pref.first;
                double weight = pref.second;
                Person &woman = women[womanId];

                if (proposalsMade.count(womanId) == 0)
                {
                    proposalsMade.insert(womanId);
                    proposalMade = true;

                    // Check if woman has space for a partner and if man has reached his maximum capacity
                    if (woman.partnerCounts < woman.partnerCapacity && man.partnerCounts < man.partnerCapacity)
                    {
                        // Woman has space and man has not reached his maximum capacity, form a match
                        man.partners.push_back(womanId);
                        woman.partners.push_back(manId);
                        man.partnerCounts++;
                        woman.partnerCounts++;
                    }
                    else
                    {
                        // Either woman is full or man has reached his maximum capacity, skip
                        continue;
                    }
                }

                // Stop proposing if man has reached his maximum capacity
                if (man.partnerCounts >= man.partnerCapacity)
                {
                    break;
                }
            }

            if (!proposalMade)
            {
                // Man made all possible proposals without success
                break;
            }
        }
    }

    void findFemaleOptimalStableMatching()
    {
        std::queue<int> freeWomen;
        std::unordered_set<int> proposalsReceived;

        // Initialize freeWomen queue with all women
        for (int i = 0; i < women.size(); ++i)
        {
            freeWomen.push(i);
        }

        while (!freeWomen.empty())
        {
            int womanId = freeWomen.front();
            freeWomen.pop();
            Person &woman = women[womanId];

            if (woman.partnerCounts >= woman.partnerCapacity)
            {
                continue; // Woman is full, skip
            }

            bool proposalReceived = false;

            // Sort preferences based on weights in descending order (for the woman)
            std::vector<std::pair<int, double>> sortedPreferences(woman.preferences.begin(), woman.preferences.end());
            std::sort(sortedPreferences.begin(), sortedPreferences.end(),
                      [](const auto &a, const auto &b)
                      {
                          return a.second > b.second; // Sort by weight (descending)
                      });

            // Woman proposes to men in sorted order of preference
            for (const auto &pref : sortedPreferences)
            {
                int manId = pref.first;
                double weight = pref.second;
                Person &man = men[manId];

                if (proposalsReceived.count(manId) == 0)
                {
                    proposalsReceived.insert(manId);
                    proposalReceived = true;

                    // Check if man has space for a partner
                    if (man.partnerCounts < man.partnerCapacity)
                    {
                        // Man has space, form a tentative match
                        man.partners.push_back(womanId);
                        woman.partners.push_back(manId);
                        man.partnerCounts++;
                        woman.partnerCounts++;

                        // If man is now full, remove him from the preferences of other women
                        // who tentatively matched with him and are less preferred
                        if (man.partnerCounts == man.partnerCapacity)
                        {
                            for (int i = 0; i < man.partners.size(); ++i)
                            {
                                int otherWomanId = man.partners[i];
                                if (man.preferences[otherWomanId] < weight)
                                {
                                    women[otherWomanId].partners.erase(
                                        std::remove(women[otherWomanId].partners.begin(),
                                                    women[otherWomanId].partners.end(), manId),
                                        women[otherWomanId].partners.end());
                                    women[otherWomanId].partnerCounts--;
                                    freeWomen.push(otherWomanId); // Add the less preferred woman back to the queue
                                }
                            }
                        }
                    }
                }

                // Woman stops proposing if she has reached her maximum capacity
                if (woman.partnerCounts >= woman.partnerCapacity)
                {
                    break;
                }
            }

            if (!proposalReceived)
            {
                // Woman made all possible proposals without success
                break;
            }
        }
    }

    void printMatching()
    {
        std::cout << "Stable Matching:\n";

        // Print each man and his partners (if any)
        for (const Person &man : men)
        {
            std::cout << "Man " << man.id << " is partnered with: ";
            if (man.partnerCounts == 0)
            {
                std::cout << "None\n";
            }
            else
            {
                for (int womanId : man.partners)
                {
                    std::cout << "Woman " << womanId << " ";
                }
                std::cout << std::endl;
            }
        }

        // Print each woman and her partners (if any)
        for (const Person &woman : women)
        {
            std::cout << "Woman " << woman.id << " is partnered with: ";
            if (woman.partnerCounts == 0)
            {
                std::cout << "None\n";
            }
            else
            {
                for (int manId : woman.partners)
                {
                    std::cout << "Man " << manId << " ";
                }
                std::cout << std::endl;
            }
        }
    }
};

int main()
{
    PrettyPrintColors();

    int numMen, numWomen, maxPartners;
    std::cout << "Enter the number of men: ";
    std::cin >> numMen;
    std::cout << "Enter the number of women: ";
    std::cin >> numWomen;
    std::cout << "Enter the maximum number of partners allowed: ";
    std::cin >> maxPartners;

    // Create a PolygamousStableMarriage instance
    PolygamousStableMarriage psm(numMen, numWomen, maxPartners);

    // Find and print the stable matching
    std::cout << "Male-Optimal Stable Matching:\n";
    psm.findMaleOptimalStableMatching();
    psm.printMatching();
    std::cout << std::endl;

    std::cout << "Female-Optimal Stable Matching:\n";
    psm.findFemaleOptimalStableMatching();
    psm.printMatching();

    int quit;
    std::cout << "Do you want to quit? (Enter any value to quit):";
    std::cin >> quit;
    return 0;
}