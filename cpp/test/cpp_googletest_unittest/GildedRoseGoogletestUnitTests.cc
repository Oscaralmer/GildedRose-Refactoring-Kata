#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, Foo) {
    vector<Item> items;
    items.push_back(Item("Foo", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Foo", app.items[0].name);
}

TEST(GildedRoseTest, Sulfuras)
{
    vector<Item> items;
    int init_sellIn = 10;
    int init_qual = 80;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < 100; i++)
    {
        app.updateQuality();
    }
    EXPECT_EQ(init_qual, app.items[0].quality);
    EXPECT_EQ(init_sellIn, app.items[0].sellIn);

}

TEST(GildedRoseTest, AgedBrie_Increasing_Value)
{
    vector<Item> items;
    int init_sellIn = 10;
    int init_qual = 30;
    int num_days = 10;
    items.push_back(Item("Aged Brie", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }
    EXPECT_EQ(app.items[0].quality, init_qual + num_days);
}

TEST(GildedRoseTest, AgedBrie_Max_Qual)
{
    vector<Item> items;
    int init_sellIn = 10;
    int init_qual = 50;
    int num_days = 10;

    items.push_back(Item("Aged Brie", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }
    
    EXPECT_EQ(app.items[0].quality, GildedRose::max_quality);
}

TEST(GildedRoseTest, Backstage_Pass_Above_Double_Threshold)
{
    vector<Item> items;
    int init_sellIn = 11;
    int init_qual = 12;
    int num_days = 1;

    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }

    EXPECT_EQ(app.items[0].quality, init_qual + num_days);
}

TEST(GildedRoseTest, Backstage_Pass_On_Double_Threshold)
{
    vector<Item> items;
    int init_sellIn = 10;
    int init_qual = 11;
    int num_days = 1;

    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }

    EXPECT_EQ(app.items[0].quality, init_qual + 2*num_days);
}

TEST(GildedRoseTest, Backstage_Pass_Double_And_Tripple_Thresholds)
{
    vector<Item> items;
    int init_sellIn = 10;
    int init_qual = 11;
    int num_days = 6;

    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }

    EXPECT_EQ(app.items[0].quality, init_qual + 13);
}


TEST(GildedRoseTest, Backstage_Pass_Negative_Sellin)
{
    vector<Item> items;
    int init_sellIn = 0;
    int init_qual = 49;
    int num_days = 1;

    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }

    EXPECT_EQ(app.items[0].quality, GildedRose::min_quality);
}

TEST(GildedRoseTest, Backstage_Max_Quality_After_First_Update)
{
    vector<Item> items;
    int init_sellIn = 5;
    int init_qual = 48;
    int num_days = 1;

    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", init_sellIn, init_qual));
    GildedRose app(items);
    for (int i = 0; i < num_days; i++)
    {
        app.updateQuality();
    }

    EXPECT_EQ(app.items[0].quality, GildedRose::max_quality);
}




