#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq() {}

PmergeMe::PmergeMe(char *input)
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
}

PmergeMe::PmergeMe(const PmergeMe &src) : vec(src.vec), deq(src.deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        vec = src.vec;
        deq = src.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<unsigned int> PmergeMe::getVec() const {
    return vec;
}

void PmergeMe::printVec(std::string str) const
{
    std::cout << str;
    for (int i = 0; i < static_cast<int>(vec.size()); i++)
        std::cout << vec[i] << " ";
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

std::vector<size_t> jacobsthalSeq(size_t n)
{
    std::vector<size_t> seq;
    size_t j0 = 0, j1 = 1;
    while (true)
    {
        size_t j2 = j1 + 2 * j0;
        if (j2 >= n)
            break;
        seq.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    return seq;
}

void PmergeMe::PmergeMeVec(std::vector<unsigned int> &vec) {
    //base for recursion case vec.size() == 1???
    if(vec.size() == 1)
        return ;
    std::vector< std::pair<int, int> > pending; //for storing smalls keepeng their relations with big.
    std::vector<unsigned int> bigs; //big res
    
    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int big = vec[i] > vec[i+1] ? vec[i] : vec[i+1];
        int small = vec[i] < vec[i+1] ? vec[i] : vec[i+1];
        pending.push_back(std::make_pair(big, small));
        bigs.push_back(big); //fill bigs
    }
    //handle odd if existd
    if(vec.size() % 2 == 1)
    {
        std::pair<int, int> dub = std::make_pair(vec.back(), -1);
        pending.push_back(dub);
        bigs.push_back(dub.first);
    }
    //at this step we should have pending - map of connection big-small
    //and array of bigs
    
    //recursevly sort in pairs vector big
    PmergeMeVec(bigs);

    //Step 4: Insert pending.second using Jacobsthal sequence
    std::vector<size_t> jacob = jacobsthalSeq(pending.size());
    //     // Insert first small element if it exists
    if (pending.size() > 0 && pending[0].second != -1) {
        bigs.insert(bigs.begin(), pending[0].second);
    }

    // Use Jacobsthal sequence to determine insertion order
    size_t lastProcessed = 0;

    for(size_t i = 0; i < jacob.size(); ++i) {
        size_t jacobIndex = jacob[i];
        if (jacobIndex >= pending.size()) continue;

        // Insert elements from jacobIndex down to lastProcessed + 1
        for (size_t j = jacobIndex; j > lastProcessed; --j) {
            if (j < pending.size() && pending[j].second != -1) {
                int val = pending[j].second;
                std::vector<unsigned int>::iterator pos = std::lower_bound(bigs.begin(), bigs.end(), val);
                bigs.insert(pos, val);
            }
        }
        lastProcessed = jacobIndex;
    }

    //Step 5: Copy back to vec
    vec = bigs;
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