#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class FordJohnsonDemo
{
private:
    static int indent;

    static void printIndent()
    {
        for (int i = 0; i < indent; i++)
            cout << "  ";
    }

    static void printVector(const vector<int> &vec, const string &name)
    {
        printIndent();
        cout << name << ": [";
        for (size_t i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i < vec.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    static void printPairs(const vector<int> &vec, int order)
    {
        printIndent();
        cout << "Pary (order=" << order << "): ";
        for (size_t i = 0; i < vec.size(); i += order * 2)
        {
            cout << "[";
            for (int j = 0; j < order * 2 && i + j < vec.size(); j++)
            {
                cout << vec[i + j];
                if (j < order * 2 - 1 && i + j + 1 < vec.size())
                    cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
    }

public:
    static int Jacobsthal(int k)
    {
        return round((pow(2, k + 1) + pow(-1, k)) / 3);
    }

    static void insert(vector<int> &main, vector<int> &pend, int odd,
                       vector<int> &left, vector<int> &vec, bool is_odd, int order)
    {
        printIndent();
        cout << "=== VSTAVKA ===" << endl;
        indent++;

        printVector(main, "main do vstavki");
        printVector(pend, "pend");
        if (is_odd)
        {
            printIndent();
            cout << "odd element: " << odd << endl;
        }

        vector<int>::iterator end;

        if (pend.size() == 1)
        {
            printIndent();
            cout << "Vstavlyaem edinstvennyj element pend[0]=" << pend[0] << endl;
            end = upper_bound(main.begin(), main.end(), *pend.begin());
            main.insert(end, *pend.begin());
        }
        else if (pend.size() > 1)
        {
            printIndent();
            cout << "Ispolzuem posledovatelnost Yakobshtalya dlya optimalnoj vstavki" << endl;

            size_t jc = 3;
            size_t count = 0;
            size_t idx;
            size_t decrease;

            while (!pend.empty())
            {
                idx = Jacobsthal(jc) - Jacobsthal(jc - 1);
                if (idx > pend.size())
                    idx = pend.size();

                printIndent();
                cout << "Gruppa Yakobshtalya: J(" << jc << ")-J(" << jc - 1 << ")=" << idx << " elementov" << endl;

                decrease = 0;
                while (idx)
                {
                    end = main.begin();
                    if (Jacobsthal(jc + count) - decrease <= main.size())
                        end = main.begin() + Jacobsthal(jc + count) - decrease;
                    else
                        end = main.end();

                    int elem = *(pend.begin() + idx - 1);
                    end = upper_bound(main.begin(), end, elem);

                    printIndent();
                    cout << "  Vstavlyaem pend[" << idx - 1 << "]=" << elem
                         << " v poziciyu " << (end - main.begin()) << endl;

                    main.insert(end, elem);
                    pend.erase(pend.begin() + idx - 1);
                    idx--;
                    decrease++;
                    count++;
                }
                jc++;
            }
        }

        printVector(main, "main posle vstavki pend");

        if (is_odd)
        {
            printIndent();
            cout << "Vstavlyaem odd element: " << odd << endl;
            end = upper_bound(main.begin(), main.end(), odd);
            main.insert(end, odd);
            printVector(main, "main posle vstavki odd");
        }

        // Vosstanovlenie ishodnykh grupp
        vector<int> yaslam;
        for (auto i = main.begin(); i != main.end(); i++)
        {
            auto it = find(vec.begin(), vec.end(), *i);
            yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
        }
        yaslam.insert(yaslam.end(), left.begin(), left.end());
        vec = yaslam;

        indent--;
    }

    static void sort(vector<int> &vec, int order = 1)
    {
        printIndent();
        cout << "\n=============================================" << endl;
        printIndent();
        cout << "  REKURSIVNYJ VYZOV (order=" << order << ")" << endl;
        printIndent();
        cout << "=============================================" << endl;
        indent++;

        printVector(vec, "Massiv");

        int unit_size = vec.size() / order;
        printIndent();
        cout << "unit_size = " << vec.size() << " / " << order << " = " << unit_size << endl;

        if (unit_size < 2)
        {
            printIndent();
            cout << "unit_size < 2, vozvrat iz rekursii" << endl;
            indent--;
            return;
        }

        bool is_odd = unit_size % 2 == 1;
        printIndent();
        cout << "is_odd = " << (is_odd ? "true" : "false") << " (unit_size % 2 = " << unit_size % 2 << ")" << endl;

        auto start = vec.begin();
        auto end = vec.begin() + ((order * unit_size) - (is_odd * order));

        printIndent();
        cout << "\n--- Sravnenie i obmen v parakh ---" << endl;
        printPairs(vec, order);

        for (auto it = start; it < end; it += (order * 2))
        {
            if (*(it + (order - 1)) > *(it + ((order * 2) - 1)))
            {
                printIndent();
                cout << "Menyaem mestami gruppy: " << *(it + (order - 1))
                     << " > " << *(it + ((order * 2) - 1)) << endl;
                for (int i = 0; i < order; i++)
                {
                    swap(*(it + i), *(it + i + order));
                }
            }
        }

        printVector(vec, "Posle obmena");
        printPairs(vec, order);

        // Rekursivnyj vyzov
        sort(vec, order * 2);

        printIndent();
        cout << "\n--- Vozvrat iz rekursii (order=" << order << ") ---" << endl;
        printVector(vec, "Massiv posle rekursii");

        // Sozdanie main i pend
        vector<int> main;
        vector<int> pend;
        int odd = 0;
        vector<int> left;

        printIndent();
        cout << "\n--- Formirovanie main i pend ---" << endl;

        // Pervye dva elementa v main
        main.push_back(*(start + order - 1));
        main.push_back(*(start + order * 2 - 1));

        printIndent();
        cout << "main[0] = " << *(start + order - 1) << " (poslednij element 1-j gruppy)" << endl;
        printIndent();
        cout << "main[1] = " << *(start + order * 2 - 1) << " (poslednij element 2-j gruppy)" << endl;

        for (auto it = start + order * 2; it < end; it += order)
        {
            int pend_elem = *(it + order - 1);
            pend.push_back(pend_elem);
            printIndent();
            cout << "pend += " << pend_elem << endl;

            it += order;
            int main_elem = *(it + order - 1);
            main.push_back(main_elem);
            printIndent();
            cout << "main += " << main_elem << endl;
        }

        if (is_odd)
        {
            odd = *(end + order - 1);
            printIndent();
            cout << "odd = " << odd << " (neparnaya gruppa)" << endl;
        }

        left.insert(left.end(), end + (order * is_odd), vec.end());
        if (!left.empty())
        {
            printVector(left, "left (ostavshiesya elementy)");
        }

        printVector(main, "main (bolshie elementy)");
        printVector(pend, "pend (malye elementy)");

        if (is_odd || !pend.empty())
        {
            insert(main, pend, odd, left, vec, is_odd, order);
        }

        printVector(vec, "Rezultat posle vstavki");
        indent--;
    }
};

int FordJohnsonDemo::indent = 0;

int main()
{
    vector<int> vec = {3, 1, 4, 2, 6, 5, 8, 7};

    cout << "============================================" << endl;
    cout << "  FORD-JOHNSON MERGE-INSERTION SORT DEMO  " << endl;
    cout << "============================================" << endl;
    cout << "\nIshodnyj massiv: [3, 1, 4, 2, 6, 5, 8, 7]" << endl;
    cout << "\nPosledovatelnost Yakobshtalya:" << endl;
    for (int i = 0; i <= 6; i++)
    {
        cout << "J(" << i << ") = " << FordJohnsonDemo::Jacobsthal(i) << endl;
    }
    cout << "\n";

    FordJohnsonDemo::sort(vec);

    cout << "\n============================================" << endl;
    cout << "         FINALNYJ REZULTAT                  " << endl;
    cout << "============================================" << endl;
    cout << "Otsortirovanny massiv: [";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ", ";
    }