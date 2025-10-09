#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq(), _j_seq(), max(0), min(0), left(0), right(0), depth(0) {}

PmergeMe::PmergeMe(char *input) : max(0), min(0), left(0), right(0), depth(0)
{
    std::istringstream iss((std::string(input)));
    long long num;

    while (iss >> num)
    {
        // check for range
        if (num <= 0)
        {
            throw std::runtime_error("Error: only positive integers allowed.");
        }
        if (num > INT_MAX)
        {
            throw std::runtime_error("Error: number too large for int.");
        }
        // check duplicate in vec

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
    }
    if (!iss.eof())
    {
        throw std::runtime_error("Error: invalid input (non-integer token).");
    }
    _j_seq = jacobstal_seq(vec.size());
}

PmergeMe::PmergeMe(const PmergeMe &src) : vec(src.vec), deq(src.deq), _j_seq(src._j_seq), max(src.max), min(src.min), left(src.left), right(src.right), depth(src.depth) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        vec = src.vec;
        deq = src.deq;
        _j_seq = src._j_seq;
        max = src.max;
        min = src.max;
        left = src.left;
        right = src.right;
        depth = src.depth;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int> PmergeMe::getVec() const
{
    return vec;
}

void PmergeMe::printVec(std::string str) const
{
    std::cout << str;
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void printPend(std::vector<std::pair<unsigned int, unsigned int>> pending)
{
    std::cout << "Pend is: ";
    for (unsigned int i = 0; i < pending.size(); i++)
        std::cout << pending[i].first << " ";
    std::cout << std::endl;
}

void PmergeMe::printDeq(std::string str) const
{
    std::cout << str;
    for (int i = 0; i < static_cast<int>(deq.size()); i++)
        std::cout << deq[i] << " ";
    std::cout << std::endl;
}

// helper
// size_t PmergeMe::getSize() const
// {
//     return size;
// }

std::vector<unsigned int> PmergeMe::jacobstal_seq(unsigned int size)
{
    std::vector<unsigned int> seq;
    unsigned int x = 0;
    unsigned int y = 1;
    seq.push_back(x);
    seq.push_back(y);
    for (unsigned int i = 2; i < size; ++i)
    {
        unsigned int j = seq[i - 1] + 2 * seq[i - 2];
        if (j > size - 1)
            break;
        seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
    }
    seq.erase(seq.begin() + 1);
    return seq;
}

void PmergeMe::PmergeMeVec()
{
    int r = 0;
    // Base case: stop recursion when vec has 1 or 0 elements
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<unsigned int, unsigned int>> pending; // for SMALL attached to its big
    std::vector<unsigned int> bigs;                             // vector for BIG
    bool hasOdd = false;                                        // odd or even amount of elements
    unsigned int odd = 0;

    // Step 1: split into pairs and collect (small, big)
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        unsigned int big = vec[i] >= vec[i + 1] ? vec[i] : vec[i + 1];
        unsigned int small = vec[i] < vec[i + 1] ? vec[i] : vec[i + 1];
        pending.push_back(std::make_pair(small, big));
        bigs.push_back(big);
    }

    // Step 2: handle odd element
    if (vec.size() % 2 == 1)
    {
        hasOdd = true;
        odd = vec.back(); // pointer to last element of vector
    }

    // Step 3: recursively sort "bigs"
    std::vector<unsigned int> sortedBigs = bigs; // copy for recursion
    vec = sortedBigs;

    PmergeMeVec(); // recursive call on vec class member
    //-----------------END OF RECURSION---------------------------------------
    r++;
    std::cout << r << " level recursion" << std::endl;
    printVec("Bigs are: ");
    printPend(pending);
    std::cout << "Odd is: " << odd << std::endl;

    // Step 4: insert smalls using Jacobsthal order
    std::vector<unsigned int> sorted = vec; // already pre-sorted "bigs"

    // Always insert the first small manually
    if (!pending.empty())
    {
        std::vector<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pending[0].first); // first - small
        sorted.insert(pos, pending[0].first);
    }
    printVec("After first insertion bigs are: ");

    // Use Jacobsthal sequence to determine insertion order
    for (size_t i = 0; i < _j_seq.size(); ++i)
    {
        right = _j_seq[i];
        if (right >= pending.size())
            continue;

        for (size_t j = right; j > left; --j)
        {
            if (j < pending.size())
            {
                min = pending[j].first;
                max = pending[j].second;

                std::vector<unsigned int>::iterator bigPos = std::find(sorted.begin(), sorted.end(), max);

                std::vector<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), bigPos, min);
                sorted.insert(pos, min);
            }
        }
        left = right;
    }

    // If any smalls remain (beyond Jacobsthal coverage)
    for (size_t j = left + 1; j < pending.size(); ++j)
    {
        min = pending[j].first;
        max = pending[j].second;
        std::vector<unsigned int>::iterator bigPos = std::lower_bound(sorted.begin(), sorted.end(), max);
        std::vector<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), bigPos, min);
        sorted.insert(pos, min);
    }

    // Step 5: insert odd if exists
    if (hasOdd)
    {
        std::vector<unsigned int>::iterator pos =
            std::lower_bound(sorted.begin(), sorted.end(), odd);
        sorted.insert(pos, odd);
    }

    // Step 6: write back
    vec = sorted;
}

// void PmergeMe::pmergeVec()
// {
//     if(vec.empty() || size == 1)
//         throw std::runtime_error("Nothing to sort here");

//     std::vector< std::pair<int, int> > pending;
//     printVec("Before: ");

//     for (size_t i = 0; i + 1 < size; i += 2) {
//         int big = vec[i] > vec[i+1] ? vec[i] : vec[i+1];
//         int small = vec[i] < vec[i+1] ? vec[i] : vec[i+1];
//         pending.push_back(std::make_pair(big, small));
//     }

//     // Handle odd leftover
//     if (size % 2 != 0) {
//         std::pair<int, int> dub = std::make_pair(vec.back(), -1);
//         pending.push_back(dub);
//     }

//     //std::sort(pending.begin(), pending.end());

//     pmergeVec(pending);

//     std::vector<unsigned int> big;

//     for (size_t i = 0; i < pending.size(); i++)
//         big.push_back(pending[i].first); // bigs

//     // Step 4: Insert pending.second using Jacobsthal sequence
//     std::vector<size_t> jacob = jacobsthalSeq(pending.size());

//     // Insert first small element if it exists
//     if (pending.size() > 0 && pending[0].second != -1) {
//         big.insert(big.begin(), pending[0].second);
//     }

//     // Use Jacobsthal sequence to determine insertion order
//     size_t lastProcessed = 0;

//     for(size_t i = 0; i < jacob.size(); ++i) {
//         size_t jacobIndex = jacob[i];
//         if (jacobIndex >= pending.size()) continue;

//         // Insert elements from jacobIndex down to lastProcessed + 1
//         for (size_t j = jacobIndex; j > lastProcessed; --j) {
//             if (j < pending.size() && pending[j].second != -1) {
//                 int val = pending[j].second;
//                 std::vector<unsigned int>::iterator pos = std::lower_bound(big.begin(), big.end(), val);
//                 big.insert(pos, val);
//             }
//         }
//         lastProcessed = jacobIndex;
//     }

//     // Insert any remaining elements that weren't covered by Jacobsthal sequence
//     for (size_t i = lastProcessed + 1; i < pending.size(); ++i) {
//         if (pending[i].second != -1) {
//             int val = pending[i].second;
//             std::vector<unsigned int>::iterator pos = std::lower_bound(big.begin(), big.end(), val);
//             big.insert(pos, val);
//         }
//     }

//     // Step 5: Copy back to vec
//     vec = big;
//     printVec("After : ");
// }

// void PmergeMe::pmergeDeq()
// {
//     std::deque<std::pair<int, int> > pending;
//     printDeq("Before: ");

//     for (size_t i = 0; i + 1 < size; i += 2)
//     {
//         int big = deq[i] > deq[i + 1] ? deq[i] : deq[i + 1];
//         int small = deq[i] < deq[i + 1] ? deq[i] : deq[i + 1];
//         pending.push_back(std::make_pair(big, small));
//     }

//     // Handle odd leftover
//     if (size % 2 != 0)
//     {
//         std::pair<int, int> dub = std::make_pair(deq.back(), -1);
//         pending.push_back(dub);
//     }

//     std::sort(pending.begin(), pending.end());

//     std::deque<unsigned int> big;

//     for (size_t i = 0; i < pending.size(); i++)
//         big.push_back(pending[i].first); // bigs

//     std::vector<size_t> jacob = jacobsthalSeq(pending.size());

//     // Insert first small element if it exists
//     if (pending.size() > 0 && pending[0].second != -1)
//     {
//         big.insert(big.begin(), pending[0].second);
//     }

//     // Use Jacobsthal sequence to determine insertion order
//     size_t lastProcessed = 0;

//     for (size_t i = 0; i < jacob.size(); ++i)
//     {
//         size_t jacobIndex = jacob[i];
//         if (jacobIndex >= pending.size())
//             continue;

//         // Insert elements from jacobIndex down to lastProcessed + 1
//         for (size_t j = jacobIndex; j > lastProcessed; --j)
//         {
//             if (j < pending.size() && pending[j].second != -1)
//             {
//                 int val = pending[j].second;
//                 std::deque<unsigned int>::iterator pos = std::lower_bound(big.begin(), big.end(), val);
//                 big.insert(pos, val);
//             }
//         }
//         lastProcessed = jacobIndex;
//     }

//     // Insert any remaining elements that weren't covered by Jacobsthal sequence
//     for (size_t i = lastProcessed + 1; i < pending.size(); ++i)
//     {
//         if (pending[i].second != -1)
//         {
//             int val = pending[i].second;
//             std::deque<unsigned int>::iterator pos =
//                 std::lower_bound(big.begin(), big.end(), val);
//             big.insert(pos, val);
//         }
//     }
//     // 3. Copy back to vec
//     deq = big;
//     printDeq("After : ");
// }

// ./PmergeMe "`shuf -i 1-100000 -n 3000 | tr '\n' ' '`"
// ./PmergeMe "$(shuf -r -i 1-1000 -n 3000 | tr "\n" " ")"
//./PmergeMe "1 4 2 7 3 8 45 44 43 42 41 40 35 25 24 23 21 20 19 18 17 16"