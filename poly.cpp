#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <random>

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
    int maxPartners;                                   // Maximum number of partners allowed

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

        // Generate random preferences for men and women
        generateRandomPreferences();
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
    void findStableMatching()
    {
        std::queue<int> freeMen;
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

                // Check if woman has space for a partner
                if (woman.partnerCounts < woman.partnerCapacity)
                {
                    // Woman has space, form a match
                    man.partners.push_back(womanId);
                    woman.partners.push_back(manId);
                    man.partnerCounts++;
                    woman.partnerCounts++;
                    break; // Man found a match, stop proposing
                }
                else
                {
                    // Woman is full, check if she prefers the new man
                    if (weight > woman.preferences[man.id])
                    {
                        // Woman prefers the new man, replace current partner
                        int leastPreferredPartnerId = woman.partners[0];
                        Person &leastPreferredPartner = men[leastPreferredPartnerId];
                        leastPreferredPartner.partnerCounts--;

                        woman.partners[0] = manId;
                        man.partners.push_back(womanId);
                        man.partnerCounts++;

                        freeMen.push(leastPreferredPartnerId); // Add the replaced man back
                        break; // Man found a match, stop proposing
                    }
                }
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
