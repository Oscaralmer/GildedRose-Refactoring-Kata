#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    static int const min_quality = 0;
    static int const max_quality = 50;

    void updateQuality();   
};

int FindDailyQualityUpdate(const Item& item);
void UpdateDueDate(Item& item);

bool PastDueDate(const Item& item);

bool isMaturing(const Item& item);
bool isDecaying(const Item& item);
bool isAgedBrie(const Item& item);
bool isConcertPass(const Item& item);
bool isLegendary(const Item& item);
bool IsConjured(const Item& item);

void IncrementQuality(int & daily_quality_update);
void DecrementQuality(int & daily_quality_update);
void UpdateItemQuality(Item& item, const int daily_quality_update);
int ClampItemQuality(const int total_quality);

