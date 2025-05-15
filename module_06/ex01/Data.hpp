class Data
{
private:
    int val;

public:
    Data();
    Data(const int i);
    Data(const Data &src);
    Data &operator=(const Data &src);
    ~Data();
    void setVal(int i);
    int getVal() const;
};