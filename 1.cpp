#include <iostream>
#include <string>

using namespace std;

class Donator {
public:
    static float totalMoney;

    void setName(string _name) { name = _name; }
    void setMoney(float _money) { money = _money; }

    string getName() const { return name; }
    float getMoney() const { return money; }

    static void printTotal() {
        cout << "total:" << totalMoney << endl;
    }

    friend string getMaxName(const Donator d[], int n);

private:
    string name;
    float money;
};

float Donator::totalMoney = 0.0;

// 返回本批次中捐款最高者的姓名
string getMaxName(const Donator d[], int n) {
    float maxMoney = d[0].money;
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (d[i].money > maxMoney) {
            maxMoney = d[i].money;
            maxIndex = i;
        }
    }
    return d[maxIndex].name;
}

//读取n个捐款人的姓名和捐款额 
void read(Donator dt[], int n) {
    string name;
    float money;
    for (int i = 0; i < n; ++i) {
        cin >> name >> money;
        dt[i].setName(name);
        dt[i].setMoney(money);
        Donator::totalMoney += money;
    }
}

int main() {
    int n;
    cin >> n; //输入本批次将参与的捐款人数
    cin >> Donator::totalMoney; //输入目前已有的捐款总额 
    Donator::printTotal();
    Donator d[n];
    read(d, n);
    Donator::printTotal();
    cout << getMaxName(d, n) << endl; //输出本批次中捐款最高者姓名 
    return 0;
}

