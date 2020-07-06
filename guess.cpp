#include <iostream>
#include <cstdlib>
#include <ctime>

int randomNumber()
{
    std::srand(std::time(nullptr));
    return std::rand() % 10 + 1;
}

void welcome_and_pick_number(int &n)
{
    std::cout << "The computer will pick a number between 1 and 10" << std::endl;
    n = randomNumber();
}

void ask_for_numbers_give_reply(int &user_number, int our_number)
{
    for (auto tries{0}; user_number != our_number && tries < 3; ++tries)
    {
        for (user_number = 0; user_number < 1 || user_number > 10;)
        {
            std::cout << "Please enter a number between 1 and 10: ";
            std::cin >> user_number;
        }
        if (our_number > user_number)
        {
            std::cout << "My number is greater than yours" << std::endl;
        }
        else if (our_number < user_number)
        {
            std::cout << "My number is lesser than yours" << std::endl;
        }
    }
}

   void give_reply_when_guess_equals_true_or_runs_out(int &user_number, int our_number) 
   {
        if (user_number == our_number)
        {
           std::cout << "Great job!" << std::endl;
        }
        else
        {
           std::cout << "Sorry, you ran out of attempts. :´(" << std::endl;
        }
        
   }
int main()
{
    auto user_number{0};
    int our_number;
    welcome_and_pick_number(our_number);
    ask_for_numbers_give_reply(user_number, our_number);
    give_reply_when_guess_equals_true_or_runs_out(user_number, our_number);

    

    return 0;
}
