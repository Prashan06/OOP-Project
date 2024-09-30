
+16
-2
Original file line number	Diff line number	Diff line change
#include <iostream>

class Farm {
    protected:
    int buyPrice;
    int sellPrice;
    int sellTime;
    time_t timer;

    public:
        virtual void sellItem() = 0;
        virtual void buyItem() = 0;
    Farm();
	virtual void applySpeedGrow();
	virtual void applyHighYield();
	int setBuyPrice(int buyPrice);
    int getBuyPrice();
	void setSellPrice(int sellPrice);
    int getSellPrice();
	void setSellTime(int sellTime);
	int getSellTime();
	~Farm();
};

#endif