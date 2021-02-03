/*


Little-Endian, Big-Endian
В современном мире любые данные в памяти компьютера и при их передаче по каналам связи представлены в виде последовательности байтов. В разных системах и протоколах байты принято упорядочивать по-разному: от старшего к младшему (big-endian) или от младшего к старшему (little-endian).

Например:

2017_{10} = 11111100001_{2}
2017 
10
​	
 =11111100001 
2
​	
 
Big-endian: \quad 2017_{10} = 00000111\quad11100001_{2}
Big−endian:2017 
10
​	
 =0000011111100001 
2
​	
 
\begin{equation} Little-endian: \quad 2017_{10} = 11100001\quad00000111_{2} \end{equation}
Little−endian:2017 
10
​	
 =1110000100000111 
2
​	
 
​	
  
​	
 
В мире блокчейн разницу между кодированием чисел можно сразу увидеть: Bitcoin использует последовательность little-endian, Ethereum использует последовательность big-endian.
Напишите программу, которая преобразует число к формату с little-endian с учетом того для гипотетической вычислительной системы, где используются байты состоящие только из 7 бит.

Формат входных данных:
На вход подается целое число NN (1 \le N \le 2^{28}-11≤N≤2 
28
 −1).

Формат выходных данных:
Необходимо вывести последовательность из 28 символов 00 или 11 (биты) – представление входного числа в формате little-endian.

Sample Input 1:

2
Sample Output 1:

0000010000000000000000000000
Sample Input 2:

268435305
Sample Output 2:

1101001111111011111111111111

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

void printBigEndian(int n) { // n in range [1, 2**28 - 1]  
    std::vector<int> res(28, 0);
    int pos = 0;
    while (n) {
        res[pos++] = n % 2;
        n /= 2;
    }
    for (int i = 0; i < 7; ++i) {
        std::swap(res[i], res[21 + i]);
        std::swap(res[7 + i], res[14 + i]);
    }
    std::copy(res.rbegin(), res.rend(), std::ostream_iterator<int>(std::cout));
}

int main() {
    int n;
    cin >> n;
    printBigEndian(n);
    return 0;
}

