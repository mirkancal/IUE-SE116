#include <iostream>
#include <ctime>

//All the instance of classes will be assume as their population
class Creature
{
  private:
    int population;

  public:
    void setPopulation(int myPopulation)
    {
        population = myPopulation;
    }

    int getPopulation(void) const
    {
        return population;
    }

    virtual void Production() = 0;
    virtual void Zombie() = 0;
    virtual void Disease() = 0;
    virtual void Earthquake() = 0;
    virtual void Tsunami() = 0;
    virtual void displayStats() = 0;
    virtual void toStart() = 0;
};

class Plant : public Creature
{

  public:
    void Production()
    {
        setPopulation(getPopulation() + 200);
    }

    void Earthquake()
    {
        setPopulation(getPopulation() - 125);
    }

    void Tsunami()
    {
        setPopulation(getPopulation() - 150);
    }

    void displayStats()
    {
        std::cout << "Plant population is:" << getPopulation() << std::endl;
    }

    void toStart()
    {
        setPopulation(2000);
    }
    virtual void Disease()
    {
        setPopulation(getPopulation());
    }
    virtual void Zombie()
    {
        setPopulation(getPopulation());
    }
};

class Animal : public Creature
{

  public:
    void Production()
    {
        setPopulation(getPopulation() + 100);
    }

    void Zombie()
    {
        setPopulation(getPopulation() - 10);
    }

    void Disease()
    {
        setPopulation(getPopulation() - 50);
    }

    void Earthquake()
    {
        setPopulation(getPopulation() - 10);
    }

    void Tsunami()
    {
        setPopulation(getPopulation() - 5);
    }

    void displayStats()
    {
        std::cout << "Animal population is:" << getPopulation() << std::endl;
    }
    void toStart()
    {
        setPopulation(1000);
    }
};

class Human : public Animal
{

  public:
    void Production()
    {
        setPopulation(getPopulation() + 50);
    }

    void Zombie()
    {
        setPopulation(getPopulation() - 5);
    }

    void Disease()
    {
        setPopulation(getPopulation() - 25);
    }

    void Earthquake()
    {
        setPopulation(getPopulation() - 30);
    }

    void Tsunami()
    {
        setPopulation(getPopulation() - 10);
    }

    void displayStats()
    {
        std::cout << "Human population is:" << getPopulation() << std::endl;
        std::cout << "Option:" << std::endl;
    }
    void toStart()
    {
        setPopulation(500);
    }
};

void theGame(Creature *Arr[])
{
    std::cout << "Number is between 0 and 50" << std::endl;
    int gs;
    int max = 50;
    int random_number;
    int counter = 0;
    std::srand(std::time(0));
    random_number = (rand() % max) + 1;

    std::cout << "Enter your guess" << std::endl;
    for (;;)
    {
        std::cin >> gs;
        if (gs < random_number)
        {
            std::cout << "Try again with the greater number" << std::endl;
            counter++;
        }
        else if (gs > random_number)
        {
            std::cout << "Try again with the smaller number" << std::endl;
            counter++;
        }

        else
        {
            std::cout << "Here is bonus" << std::endl;
            for (int i = 0; i < 2; i++)
            {
                Arr[i]->Production();
            }
            break;
        }
        if (counter > 5)
        {
            std::cout << "Zombies!" << std::endl;
            for (int i = 0; i < 2; i++)
            {
                Arr[i]->Zombie();
            }
            break;
        }
    }
}

void menuItself(int sw, Creature *Arr[3])
{

    do
    {
        switch (sw)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                Arr[i]->Disease();
                Arr[i]->displayStats();
            }
            break;

        case 2:
            for (int i = 0; i < 3; i++)
            {
                Arr[i]->Earthquake();
                Arr[i]->displayStats();
            }
            break;

        case 3:
            for (int i = 0; i < 3; i++)
            {
                Arr[i]->Tsunami();
                Arr[i]->displayStats();
            }
            break;

        case 4:
            std::cout << "Ready to take risk?(Better yes, don't have back button)" << std::endl;
            std::cout << "Game on!" << std::endl;
            theGame(Arr);
            for (int i = 0; i < 3; i++)
            {
                Arr[i]->displayStats();
            }
            break;

        default:
            for (int i = 0; i < 3; i++)
            {
                Arr[i]->displayStats();
            }
            return;
        }
    } while (sw <= 0 || sw > 4);
}

void displayMenu()
{
    std::cout << "Select the next move from the menu below" << std::endl
              << std::endl;
    std::cout << "1)Disease" << std::endl;
    std::cout << "2)Earthquake" << std::endl;
    std::cout << "3)Tsunami" << std::endl;
    std::cout << "4)Try new medicine" << std::endl;
    std::cout << "Press 0 to exit" << std::endl;
    std::cout << "Enter your option" << std::endl;
}

int main()
{

    Creature *ar[3];
    ar[0] = new Plant;
    ar[1] = new Animal;
    ar[2] = new Human;

    for (int i = 0; i < 3; i++)
    {
        ar[i]->toStart();
    }

    displayMenu();
    int i;
    std::cin >> i;

    while (i != 0)
    {

        if (ar[0]->getPopulation() == 0 || ar[1]->getPopulation() == 0 || ar[2]->getPopulation() == 0)
        {
            std::cout << "Creature population is under 0" << std::endl;
            std::cout << "Re-Launch program to play again!" << std::endl;
            break;
        }
        displayMenu();
        menuItself(i, ar);
        std::cin >> i;
    }

    return 0;
}
