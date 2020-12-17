#include <iostream>
#include <vector>
#include <cstdlib>

long long MaxPairwiseProduct(const std::vector<int>& numbers)
{
    long long result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if ((long long)numbers[i] * numbers[j] > result)
            {
                result = (long long)numbers[i] * numbers[j];
            }
        }
    }

    return result;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();
    int max_index1 = -1, max_index2 = -1;

    for (int i = 0; i < n; i += 1)
    {
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
        {
            max_index1 = i;
        }
    }

    for (int j = 0; j < n; j += 1)
    {
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
        {
            max_index2 = j;
        }
    }

    return ((long long)numbers[max_index1]) * numbers[max_index2];
}

int main() {
    /*********** Stress Testing ***********/
    // while (true)
    // {
    //     int n = rand() % 1000 + 2;
    //     std::cout << n << std::endl;

    //     std::vector<int> a;
    //     for (int i = 0; i < n; i += 1)
    //     {
    //         a.push_back(rand() % 100000);
    //     }
    //     for (int i = 0; i < n; i += 1)
    //     {
    //         std::cout << a[i] << " ";
    //     }
    //     std::cout << std::endl;

    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProductFast(a);
    //     if (res1 != res2)
    //     {
    //         std::cout << "Wrong answer: " << res1 << " " << res2 << std::endl;
    //         break;
    //     }
    //     else
    //     {
    //         std::cout << "OK" << std::endl;
    //     }
    // }

    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; i += 1) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << std::endl;
    return 0;
}
