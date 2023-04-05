#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");

    int N = 0;
    int M = 0;

    fin >> N >> N >> N >> N >> N >> N >> N;
    fout << N << "\n";

    int* n = new int[N];

    for (int i = 0; i < N; i++)
    {
        fin >> n[i];
    }

    for (int i = N - 1; i > 0; i--) // Цикл сдвигает вправо.
    {
        int t = n[i];
        n[i] = n[i - 1];
        n[i - 1] = t;
    }

    for (int i = 0; i < N; i++)
    {
        fout << n[i] << " ";
    }

    fin.clear();
    fin.seekg(0);

    fin >> M;
    fout << "\n" << M << "\n";

    int* m = new int[M];

    for (int j = 0; j < M; j++)
    {
        fin >> m[j];
    }

    int t = m[0];
    for (int j = 0; j < M - 1; j++) // Цикл сдвигает влево.
    {
        m[j] = m[j + 1];
    }
    m[M - 1] = t;

    for (int j = 0; j < M; j++)
    {
        fout << m[j] << " ";
    }

    fin.close();
    fout.close();
    delete[] n;
    delete[] m;
    return 0;
}