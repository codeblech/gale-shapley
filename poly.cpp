#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <random>
#include <unordered_set>

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

                // Print the generated preference
                std::cout << "Man " << man.id << " preference for Woman " << woman.id << ": " << weight << std::endl;
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

                // Print the generated preference
                std::cout << "Woman " << woman.id << " preference for Man " << man.id << ": " << weight << std::endl;
            }
        }
    }

    // Function to find a stable matching (adapted for polygamy and weights)
    void findStableMatching()
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
    psm.findStableMatching();
    psm.printMatching();

    return 0;
}
