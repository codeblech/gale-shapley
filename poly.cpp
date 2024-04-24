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
    int proposalIndex;                 // Index of the next person to propose to
    int partnerCapacity;               // Maximum number of partners allowed
    int partnerCounts;                 // Current number of partners

    Person(int id, int capacity) : id(id), proposalIndex(0), partnerCapacity(capacity), partnerCounts(0) {}
};

class PolygamousStableMarriage
{
public:
    std::vector<Person> men;
    std::vector<Person> women;
    std::map<std::pair<int, int>, double> preferences; // Weighted preferences: (personId, partnerId) -> weight
    int maxPartners;                                   // Maximum number of partners allowed
    bool maleOptimal;

    PolygamousStableMarriage(int numMen, int numWomen, int maxPartners, bool maleOptimal = true)
        : maleOptimal(maleOptimal)
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

        char choice;
        std::cout << "Generate random preferences or enter manually? (r/m): ";
        std::cin >> choice;

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
            std::cout << "Invalid choice. Using random preferences.\n";
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
            int desiredPartners = std::uniform_int_distribution<>(1, women.size() / 2)(g); // Up to half the women
            man.partnerCounts = desiredPartners;

            // Clear existing preferences and fill with random women and weights
            man.preferences.clear();
            for (int i = 0; i < desiredPartners; ++i)
            {
                int womanId = std::uniform_int_distribution<>(0, women.size() - 1)(g);
                double weight = std::uniform_real_distribution<>(0.0, 1.0)(g);
                man.preferences[womanId] = weight;
            }
        }

        // Similarly for women
        for (Person &woman : women)
        {
            int desiredPartners = std::uniform_int_distribution<>(1, men.size() / 2)(g); // Up to half the men
            woman.partnerCounts = desiredPartners;

            woman.preferences.clear();
            for (int i = 0; i < desiredPartners; ++i)
            {
                int manId = std::uniform_int_distribution<>(0, men.size() - 1)(g);
                double weight = std::uniform_real_distribution<>(0.0, 1.0)(g);
                woman.preferences[manId] = weight;
            }
        }
    }

    // Function to get manual preferences from the user
    void getManualPreferences()
    {
        for (Person &man : men)
        {
            std::cout << "Enter the number of partners desired by Man " << man.id << ": ";
            std::cin >> man.partnerCounts;

            man.preferences.clear(); // Clear any existing preferences

            std::cout << "Enter preferences for Man " << man.id << ":\n";
            for (int i = 0; i < man.partnerCounts; ++i)
            {
                int womanId;
                double weight;
                std::cout << "  Woman ID and weight (space-separated): ";
                std::cin >> womanId >> weight;
                man.preferences[womanId] = weight;
            }
        }

        // Similarly for women
        for (Person &woman : women)
        {
            std::cout << "Enter the number of partners desired by Woman " << woman.id << ": ";
            std::cin >> woman.partnerCounts;

            woman.preferences.clear();

            std::cout << "Enter preferences for Woman " << woman.id << ":\n";
            for (int i = 0; i < woman.partnerCounts; ++i)
            {
                int manId;
                double weight;
                std::cout << "  Man ID and weight (space-separated): ";
                std::cin >> manId >> weight;
                woman.preferences[manId] = weight;
            }
        }
    }

    // Function to find a stable matching (adapted for polygamy and weights)
    void findStableMatching()
    {
        if (maleOptimal)
            findStableMatchingMaleOptimal();
        // else findStableMatchingFemaleOptimal();
    }

    void findStableMatchingMaleOptimal()
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

            // Sort preferences based on weights in ascending order
            std::vector<std::pair<int, double>> sortedPreferences(man.preferences.begin(), man.preferences.end());
            std::sort(sortedPreferences.begin(), sortedPreferences.end(),
                      [](const auto &a, const auto &b)
                      {
                          return a.second < b.second; // Sort by weight (ascending)
                      });

            // Propose to women in sorted order using proposalIndex
            while (man.proposalIndex < sortedPreferences.size() && man.partnerCounts < man.partnerCapacity)
            {
                int womanId = sortedPreferences[man.proposalIndex].first;
                double weight = sortedPreferences[man.proposalIndex].second;
                Person &woman = women[womanId];
                man.proposalIndex++; // Update proposal index for next iteration

                // Check if woman has space for a partner
                if (woman.partnerCounts < woman.partnerCapacity)
                {
                    // Woman has space, form a match
                    man.partners.push_back(womanId);
                    woman.partners.push_back(manId);
                    man.partnerCounts++;
                    woman.partnerCounts++;

                    // If man is now full, remove him from the queue
                    if (man.partnerCounts >= man.partnerCapacity)
                    {
                        break; // Man is full, move to the next man
                    }
                }
                else
                {
                    // Woman is full, check if she prefers the new man
                    // Find the partner with the lowest weight
                    int leastPreferredPartnerId = -1;
                    double lowestWeight = std::numeric_limits<double>::max();
                    for (int partnerId : woman.partners)
                    {
                        double currentWeight = woman.preferences[partnerId];
                        if (currentWeight < lowestWeight)
                        {
                            leastPreferredPartnerId = partnerId;
                            lowestWeight = currentWeight;
                        }
                    }

                    // Compare weights and potentially replace partner
                    if (weight > lowestWeight)
                    {
                        // Woman prefers the new man
                        Person &leastPreferredPartner = men[leastPreferredPartnerId];
                        leastPreferredPartner.partners.erase(
                            std::remove(leastPreferredPartner.partners.begin(),
                                        leastPreferredPartner.partners.end(), womanId),
                            leastPreferredPartner.partners.end());
                        leastPreferredPartner.partnerCounts--;
                        freeMen.push(leastPreferredPartnerId); // Add the replaced man back

                        woman.partners.erase(
                            std::remove(woman.partners.begin(), woman.partners.end(), leastPreferredPartnerId),
                            woman.partners.end());
                        woman.partners.push_back(manId);

                        man.partners.push_back(womanId);
                        man.partnerCounts++;

                        // If man is now full, remove him from the queue
                        if (man.partnerCounts >= man.partnerCapacity)
                        {
                            break; // Man is full, move to the next man
                        }
                    }
                }
            }

            // If man is still not full after proposing to all preferred women, add him back to the queue
            if (man.partnerCounts < man.partnerCapacity)
            {
                freeMen.push(manId);
                man.proposalIndex = 0; // Reset proposal index for next round
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
            if (man.partners.empty())
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
            if (woman.partners.empty())
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

    // Create a PolygamousStableMarriage instance (male optimal by default)
    PolygamousStableMarriage psm(numMen, numWomen, maxPartners);

    // Find and print the stable matching
    psm.findStableMatching();
    psm.printMatching();

    return 0;
}