
We have a data structure 

struct Data
{
    int value;
};

/// as far as we know, only three different values could be inside Data, which means Data.value at most has three different 
value

vector<Data> datas;

Please sort the datas by its value, in O(n) time complextity.
as less as you can. 3

// swap twp Data
void swap(Data &a, Data &b)
{
    int tmp = a.value;
    a.value = b.value;
    b.value = tmp;
}

//
int shouldInsertValue(int values[], int valuesFound, int targetValue)
{
    int b = 0, e = valuesFound - 1;
    while (b <= e) {
        int mid = (b + e) >> 1;
        if (values[mid] == targetValue) return -1;
        if (values[mid] < targetValue) b = mid + 1;
        else e = mid - 1;
    }

    return b;
}

void insertValue(int values[], int &valuesFound, int targetValue, int index)
{
    for (int i = valuesFound; i >= index + 1; i --) {
        values[i] = values[i - 1];
    }
    values[index] = targetValue;
    valuesFound ++;
}

//Find three values and sort them...
void findThreeValues(int values[], int &valuesFound)
{
    values[0] = datas[0].value;
    valuesFound = 1;

    for (int i = 1; i < datas.size(); i ++) {
        int index = shouldInsertValue(values, valuesFound, datas[i].value)
        if (index == -1) continue;
        insertValue(values, valuesFound, datas[i].value, index);
    }
}

// 0 1 2 0 1 2
// 0 0 1 1 2 2
//   b     e
vector<Data> sortData(vector<Data>& datas)
{
    if (datas.size() <= 1) return datas;

    int values[3];
    int valuesFound = 0;
    findThreeValues(values, valuesFound);
    
    int b = 0, e = datas.size() - 1;
    if (valuesFound == 1) return datas;
    if (valuesFound == 2) values[2] = values[1];

    for (int i = 0; i < datas.size() && i <= e;) {
        if (datas[i].value == values[0]) {
            swap(datas[b ++], datas[i ++]);
            continue;
        }
        if (datas[i].value == values[2]) { 
            swap(datas[i], datas[e --]);
            continue;
        }
        i ++;
    }
}

void FindThreeValues(int values[], int & valueFound)
{
    valueFound = 0;
    for (int i = 0; i < datas.size(); ++i)
    {
        int curValue = datas[i].value;
        bool found = false;
        for (int j = 0; j < valueFound; ++j)
            if (values[j] == curValue) 
            {
                found = true;
                break;
            }

        if (found) continue;

        values[valueFound] = curValue;
        valueFound++;
        
        for (int j = valueFound - 1; j >= 1; --j)
        {
            if (values[j] < values[j - 1]) 
                swap(values[j], values[j - 1]);
            else
                break;
        }
    }
}










