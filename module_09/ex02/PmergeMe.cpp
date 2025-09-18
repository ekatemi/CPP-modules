#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec(), deq(), size(0) {}

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
        if (std::find(vec.begin(), vec.end(), static_cast<int>(num)) != vec.end())
            throw std::runtime_error("Error: duplicate number.");

        vec.push_back(static_cast<int>(num));
        deq.push_back(static_cast<int>(num));
        
    }
    if (!iss.eof())
    {
        throw std::runtime_error("Error: invalid input (non-integer token).");
    }
    size = vec.size();
}

PmergeMe::PmergeMe(const PmergeMe &src) : vec(src.vec), deq(src.deq), size(src.size) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src)
    {
        vec = src.vec;
        deq = src.deq;
        size = src.size;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

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

//helper
size_t PmergeMe::getSize() const {
    return size;
}


std::vector<size_t> jacobsthalSeq(size_t n) {
    std::vector<size_t> seq;
    size_t j0 = 0, j1 = 1;
    while (true) {
        size_t j2 = j1 + 2 * j0;
        if (j2 >= n) break;
        seq.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    return seq;
}


void PmergeMe::pmergeVec()
{
    if(vec.empty() || size == 1)
        throw std::runtime_error("Nothing to sort here");
    std::vector< std::pair<int, int> > pending;
    printVec("Before: ");

    for (size_t i = 0; i + 1 < size; i += 2) {
        int big = vec[i] > vec[i+1] ? vec[i] : vec[i+1];
        int small = vec[i] < vec[i+1] ? vec[i] : vec[i+1];
        pending.push_back(std::make_pair(big, small));
    }

    // Handle odd leftover
    if (size % 2 != 0) {
        std::pair<int, int> dub = std::make_pair(vec.back(), -1);
        pending.push_back(dub);
    }

    std::sort(pending.begin(), pending.end());
    
    std::vector<unsigned int> sorted;
    
    for (size_t i = 0; i < pending.size(); i++)
        sorted.push_back(pending[i].first); // bigs


    // Step 4: Insert pending.second using Jacobsthal sequence
    std::vector<size_t> jacob = jacobsthalSeq(pending.size());
    
    // Insert first small element if it exists
    if (pending.size() > 0 && pending[0].second != -1) {
        sorted.insert(sorted.begin(), pending[0].second);
        //pending[0].second = -1; // Mark as inserted
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
                std::vector<unsigned int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), val);
                sorted.insert(pos, val);
            }
        }
        lastProcessed = jacobIndex;
    }
    
    // Insert any remaining elements that weren't covered by Jacobsthal sequence
    for (size_t i = lastProcessed + 1; i < pending.size(); ++i) {
        if (pending[i].second != -1) {
            int val = pending[i].second;
            std::vector<unsigned int>::iterator pos = 
                std::lower_bound(sorted.begin(), sorted.end(), val);
            sorted.insert(pos, val);
        }
    }
    
    // Step 5: Copy back to vec
    vec = sorted;
    printVec("After: ");
}
   


void PmergeMe::pmergeDeq()
{
    std::deque< std::pair<int, int> > pending;
    printDeq("Before: ");
    
    for (size_t i = 0; i + 1 < size; i += 2) {
        int big = deq[i] > deq[i+1] ? deq[i] : deq[i+1];
        int small = deq[i] < deq[i+1] ? deq[i] : deq[i+1];
        pending.push_back(std::make_pair(big, small));
    }

    // Handle odd leftover
    if (size % 2 != 0) {
        std::pair<int, int> dub = std::make_pair(deq.back(), -1);
        pending.push_back(dub);
    }

    std::sort(pending.begin(), pending.end());
    
    std::deque<unsigned int> sorted;
    
    for (size_t i = 0; i < pending.size(); i++)
        sorted.push_back(pending[i].first); // bigs

    std::vector<size_t> jacob = jacobsthalSeq(pending.size());

    // Insert first small element if exists
    if (pending[0].second != -1) {
        sorted.insert(sorted.begin(), pending[0].second);
        pending[0].second = -1;
    }

    // Insert remaining elements using Jacobsthal sequence
    for (size_t j = 0; j < jacob.size(); j++) {
        size_t start = (j == 0) ? 1 : jacob[j-1] + 1;
        size_t end = (jacob[j] < pending.size()) ? jacob[j] : pending.size() - 1;

        for (size_t k = end + 1; k-- > start; ) {
            if (pending[k].second == -1)
                continue;

            int small = pending[k].second;
            int big = pending[k].first;

            std::deque<unsigned int>::iterator bigPos = std::find(sorted.begin(), sorted.end(), big);
            std::deque<unsigned int>::iterator insertPos = std::lower_bound(sorted.begin(), bigPos, small);

            sorted.insert(insertPos, small);
            pending[k].second = -1;
        }
    }

    // Insert any remaining unprocessed elements
    for (size_t i = 0; i < pending.size(); i++) {
        if (pending[i].second != -1 ) {
            int small = pending[i].second;
            int big = pending[i].first;

            std::deque<unsigned int>::iterator bigPos = std::find(sorted.begin(), sorted.end(), big);

            std::deque<unsigned int>::iterator insertPos = std::lower_bound(sorted.begin(), bigPos, small);

            sorted.insert(insertPos, small);
        }
    }
    // 3. Copy back to vec
    deq = sorted;
    printDeq("After: ");   
}

// ./PmergeMe "`shuf -i 1-100000 -n 3000 | tr '\n' ' '`"
//./PmergeMe "1 4 2 7 3 8 45 44 43 42 41 40 35 25 24 23 21 20 19 18 17 16"