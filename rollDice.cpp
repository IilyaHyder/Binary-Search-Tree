#include <iostream>
#include <string>

void rollDice(std::string ans, int target)
{
    if (target == 0)
    {
        std::cout << ans << " ";
        return;
    }

    for (int i = 1; i <= 6 && i <= target; i++)
    {
        rollDice(ans + std::to_string(i), target - i);
    }
}

int main()
{
    std::string ans = "";
    int target = 5;

    rollDice(ans, target);

    return 0;
}